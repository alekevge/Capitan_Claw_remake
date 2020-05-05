#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>
#include "Map.h"
#include "AnimationMainHero.h"
#include "Camera.h"
#include "General_Data.h"
#include "Control.h"
#include "windows.h"
#include <future>



int main_()
{
	sf::RenderTexture background_texture;
	background_texture.create(1200, 1000);
	bool count = false;
	int fps = 0;
	sf::Sprite background_sprite;
	background_sprite.setTexture(background_texture.getTexture());
	int con = 0;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
	//	window.setFramerateLimit(90);
	window.setVerticalSyncEnabled(true);
	camera.reset(sf::FloatRect(0, 0, 1200, 800));
	//	camera.setCenter(1000*1.f, 400*1.f);
	window.setView(camera);
	float time, counter, tx, tz;
	counter = 0;
	counter = GetTickCount();
	General_Data general_data = General_Data(600., 470., window);

	Map map(background_texture, background_texture, window, general_data);
	Character Player = Character(1, time, general_data, map);
	sf::Clock gl_clock;
	sf::Clock clock, fps_clock;
	bool pr = false;

	Control controls = Control(Player, general_data, gl_clock);
	state State = standing;
	float runspeed = 0.007;
	//	InitMap(background_texture);
	//	Entity en(400, 300, 0, 0);
	sf::Time updateTime;

	float last[2] = { 0, 0 };
	//background_sprite.setScale(1.3, 1.3);


	while (window.isOpen())

	{
		sf::Event e;
		//cout << endl << "time"<< clock.getElapsedTime().asMicroseconds();
		if (clock.getElapsedTime().asMilliseconds() > int(1000 / 60))
		{
			counter = GetTickCount();
			time = clock.getElapsedTime().asMicroseconds();
			fps++;
			if (fps_clock.getElapsedTime().asMilliseconds() > 1000)
			{
				fps_clock.restart();
				cout << endl << fps;
				fps = 0;

			}
			clock.restart();
			time /= 800;



			while (window.pollEvent(e))
			{
				if (e.type == sf::Event::Closed)
					window.close();
			}



			controls.control();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
			{
				Player.ResetFrame();
				if (Player.Status == test) Player.test_();
				Player.Status = test;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
			{
				con = 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
			{
				con = -1;
			}


			int delta = -40;





			if (trunc(general_data.Get_Screen_Pos().x / 60) != int(map.Get_Last_Pos().x / 60)
				|| trunc(general_data.Get_Screen_Pos().y / 60) != int(map.Get_Last_Pos().y / 60))
				map.DrawMap_save(background_texture);



			tx = (general_data.Get_Screen_Pos().x) - int((map.Get_Last_Pos().x) / 60) * 60;
			tz = (general_data.Get_Screen_Pos().y) + delta - int((map.Get_Last_Pos().y + delta) / 60) * 60;
			tx += map.buffer_background_texture.x*map.sizeMapX;
			tz += map.buffer_background_texture.y*map.sizeMapY + 0 * delta;
			//	background_sprite.setPosition(sf::Vector2f(round(-tx), round(-tz)));
			float d = 1;

			/*	if ((int(tx) - int(last[0])) >= d ||
			(int(tx) - int(last[0]) <= -d) ||
			(int(tz) - int(last[1]) >= d) ||
			(int(tz) - int(last[1]) <= -d))*/

			{

				background_sprite.setPosition(sf::Vector2f(/*round*/(-(tx)), /*round*/(-(tz))));



				last[0] = tx;
				last[1] = tz;
			}




			//	if (con == 10)
			{
				camera.setCenter(/*(int)*/camera.getCenter().x + 0,/*(int)*/ camera.getCenter().y + con);
				//	camera.move(0, con);
				//	con = 0;
			}
			window.setView(camera);
			window.clear();

			//	background_sprite.setPosition(sf::Vector2f(round(-map.buffer_background_texture.x*map.sizeMapX), round(-map.buffer_background_texture.y*map.sizeMapY)));
			window.draw(background_sprite);

			Player.UpdateHero();
			window.draw(Player.herosprite);
			window.display();
		}

	}

	return 0;

}

class Gen_data
{
public:
	sf::Vector2f screen_pos;
	sf::Vector2f motion_vel;

	Gen_data(float a, float  b)
		: screen_pos(a, b)
	{
		motion_vel = { 0.f,0.f };
	}
};

class Render
{
	sf::Sprite sprite;
	sf::View camera;
	sf::Texture tex;
	Gen_data& general_data;
	int acc = 0;

public:
	sf::RenderWindow window;

	Render(Gen_data & general_data)
		: general_data(general_data),
		  window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default)
	{
		tex.loadFromFile("Images\\PC Computer - Captain Claw - Level 1 Tiles_2.png", sf::IntRect(130, 65, 600, 600));
		tex.setSmooth(true);

		sprite.setTexture(tex);
		sprite.setTextureRect(sf::IntRect(0, 0, 600, 600));
		sprite.setOrigin(0, 0);

		window.setVerticalSyncEnabled(true);
		camera.reset(sf::FloatRect(0, 0, 1200, 800));
	}

	void motion();
	void run();

};



void Render::motion()
{
	float new_pos = general_data.screen_pos.y;

	if (abs((camera.getCenter().y - (new_pos))) > abs(10))
	{
		camera.setCenter(camera.getCenter().x, (general_data.screen_pos.y));
		acc = 0;
	}
	else
	{
		if (abs((camera.getCenter().y - new_pos)) > abs(5))
		{
			acc = general_data.motion_vel.y;
		}
		else acc = 0;

		camera.move(0, general_data.motion_vel.y + acc);
	}
}

void Render::run()
{

	while (window.isOpen())
	{

		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.setView(camera);

		motion();
		window.draw(sprite);
		window.display();
	}
}


class Game
{
	sf::Clock clock;
	sf::Thread logic_thread;

	Gen_data general_data;

	Render render;
	int con = 0;
	sf::Vector2f pos;

public:
	Game()
		:logic_thread(&Game::logic, this),
		general_data(0.f, 0.f),
		render(general_data)
	{
		pos = camera.getCenter();
	}

	void run();

	void logic();

	void control();
};


void Game::control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		general_data.motion_vel.y = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		general_data.motion_vel.y = -1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		render.window.close();
	}
}


void Game::logic()
{

	while (render.window.isOpen())
	{

		float v = 1.f * 60.f / 1000000.f;

		control();

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
	
		general_data.screen_pos.y += time*v*general_data.motion_vel.y;
	
		sf::sleep(sf::milliseconds(1));
	}
}


void Game::run()
{
	logic_thread.launch();
	render.run();
}

int main()
{

	Game game;
	game.run();


	return 0;
}
