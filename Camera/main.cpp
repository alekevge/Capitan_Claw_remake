#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>
#include "Map.h"
#include "AnimationMainHero.h"
#include "Camera.h"
#include "General_Data.h"


using namespace std;

int main()
{
	sf::RenderTexture background_texture;
	background_texture.create(1200, 800);
	sf::Sprite background_sprite;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
	camera.reset(sf::FloatRect(0, 0, 1200, 800));
	float time;
	General_Data general_data = General_Data(600., 470.,window);
	
	Map map(background_texture,window,general_data);
	Character Player = Character(1, time, general_data,map);
	sf::Clock gl_clock;
	sf::Clock clock;
	bool pr = false;
	sf::Vector2f Player_pos(600,400);
	state State = standing;
	float runspeed = 0.007;
//	InitMap(background_texture);

	window.display();
	



	while (window.isOpen())

	{
		sf::Event event;
		
		time = clock.getElapsedTime().asMicroseconds();
		
		clock.restart();
		time /= 800;

	

		while (window.pollEvent(event))

		{
			  

			if (event.type == sf::Event::Closed)

			
				window.close();
			
		}

		//DrawMap(background_texture, Player_pos);
		//cout << endl;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{

			if (!Player.jumped)
			{
				cout << "Jump";
				Player.firstpress = gl_clock.getElapsedTime().asMicroseconds();
				Player.jumped = true;
			}
			else if (Player.State != inair)

			{
				if ((gl_clock.getElapsedTime().asMicroseconds() - Player.firstpress > 600000))
				{
					Player.ResetFrame();
					cout << "Long _ Jump";
					Player.Jump(false);
					Player.State = inair;
					Player.jumped = false;
					Player.Status = long_jump;
					Player.firstpress = gl_clock.getElapsedTime().asMicroseconds();

				}


			}

		}
		else if (Player.State != inair)
		{

			if (Player.jumped && ((gl_clock.getElapsedTime().asMicroseconds() - Player.firstpress > 450000)))
			{
				Player.ResetFrame();
				cout << "Long _ Jump";
				Player.Jump(false);
				Player.State = inair;
				Player.Status = long_jump;
				Player.jumped = false;

			}
			if (Player.jumped && (gl_clock.getElapsedTime().asMicroseconds() - Player.firstpress < 350000))
			{
				Player.ResetFrame();
				cout << "Short _ Jump";
				Player.GetDir() ? Player.dx = Player.speed : Player.dx = -Player.speed;
				Player.Jump(true);
				Player.State = inair;
				Player.Status = short_jump;
				Player.jumped = false;

			}

			//			Player.jumped = false;
		}






			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		)
			{
				if (Player.State != inair)
				{
					cout << endl << "DD=" << Player.Status;
					if (Player.Status == balancing) /*cout << endl << Player.GetDir();*/
					{

						if (Player.GetDir() == 0)
						{
							Player.SetDir(false);
							general_data.Increm_Screen_Pos(-40, 0);
							Player.Status = run;
						}
						else
						{
							Player.State = inair;
							Player.Status = falling;
						//	Player.dy = 1.3;
							general_data.Increm_Screen_Pos(-50, 0);
						}
					}
					
					//		if (Player.GetDir())   Player.SetDir(0); else 
					//		if (Player.State == standing)	Player.Status = run;
					if (Player.Previous != run&&Player.Status == run)  Player.Previous = run;
					if (Player.GetDir())  Player.SetDir(0); 
					else if (Player.Status != jump) {
						Player.Status = run;

					}


				}
				else if (Player.State == inair && Player.GetDir() == 1) Player.SetDir(1);
				else Player.Move_in_air();


			}
			else
			{   //отжатие клавищи  - перестаёт бежать когда отпускаешь
				if (Player.Previous == run&Player.Status == waiting)  Player.Previous = waiting;
				if (Player.Status == run &&  Player.GetDir()==0)
					Player.Status = waiting;
				
			}
	
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				)
			{
				if (Player.State != inair)
				{
					cout << "noot in air" << endl;
					if (Player.Status == balancing ) 
						if (Player.GetDir()) 
						{ 
							Player.Status = falling; 
							Player.State = inair;
							general_data.Increm_Screen_Pos(60,0); 
						}
						else
						{
							Player.SetDir(false);
							general_data.Increm_Screen_Pos(40, 0);
							Player.Status = run;
						}
						
					//		if (!Player.GetDir())   Player.SetDir(1); else
					//		if (Player.State==standing)	Player.Status = run;
							//else if (!Player.GetDir())   Player.SetDir(1);
					if (Player.Previous != run&&Player.Status == run) Player.Previous = run;
					if (!Player.GetDir())  Player.SetDir(1); 
					else if (Player.Status != jump)	Player.Status = run;
					
				}
				else if (Player.State == inair && Player.GetDir() != 1) Player.SetDir(0);
				else Player.Move_in_air();
			}
			else
			{ //отжатие клавищи  - перестаёт бежать когда отпускаешь 
				if (Player.Previous == run & Player.Status == waiting)  Player.Previous = waiting; 
				if (Player.Status == run && Player.GetDir()==1)//&& (Player.Status == run
				Player.Status = waiting;
	
			}




			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) )
			{
				
				if (Player.Status != meleeattack) Player.ResetFrame();
				if (Player.Previous != meleeattack)  Player.Status = meleeattack;
			
			}
			else  if (Player.Previous == meleeattack) Player.Previous = waiting;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) )
			{
				
		//		if (Player.Previous != pistolattack && Player.Status != pistolattack) 
			//	{Player.Status = pistolattack; Player.ResetFrame();}
				if (Player.Status != pistolattack) Player.ResetFrame();
				if (Player.Previous != pistolattack)  Player.Status = pistolattack;
			}
			else  if (Player.Previous == pistolattack) { Player.Previous = waiting; };// Player.action = false; }


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
	
			} 

		
			//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && Player.State == standing)

			//{

			//	if (Player.Status == waiting || Player.Status == run)// && (Player.State != inair))
			//	{
			//		if (!Player.jumped)
			//		{
			//			Player.jumped = true;
			//			Player.firstpress = gl_clock.getElapsedTime().asMicroseconds();;
			//		//	cout << "SetClock   " << Player.firstpress << endl;
			//		}
			//	}
			//}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
			{
				Player.ResetFrame();
				Player.Status = test;
			}



			

		/*		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					
					if (!Player.jumped)
					{
						cout << "Jump";
						Player.firstpress = gl_clock.getElapsedTime().asMicroseconds();
						Player.jumped = true;
				
					}
				}
				else  if (Player.jumped)
				{
					cout << "TIME" << gl_clock.getElapsedTime().asMicroseconds() - Player.firstpress;
					Player.Jump(false);
					Player.Status = jump;
					Player.jumped = false;
				}*/
			 


				//{
				//	if (Player.pressed&& (gl_clock.getElapsedTime().asMicroseconds() - Player.firstpress > 45000))
				//	{
				//		cout << "long jump" << gl_clock.getElapsedTime().asMicroseconds() - Player.firstpress << endl;
				//		Player.ResetFrame();
				//		Player.Status = jump;
				//		Player.pressed = false;
				//		Player.Jump(false);
				//	}

				//}
				//else
				//{
				//	if (Player.pressed)
				//	{
				//		if (gl_clock.getElapsedTime().asMicroseconds() - Player.firstpress < 45000)
				//		{
				//			cout << "short jump"<< gl_clock.getElapsedTime().asMicroseconds() - Player.firstpress << endl;
				//			Player.ResetFrame();
				//			Player.Status = jump;
				//			Player.pressed = false;
				//			Player.Jump(true);
				//	
				//		}
				//		else {
				///*			cout << "long jump" << gl_clock.getElapsedTime().asMicroseconds() - Player.firstpress << endl;
				//			Player.ResetFrame();
				//			Player.Status = jump;
				//			Player.pressed = false;
				//			Player.Jump(false);*/
				//			cout << "short jump" << gl_clock.getElapsedTime().asMicroseconds() - Player.firstpress << endl;
				//			Player.ResetFrame();
				//			Player.Status = jump;
				//			Player.pressed = false;
				//			Player.Jump(true);
				//		}
				//	
				//	}
			
				//}
		

	/*		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && Player.State == inair)
			{
				
				if ((Player.Status == inair) &&!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { Player.Jump(true);  };
			}*/

			
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
			{
				if (Player.Status == waiting) 	Player.State = crouch;
			}
			else
				if ((Player.Status == waiting && Player.State != inair)&&!Player.jumped) { Player.State = standing; gl_clock.restart(); }
			
			window.setView(camera);
			window.clear();

	
			if (map.IsMapChanged()) 	map.DrawMap();
		
	

			background_sprite.setTexture(background_texture.getTexture());

			float r = general_data.Get_Screen_Pos().x - int(general_data.Get_Screen_Pos().x) / 60 * 60;
			background_sprite.setPosition(-r,0);
			window.draw(background_sprite);
			//cout << "A=" << Player.action<<"  J="<<Player.jumped;
			Player.UpdateHero();
			
			DrawWindow(Player.herosprite, window);

			//			Player.Metka(window);
		window.display();
	//	std::cin.ignore();
	}

	return 0;

}