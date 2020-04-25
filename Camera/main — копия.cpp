#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>
#include "Map.h"
#include "AnimationMainHero.h"
//#include "Camera.h"
#include "General_Data.h"
#include "Control.h"
#include "windows.h"
#include <future>

	while (window.isOpen())

	{
		sf::Event e;
		//cout << endl << "time"<< clock.getElapsedTime().asMicroseconds();
	


			while (window.pollEvent(e))
			{
				if (e.type == sf::Event::Closed)
					window.close();
			}



	
		
		
	}


int main_main()
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
	sf::Clock clock,fps_clock;
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
		if (clock.getElapsedTime().asMilliseconds() > int(1000/60))
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
				camera.setCenter((int)camera.getCenter().x+0,(int) camera.getCenter().y+con);
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


int main_smooth()
{
	sf::RenderTexture background_texture;
	background_texture.create(1200, 1000);
	bool count = false;
	int fps = 0;
	sf::Texture tex;
	sf::Sprite background_sprite,sprite;
	background_sprite.setTexture(background_texture.getTexture());
	int con = 0;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
	camera.reset(sf::FloatRect(0, 0, 1200, 800));
	//	camera.setCenter(1000*1.f, 400*1.f);
	window.setView(camera);
	float time, counter, tx, tz;
	counter = 0;
	counter = GetTickCount();
//window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	sf::Clock gl_clock;
	sf::Clock clock, fps_clock;
	bool pr = false;

	float runspeed = 0.007;
	//	InitMap(background_texture);
	//	Entity en(400, 300, 0, 0);
	sf::Time updateTime;

	float last[2] = { 0, 0 };

	tex.loadFromFile("Images\\PC Computer - Captain Claw - Level 1 Tiles_2.png", sf::IntRect(130, 65, 600, 600));
	tex.setSmooth(true);
//sprite.setScale(1.3, 1.3);
	sprite.setTexture(tex);
	sprite.setTextureRect(sf::IntRect(0, 0, 600, 600));
	sprite.setOrigin(0, 0);
	window.draw(sprite);
	sf::Sprite ar[30] = {};
//	sprite.setTextureRect(sf::IntRect(0, 0, 66, 60));  sprite.setOrigin(0, 0);

	while (window.isOpen())

	{
		sf::Event e;
		//cout << endl << "time"<< clock.getElapsedTime().asMicroseconds();
	//	if (clock.getElapsedTime().asMilliseconds() > int(1000 / 60))
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



		

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
			{
				con =1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
			{
				con = -1;
			}

		
			{
				camera.setCenter(round(camera.getCenter().x + 0), round(camera.getCenter().y + con));
		
			}

			if ((int)camera.getCenter().y == (int)camera.getCenter().y + con)
				cout << endl << "int "<< (int)camera.getCenter().y;
				//		sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y+con);
			window.clear();

	//		window.draw(sprite);
			window.draw(sprite);

			window.setView(camera);
		//	window.clear();
	
	
			window.display();
		
		}

	}

	return 0;

}














class game 
{

	sf::RenderWindow window;
	sf::View Camera;
	sf::Thread render_thread;
	sf::Clock gl_clock;

	int con = 0;
	float time = 0.f;
	float delta = 0.f;
public:
	game()
		: window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default),
		  render_thread (&game::render, this)
	{
		window.setVerticalSyncEnabled(true);
		Camera.reset(sf::FloatRect(0, 0, 1200, 800));

	};



	void run();

		   void render();
		   void game_logic();
};

void game :: render()
{
	sf::Texture tex;
	sf::Sprite  sprite;
	sf::Clock clock;
	tex.loadFromFile("Images\\PC Computer - Captain Claw - Level 1 Tiles_2.png", sf::IntRect(130, 65, 600, 600));
	tex.setSmooth(true);

	window.setActive(true);

	sprite.setTexture(tex);
	sprite.setTextureRect(sf::IntRect(0, 0, 600, 600));
	sprite.setOrigin(0, 0);

	while (window.isOpen())
	{
		window.clear();
		window.draw(sprite);
		
			Camera.move(0, int(delta));
			
			delta -= int(delta);
			window.setView(Camera);

		window.display();

		//	sf::sleep(sf::milliseconds(10));
	}
};

void game::run()
{
	window.setActive(false);
	render_thread.launch();
	game_logic();
};

void game::game_logic()
{
	sf::Vector2f pos = Camera.getCenter();
	while (window.isOpen())
	{

		time = gl_clock.getElapsedTime().asMicroseconds();
		gl_clock.restart();

		time /= 800;

		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			//cout << endl << "sss";
			con = 1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{

			con = -1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{

			window.close();

		}

		delta +=(time* con*0.07);

		int x=int((Camera.getCenter().y - pos.y));
	//	cout <<endl<< "x="<< x<<"  "<< pos.y<<"  " <<time<<"   "<<Camera.getCenter().y;
	//	if (abs(x)>10)getchar();
	
			//	Camera.setCenter(round(Camera.getCenter().x + 0), round(Camera.getCenter().y + x));
		//		Camera.move( 0, con );
				

//if (x != 0)
		//		 pos = Camera.getCenter();
	

	//	Camera.setCenter(round(pos.x),round(pos.y));
//Camera.move({ 0,con*0.07f });
	//	sf::sleep(sf::milliseconds(16.5));
	}
}

int main()
{
	game g;
	g.run();


	return 0;
}

//class Game {
//	int con = 0;
//	sf::RenderWindow window;
//	sf::View Camera;
//	float delta;
//	sf::Thread  logic_thread;
//	sf::Clock gl_clock;
//public:
//
//	Game()
//		:window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default),
//
//		logic_thread(&Game::game_logic,this)
//
//	{
//		Camera.reset(sf::FloatRect(0, 0, 1200, 800));
//		window.setVerticalSyncEnabled(true);
//
//	};
//	void display();
// void	render();
// void game_logic();
// void run();
//
//};
//
//void Game::display()
//{
//	window.setActive(true);
//	window.display();
//}
//
//void Game::run()
//{
////	window.setActive(false);
//	//	render_thread.launch();
//	logic_thread.launch();
//	render();
//	
//	//	game_logic();
//}
//
//void Game::render()
//{
//
//	sf::Texture tex;
//	sf::Sprite  sprite;
//	sf::Clock clock;
//	tex.loadFromFile("Images\\PC Computer - Captain Claw - Level 1 Tiles_2.png", sf::IntRect(130, 65, 600, 600));
//	tex.setSmooth(true);
//
//
//	sprite.setTexture(tex);
//	sprite.setTextureRect(sf::IntRect(0, 0, 600, 600));
//	sprite.setOrigin(0, 0);
//	window.draw(sprite);
//
//	sf::Vector2f pos = Camera.getCenter();
//	sf::Vector2f cam_pos = Camera.getCenter();
//	while (window.isOpen())
//	{
//
//
//		 float	v = 1.f * 60 / 1000000;
//			float y= gl_clock.getElapsedTime().asMicroseconds()*con*v;
//		
//		//	delta += y;
//		
//		//	gl_clock.restart();
//
//			pos.y += delta;
//	
//			cout << endl<< "del" << round(pos.y);
//		Camera.setCenter(round(Camera.getCenter().x + 0), round(pos.y ));
//
//
//
//		cam_pos = Camera.getCenter();
//			
//			window.clear();
//			window.setView(Camera);
//
//		window.draw(sprite);
//
//		delta = 0.f;
//		window.display();
//
//
//	}
//}
//
//
//
//
//void Game::game_logic()
//{
//	float time = 0.f;
//	
//	sf::Clock clock, fps_clock;
//	sf::Vector2f pos = Camera.getCenter();
//	while (window.isOpen())
//	{
//		time = gl_clock.getElapsedTime().asMicroseconds();
//		gl_clock.restart();
//
//		sf::Event e;
//		while (window.pollEvent(e))
//		{
//			if (e.type == sf::Event::Closed)
//				window.close();
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
//		{
//			con = 1;
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
//		{
//			con = -1;
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//		{
//			window.close();
//		}
//
//		float	v = 1.f * 59 / 1000000;
//		delta +=(time* con*v);
//	//	cout <<endl<< "run" << time <<"   "<< v;
//
//		sf::milliseconds(1);
//	}
//}
//
//int main()
//{
//	Game g;
//		g.run();
//	return 0;
//}



int mainjg()
{
	sf::RenderTexture background_texture;
	background_texture.create(1200, 1000);
	bool count = false;
	int fps = 0;
	sf::Texture tex;
	sf::Sprite background_sprite, sprite;
	background_sprite.setTexture(background_texture.getTexture());
	int con = 0;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
	camera.reset(sf::FloatRect(0, 0, 1200, 800));
	//	camera.setCenter(1000*1.f, 400*1.f);
	window.setView(camera);
	float time, counter, tx, tz;
	counter = 0;
	counter = GetTickCount();
	//window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	sf::Clock gl_clock;
	sf::Clock clock, fps_clock;
	bool pr = false;

	float runspeed = 0.007;
	//	InitMap(background_texture);
	//	Entity en(400, 300, 0, 0);
	sf::Time updateTime;

	float last[2] = { 0, 0 };

	tex.loadFromFile("Images\\PC Computer - Captain Claw - Level 1 Tiles_2.png", sf::IntRect(130, 65, 600, 600));
	tex.setSmooth(true);


	//sprite.setScale(1.3, 1.3);
	sprite.setTexture(tex);
	sprite.setTextureRect(sf::IntRect(0, 0, 600, 600));
	sprite.setOrigin(0, 0);
	window.draw(sprite);

	//	sprite.setTextureRect(sf::IntRect(0, 0, 66, 60));  sprite.setOrigin(0, 0);

	while (window.isOpen())

	{
		sf::Event e;
		//cout << endl << "time"<< clock.getElapsedTime().asMicroseconds();
		//	if (clock.getElapsedTime().asMilliseconds() > int(1000 / 60))
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





			if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
			{
				con = 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
			{
				con = -1;
			}


			{
				camera.setCenter(round(camera.getCenter().x + 0), round(camera.getCenter().y + con));

			}

			if ((int)camera.getCenter().y == (int)camera.getCenter().y + con)
				cout << endl << "int " << (int)camera.getCenter().y;
			//		sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y+con);
			window.clear();

			//		window.draw(sprite);
			window.draw(sprite);

			window.setView(camera);
			//	window.clear();


			window.display();

		}

	}

	return 0;

}
