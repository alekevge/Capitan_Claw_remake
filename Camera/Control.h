#pragma once
#include "AnimationMainHero.h"

class Control
{
	

	Character& Player;
	General_Data& general_data;
	sf::Clock& clock;
	public: 
		Control(Character& Char, General_Data& data,sf::Clock& clock):Player(Char), general_data(data),clock(clock)
	{}
		void control();
	private:
		
		void jump_control();
		void move_logic();
		void melee_logic();
		void climb_control();
		void atack_logic();
};

