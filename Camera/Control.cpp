#include "Control.h"
using namespace std;


void Control::control()
{
	jump_control();
	move_logic();
	melee_logic();
	climb_control();
	atack_logic();
}


void Control::jump_control()
{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{

				if (!Player.jumped)
				{
					Player.firstpress = clock.getElapsedTime().asMicroseconds();
					Player.jumped = true;
				}
				else if (Player.State != inair)

				{
					if ((clock.getElapsedTime().asMicroseconds() - Player.firstpress > 600000))
					{
						Player.ResetFrame();
						Player.Jump(false);
						Player.State = inair;
						Player.jumped = false;
						Player.Status = long_jump;
						Player.firstpress = clock.getElapsedTime().asMicroseconds();

					}


				}

			}
			else if (Player.State != inair)
			{

				if (Player.jumped && ((clock.getElapsedTime().asMicroseconds() - Player.firstpress > 450000)))
				{
					Player.ResetFrame();
					Player.Jump(false);
					Player.State = inair;
					Player.Status = long_jump;
					Player.jumped = false;

				}
				if (Player.jumped && (clock.getElapsedTime().asMicroseconds() - Player.firstpress < 350000))
				{
					Player.ResetFrame();
					Player.GetDir() ? Player.dx = Player.speed : Player.dx = -Player.speed;
					Player.Jump(true);
					Player.State = inair;
					Player.Status = short_jump;
					Player.jumped = false;

				}

			}
}

void Control::move_logic()
{
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				)
			{
				if (Player.State != inair)
				{
					//	cout << endl << "DD=" << Player.Status;
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

							if (Player.GetDir())   Player.SetDir(0); else 
							if (Player.State == standing)	Player.Status = run;
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
				if (Player.Status == run &&  Player.GetDir() == 0)
					Player.Status = waiting;

			}





	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || 
		 sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						)
					{
						general_data.Increm_Screen_Pos(0.5, 0);
						if (Player.State != inair)
						{
							//	cout << "noot in air" << endl;
							if (Player.Status == balancing)
								if (Player.GetDir())
								{
									Player.Status = falling;
									Player.State = inair;
									general_data.Increm_Screen_Pos(60, 0);
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
						if (Player.Status == run && Player.GetDir() == 1)//&& (Player.Status == run
							Player.Status = waiting;

					}
}


void Control::melee_logic()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
				{

					if (Player.Status != meleeattack) Player.ResetFrame();
					if (Player.Previous != meleeattack)  Player.Status = meleeattack;

				}
				else  if (Player.Previous == meleeattack) Player.Previous = waiting;
	
}

void Control::atack_logic()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{

		//		if (Player.Previous != pistolattack && Player.Status != pistolattack) 
		//	{Player.Status = pistolattack; Player.ResetFrame();}
		if (Player.Status != pistolattack) Player.ResetFrame();
		if (Player.Previous != pistolattack)  Player.Status = pistolattack;
	}
	else  if (Player.Previous == pistolattack) { Player.Previous = waiting; };// Player.action = false; }


}





void Control::climb_control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
	  if (Player.Can_Climbing()) 
	  {
		if (Player.Status != climb_up)
		{
			Player.Status = climb_up;
			Player.dx = 0;
		}
	  }
	}
	else 
		if (Player.Can_Climbing() && Player.Status == climb_up)
		{
			Player.Status = climb;
			Player.dx = 0;
		}




	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
	{

	/*	float b = clock.getElapsedTime().asMicroseconds() - y;
		y = clock.getElapsedTime().asMicroseconds();
		if (b > 5000) {
			general_data.Increm_Screen_Pos(0, 1);

			int z = b / 5000;
			cout << endl << "z= " << z << "   " << b << " " << y;
			if (z > 3) z = 1;
			for (int i = 0; i <= z; i++)
			{
				cout << endl << "z= " << z;
				general_data.Increm_Screen_Pos(0, 1);
			}
		}*/
	//	cout << endl << "climb" << b;
				if (Player.Status == waiting) 	Player.State = crouch;
		if (Player.Can_Climbing()) {
		if (Player.Status != climb_down)
		{
		Player.Status = climb_down;
		Player.dx = 0;

		}
		}
		}
		else
		{
		if ((Player.Status == waiting && Player.State != inair&&
		Player.Status != climb_down&&Player.Status != climb_up&&Player.Status != climb) && !Player.jumped) {
		Player.State = standing; clock.restart();
		}

		if (Player.Can_Climbing() && Player.Status == climb_down)
		{
		Player.Status = climb;
		Player.dx = 0;
		}
	}

}