#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>
using namespace std;
class General_Data
{

	sf::Vector2f screen_pos,real_pos;
	float delta_x, delta_y = 0.f;
public:
	sf::RenderWindow& window;
	General_Data(float a, float b,sf::RenderWindow & win) :screen_pos(a, b),real_pos(truncf(a),truncf(b)), window(win) {};

	void Set_Screen_Pos(float a,float b) 
	{
		screen_pos.x = a;
		screen_pos.y = b;

	//	cout << endl << " set pos" <<a<<"  "<<b ;
		getchar();
	};
	void Increm_Screen_Pos(float a, float b)
	{
	//	blur(a, b);
	//	cout<<endl << "Increase" << a<< "   " << b;

		real_pos.x += a;
		real_pos.y += b;

		screen_pos.x =truncf(real_pos.x);
		screen_pos.y =truncf(real_pos.y);

//		screen_pos.x += a;
//		screen_pos.y += b;
	}

	void blur(float c, float d)
	{
		c = (c + delta_x)/2;
		delta_x = c;
		screen_pos.x += c;

		d = (d + delta_y)/2;
		delta_y = d;
		screen_pos.y += d;
	}



	sf::Vector2f Get_Screen_Pos() {  return screen_pos; }
};