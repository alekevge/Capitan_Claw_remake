#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>
#include "Camera.h"
#include "General_Data.h"
#include "Map.h"

const float SizeX = 600, SizeY = 400;

enum state { inair, crouch, standing };
enum status {null,waiting,endaction,run,pistolattack,meleeattack,jump,
	falling,test,balancing,long_jump,short_jump,stop_falling,climb,climb_up,climb_down};
class Character
{
	float  dy, gravity;
	float runspeed = 0.007;
	bool dir;
	
	General_Data& general_data;
	Map& map;
	float& time;
	float CurFrame;
	float sizeMapX;
	float sizeMapY;
	int clim = 0;
	int   MeleeAttackType = -1, last_frame = 0;
	
	void  Idle();
	void  MeleeAttack();
	void  PistolAttack();
	void  Jump(float);
	void  Run();
	void  Balancing();
	void  Falling();
	void  Edge();
	void  Jump();
	void  Climbing();
	void  Climbing_end();
	void  Stop_Falling();

	//const float short_jump_dy = 0.47;
	const float short_jump_dy = 0.53;
	const float long_jump_dy = 0.70;
	bool up_stair;
	int  up_stair_index = -1;

	public:
		bool action = false;
		//sf::Vector2f& pos=general_data.Get_Screen_Pos();
		float dx, x, y ,speed ;
		bool jumped;
		float firstpress;
		status Status,Previous;
		state State,last_state;
		sf::Sprite herosprite;
		sf::Texture herotexture;
		bool redraw = false;

	Character(bool,float &,General_Data &, Map&);
	void Move();
	void ResetFrame();
	void Attach_to_Stair();

public:
	void UpdateHero();
public:
	void  Set_dy(float a) { dy = a; };
	void Jump(bool j);
	void SetDir(bool d)	{dir = d;};
	bool GetDir()	{return dir;};
	void InteractionWithMap();
	void Move_in_air();
//	bool IsUpdate ();
	bool InteractionWithMapX(float delta);
	bool InteractionWithMapY(float deltaY);
	void Interaction_with_Objects();
	bool Can_Climbing();
	void test_();
	float	counter = 0;
	bool isUpdated(status s);
};

void DrawWindow(sf::Sprite herosprite, sf::RenderWindow &window);