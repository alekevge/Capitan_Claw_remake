#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>

class General_Data
{

	sf::Vector2f screen_pos;
	
public:
	sf::RenderWindow& window;
	General_Data(float a, float b,sf::RenderWindow & win) :screen_pos(a, b), window(win) {};

	void Set_Screen_Pos(float a,float b) 
	{
		screen_pos.x = a;
		screen_pos.y = b;
	};
	void Increm_Screen_Pos(float a, float b)
	{
		screen_pos.x += a;
		screen_pos.y += b;
	}
	sf::Vector2f Get_Screen_Pos() {  return screen_pos; }
};