
#include "AnimationMainHero.h"
#include "Map.h"
using namespace std;
float max_dx = 3, max_dy = 3;
extern const float sizeMapX;
extern const float sizeMapY;
Character::Character(bool d,float& t, General_Data& data, Map& map_):time(t), general_data(data), map(map_)

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
	x = 200.;
	y = 470.;
	herosprite.setPosition(x,y);//з
	//cout << "pos=" << pos.x << " " << pos.y << endl;
	//cout <<"SIZEMAP" <<sizeMapX;
}



void DrawWindow(sf::Sprite herosprite, sf::RenderWindow& window)
{

	window.draw(herosprite);


}
void Character::PistolAttack( )
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
				herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], 1060-20, i[int(CurFrame)], 120));
				herosprite.setScale(1, 1);
				herosprite.setOrigin(10, 10 +20+ n[int(CurFrame)]);
				//	herosprite.setOrigin(10, -35);
			}
		
			else
			{
				int v[9] = { 15,165,310,448,624,775,165,15,15 };

				int i[9] = { 120, 100, 150, 160, 120, 120,120,120,120 };

				int n[9] = { -37,-35, -35,-35,-35,-35,-35,-37,-37 };

				herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], 1060-20, i[int(CurFrame)], 120));
				herosprite.setScale(-1, 1);
				herosprite.setOrigin(140, 10+20 + n[int(CurFrame)]);
			}
		}
		last_frame = int(CurFrame);
		CurFrame += 0.006*time;
		if (CurFrame > 8) { CurFrame -= 8; Previous = Status; Status = waiting; }
		
		break;
	}



};

void Character::MeleeAttack( )
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
		if (CurFrame > d[MeleeAttackType]) {	CurFrame -= d[MeleeAttackType];  Previous = Status; Status = waiting; MeleeAttackType = -1;}
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
				if (CurFrame > 5) { CurFrame -= 5; Previous = Status; Status = waiting;	};
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
	if (j) dy = -0.43; //short
	else dy = -0.60;	  //long
}



void  Character::Idle()
{	
	switch (State)
	{
		
					case standing:
						
					{
						if (last_frame!=int(CurFrame))//&&Previous==Status)
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
	int v[5] = { 0,103,190,283,373};

	int c[5] = { 0,-10,-10,-10,-10 };
	//	int h[15] = { 0,-8,-8,-8,-8,-8,-8,-8 ,-8,-8,-8,-8,-8,-8,0 };
	int y = 1701;

	herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], y,int(CurFrame)==0? 105:92, 105));

	if (dir)
	{
		herosprite.setScale(1, 1);
		herosprite.setOrigin( c[int(CurFrame)], -15);
	}
	else
	{
		herosprite.setScale(-1, 1);
		herosprite.setOrigin( c[int(CurFrame)] + 130, -15);
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
	
	float deltaX = dx*time > max_dx ? max_dx : dx*time;
	float deltaY = dy*time > max_dy ? max_dy : dy*time;
	x = pos.x + deltaX;//- window.getSize().x/2 + herosprite.getTextureRect().width/2
	y = pos.y;//- window.getSize().y/2
	//if (pos.x+deltaX > 600 && herosprite.getPosition().x >= 200)  
	if (general_data.Get_Screen_Pos().x + deltaX > 600 && herosprite.getPosition().x >= 200)
	{
	
	//	x = pos.x+herosprite.getPosition().x-SizeX+dx*time;
		
		//	x += dx*time;
		//	x += dx*time
		//dir ? x+100 : x+25
//		if (InteractionWithMapX(window, sf::Vector2f(x, y), herosprite.getPosition(), herosprite.getTextureRect().width, herosprite.getTextureRect().height, deltaX))
		if (InteractionWithMapX(deltaX))
		{
			general_data.Increm_Screen_Pos(deltaX, 0);
			pos.x += deltaX;
			
		} else cout << "Block";
	}
	else Move();
	
	//dir ? x +10+herosprite.getTextureRect().width/2 : x - 10 - herosprite.getTextureRect().width / 2
	//if (InteractionWithMapYII(window, sf::Vector2f(pos.x + herosprite.getPosition().x - window.getSize().x / 2, y+deltaY + herosprite.getPosition().y - window.getSize().y/2),herosprite.getPosition(), herosprite.getTextureRect().height, dir,time))
	if (InteractionWithMapY(deltaY))
	{
	//	herosprite.setPosition(herosprite.getPosition()+sf::Vector2f(0,deltaY));
		pos.y += deltaY;
		general_data.Increm_Screen_Pos(0, deltaY);
		
	//	cout << "  herosprite" << herosprite.getPosition().x << " " << herosprite.getPosition().x << "  POS=" << pos.x << " " << pos.y;
	/*if (State==inair)*/	dy += gravity*time;
		if (State == standing) 
		{ State = inair;
		  if (Status!=short_jump && Status!=long_jump) Status = falling;
		}
	}
	else
	{	
		if (State == inair) { State = standing;	dy = 0.1; Status = waiting; }
		/*if (abs(deltaX) < 0.01)
			Edge();*/
	
		//cout << "stop";
	}
	//cout << "y =" << pos.y << endl;

	//  CameraGoForHero(x, y);
}
void Character::Balancing()
{

	//int v[8] = { 0,137,263,395,512,628,760,875};
//	int v[15] = { 0,137,263,395,512,628,760,875 ,760,628,512,395,263,137,0};
	int v[14] = { 0,137,263,395,512,628,760,875 ,263,395,512,628,760,875 };
	//	int y[3] = { 1590,1590,1590,1590,1590 };
	//int c[3] = { -5,-5,-5,-5,-5 };*/
//	int h[8] = { 0,-8,-8,-8,-8,-8,-8,-8};
	//int c[14] = { 0,-8,-8,-8,-8,-10,-11,-11 ,-8,-8,-8,-10,-11,-11}; 
	int c[14] = { -0,-11,-11,-11,-11,-11,-11,-11 ,-11,-11,-11,-11,-11,-11 };
	//	int h[15] = { 0,-8,-8,-8,-8,-8,-8,-8 ,-8,-8,-8,-8,-8,-8,0 };
	int y = 1240;

	herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)], y, int(CurFrame)==3|| int(CurFrame) == 6||int(CurFrame)==9||int(CurFrame)==12 ? 125:135, 100));

	if (dir)
	{
		herosprite.setScale(1, 1);
		herosprite.setOrigin(c[int(CurFrame)], -20);//-30
	}
	else
	{
		herosprite.setScale(-1, 1);
		herosprite.setOrigin( c[int(CurFrame)]+130,-20);//-30
	}

//	CurFrame += 0.002*time;
	CurFrame += 0.0045*time;
	if (CurFrame > 13) CurFrame -=11;

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

	herosprite.setTextureRect(sf::IntRect(v[int(CurFrame)] , y, 100, 110));
//	int h = -25;
	
	if (dir)
		{
			herosprite.setScale(1, 1);
			herosprite.setOrigin(cc-0, h[int(CurFrame)]+5+0*35);
		}
		else
		{
			herosprite.setScale(-1, 1);
			herosprite.setOrigin(cc+120,h[int(CurFrame)]+5+0*35);
		}
	//CurFrame += 0.0006*time;
	CurFrame += df*time;
	if (CurFrame > 7) { Status = falling; Falling(); }
	//{ CurFrame -= 7; Status = waiting; State = standing; }

}


void Character::UpdateHero()
{
	//cout << Status;
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
	case waiting:dx = 0;  Idle();  Previous = waiting;
		 break;
	 case pistolattack:dx = 0; PistolAttack();
		 break;
	 case meleeattack: dx = 0; MeleeAttack();
		 break;
	 case jump:Jump(0.0006f);/*cout << "comand"; */// Jump(time); 
	//	 if (State!=inair) {  Jump(); State = inair;  }

	//	 cout << "jump!";
		// if ((State== inair)&&(Previous!=jump)) { Previous=jump; }
		 Previous = jump;
		 break;
	 case long_jump:Jump(0.008f);
		 break;
	 case short_jump: Jump(0.010f);
		 break;
	 //case balancing: {Balancing();  Previous = balancing;
		// cout << "balancing"; };
		//			 break;
	 case falling: {Falling(); } break;
	 case test: {Balancing();
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
bool Character::IsUpdate()
{
	return (int(CurFrame) != int(last_frame));
}
void Character::Move()
{
	sf::Vector2f s = herosprite.getPosition();
	if (s.x+dx*time>60) s.x += dx*time;
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
	int	i = int((V.x + S.x /*- herosprite.getOrigin().x*/ + delta- general_data.window.getSize().x / 2) / sizeMapX);
	int	i_r = int((V.x + S.x /*- herosprite.getOrigin().x*/ +width+ delta - general_data.window.getSize().x / 2) / sizeMapX);
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
		cout << "BLOCK 0";
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
		cout << "if" << map.TileMap[j_2][i_l] << "      " << (V.y + S.y + height - general_data.window.getSize().y / 2) << ">>" <<( (j_2+1)* 60 + 30);
	//	cout << "BLOCK WALL1" << map.TileMap[j_2][i];
		//	if (((V.x ))<( (i_l ) * 60+120)) {
		//		map_s.setTextureRect(sf::IntRect(190, 450, 60, 60));
		//		map_s.setPosition(i * 60, j * 60);
		//		DrawWindow(map_s, window);

		if (delta <= 0)
		{
		//	cout << "delta"<< map.TileMap[j_2][i_l]<< map.TileMap[j_1][i_l]<< map.TileMap[j][i_l];
			if (map.TileMap[j_2][i_l] == '2'|| map.TileMap[j_1][i_l] == '2'|| map.TileMap[j][i_l] == '2')
			{
				if ((V.y + S.y + height - general_data.window.getSize().y / 2) > ((j_2 + 1) * 60 + 30))
				{
					return false;
				}
				else
				{
					if ((V.x + S.x/*+ width / 2*/- general_data.window.getSize().x / 2) < ((i)* 60 + 10))
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
		else cout << "else" << delta;

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
					cout << "else11";
					return false;
				}
				else
				{
			//		cout <<"   "<<i<< "else22   " << (V.x + S.x + width / 2 - general_data.window.getSize().x / 2) << "  >   " << ((i_r)* 60 - 30);
					if ((V.x + S.x+ width / 2 - general_data.window.getSize().x / 2) > ((i_r)* 60 - 30))
						return false;


				}
			}

			if (map.TileMap[j_2][i_r] == '7' || map.TileMap[j_1][i_r] == '7' || map.TileMap[j][i_r] == '7')
			{
				cout << "dddd" << (V.x + S.x + width / 2 - general_data.window.getSize().x / 2) << '<' << ((i_r)* 60 -30);
				if ((V.x + S.x+ width / 2 - general_data.window.getSize().x / 2) > ((i_r)* 60 - 30))
					return false;
			}

			if (map.TileMap[j_2][i_r] == '8' || map.TileMap[j_1][i_r] == '8' || map.TileMap[j][i_r] == '8')
			{
				int edge = map.TileMap[j_2][i_r] == '8' ? j_2 : map.TileMap[j_1][i_r] == '8' ? j_1 : j;
				if ((V.y + S.y + height - general_data.window.getSize().y / 2) > ((edge + 1) * 60 - 30))
				{
					if ((V.x + S.x+ width / 2 - general_data.window.getSize().x / 2) > ((i_r)* 60 - 30))

						return false;
				}

			}
		}
	//	else cout << "else" << delta;

	}

	return true;
}
bool Character::InteractionWithMapX_new(float delta)
{

	//	InteractionWithMapX(   deltaX))
	sf::Vector2f V = general_data.Get_Screen_Pos();
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



	if (map.TileMap[j][i] == '0' || map.TileMap[j_1][i] == '0'/* || map.TileMap[j_2][i] == '0'*/)//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
	{
		cout << "BLOCK 0";
		//	map_s.setTextureRect(sf::IntRect(190, 450, 60, 60));
		//	map_s.setPosition(i * 60, j * 60);
		//	DrawWindow(map_s, window);
		//		cout << " FFF=" << map.TileMap[j_2][i] << "" << " " << j_1 << i << " " << j_2 << i;
		return false;
	}
	// нет взаимодействия с блоком 3, блок 0 не пол а стена
	if (map.left_wall.find(map.TileMap[j][i]) != map.left_wall.end() ||
		map.left_wall.find(map.TileMap[j_1][i]) != map.left_wall.end() ||
		map.left_wall.find(map.TileMap[j_2][i]) != map.left_wall.end())
	{

		//	cout << "BLOCK WALL1" << map.TileMap[j_2][i];
		//	if (((V.x ))<( (i_l ) * 60+120)) {
		//		map_s.setTextureRect(sf::IntRect(190, 450, 60, 60));
		//		map_s.setPosition(i * 60, j * 60);
		//		DrawWindow(map_s, window);
		if (delta < 0)
			if ((V.x + S.x/*+ width / 2*/ - general_data.window.getSize().x / 2) < ((i)* 60 + 30))
			{
				cout << "LEFT V=" << (V.x + delta + S.x - general_data.window.getSize().x / 2) << "<" << (i)* 60 + 30;
				//cout << "BLOCK WALL";
				if ((map.TileMap[j_2][i] == '5') && ((V.y + S.y + height - general_data.window.getSize().y / 2) > ((j_2)* 60 + 30))) return true;
				else	return false;
			}
		//	}
	}


	if (map.right_wall.find(map.TileMap[j][i_r]) != map.right_wall.end() ||
		map.right_wall.find(map.TileMap[j_1][i_r]) != map.right_wall.end() ||
		map.right_wall.find(map.TileMap[j_2][i_r]) != map.right_wall.end())
	{
		cout << "WALL";
		if (delta > 0)
		{
			if ((V.x + delta + width + S.x - general_data.window.getSize().x / 2) > ((i_r)* 60 + 30))
			{
				if ((map.TileMap[j_2][i_r] == '6') && ((V.y + S.y + height - general_data.window.getSize().y / 2) > ((j_2)* 60 + 30))) return true;
				else	return false;
				return false;
			}
		}
	}

	return true;
}

bool Character::InteractionWithMapY(float deltaY)
{

	sf::Vector2f V = sf::Vector2f(general_data.Get_Screen_Pos().x /*+herosprite.getOrigin().x*/+ herosprite.getPosition().x - general_data.window.getSize().x / 2,
		general_data.Get_Screen_Pos().y /*- herosprite.getOrigin().y*/	/*y*/ + deltaY + herosprite.getPosition().y -general_data.window.getSize().y / 2);
	
	float height = 120;// herosprite.getTextureRect().height;
	int	j = int((V.y) / sizeMapY);
	int j_next = int((V.y +height) / sizeMapY);
	int	i_1 = int((V.x + (dir ? 33 : 45)) / sizeMapX);
	int	i_2 = int((V.x + (dir ? 33 : 45) + 45) / sizeMapX);
	int j_current = int((V.y +height/ 2) / sizeMapY);
//	cout << "  jcur "<< (dir ? 33 : 45);
	cout <<"  "<< map.TileMap[j_next][i_1] << "    " << map.TileMap[j_next][i_2];
	
//	cout << " jnext=" << j_next << "." << ((map.TileMap[j_next][i_1] == ' ') ? ' ' : (map.TileMap[j_next][i_1] - 48)) << "." <<
//		((map.TileMap[j_next][i_2] == ' ') ? ' ' : (map.TileMap[j_next][i_2] - 48)) << "." << " jcur=" << j_current << endl;
//	cout << "X=" << V.x << "  V.X" << (i_1)*sizeMapX;
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
		if (V.x >((i_1)*sizeMapX )) 	return true;
		//	if (V.x >((i_1)*sizeMapX - 5)) 	return true;
	}
	if ((map.TileMap[j_next][i_1] == '2' && map.TileMap[j_next][i_2] == '3'))
	{
//		cout << "DELTE" << (V.x - i_1 * 60) << " V.Y=" << (V.y + height);
		if ((V.x > ((i_1)*sizeMapX) ) && (V.y  < ((j_next)* 60 + 30)))	return true;
		///	if ((V.x > ((i_1)*sizeMapX) - 10) && (V.y  < ((j_next)* 60 + 30)))	return true;
	}


	if ((map.TileMap[j_next][i_1] == '3' && map.TileMap[j_next][i_2] == '8'))
	{
		cout << "rano2";
//		cout << "DELTE" << (V.x - i_1 * 60) << " V.Y=" << (V.y + height);
	//	if ((V.x < ((i_2)*sizeMapX - 30)))  return true;
			
		cout <<"  "<<V.y << "  "<< (j_next)* 60 + 30;
		getchar();
		if (V.y < ((j_next)* 60 + 30)) return true;
		//if ((V.x < ((i_2)*sizeMapX) + 10) && (V.y  < ((j_next)* 60 + 30)))	
	}
	if ((map.TileMap[j_next][i_1] == ' ' && map.TileMap[j_next][i_2] == '8')
		)
	{
		cout << "rano1";
		if (V.x <((i_2)*sizeMapX + 30)) 	return true;
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}
	if ((map.TileMap[j_next][i_1] == ' ' && map.TileMap[j_next][i_2] == '6')
		)
	{
		if (V.x <((i_2)*sizeMapX + 30)) 	return true;
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}


	if ((map.TileMap[j_next][i_1] == '6' && map.TileMap[j_next][i_2] == '6')
		)
	{
		if (V.x >((i_1)*sizeMapX + 30)&& (V.x <((i_2)*sizeMapX + 30))) 	return true;
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}
	

	if ((map.TileMap[j_next][i_1] == '6' && map.TileMap[j_next][i_2] == '3')
		)
	{
		if (V.x <((i_2)*sizeMapX + 30)) 	return true;
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}
	

	if ((map.TileMap[j_next][i_2] == '7' && map.TileMap[j_next][i_1] == ' '))
	{
		if (V.x <((i_2)*sizeMapX )) 	return true;
		//	if (V.x <((i_2)*sizeMapX + 10)) 	return true;
	}
	////6 8  /////
	if ((map.TileMap[j_next][i_1] == '6' && map.TileMap[j_next][i_2] == '8'))
	{
		cout << "rano";

		if (V.x <((i_2)*sizeMapX + 30)) 	return true;
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}



	//cout << " JNEX=" << (j_next * 60) << "V.Y=" << V.y<<endl;
	return false;
}

bool Character::InteractionWithMapY_old(float deltaY)
{

	sf::Vector2f V = sf::Vector2f(general_data.Get_Screen_Pos().x /*+herosprite.getOrigin().x*/ + herosprite.getPosition().x - general_data.window.getSize().x / 2,
		general_data.Get_Screen_Pos().y /*- herosprite.getOrigin().y*/	/*y*/ + deltaY + herosprite.getPosition().y - general_data.window.getSize().y / 2);

	float height = 120;// herosprite.getTextureRect().height;
	int	j = int((V.y) / sizeMapY);
	int j_next = int((V.y + height) / sizeMapY);
	int	i_1 = int((V.x + (dir ? 33 : 45)) / sizeMapX);
	int	i_2 = int((V.x + (dir ? 33 : 45) + 45) / sizeMapX);
	int j_current = int((V.y + height / 2) / sizeMapY);
	//	cout << "  jcur "<< (dir ? 33 : 45);


	//	cout << " jnext=" << j_next << "." << ((map.TileMap[j_next][i_1] == ' ') ? ' ' : (map.TileMap[j_next][i_1] - 48)) << "." <<
	//		((map.TileMap[j_next][i_2] == ' ') ? ' ' : (map.TileMap[j_next][i_2] - 48)) << "." << " jcur=" << j_current << endl;
	//	cout << "X=" << V.x << "  V.X" << (i_1)*sizeMapX;
	if (map.TileMap[j_next][i_1] == map.TileMap[j_next][i_2])
	{
		if (map.TileMap[j_next][i_1] == ' ')	return true;
		//	(TileMap[j_current][i_1] == ' ' && TileMap[j_current][i_2] == ' ')&&(V.y>(j+1)*sizeMapY))

		if ((map.TileMap[j_next][i_1] == '5') && (V.x > ((i_1)*sizeMapX + 30))) return true;

	}
	cout << "rano3";
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
	cout << "rano2";
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


	if ((map.TileMap[j_next][i_1] == '3' && map.TileMap[j_next][i_2] == '8'))
	{
		//		cout << "DELTE" << (V.x - i_1 * 60) << " V.Y=" << (V.y + height);
		if ((V.x < ((i_2)*sizeMapX)) && (V.y  < ((j_next)* 60 + 30)))	return true;
		//if ((V.x < ((i_2)*sizeMapX) + 10) && (V.y  < ((j_next)* 60 + 30)))	
	}
	if ((map.TileMap[j_next][i_1] == ' ' && map.TileMap[j_next][i_2] == '8')
		)
	{
		if (V.x <((i_2)*sizeMapX + 30)) 	return true;
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}
	if ((map.TileMap[j_next][i_1] == ' ' && map.TileMap[j_next][i_2] == '6')
		)
	{
		if (V.x <((i_2)*sizeMapX + 30)) 	return true;
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}


	if ((map.TileMap[j_next][i_1] == '6' && map.TileMap[j_next][i_2] == '6')
		)
	{
		if (V.x >((i_1)*sizeMapX + 30) && (V.x <((i_2)*sizeMapX + 30))) 	return true;
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}



	if ((map.TileMap[j_next][i_1] == '6' && map.TileMap[j_next][i_2] == '3')
		)
	{
		if (V.x <((i_2)*sizeMapX + 30)) 	return true;
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}


	if ((map.TileMap[j_next][i_2] == '7' && map.TileMap[j_next][i_1] == ' '))
	{
		if (V.x <((i_2)*sizeMapX)) 	return true;
		//	if (V.x <((i_2)*sizeMapX + 10)) 	return true;
	}
	////6 8  /////
	if ((map.TileMap[j_next][i_1] == '6' && map.TileMap[j_next][i_2] == '8'))
	{


		if (V.x <((i_2)*sizeMapX + 30)) 	return true;
		if (V.y  < ((j_next)* 60 + 30)) return true;
	}



	//cout << " JNEX=" << (j_next * 60) << "V.Y=" << V.y<<endl;
	return false;
}

void Character::Edge()
{
	sf::Vector2f V = sf::Vector2f(general_data.Get_Screen_Pos().x  + herosprite.getPosition().x - general_data.window.getSize().x / 2,
		general_data.Get_Screen_Pos().y + herosprite.getPosition().y - general_data.window.getSize().y / 2);

	int result = 0;

	float height = 120;// herosprite.getTextureRect().height;
	int	j = int((V.y) / sizeMapY);
	int j_next = int((V.y + height) / sizeMapY);
	int	i_1 = int((V.x + (dir ? 33 : 45)) / sizeMapX);
	int	i_2 = int((V.x + (dir ? 33 : 45) + 45) / sizeMapX);
	int j_current = int((V.y + height / 2) / sizeMapY);
	

	cout << "DDD=" << (V.x + (dir ? 33 : 45) + 45) << "  "
		<< map.TileMap[j_next][i_1] << " " << map.TileMap[j_next][i_2] <<" ";
	cout << "   VV= " << i_1 << "  " << i_2;

	if ((map.TileMap[j_next][i_1] == '5' && map.TileMap[j_next][i_2] == '5'))
	{
		if ((V.x + (dir ? 33 : 45) + 45) > ((i_2)* sizeMapX + 15))
		{
			result = 1;// general_data.Set_Screen_Pos(i_2*sizeMapX-herosprite.getPosition().x+general_data.window.getSize().x/2, general_data.Get_Screen_Pos().y);
		}
	}

	if ((map.TileMap[j_next][i_1] == '5' && map.TileMap[j_next][i_2] == ' '))
	{
		if ((V.x + (dir ? 33 : 45) + 45) >((i_1)*sizeMapX + 15)) 
		{
			result = 1;// general_data.Set_Screen_Pos(i_1*sizeMapX - herosprite.getPosition().x + general_data.window.getSize().x / 2, general_data.Get_Screen_Pos().y);
		}
	}

	if ((map.TileMap[j_next][i_1] == '4' && map.TileMap[j_next][i_2] == '5'))
	{
		if ((V.x + (dir ? 33 : 45) + 45) > ((i_2)*sizeMapX + 15)) 
		{
			result = 1;// general_data.Set_Screen_Pos(i_2*sizeMapX - herosprite.getPosition().x + general_data.window.getSize().x / 2, general_data.Get_Screen_Pos().y);
		}
	}



	if (result>0)// Status = balancing;

	switch (result)
	{
	case 1:  SetDir(1); cout << "balance";
		break;

	default:
		break;
	}


}