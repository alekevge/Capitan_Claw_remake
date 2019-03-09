#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>
#include "Camera.h"
#include "General_Data.h"
#include "Map.h"
//#include "Map.h"
const float SizeX = 600, SizeY = 400;

enum state { inair, crouch, standing };
enum status {null,waiting,endaction,run,pistolattack,meleeattack,jump,
	falling,test,balancing,long_jump,short_jump};
class Character
{
	float  dy, gravity;
	float runspeed = 0.007;
	bool dir;
	
	General_Data& general_data;
	Map& map;
	float& time;
	float CurFrame;
	int   MeleeAttackType = -1, last_frame = 0;
	
	void  Idle();
	void  MeleeAttack();
	void  PistolAttack();
	void  Jump(float);
	void  Run();
	void  Balancing();
	void  Falling();
	void   Edge();

	public:
		bool action = false;
		sf::Vector2f& pos=general_data.Get_Screen_Pos();
		float dx, x, y ,speed ;
		bool jumped;
		float firstpress;
		status Status,Previous;
		state State,last_state;
		sf::Sprite herosprite;
		sf::Texture herotexture;

	Character(bool,float &,General_Data &, Map&);
	void Move();
	void ResetFrame();

public:
	void UpdateHero();
public:
	void Jump(bool j);
	void SetDir(bool d)	{dir = d;};
	bool GetDir()	{return dir;};
	void InteractionWithMap();
	bool IsUpdate ();
	bool InteractionWithMapX(float delta);
	bool InteractionWithMapX_new(float delta);
	bool InteractionWithMapY(float deltaY);
	bool InteractionWithMapY_old(float deltaY);

};

void DrawWindow(sf::Sprite herosprite, sf::RenderWindow &window);