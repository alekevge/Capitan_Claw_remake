#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>
#include "Map.h"
#include "AnimationMainHero.h"
#include "Camera.h"
#include "General_Data.h"
#include "Control.h"
#include "windows.h"

using namespace std;
struct Entity
{
	Entity(float x_l, float y_l, float vx_l, float vy_l)
	{
		x = x_l;
		y = y_l;
		vx = vx_l;
		vy = vy_l;
		tex.loadFromFile("Images\\PC Computer - Captain Claw - Level 1 Tiles_2.png");
		tex.setSmooth(false);

		sprite.setTexture(tex);
		sprite.setTextureRect(sf::IntRect(130, 65, 600, 600));
		sprite.setOrigin(0, 0);
		sprite.setScale(1.5, 1.5);
//		sprite.setScale(2, 2);
	}
public:
	/* Current position. */
	float x;
	float y;

	/* Velocity per unit of time. */
	float vx=0;
	float vy;
	bool lag = false;
	sf::Sprite sprite;

	sf::Texture tex;


public:

	void update(float dt)
	{
		vy = 0;
		//vx = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (abs(vx)<2)  vx -= 0.2;
		//	vx -= 2;
		
		}
		else { if (vx < 0 && abs(vx)>0.2) vx += 0.2; };

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (!lag)
			{
				lag = true;

				cout << endl << "lag_ true";
			}
			if (abs(vx)<2
				
				)  vx += 0.2;
		//	vx += 2;
		}
		else { 
			if (lag)
			{
				lag = false;
				cout << endl << "lag_ false";
			}

			if (vx > 0 && abs(vx)>0.2) vx -= 0.2; };



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			vy += -2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			vy += 2;
		}
		if (abs(vx)>0.2) x += vx*0.25 * dt;
	//	y += vy * dt*0.65;
//		x += vx*dt*0.65;

		y += vy * dt*0.25;
	//	x += vx*dt*0.1;
	}

	void render(sf::RenderTarget& rt)
	{
		float x_l = sprite.getPosition().x;
		float y_l = sprite.getPosition().y;
		
		if (round(x_l)!=round(x)|| round(y_l)!=round(y))
		sprite.setPosition({round(x),round(y) });
		rt.draw(sprite);

	}
};



int main()
{
	sf::RenderTexture background_texture;
	background_texture.create(1200, 1000);
	bool count = false;
	sf::Sprite background_sprite, background_sprite_temp;
	background_sprite.setTexture(background_texture.getTexture());
	background_sprite_temp.setTexture(background_texture.getTexture());
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
	camera.reset(sf::FloatRect(0, 0, 1200, 800));
	float time, counter, tx, tz;
	counter = 0;
	counter = GetTickCount();
	sf::View my_view(sf::FloatRect(0, 0, 1200, 800));
	General_Data general_data = General_Data(600., 470., window);
//	window.setFramerateLimit(90);
//	window.setVerticalSyncEnabled(true);
	Map map(background_texture, window, general_data);
	Character Player = Character(1, time, general_data, map);
	sf::Clock gl_clock;
	sf::Clock clock;
	bool pr = false;

	Control controls = Control(Player,general_data,gl_clock);
	state State = standing;
	float runspeed = 0.007;
	//	InitMap(background_texture);
	Entity en(400, 300, 0, 0);
	sf::Time updateTime;



//	while (window.isOpen()) {
//		// Event handling is performed here
//
//		// Determine the time that passed
//		sf::Time delta = clock.restart();
//		bool t = false;
//		updateTime += delta; // add up previous leftover time
//
//		int IIIAG = 2;
//		int loops = std::min<int>((int)(updateTime / sf::milliseconds(IIIAG)), IIIAG); // determine the number of iterations to do (100 fps; capped at 10)
//		while (loops--)
//		{
//			en.update(IIIAG);
//	//		if (loops%2==0)
//			{
//			
//				window.clear();
//				// rendering
//en.render(window);
//				window.display();
//			}
//
//			//	updateSingleStep(); // update by one fixed timestep
//		}
//        updateTime %= sf::milliseconds(IIIAG); // drop leftover frames
//
//		en.update(updateTime.asMilliseconds()/* / 10*/); // update based on time passed
//		
//		window.clear();
//		// rendering
//		en.render(window);
//		window.display();		//sf::sleep(sf::microseconds(10));
//		sf::sleep(sf::microseconds(IIIAG));
//		// sleep a minimum amount of time to ensure there's always at least some delta time (assuming very, very fast CPUs).
//	}


	while (window.isOpen())

	{
	sf::Event e;

	counter = GetTickCount();
	time = clock.getElapsedTime().asMicroseconds();
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

		
	window.clear();
			
			
	if (map.IsMapChanged())
	{	
		int delta =-40;
		tx = (general_data.Get_Screen_Pos().x) - int((general_data.Get_Screen_Pos().x) / 60) * 60;
		tz = (general_data.Get_Screen_Pos().y)+delta  - int((general_data.Get_Screen_Pos().y +delta) / 60) * 60;
		sf::Vector2f v = background_sprite.getPosition();

		map.DrawMap_save(background_texture);		
		background_sprite.setPosition(sf::Vector2f(round(-tx), round(-tz)));
					
	}
	
	window.draw(background_sprite);
		
	Player.UpdateHero();
	window.draw(Player.herosprite);
	window.display();

	}
			

	return 0;

}