
#include "AnimationMainHero.h"
#include "Map.h"
using namespace std;
float max_dx = 3, max_dy = 3;

Character::Character(bool d, float& t, General_Data& data, Map& map_) :time(t), general_data(data), map(map_)

{
	//	pos=sf::Vector2f (600, 470);
	firstpress = 0;
	jumped = false;
	dx = 0.;
	dy = 0.1;
	gravity = 0.00149;
	speed = 0.25;
	dir = d;
	Status = waiting;
	Previous = waiting;
	CurFrame = 0.;
	herotexture.loadFromFile("Images\\Captain Claw3.png");
	herosprite.setTexture(herotexture);//передаём в него объект Texture (текстуры)
	sizeMapX = map.sizeMapX;
	sizeMapY = map.sizeMapY;
	//int clim = 0;
	x = 200.;
	y = 470.;
	herosprite.setPosition(x, y);//з
								 //cout << "pos=" << pos.x << " " << pos.y << endl;
								 //cout <<"SIZEMAP" <<sizeMapX;
}



void DrawWindow(sf::Sprite herosprite, sf::RenderWindow& window)
{

	window.draw(herosprite);


}
void Character::PistolAttack()
{
	switch (State)
	{
	case standing:
	{//cout <<int( CurFrame);
		if (int(CurFrame) != last_frame)//&&Status==Previous )
		{

			int v[7] = { 19, 150, 270, 390, 544, 675, 19 };
			int i[7] = { 120, 120, 120, 140, 140, 140, 140 };
			if (dir)
			{
				herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], 449, i[int(CurFrame)], 130));
				herosprite.setScale(1, 1);
				herosprite.setOrigin(0, 10);
			}
			else
			{
				herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], 449, i[int(CurFrame)], 130));
				herosprite.setScale(-1, 1);
				herosprite.setOrigin(130, 10);
			}
		}
		//	cout <<"last_frame="<< int(CurFrame);
		last_frame = int(CurFrame);
		CurFrame += 0.0055*time;

		//	cout << CurFrame;


		if (CurFrame > 7) { CurFrame -= 7; Previous = Status; Status = waiting; }
	}
	break;
	case crouch:
		if (int(CurFrame) != last_frame)//&&Status==Previous )
		{
			cout << "crouch pistol";
			if (dir)
			{
				//	int aa =775;
				//	int v[7] = { 15,167,310,450,624,775,167 };
				int v[9] = { 15,165,310,448,624,775,165,15,15 };
				//			int v[7] = { aa,aa,aa,aa,aa,aa,aa };
				int i[9] = { 120, 100, 150, 160, 120, 120,120,120,120 };
				//		int aa = 775;
				//		int v[7] = { 15,165,310,448,624,aa,aa };
				int n[9] = { -37,-35, -35,-35,-35,-35,-35,-37,-37 };
				//	cout << int(CurFrame);
				herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], 1060 - 20, i[int(CurFrame)], 120));
				herosprite.setScale(1, 1);
				herosprite.setOrigin(10, 10 + 20 + n[int(CurFrame)]);
				//	herosprite.setOrigin(10, -35);
			}

			else
			{
				int v[9] = { 15,165,310,448,624,775,165,15,15 };

				int i[9] = { 120, 100, 150, 160, 120, 120,120,120,120 };

				int n[9] = { -37,-35, -35,-35,-35,-35,-35,-37,-37 };

				herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], 1060 - 20, i[int(CurFrame)], 120));
				herosprite.setScale(-1, 1);
				herosprite.setOrigin(140, 10 + 20 + n[int(CurFrame)]);
			}
		}
		last_frame = int(CurFrame);
		CurFrame += 0.006*time;
		if (CurFrame > 8) { CurFrame -= 8; Previous = Status; Status = waiting; }

		break;
	}



};

void Character::MeleeAttack()
{
	switch (State)
	{
	case standing:
	{	if (MeleeAttackType == -1)	MeleeAttackType = rand() % 4;
	switch (MeleeAttackType)
	{
	case 0:
	{	CurFrame += 0.009*time;
	int v[8] = { 37,189,347,472,472,189,37,37 };
	int b[8] = { 301,300,300,300,300,300,301,301 };
	int c[8] = { 120,120,120,170,170,120,120,120 };

	herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], b[int(CurFrame)], c[int(CurFrame)], 125));

	if (dir)
	{
		herosprite.setScale(1, 1);
		herosprite.setOrigin(-10, 0);
	}
	else
	{
		herosprite.setScale(-1, 1);
		herosprite.setOrigin(120, 0);
	};
	//		DrawWindow(herosprite, window);

	}
	break;
	case 1:
	{	CurFrame += 0.0065*time;
	int j = 237;
	int v[3] = { 27,237,237 };
	int h = 620;
	int b[3] = { h,h,h };
	int c[3] = { 110,110,110 };

	herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], b[int(CurFrame)], c[int(CurFrame)], 125));

	if (dir)
	{
		herosprite.setScale(1, 1);
		herosprite.setOrigin(-10, 0);
	}
	else
	{
		herosprite.setScale(-1, 1);
		herosprite.setOrigin(120, 0);


	};
	//		DrawWindow(herosprite, window);
	}
	break;
	case 2:
	{	CurFrame += 0.0065*time;
	int j = 350;//135/137
	int v[3] = { 147,350,147 };
	int h = 620;
	int b[3] = { h,h,h };
	int c[3] = { 100,100,100 };

	herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], b[int(CurFrame)], c[int(CurFrame)], 125));

	if (dir)
	{
		herosprite.setScale(1, 1);
		herosprite.setOrigin(-20, 0);
	}
	else
	{
		herosprite.setScale(-1, 1);
		herosprite.setOrigin(110, 0);
	};
	//		DrawWindow(herosprite, window);
	}
	break;
	case 3:
	{	CurFrame += 0.0065*time;
	int j = 785;//458/569/670/
				//		int v[3] = { j,j,j };
	int v[4] = { 458,569,670,785 };
	int h = 620;
	int b[4] = { h,h,h,h };
	int c[4] = { 100,100,120,100 };

	herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], b[int(CurFrame)], c[int(CurFrame)], 125));

	if (dir)
	{
		herosprite.setScale(1, 1);
		herosprite.setOrigin(0, 0);
	}
	else
	{
		herosprite.setScale(-1, 1);
		herosprite.setOrigin(130, 0);
	};
	//		DrawWindow(herosprite, window);
	}
	break;
	}

	int d[4] = { 7,2,2,3 };
	if (CurFrame > d[MeleeAttackType]) { CurFrame -= d[MeleeAttackType];  Previous = Status; Status = waiting; MeleeAttackType = -1; }
	}
	break;
	case crouch:

	{	int v[6] = { 177,329,475,598,475,475 };
	int c[6] = { 100,100,130,155,130,130 };
	int a[6] = { 908,910,910,910,910,910 };

	herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], a[int(CurFrame)], c[int(CurFrame)], 120));

	if (!dir)
	{
		herosprite.setScale(-1, 1);
		herosprite.setOrigin(130, 0);
	}
	else
	{
		herosprite.setScale(1, 1);
		herosprite.setOrigin(0, 0);
	}
	CurFrame += 0.007*time;
	if (CurFrame > 5) { CurFrame -= 5; Previous = Status; Status = waiting; };
	//	DrawWindow(herosprite, window);
	}
	break;
	}
};
void Character::ResetFrame()
{
	CurFrame = 0;
}
void Character::Jump(bool j)
{
	if (j) dy = -short_jump_dy; //short
	else dy = -long_jump_dy;	  //long
}



void  Character::Idle()
{
	switch (State)
	{

	case standing:

	{
		if (last_frame != int(CurFrame))//&&Previous==Status)
		{
			int v[8] = { 0, 112 ,216,330,451,554,661,771 };
			int y[8] = { 155,154,154 ,154,154,153,153,153 };
			if (dir)
			{
				herosprite.setScale(1, 1);
				herosprite.setOrigin(0, 0);
			}
			else
			{
				herosprite.setScale(-1, 1);
				herosprite.setOrigin(130, 0);
			}
			herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)] + 10, y[int(CurFrame)], 100, 120));

			last_frame = int(CurFrame);
		}

		CurFrame += 0.004*time;
		if (CurFrame > 8)  CurFrame -= 8;
	}

	break;

	case crouch:
		herosprite.setTextureRect(sf::IntRect(177, 908, 100, 125));
		if (dir)
		{
			herosprite.setScale(1, 1);
			herosprite.setOrigin(0, 0);
		}
		else
		{
			herosprite.setScale(-1, 1);
			herosprite.setOrigin(130, 0);
		}
		break;
	}
	//int aa = 510;
	//int bb = 1590;

	//herosprite.setTextureRect(sf::IntRect(aa, bb, 110, 110));
	//int h = -25;
	//int cc = -5;

	//if (dir)
	//{
	//	herosprite.setScale(1, 1);
	//	herosprite.setOrigin(cc-10, h);
	//}
	//else
	//{
	//	herosprite.setScale(-1, 1);
	//	herosprite.setOrigin(cc+120, h);
	//}
	//CurFrame += 0.004*time;

	//if (CurFrame > 3)  CurFrame -= 3;
};
void Character::Falling()
{
	int v[5] = { 0,103,190,283,373 };

	int c[5] = { 0,-10,-10,-10,-10 };
	//	int h[15] = { 0,-8,-8,-8,-8,-8,-8,-8 ,-8,-8,-8,-8,-8,-8,0 };
	int y = 1701;

	herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], y, int(CurFrame) == 0 ? 105 : 92, 105));

	if (dir)
	{
		herosprite.setScale(1, 1);
		herosprite.setOrigin(c[int(CurFrame)], -15);
	}
	else
	{
		herosprite.setScale(-1, 1);
		herosprite.setOrigin(c[int(CurFrame)] + 130, -15);
	}

	//	CurFrame += 0.002*time;
	//CurFrame += 0.0045*time;
	CurFrame += 0.003*time;
	if (CurFrame > 5) CurFrame -= 4;
};

void Character::Run()
{

	CurFrame += runspeed*time;
	if (CurFrame > 10) CurFrame -= 10;
	if (last_frame != int(CurFrame))
	{
		herosprite.setTextureRect(sf::IntRect(13 + 110 * int(CurFrame), 15, 100, 120));
		if (dir)
		{
			herosprite.setScale(1, 1);
			herosprite.setOrigin(0, 0);

		}
		else
		{
			herosprite.setScale(-1, 1);
			herosprite.setOrigin(130, 0);
			//	herosprite.move(-0.1*time, 0);

		}
		last_frame = int(CurFrame);
	}



}

void Character::InteractionWithMap()
{

	float deltaX = abs(dx*time) > max_dx ? max_dx*dx / abs(dx) : dx*time;
	float deltaY = dy*time > max_dy ? max_dy : dy*time;

	//	x = pos.x + deltaX;//- window.getSize().x/2 + herosprite.getTextureRect().width/2
	//	y = pos.y;//- window.getSize().y/2
	//if (pos.x+deltaX > 600 && herosprite.getPosition().x >= 200)
	if (general_data.Get_Screen_Pos().x + deltaX > 600 && herosprite.getPosition().x >= 200)
	{

		//	x = pos.x+herosprite.getPosition().x-SizeX+dx*time;

		//	x += dx*time;
		//	x += dx*time
		//dir ? x+100 : x+25
		//		if (InteractionWithMapX(window, sf::Vector2f(x, y), herosprite.getPosition(), herosprite.getTextureRect().width, herosprite.getTextureRect().height, deltaX))
		if (InteractionWithMapX(deltaX) && abs(deltaX)>0.001)
		{
			general_data.Increm_Screen_Pos(deltaX, 0);
			//		pos.x += deltaX;

		}
		else {} //cout << "Block";
	}
	else Move();

	//dir ? x +10+herosprite.getTextureRect().width/2 : x - 10 - herosprite.getTextureRect().width / 2
	//if (InteractionWithMapYII(window, sf::Vector2f(pos.x + herosprite.getPosition().x - window.getSize().x / 2, y+deltaY + herosprite.getPosition().y - window.getSize().y/2),herosprite.getPosition(), herosprite.getTextureRect().height, dir,time))
	if (InteractionWithMapY(deltaY) && Status != test&&Status != climb&&
		Status != climb_up&&Status != climb_down)
	{

		general_data.Increm_Screen_Pos(0, deltaY);
		if (Status != short_jump &&Status != test&& Status != long_jump&&Status != jump && Status != stop_falling &&  Previous != short_jump&& Previous != long_jump) { cout << "Falling 2   " << Status; Status = falling; }
		//	cout << "  herosprite" << herosprite.getPosition().x << " " << herosprite.getPosition().x << "  POS=" << pos.x << " " << pos.y;
		/*if (State==inair)*/	dy += gravity*time;
		//cout << "Dy=" << dy << endl;

		if (State == standing)
		{
			State = inair;
			//	cout << "QQQ";
			//		if (/*Status != short_jump && Status != long_jump&&Status!=jump && Status!=stop_falling &&*/ dy>0.12/*&& Previous!=short_jump&& Previous!=long_jump*/) { cout << "Falling 2   " << Status; Status = falling;  }

		}
		State = inair;
	}
	else
	{
		if (State == inair) { Stop_Falling();/* cout << "     Falling END  " << Status; *//*State = standing;	dy = 0.1; Status = waiting; */ }

		State = standing;
		if (abs(deltaX) < 0.01 &&Status != climb&&Status != jump&&Status != long_jump&&Status != short_jump&& Status != run&& Status != balancing)
			Edge();

		//cout << "stop";
	}
	//cout << "y =" << pos.y << endl;

	//  CameraGoForHero(x, y);
}

void Character::Stop_Falling()
{
	//	cout << "Stop_falling";
	Status = stop_falling;
	int i = 10;
	while (i != 0)
	{
		while (InteractionWithMapY(i*0.1))
		{
			//		pos.y += i*0.1;
			general_data.Increm_Screen_Pos(0, i*0.1);
		}
		i--;
	}
	State = standing;	dy = 0.1;
	if (abs(dx) < 0.1) Status = waiting; else Status = run;
}

void Character::Balancing()
{

	int v[8] = { 0,137,263,395,512,628,760,875 };
	//	int v[15] = { 0,137,263,395,512,628,760,875 ,760,628,512,395,263,137,0};
	//int v[14] = { 0,137,263,395,512,628,760,875 ,263,395,512,628,760,875 };
	//	int y[3] = { 1590,1590,1590,1590,1590 };
	//int c[3] = { -5,-5,-5,-5,-5 };*/
	int c[8] = { 0,-8,-8,-8,-8,-8,-8,-8 };
	//int c[14] = { 0,-8,-8,-8,-8,-10,-11,-11 ,-8,-8,-8,-10,-11,-11}; 
	//int c[14] = { -0,-11,-11,-11,-11,-11,-11,-11 ,-11,-11,-11,-11,-11,-11 };
	//	int h[15] = { 0,-8,-8,-8,-8,-8,-8,-8 ,-8,-8,-8,-8,-8,-8,0 };
	int y = 1240;

	herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], y, int(CurFrame) == 3 || int(CurFrame) == 6 || int(CurFrame) == 9 || int(CurFrame) == 12 ? 125 : 135, 100));
	//	herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], y,  125 , 100));
	int j[8] = { -3,0,0,2, 1,5,6,8 };
	if (dir)
	{
		herosprite.setScale(1, 1);
		herosprite.setOrigin(c[int(CurFrame)] + j[int(CurFrame)], -20);//-30
	}
	else
	{
		herosprite.setScale(-1, 1);
		herosprite.setOrigin(c[int(CurFrame)] + 130 + j[int(CurFrame)], -20);//-30
	}

	//	CurFrame += 0.002*time;
	CurFrame += 0.0035*time;
	if (int(CurFrame) > 7) CurFrame -= 8;

}



void  Character::Jump(float df)
{
	//int v[8] = { 0, 112 ,216,330,451,554,661,771 };
	//int y[8] = { 155,154,154 ,154,154,153,153,153 };
	int aa = 610;
	int bb = 1590;
	int cc = -5;


	int v[7] = { 0,110,205,305,410,513,610 };
	//	int y[3] = { 1590,1590,1590,1590,1590 };
	//int c[3] = { -5,-5,-5,-5,-5 };*/
	int h[7] = { -25,-15,-15,-25,-25,-25,-25 };

	int y = 1590;

	herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], y, 100, 110));

	//	int h = -25;

	if (dir)
	{
		//	cout << "Right_JUMP";
		herosprite.setScale(1, 1);
		herosprite.setOrigin(cc - 0 + 20, h[int(CurFrame)] + 5 + 0 * 35);
	}
	else
	{
		herosprite.setScale(-1, 1);
		herosprite.setOrigin(cc + 120, h[int(CurFrame)] + 5 + 0 * 35);
	}
	//CurFrame += 0.0006*time;
	CurFrame += df*time;
	if (CurFrame > 7) { Status = falling; Falling(); }
	//{ CurFrame -= 7; Status = waiting; State = standing; }

}
void Character::Jump()
{
	int aa = 610;
	int bb = 1590;
	int cc = -5;


	int v[7] = { 0,110,205,305,410,513,610 };
	//	int y[3] = { 1590,1590,1590,1590,1590 };
	//int c[3] = { -5,-5,-5,-5,-5 };*/
	int h[7] = { -25,-15,-15,-25,-25,-25,-25 };

	int y = 1590;
	float jump_height;
	if (Status == short_jump) jump_height = short_jump_dy;
	else jump_height = long_jump_dy;
	herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], y, 100, 110));
	//	int h = -25;

	if (dir)
	{
		herosprite.setScale(1, 1);
		herosprite.setOrigin(cc - 0, h[int(CurFrame)] + 5 + 0 * 35);
	}
	else
	{
		herosprite.setScale(-1, 1);
		herosprite.setOrigin(cc + 120 + 20, h[int(CurFrame)] + 5 + 0 * 35);
	}
	//CurFrame += 0.0006*time;
	//CurFrame += df*time;
	CurFrame = (jump_height + dy) / (2 * jump_height / 7 + 0.03);
	//if (dy < 0.05 && dy>-0,05) CurFrame = 3;
	// cout << endl << "Dy=" << dy << "  " << jump_height << "  " << CurFrame;
	if (CurFrame > 7) { Status = falling; Falling(); /*cout << "Falling"*/; }
	//{ CurFrame -= 7; Status = waiting; State = standing; }

}

void Character::UpdateHero()
{
	redraw = false;
	Interaction_with_Objects();
	InteractionWithMap();
	switch (Status)
	{
	case run: {	if (dir)
	{

		dx = speed;
	}
			  else
			  {

				  //	herosprite.move(-0.1*time, 0);
				  dx = -speed;
			  }
			  Run();
	}
			  break;
	case waiting: {dx = 0;  Idle();  Previous = waiting; }
				  break;
	case pistolattack: {dx = 0; PistolAttack(); }
					   break;
	case meleeattack: {dx = 0; MeleeAttack(); }
					  break;
	case jump: {Jump(0.0006f);/*cout << "comand"; */// Jump(time); 
													//	 if (State!=inair) {  Jump(); State = inair;  }

													//	 cout << "jump!";
													// if ((State== inair)&&(Previous!=jump)) { Previous=jump; }
		Previous = jump; }
			   break;
	case long_jump:Jump();//Jump(0.008f);
		break;
	case short_jump:Jump();//Short_Jump(); //Jump(0.010f);
		break;
		//case balancing: {Balancing();  Previous = balancing;
		// cout << "balancing"; };
		//			 break;
	case falling: {Falling(); }
				  break;
	case balancing: {dx = 0; Balancing(); }
					break;
	case climb:
	case climb_down:
	case climb_up: {
		if (Previous != climb && Previous != climb_up && Previous != climb_down)
		{
			ResetFrame();
			Attach_to_Stair();
		}
		Climbing();
		//dx = 0; dy = 0; 
		//	 if (int(CurFrame) == 0) general_data.Increm_Screen_Pos(0, -50);
		//	 if (abs(dy) > 0.01 || Previous != climb) { Previous = climb; ResetFrame(); }; Climbing();  }
	}
				   break;

				   //case climb_up:Climbing();
				   // break;

				   //case climb_down: Climbing();
				   // break;
	case test: {dx = 0;
		//	 if (CurFrame < 0.00000000001)
		//	 test_();
		dy = 0; //Climbing(); //Climbing_end();// Climbing();
		cout << "Test"; }
			   break;

	default:cout << "default";
		break;

		// cout << ;
	}

	//	cout << "  Previous=" << Previous << " Jumped=" << jumped;
	if (Previous == jump&& Status != Previous) jumped = false;
	//Player_pos.x += dx*time;


	//	cout << "spritepos=" << herosprite.getPosition().x << endl;
	//pos.x += dx*time;
	//pos.y += dy*time;
	//y += dy;
	//dy += gravity;

	//	herosprite.setPosition(x, y);
}
//bool Character::IsUpdate()
//{
//	return (int(counter) != int(last_frame));
//}
void Character::Move()
{
	sf::Vector2f s = herosprite.getPosition();
	if (s.x + dx*time>60) s.x += dx*time;
	herosprite.setPosition(s);
};

bool Character::InteractionWithMapX(float delta)
{

	//	InteractionWithMapX(   deltaX))
	sf::Vector2f V = general_data.Get_Screen_Pos();
	//sf::Vector2f V = sf::Vector2f(general_data.Get_Screen_Pos().x /*+herosprite.getOrigin().x*/ + herosprite.getPosition().x - general_data.window.getSize().x / 2,
	//	general_data.Get_Screen_Pos().y /*- herosprite.getOrigin().y*/	/*y*/  + herosprite.getPosition().y - general_data.window.getSize().y / 2);

	//InteractionWithMapX(  float delta)
	float width = herosprite.getTextureRect().width;
	float height = 120;// herosprite.getTextureRect().height;
	sf::Vector2f S = herosprite.getPosition();
	//	S	
	//y + deltaY + herosprite.getPosition().y - general_data.window.getSize().y / 2);
	int i_l = int((V.x + S.x - general_data.window.getSize().x / 2) / sizeMapX);
	int	i = int((V.x + S.x /*- herosprite.getOrigin().x*/ + delta - general_data.window.getSize().x / 2) / sizeMapX);
	int	i_r = int((V.x + S.x /*- herosprite.getOrigin().x*/ + width + delta - general_data.window.getSize().x / 2) / sizeMapX);
	int	j = int((V.y + S.y - general_data.window.getSize().y / 2) / sizeMapY);
	int j_1 = int((V.y + S.y + height / 2 - general_data.window.getSize().y / 2) / sizeMapY);
	int j_2 = int((V.y + S.y + height - general_data.window.getSize().y / 2) / sizeMapY);



	//int i_l = int((V.x/* + S.x - general_data.window.getSize().x / 2*/) / sizeMapX);
	//int	i = int((V.x /*+ S.x*/ /*- herosprite.getOrigin().x*/ + delta /*- general_data.window.getSize().x / 2*/) / sizeMapX);
	//int	i_r = int((V.x/* + S.x*/ /*- herosprite.getOrigin().x*/ + width + delta /*- general_data.window.getSize().x / 2)*/) / sizeMapX);
	//int	j = int((V.y /*+ S.y - general_data.window.getSize().y / 2*/) / sizeMapY);
	//int j_1 = int((V.y/* + S.y */+ height / 2 /*- general_data.window.getSize().y / 2*/) / sizeMapY);
	//int j_2 = int((V.y /*+ S.y*/ + height /*- general_data.window.getSize().y / 2*/) / sizeMapY);

	if (map.TileMap[j][i] == '0' || map.TileMap[j_1][i] == '0'/* || map.TileMap[j_2][i] == '0'*/)//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
	{
		//	cout << "BLOCK 0";
		//	map_s.setTextureRect(sf::IntRect(190, 450, 60, 60));
		//	map_s.setPosition(i * 60, j * 60);
		//	DrawWindow(map_s, window);
		//		cout << " FFF=" << map.TileMap[j_2][i] << "" << " " << j_1 << i << " " << j_2 << i;
		return false;
	}
	// нет взаимодействия с блоком 3, блок 0 не пол а стена
	if (map.left_wall.find(map.TileMap[j][i_l]) != map.left_wall.end() ||
		map.left_wall.find(map.TileMap[j_1][i_l]) != map.left_wall.end() ||
		map.left_wall.find(map.TileMap[j_2][i_l]) != map.left_wall.end())
	{
		/*	cout << "if" << map.TileMap[j_2][i_l] << "      " << (V.y + S.y + height - general_data.window.getSize().y / 2) << ">>" <<( (j_2+1)* 60 + 30);*/
		//	cout << "BLOCK WALL1" << map.TileMap[j_2][i];
		//	if (((V.x ))<( (i_l ) * 60+120)) {
		//		map_s.setTextureRect(sf::IntRect(190, 450, 60, 60));
		//		map_s.setPosition(i * 60, j * 60);
		//		DrawWindow(map_s, window);

		if (delta <= 0)
		{
			//	cout << "delta"<< map.TileMap[j_2][i_l]<< map.TileMap[j_1][i_l]<< map.TileMap[j][i_l];
			if (map.TileMap[j_2][i_l] == '2' || map.TileMap[j_1][i_l] == '2' || map.TileMap[j][i_l] == '2')
			{
				if ((V.y + S.y + height - general_data.window.getSize().y / 2) > ((j_2 + 1) * 60 + 30))
				{
					return false;
				}
				else
				{
					if ((V.x + S.x/*+ width / 2*/ - general_data.window.getSize().x / 2) < ((i)* 60 + 10))
						return false;


				}
			}

			if (map.TileMap[j_2][i_l] == '1' || map.TileMap[j_1][i_l] == '1' || map.TileMap[j][i_l] == '1')
			{
				//	cout << "dddd" << (V.x + S.x /*+ width / 2*/ - general_data.window.getSize().x / 2) << '<' << ((i)* 60 + 10);
				if ((V.x + S.x/*+ width / 2*/ - general_data.window.getSize().x / 2) < ((i)* 60 + 10))
					return false;
			}

			if (map.TileMap[j_2][i_l] == '5' || map.TileMap[j_1][i_l] == '5' || map.TileMap[j][i_l] == '5')
			{
				int edge = map.TileMap[j_2][i_l] == '5' ? j_2 : map.TileMap[j_1][i_l] == '5' ? j_1 : j;
				if ((V.y + S.y + height - general_data.window.getSize().y / 2) > ((edge + 1) * 60 + 30))
				{
					if ((V.x + S.x/*+ width / 2*/ - general_data.window.getSize().x / 2) < ((i)* 60 + 10))

						return false;
				}

			}
		}
		else {}//cout << "else" << delta;

	}


	if (map.right_wall.find(map.TileMap[j][i_r]) != map.right_wall.end() ||
		map.right_wall.find(map.TileMap[j_1][i_r]) != map.right_wall.end() ||
		map.right_wall.find(map.TileMap[j_2][i_r]) != map.right_wall.end())
	{
		if (delta >= 0)
		{
			//	cout << "delta" << map.TileMap[j_2][i_r] << map.TileMap[j_1][i_r] << map.TileMap[j][i_r];
			if (map.TileMap[j_2][i_r] == '8' || map.TileMap[j_1][i_r] == '8' || map.TileMap[j][i_r] == '8')
			{
				if ((V.y + S.y + height - general_data.window.getSize().y / 2) > ((j_2 + 1) * 60 + 30))
				{
					//	cout << "else11";
					return false;
				}
				else
				{
					//		cout <<"   "<<i<< "else22   " << (V.x + S.x + width / 2 - general_data.window.getSize().x / 2) << "  >   " << ((i_r)* 60 - 30);
					if ((V.x + S.x + width / 2 - general_data.window.getSize().x / 2) > ((i_r)* 60 - 30))
						return false;


				}
			}

			if (map.TileMap[j_2][i_r] == '7' || map.TileMap[j_1][i_r] == '7' || map.TileMap[j][i_r] == '7')
			{
				//	cout << "dddd" << (V.x + S.x + width / 2 - general_data.window.getSize().x / 2) << '<' << ((i_r)* 60 -30);
				if ((V.x + S.x + width / 2 - general_data.window.getSize().x / 2) > ((i_r)* 60 - 30))
					return false;
			}

			if (map.TileMap[j_2][i_r] == '8' || map.TileMap[j_1][i_r] == '8' || map.TileMap[j][i_r] == '8')
			{
				int edge = map.TileMap[j_2][i_r] == '8' ? j_2 : map.TileMap[j_1][i_r] == '8' ? j_1 : j;
				if ((V.y + S.y + height - general_data.window.getSize().y / 2) > ((edge + 1) * 60 - 30))
				{
					if ((V.x + S.x + width / 2 - general_data.window.getSize().x / 2) > ((i_r)* 60 - 30))

						return false;
				}

			}
		}
		//	else cout << "else" << delta;

	}

	return true;
}


bool Character::InteractionWithMapY(float deltaY)
{

	sf::Vector2f V = sf::Vector2f(general_data.Get_Screen_Pos().x /*+herosprite.getOrigin().x*/ + herosprite.getPosition().x - general_data.window.getSize().x / 2,
		general_data.Get_Screen_Pos().y /*- herosprite.getOrigin().y*/	/*y*/ + deltaY + herosprite.getPosition().y - general_data.window.getSize().y / 2 + 10);

	float height = 120;// herosprite.getTextureRect().height;
	int	j = int((V.y) / sizeMapY);
	int j_next = int((V.y + height) / sizeMapY);
	int	i_1 = int((V.x + (dir ? 33 : 45)) / sizeMapX);
	int	i_2 = int((V.x + (dir ? 33 : 45) + 45) / sizeMapX);
	int j_current = int((V.y + height / 2) / sizeMapY);
	//	cout<<"map" << map.TileMap[j_next][i_1] << "  " << map.TileMap[j_next][i_1] << endl;
	//	cout << "  jcur "<< (dir ? 33 : 45);
	//	cout <<"ЕШДУ  X"<< map.TileMap[j_next][i_1] <<"Y" <<map.TileMap[j_next][i_2]<< map.TileMap[j_next][i_1] << "    " << map.TileMap[j_next][i_2];

	//	cout << " jnext=" << j_next << "." << ((map.TileMap[j_next][i_1] == ' ') ? ' ' : (map.TileMap[j_next][i_1] - 48)) << "." <<
	//		((map.TileMap[j_next][i_2] == ' ') ? ' ' : (map.TileMap[j_next][i_2] - 48)) << "." << " jcur=" << j_current << endl;
	//	cout << "X=" << V.x << "  V.X" << (i_1)*sizeMapX << " s=" << map.TileMap[j_next][i_1] << "  " << map.TileMap[j_next][i_2]<< endl;
	if (map.TileMap[j_next][i_1] == map.TileMap[j_next][i_2])
	{

		if (map.TileMap[j_next][i_1] == ' ')	return true;
		//	(TileMap[j_current][i_1] == ' ' && TileMap[j_current][i_2] == ' ')&&(V.y>(j+1)*sizeMapY))

		if ((map.TileMap[j_next][i_1] == '5') && (V.x > ((i_1)*sizeMapX + 30))) return true;

	}

	if
		(((map.TileMap[j_next][i_1] == '5' || map.TileMap[j_next][i_1] == '1') && map.TileMap[j_next][i_2] == ' ') ||
			(map.TileMap[j_next][i_1] == ' ' && (map.TileMap[j_next][i_2] == '5' || map.TileMap[j_next][i_2] == '1'))
			)

	{

		if (V.x > ((i_1)*sizeMapX + 30)) return true;

	}

	if ((map.TileMap[j_next][i_1] == '3' || map.TileMap[j_next][i_1] == '4') &&
		(map.TileMap[j_next][i_2] == '3' || map.TileMap[j_next][i_2] == '4')
		&&
		(map.TileMap[j_current][i_1] == ' ' && map.TileMap[j_current][i_2] == ' '))
	{
		return true;
	}

	if ((map.TileMap[j_next][i_1] == '3' && map.TileMap[j_next][i_2] == ' '))
	{
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}
	//if (map.TileMap[j_next][i_1]=='2'&&map.TileMap[j_next][i_2]==' ')
	//	if ()
	/*if (map.TileMap[j_current][i_1] == '3' && map.TileMap[j_current][i_2] == '3')
	{
	if (V.y+90<((j_current)*60+30)) return true;
	}*/
	if ((map.TileMap[j_next][i_1] == '4' && map.TileMap[j_next][i_2] == '5'))
	{
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}

	if ((map.TileMap[j_next][i_1] == '3' && map.TileMap[j_next][i_2] == '4')
		|| (map.TileMap[j_next][i_1] == '4' && map.TileMap[j_next][i_2] == '3'))
	{
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}

	if ((map.TileMap[j_next][i_1] == '2' && map.TileMap[j_next][i_2] == '4'))
	{
		//if (V.y  < ((j_next)* 60 + 30)) return true;
		if ((V.x >((i_1)*sizeMapX)) && (V.y  < ((j_next)* 60 + 30))) return true;
	}


	if ((map.TileMap[j_next][i_1] == '5' && map.TileMap[j_next][i_2] == '5'))
	{
		//	cout << "DELTE" << (V.x - i_1 * 60);
		if (V.y < ((j_next)* 60 + 30)) return true;
		if (V.x >((i_1)*sizeMapX + 30)) 	return true;
	}
	if ((map.TileMap[j_next][i_1] == '5' && map.TileMap[j_next][i_2] == ' '))
	{
		if (V.x >((i_1)*sizeMapX + 30)) 	return true;
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}


	if ((map.TileMap[j_next][i_1] == '1' && map.TileMap[j_next][i_2] == ' '))
	{
		//		cout << "DELTE" << (V.x - i_1 * 60);
		if (V.x >((i_1)*sizeMapX)) 	return true;
		//	if (V.x >((i_1)*sizeMapX - 5)) 	return true;
	}
	if ((map.TileMap[j_next][i_1] == '2' && map.TileMap[j_next][i_2] == '3'))
	{
		//		cout << "DELTE" << (V.x - i_1 * 60) << " V.Y=" << (V.y + height);
		if ((V.x > ((i_1)*sizeMapX)) && (V.y  < ((j_next)* 60 + 30)))	return true;
		///	if ((V.x > ((i_1)*sizeMapX) - 10) && (V.y  < ((j_next)* 60 + 30)))	return true;
	}
	int r = -20;

	if ((map.TileMap[j_next][i_1] == '3' && map.TileMap[j_next][i_2] == '8'))
	{
		//		cout << "rano2";
		//		cout << "DELTE" << (V.x - i_1 * 60) << " V.Y=" << (V.y + height);
		if ((V.x < ((i_2)*sizeMapX - 30 + r)))

			if (V.y < ((j_next)* 60 + 30)) return true;
		//if ((V.x < ((i_2)*sizeMapX) + 10) && (V.y  < ((j_next)* 60 + 30)))	
	}
	if ((map.TileMap[j_next][i_1] == ' ' && map.TileMap[j_next][i_2] == '8')
		)
	{
		//	cout << "rano1";
		if (V.x <((i_2)*sizeMapX + 30 + r)) 	return true;
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}
	if ((map.TileMap[j_next][i_1] == ' ' && map.TileMap[j_next][i_2] == '6')
		)
	{
		if (V.x <((i_2)*sizeMapX + 30 + r)) 	return true;
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}
	if ((map.TileMap[j_next][i_1] == '6' && i_1 == i_2)
		)
	{
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
		if (V.x <((i_2)*sizeMapX + 30 + r)) 	return true;
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}

	if ((map.TileMap[j_next][i_1] == '6' && map.TileMap[j_next][i_2] == '6'&&i_1 != i_2)
		)
	{
		if (V.x >((i_1)*sizeMapX + 30 + r) && (V.x <((i_2)*sizeMapX + 30 + r))) 	return true;
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}


	if ((map.TileMap[j_next][i_1] == '6' && map.TileMap[j_next][i_2] == '3')
		)
	{
		if (V.x <((i_1)*sizeMapX + 30)) 	return true;
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}


	//if ((map.TileMap[j_next][i_2] == '7' && map.TileMap[j_next][i_1] == ' '))
	//{
	//	if (V.x <((i_2)*sizeMapX+0+1*30+1*r )) 	return true;
	//	//	if (V.x <((i_2)*sizeMapX + 10)) 	return true;
	//}
	////6 8  /////
	if ((map.TileMap[j_next][i_1] == '6' && map.TileMap[j_next][i_2] == '8'))
	{
		//	cout << "rano";

		if (V.x <((i_2)*sizeMapX + 30 + r)) 	return true;
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}



	//cout << " JNEX=" << (j_next * 60) << "V.Y=" << V.y<<endl;
	//	cout << "FALSE";
	return false;
}





void Character::Move_in_air()
{
	//	cout << "MOVE IN AIR";
}


void Character::Edge()
{
	sf::Vector2f V = sf::Vector2f(general_data.Get_Screen_Pos().x + herosprite.getPosition().x - general_data.window.getSize().x / 2,
		general_data.Get_Screen_Pos().y + herosprite.getPosition().y - general_data.window.getSize().y / 2);

	int result = 0;

	float height = 120;// herosprite.getTextureRect().height;
	int	j = int((V.y) / sizeMapY);
	int j_next = int((V.y + height) / sizeMapY);
	int	i_1 = int((V.x + (dir ? 33 : 45)) / sizeMapX);
	int	i_2 = int((V.x + (dir ? 33 : 45) + 45) / sizeMapX);
	int j_current = int((V.y + height / 2) / sizeMapY);


	//cout << "DDD=" << (V.x + (dir ? 33 : 45) + 45) << "  "
	//	<< map.TileMap[j_next][i_1] << " " << map.TileMap[j_next][i_2] <<" ";
	//	cout << "   VV= " << i_1 << "  " << i_2;

	if ((map.TileMap[j_next][i_1] == '5' && map.TileMap[j_next][i_2] == '5'))
	{
		if ((V.x + (dir ? 33 : 45) + 45) > ((i_2)* sizeMapX + 15))
		{
			result = 1;// general_data.Set_Screen_Pos(i_2*sizeMapX-herosprite.getPosition().x+general_data.window.getSize().x/2, general_data.Get_Screen_Pos().y);
					   //	cout << "5 5";
		}
	}

	if ((map.TileMap[j_next][i_1] == '5' && map.TileMap[j_next][i_2] == ' '))
	{
		if ((V.x + (dir ? 33 : 45) + 45) >((i_1)*sizeMapX + 15))
		{
			result = 1;// general_data.Set_Screen_Pos(i_1*sizeMapX - herosprite.getPosition().x + general_data.window.getSize().x / 2, general_data.Get_Screen_Pos().y);
					   //		cout << "5 _ ";
		}
	}

	if ((map.TileMap[j_next][i_1] == '4' && map.TileMap[j_next][i_2] == '5'))
	{
		if ((V.x + (dir ? 33 : 45) + 45) > ((i_2)*sizeMapX + 15))
		{
			result = 1;// general_data.Set_Screen_Pos(i_2*sizeMapX - herosprite.getPosition().x + general_data.window.getSize().x / 2, general_data.Get_Screen_Pos().y);


		}
	}

	//if ((map.TileMap[j_next][i_1] == '4'|| map.TileMap[j_next][i_1] == '5')&&
	//	(map.TileMap[j_next][i_2] == '5' || map.TileMap[j_next][i_2] == ' '))
	//	if ((V.x + (dir ? 33 : 45) + 45) > ((i_2)*sizeMapX + 15))
	//	{
	//		result = 1;// general_data.Set_Screen_Pos(i_2*sizeMapX - herosprite.getPosition().x + general_data.window.getSize().x / 2, general_data.Get_Screen_Pos().y);


	//	}


	/////////////////////////////right 

	//cout <<" s=" <<map.TileMap[j_next][i_1] <<"  "<< map.TileMap[j_next][i_2]<<" "<< (V.x + (dir ? 33 : 45) )<<" "<< (i_1)* sizeMapX +15 <<endl;
	if ((map.TileMap[j_next][i_1] == '6' && map.TileMap[j_next][i_2] == '6'))
	{
		if ((V.x + (dir ? 33 : 45)) < ((i_2)* sizeMapX + 15))
		{
			result = 2;// general_data.Set_Screen_Pos(i_2*sizeMapX-herosprite.getPosition().x+general_data.window.getSize().x/2, general_data.Get_Screen_Pos().y);
					   //	cout << "5 5";
		}
	}

	if ((map.TileMap[j_next][i_1] == ' ' && map.TileMap[j_next][i_2] == '6'))
	{
		if ((V.x + (dir ? 33 : 45)) < ((i_2)* sizeMapX + 15))
		{
			result = 2;// general_data.Set_Screen_Pos(i_2*sizeMapX-herosprite.getPosition().x+general_data.window.getSize().x/2, general_data.Get_Screen_Pos().y);
					   //	cout << "5 5";
		}
	}






	if (result > 0)// Status = balancing;
	{
		int x, y;

		switch (result)
		{

		case 1:
			x = (i_2)* 60;
			y = 30;
			general_data.Increm_Screen_Pos(x - V.x - y, 0);
			SetDir(1); Status = balancing; /*cout << "balance";*/
			break;

		case 2:
			x = (i_2 - 1) * 60;
			y = -10;
			general_data.Increm_Screen_Pos(x - V.x - y, 0);
			SetDir(false); Status = balancing;/* getchar(); *//*cout << "balance";*/
			break;

		default:
			break;
		}
	}
}
void Character::test_()
{


	counter += 0.006*time;
	int x = (int)counter;
	if (x >= 6)
	{
		//	cout << endl << "Do " << general_data.Get_Screen_Pos().y;
		general_data.Increm_Screen_Pos(0, -65);
		//	cout << "  Posle" << general_data.Get_Screen_Pos().y;
		counter -= 6;
		x = 0;
		//	Climbing();
	}
	const int length = 6;

	int v[length] = { 0,85,158,236,313,386 };
	//	int y[3] = { 1590,1590,1590,1590,1590 };
	//int c[3] = { -5,-5,-5,-5,-5 };*/
	int h[length] = { -5,0,15,18,18,28 };
	int delta_y[length] = { 20,20,5,5,5,5 };
	int cc[length] = { 0,-13,-10,-15,-27,-25 };
	int y = 2170;
	int delta_h[length] = { 0,0,20,18,20,20 };
	int width[length] = { 90,82,82,82,78,78 };
	herosprite.setTextureRect(sf::IntRect(v[x], y + delta_y[x], width[x], 120 + delta_h[x]));

	if (dir)
	{
		herosprite.setScale(1, 1);
		herosprite.setOrigin(cc[x] - 0, h[x] + 5 + 0 * 35);
	}
	else
	{
		herosprite.setScale(-1, 1);
		herosprite.setOrigin(cc[x] + 120, h[x] + 5 + 0 * 35);
	}

	//		ResetFrame();

	//cout << "frame" <<counter<<"time "<<time<<"   x" << x<<endl;
}

void Character::Climbing()
{
	//int v[8] = { 0, 112 ,216,330,451,554,661,771 };
	//int y[8] = { 155,154,154 ,154,154,153,153,153 };



	const int length = 6;
	int x;
	int v[length] = { 0,85,158,236,313,386 };
	//	int y[3] = { 1590,1590,1590,1590,1590 };
	//int c[3] = { -5,-5,-5,-5,-5 };*/
	//int h[length] = { -5,0,15,18,18,28 };
	int h[length] = { 0,0,0,0,0,0 };
	int delta_y[length] = { 20,20,5,5,5,5 };
	int cc[length] = { 0,-13,-10,-15,-27,-25 };
	int y = 2170;
	int delta_h[length] = { 0,0,20,18,20,20 };
	int width[length] = { 90,82,82,82,78,78 };
	herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], y + delta_y[int(CurFrame)], width[int(CurFrame)], 120 + delta_h[int(CurFrame)]));

	//	int h = -25;

	if (dir)
	{

		herosprite.setScale(1, 1);
		herosprite.setOrigin(cc[int(CurFrame)] - 0, h[int(CurFrame)] + 5 + 0 * 35);
	}
	else
	{
		herosprite.setScale(-1, 1);
		herosprite.setOrigin(cc[int(CurFrame)] + 120, h[int(CurFrame)] + 5 + 0 * 35);
	}
	//	float dt;
	//	0.001*time > 0.3 ? dt = 0.3 : dt = 0.001*time;


	switch (Status)
	{
	case climb_up: if (int(CurFrame + 0.006*time)<length)
		CurFrame += 0.006*time;
				   else {
					   CurFrame += 0.006*time;
					   dir = !dir;
					   CurFrame -= length;
					  // general_data.Increm_Screen_Pos(0, -150);
				   }
				   general_data.Increm_Screen_Pos(0, -1);
				   break;
	case climb_down: if ((CurFrame - 0.006*time) >= 0)
	{
		//		if (int(96*CurFrame)!=int(96*(CurFrame - 0.006*time))) 
		{
			//int f[48] = { 0,4,8,6,9,12,15,18,21,24,27,30,33,36 };

			//general_data.Increm_Screen_Pos(0, 2* (int(8 * CurFrame) -int(8 * (CurFrame - 0.006*time))));
			int g = herosprite.getOrigin().y;
			int l = herosprite.getOrigin().x;
			if (clim != int(50 * CurFrame))

			{
			//	herosprite.setOrigin(0, 1);
				general_data.Increm_Screen_Pos(0, 1);
				clim = int(50 * CurFrame);
			}
			//	cout << endl << "1";
		}
		CurFrame -= 0.006*time;
	}
					 else
					 {
						 int l = herosprite.getOrigin().x;
						 int g = herosprite.getOrigin().y;

						 //	herosprite.setOrigin(l, g );
						 CurFrame -= 0.006*time;
						 dir = !dir;
						 CurFrame += 6;
						 cout << endl << "V";
					/*	 if (clim != int(1000 * CurFrame))

						 {
							 herosprite.setOrigin(0, 1);
							 general_data.Increm_Screen_Pos(0, 1);
							 clim = int(1000 * CurFrame);
						 }*/
						 //	cout <<endl<< "reset";
						 //	getchar();
						 		general_data.Increm_Screen_Pos(0,1);
					 }
				

					 //if (0.3*0.2*time > 1)
					 //{
						// 
						// general_data.Increm_Screen_Pos(0, 1);
					 //}
					 //else
					 //{
						// cout << endl << ">";
						// general_data.Increm_Screen_Pos(0, 1);
					 //}
					 break;
	case climb:
		break;
	default:
		break;


	}



	//cout << endl;
	//Status = waiting;
	//	general_data.Increm_Screen_Pos(0,10);
	//	pos.y += 10;

	//CurFrame += 0.007*time;
	//herosprite.setPosition(pos.x,pos.y-10);
	if (Previous != climb&& Previous != climb_down&& Previous != climb_up)
	{
		Previous = Status;
	}
	//	cout << "frame" <<CurFrame<< "  int"<<int(CurFrame) <<"  dy"<<dy<<" Status"<<Status<<"  POS "<<general_data.Get_Screen_Pos().x <<endl;
	//{ CurFrame -= 7; Status = waiting; State = standing; }

}

void Character::Climbing_end()
{

	//	int y[3] = { 1590,1590,1590,1590,1590 };
	//int c[3] = { -5,-5,-5,-5,-5 };*/

	const int length = 7;
	int v[length] = { 386,0,90,165,235,320,390 };
	//	int y[3] = { 1590,1590,1590,1590,1590 };
	//int c[3] = { -5,-5,-5,-5,-5 };*/
	int h[length] = { 28,20,33,41,58,67,85 };
	int delta_y[length] = { 5,145,145,145,145,145,145 };
	int cc[length] = { -25,-14,-20,-20,-17,-23,-15 };
	int y = 2170;
	int delta_h[length] = { 20,0,0 ,0,0,0,0 };
	int width[length] = { 78,90,85,80,80,80,80 };
	herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], y + delta_y[int(CurFrame)], width[int(CurFrame)], 120 + delta_h[int(CurFrame)]));


	//	int h = -25;

	if (dir)
	{

		herosprite.setScale(1, 1);
		herosprite.setOrigin(cc[int(CurFrame)] - 0, h[int(CurFrame)] + 5 + 0 * 35);
	}
	else
	{
		herosprite.setScale(-1, 1);
		herosprite.setOrigin(cc[int(CurFrame)] + 120, h[int(CurFrame)] + 5 + 0 * 35);
	}
	if (int(CurFrame)<length) CurFrame += 0.0006*time;
	else
	{
		CurFrame = 0;
	}
}
void Character::Interaction_with_Objects()
{
	sf::Vector2f V = general_data.Get_Screen_Pos();
	//sf::Vector2f V = sf::Vector2f(general_data.Get_Screen_Pos().x /*+herosprite.getOrigin().x*/ + herosprite.getPosition().x - general_data.window.getSize().x / 2,
	//	general_data.Get_Screen_Pos().y /*- herosprite.getOrigin().y*/	/*y*/  + herosprite.getPosition().y - general_data.window.getSize().y / 2);

	//InteractionWithMapX(  float delta)
	float width = herosprite.getTextureRect().width;
	float height = 120;// herosprite.getTextureRect().height;
	sf::Vector2f S = herosprite.getPosition();
	//	S	
	//y + deltaY + herosprite.getPosition().y - general_data.window.getSize().y / 2);
	//	int i_l = int((V.x + S.x - general_data.window.getSize().x / 2) / sizeMapX);
	int	i = int((V.x + S.x + width / 2/*- herosprite.getOrigin().x*/ - general_data.window.getSize().x / 2));

	int	j = int((V.y + S.y - general_data.window.getSize().y / 2));
	//	int j_1 = int((V.y + S.y + height / 2 - general_data.window.getSize().y / 2) / sizeMapY);
	//	int j_2 = int((V.y + S.y + height - general_data.window.getSize().y / 2) / sizeMapY);

	up_stair = false;
	up_stair_index = -1;
	for (int k = 0; k < map.all_stairs_length; k++)
	{
		if (map.all_stairs[k].Active(i, j))
		{
			up_stair = true;
			up_stair_index = k;
			//	cout << endl << "stair" << map.all_stairs[k].pos.x << "  " << pos.x << "   " << herosprite.getPosition().x << "   " << general_data.window.getSize().x;
			//	cout << endl << "" << pos.x - general_data.window.getSize().x / 2 + herosprite.getPosition().x+width/2
			//	float z = V.x + herosprite.getPosition().x + width / 2 - general_data.window.getSize().x/2;
			//	sf::Vector2f V = map.all_stairs[up_stair_index].Attach();
			//	cout << endl << "stair" <<  z <<"  "<< map.all_stairs[k].pos.x << "  " << pos.x << "   " << herosprite.getPosition().x << "   " << general_data.window.getSize().x;
			;
		}

	}
	//	cout << "Activate" << up_stair << endl;
}
bool  Character::Can_Climbing()
{
	return up_stair;
}

void Character::Attach_to_Stair()
{


	sf::Vector2f V = map.all_stairs[up_stair_index].Attach();
	// << endl << "  Atac" << map.all_stairs[up_stair_index].pos.x << "   " << map.all_stairs[up_stair_index].pos.y << "";


	float width = herosprite.getTextureRect().width;

	sf::Vector2f V_p = general_data.Get_Screen_Pos();
	//	float z = V_p.x  + herosprite.getPosition().x - general_data.window.getSize().x / 2;

	float l = V.x - herosprite.getPosition().x - width / 2;
	float m = V.y - herosprite.getPosition().y;

	general_data.Increm_Screen_Pos(l, m);
	Previous = Status;

	//general_data.Set_Screen_Pos(z, V.y);
	/*if (dir)
	general_data.Increm_Screen_Pos( z-V.x, 0);
	else  general_data.Increm_Screen_Pos(z-V.x, 0);*/
	//	general_data.Set_Screen_Pos(V.x-herosprite.getPosition().x+ general_data.window.getSize().x / 2,V_p.y);
	//cout << endl<<"z=" <<z <<  "    " <<"x=" <<V.x <<"dir"<<dir;
	//	getchar();
}

bool Character::isUpdated(status s)
{
	if (s != Status)
	{
		redraw = true;
	}
}