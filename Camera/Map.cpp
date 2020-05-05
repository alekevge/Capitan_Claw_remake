#include "Map.h"

using namespace std;
int MapWidth = 40;
sf::Sprite map_s;
sf::Texture map_t;


int last_map_pos[2] = { -100, 0 };
set<char> left_wall = { '1','2','5' };
set<char> ground = { '2','3','6' };
set<char> right_wall = { '6','7','8' };
set<char>::iterator it;

//string TileMap[MapHeight] = {
//	 1234567890123456789012345678901234567890
//	"0                                      0",
//	"01                                     0",
//	"01                                     0",
//	"0000000000000000000000000000000000000000",
//	"01                                     0",
//	"01                                     0",
//	"01                                     0",
//	"01                                     0",
//	"01                                     0",
//	"01                                     0",
//	"01                            6333333330",
//	"01                 000        7000000000",
//	"02333333333345          6333338000000000",
//	"00000000000001        638000000000000000",
//	"000000000000013345   6800000000000000000",
//	"0000000000000000023338000000000000000000",
//	"0                00000                 0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",	
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0000000000000000000000000000000000000000",
//};


Map::Map(sf::RenderTexture& bg_texture_1, sf::RenderTexture& bg_texture_2,sf::RenderWindow& Wi, General_Data& dat) :
		 background_texture_1(bg_texture_1), background_texture_2(bg_texture_2), window(Wi), data(dat),stair(900,850,4,bg_texture_1, map_t,dat)
{
	
	
	sf::Vector2f V_s = camera.getSize();
	map_t.loadFromFile("Images\\PC Computer - Captain Claw - Level 1 Tiles_2.png");
	map_s.setTexture(map_t);
//	map_texture.create(V_s.x, V_s.y+2000);
//	cout << "jj=" << Pl.pos.x << "c " << Pl.pos.y;
//	Up_Stair stair;
		last_map_pos[0] = int(data.Get_Screen_Pos().x) % 60;
		last_map_pos[1] = int(data.Get_Screen_Pos().y) % 60;
	DrawMap(background_texture_1,0,0);
	cout << "mapinit";

	
	all_stairs_length = 4;



	float* data;
	int size;

	size = 2;
	data = new float[size*size];

	vector<Up_Stair> all;
	//all.push_back(Up_Stair(900 + 50 * 1, 850, 4, bg_texture, map_t, dat));
	//cout << "try"<<all[0].pos.x;
	for (int i = 0; i < all_stairs_length; ++i) all_stairs.push_back( Up_Stair(900 + 200 * i, 750, 4, background_texture_1, map_t, dat));


	Init();
};


void Map::Init()
{
	sf::Sprite s_1;
	s_1.setTexture(map_t);
	s_1.setTextureRect(sf::IntRect(130, 65, 60, 60));
	s_1.setOrigin(0, 0);
	sprite_buffer[0] = s_1;

	sf::Sprite s_2;
	s_2.setTexture(map_t);
	s_2.setTextureRect(sf::IntRect(260, 65, 60, 60));
	s_2.setOrigin(0, 0);
	sprite_buffer[1] = s_2;

	sf::Sprite s_3;
	s_3.setTexture(map_t);
	s_3.setTextureRect(sf::IntRect(130, 130, 70, 60));
	s_3.setOrigin(0, 0);
	sprite_buffer[2] = s_3;

	sf::Sprite s_4;
	s_4.setTexture(map_t);
	s_4.setTextureRect(sf::IntRect(130, 0, 60, 60));
	s_4.setOrigin(-8, 0);
	sprite_buffer[3] = s_4;

	sf::Sprite s_5;
	s_5.setTexture(map_t);
	s_5.setTextureRect(sf::IntRect(200, 0, 60, 60));
	s_5.setOrigin(-7, 0);
	sprite_buffer[4] = s_5;

	sf::Sprite s_6;
	s_6.setTexture(map_t);
	s_6.setTextureRect(sf::IntRect(260, 0, 60, 60));
	s_6.setOrigin(-6, 0);
	sprite_buffer[5] = s_6;

	sf::Sprite s_7;
	s_7.setTexture(map_t);
	s_7.setTextureRect(sf::IntRect(60, 200, 80, 60));
	s_7.setOrigin(9, -13);
	sprite_buffer[6] = s_7;

	sf::Sprite s_8;
	s_8.setTexture(map_t);
	s_8.setTextureRect(sf::IntRect(60, 65, 70, 60));
	s_8.setOrigin(9, 0);
	sprite_buffer[7] = s_8;

	sf::Sprite s_9;
	s_9.setTexture(map_t);
	s_9.setTextureRect(sf::IntRect(60, 130, 70, 60));
	s_9.setOrigin(9, 0);
	sprite_buffer[8] = s_9;

	sf::Sprite s_10;
	s_10.setTexture(map_t);
	s_10.setTextureRect(sf::IntRect(600, 0, 60, 60));
	s_10.setOrigin(0, 0);
	sprite_buffer[9] = s_10;
			
}



void Map::Draw_Elements()
{
	for (int i = 0; i < all_stairs_length; ++i)
	{
	
	if (all_stairs[i].Visibility()) {
			all_stairs[i].Draw();
	}
	}
	
}


bool Map::Check_()
{}

void Map::DrawMap_new()
{

	//background_texture.display();

	//
	//map_texture.clear();
	//	sf::Vector2f V_c = Player.pos;
	sf::Vector2f V_c = data.Get_Screen_Pos();
	//	cout << Player.pos.x << "  " << Player.pos.y<<"L";



	//	sf::Vector2f V_c = camera.getCenter();
	sf::Vector2f V_s = camera.getSize();
	//background_texture.display();
//	bg_texture.clear();
	int i_0 = int((V_c.x - 0.5*V_s.x) / sizeMapX);
	int i_l = int((V_c.x + 0.5*V_s.x) / sizeMapX);// +10;
	int j_0 = int((V_c.y - 0.5*V_s.y) / sizeMapY);
	int j_l = int((V_c.y + 0.5*V_s.y) / sizeMapY);
	//int j_l = j_0 + 20;
	//	cout <<endl<< "Mapj"<<j_0<<"  " << j_l << "  " << MapWidth;
	//	cout << endl << "Mapi" <<i_0<<"  "<< i_l << "  " << MapHeight;

	for (int i = i_0; i <= i_l; ++i)
		for (int j = j_0; j <= j_l; ++j)
		{
			if (i < MapWidth && j < MapHeight)
			{
				switch (TileMap[j][i])
				{
				case '0': sprite_buffer[0].setPosition(int((i - i_0) * 60), int((j - j_0) * 60)); window.draw(sprite_buffer[0]); break;
				case '1': sprite_buffer[1].setPosition(int((i - i_0) * 60), int((j - j_0) * 60)); window.draw(sprite_buffer[1]); break;
				case '2': sprite_buffer[2].setPosition(int((i - i_0) * 60), int((j - j_0) * 60)); window.draw(sprite_buffer[2]); break;
				case '3': sprite_buffer[3].setPosition(int((i - i_0) * 60), int((j - j_0) * 60)); window.draw(sprite_buffer[3]); break;
				case '4': sprite_buffer[4].setPosition(int((i - i_0) * 60), int((j - j_0) * 60)); window.draw(sprite_buffer[4]); break;
				case '5': sprite_buffer[5].setPosition(int((i - i_0) * 60), int((j - j_0) * 60)); window.draw(sprite_buffer[5]); break;
				case '6': sprite_buffer[6].setPosition(int((i - i_0) * 60), int((j - j_0) * 60)); window.draw(sprite_buffer[6]); break;
				case '7': sprite_buffer[7].setPosition(int((i - i_0) * 60), int((j - j_0) * 60)); window.draw(sprite_buffer[7]); break;
				case '8': sprite_buffer[8].setPosition(int((i - i_0) * 60), int((j - j_0) * 60)); window.draw(sprite_buffer[8]); break;
				case ' ': sprite_buffer[9].setPosition(int((i - i_0) * 60), int((j - j_0) * 60)); window.draw(sprite_buffer[9]); break;
					//		case 'r':  map_s.setTextureRect(sf::IntRect(325, 0, 66, 60));  map_s.setOrigin(-6, 0); break;
					//		case 't':  map_s.setTextureRect(sf::IntRect(325, 65, 66, 60));  map_s.setOrigin(-6, 0); break;
					//		case 's':  map_s.setTextureRect(sf::IntRect(325, 130,66, 40));  map_s.setOrigin(-6, 0); break;

				default:  map_s.setTextureRect(sf::IntRect(0, 0, 60, 60));  map_s.setOrigin(0, 0); break;
				}
				//	map_s.setPosition((i - i_0) * 60, (j - j_0) * 60);
				//	window.draw(map_s);
				
				//	map_texture.draw(map_s);
				//	map_texture.display();
			}
		}
	//	map_texture.draw(map_s);
	//	map_texture.display();
	//	map_t = map_texture.getTexture();
	//	map_s.setPosition(0, 0);

	//	cout <<"" << endl;
	//background_texture.draw(map_s);
	window.display();
	Draw_Elements();

	//.draw();
	last_map_pos[0] = int(V_c.x);//int(V_c.x) % 60;
	last_map_pos[1] = int(V_c.y);//int(V_c.y) % 60;
};





void Map::DrawMap(sf::RenderTexture& bg_texture,float dx,float dy)
{

	//background_texture.display();

	//
	//map_texture.clear();
	//	sf::Vector2f V_c = Player.pos;
	sf::Vector2f V_c = data.Get_Screen_Pos();
	//	cout << Player.pos.x << "  " << Player.pos.y<<"L";



	//	sf::Vector2f V_c = camera.getCenter();
	sf::Vector2f V_s = camera.getSize();
	//background_texture.display();
	bg_texture.clear();
	int i_0 = int((V_c.x - 0.5*V_s.x) / sizeMapX);
	int i_l = int((V_c.x + 0.5*V_s.x) / sizeMapX);// +10;
	int j_0 = int((V_c.y - 0.5*V_s.y) / sizeMapY);
	int j_l = int((V_c.y + 0.5*V_s.y) / sizeMapY);
	//int j_l = j_0 + 20;
	//	cout <<endl<< "Mapj"<<j_0<<"  " << j_l << "  " << MapWidth;
	//	cout << endl << "Mapi" <<i_0<<"  "<< i_l << "  " << MapHeight;

	for (int i = i_0; i <= i_l; ++i)
		for (int j = j_0; j <= j_l; ++j)
		{
			if (i < MapWidth && j < MapHeight)
			{
				switch (TileMap[j][i])
				{
				case '0': sprite_buffer[0].setPosition(sf::Vector2f(/*round*/(dx+(i - i_0) * 60), /*round*/(dy + (j - j_0) * 60))); bg_texture.draw(sprite_buffer[0]); break;
				case '1': sprite_buffer[1].setPosition(sf::Vector2f(/*round*/(dx+(i - i_0) * 60), /*round*/(dy + (j - j_0) * 60))); bg_texture.draw(sprite_buffer[1]); break;
				case '2': sprite_buffer[2].setPosition(sf::Vector2f(/*round*/(dx+(i - i_0) * 60), /*round*/(dy + (j - j_0) * 60))); bg_texture.draw(sprite_buffer[2]); break;
				case '3': sprite_buffer[3].setPosition(sf::Vector2f(/*round*/(dx+(i - i_0) * 60), /*round*/(dy + (j - j_0) * 60))); bg_texture.draw(sprite_buffer[3]); break;
				case '4': sprite_buffer[4].setPosition(sf::Vector2f(/*round*/(dx+(i - i_0) * 60), /*round*/(dy + (j - j_0) * 60))); bg_texture.draw(sprite_buffer[4]); break;
				case '5': sprite_buffer[5].setPosition(sf::Vector2f(/*round*/(dx+(i - i_0) * 60), /*round*/(dy + (j - j_0) * 60))); bg_texture.draw(sprite_buffer[5]); break;
				case '6': sprite_buffer[6].setPosition(sf::Vector2f(/*round*/(dx+(i - i_0) * 60), /*round*/(dy + (j - j_0) * 60))); bg_texture.draw(sprite_buffer[6]); break;
				case '7': sprite_buffer[7].setPosition(sf::Vector2f(/*round*/(dx+(i - i_0) * 60), /*round*/(dy + (j - j_0) * 60))); bg_texture.draw(sprite_buffer[7]); break;
				case '8': sprite_buffer[8].setPosition(sf::Vector2f(/*round*/(dx+(i - i_0) * 60), /*round*/(dy + (j - j_0) * 60))); bg_texture.draw(sprite_buffer[8]); break;
				case ' ': sprite_buffer[9].setPosition(sf::Vector2f(/*round*/(dx+(i - i_0) * 60), /*round*/(dy+(j - j_0) * 60))); bg_texture.draw(sprite_buffer[9]); break;
					//		case 'r':  map_s.setTextureRect(sf::IntRect(325, 0, 66, 60));  map_s.setOrigin(-6, 0); break;
					//		case 't':  map_s.setTextureRect(sf::IntRect(325, 65, 66, 60));  map_s.setOrigin(-6, 0); break;
					//		case 's':  map_s.setTextureRect(sf::IntRect(325, 130,66, 40));  map_s.setOrigin(-6, 0); break;

				default:  map_s.setTextureRect(sf::IntRect(0, 0, 60, 60));  map_s.setOrigin(0, 0); break;
				}
			//	map_s.setPosition((i - i_0) * 60, (j - j_0) * 60);
			//	bg_texture.draw(map_s);

				//	map_texture.draw(map_s);
				//	map_texture.display();
			}
		}
	//	map_texture.draw(map_s);
	//	map_texture.display();
	//	map_t = map_texture.getTexture();
	//	map_s.setPosition(0, 0);

	//	cout <<"" << endl;
	//background_texture.draw(map_s);

	Draw_Elements();

	bg_texture.display();
	last_map_pos[0] = /*round*/(V_c.x);//% 60;
	last_map_pos[1] = /*round*/(V_c.y); //% 60;
};


void Map::DrawMap_save(sf::RenderTexture& bg_texture)
{

	sf::Vector2f V_c = data.Get_Screen_Pos();
	sf::Vector2f V_s = camera.getSize();
	//V_c.y = V_c.y - 40;


//	cout << endl << "Drawmap__" << last_map_pos[0]<<"  "<<last_map_pos[1];
	bg_texture.clear();
	int i_0 = int((V_c.x - 0.5*V_s.x) / sizeMapX) - buffer_background_texture.x;
	int i_l = int((V_c.x + 0.5*V_s.x) / sizeMapX) + buffer_background_texture.x;// +10;
	int j_0 = int((V_c.y - 0.5*V_s.y) / sizeMapY) - buffer_background_texture.y;
	int j_l = int((V_c.y + 0.5*V_s.y) / sizeMapY) + buffer_background_texture.y;
	

	for (int i = i_0; i <= i_l; ++i)
		for (int j = j_0; j <= j_l; ++j)
		{
			if (i>=0 && i < MapWidth&& j>=0 && j < MapHeight)
			{
     				switch (TileMap[j][i])
				{
				case '0': map_s.setTextureRect(sf::IntRect(130, 65, 60, 60)); map_s.setOrigin(0, 0); break;
				case '1': map_s.setTextureRect(sf::IntRect(260, 65, 60, 60)); map_s.setOrigin(0, 0); break;
				case '2': map_s.setTextureRect(sf::IntRect(130, 130, 70, 60)); map_s.setOrigin(0, 0); break;
				case '3': map_s.setTextureRect(sf::IntRect(130, 0, 60, 60)); map_s.setOrigin(-8, 0); break;
				case '4': map_s.setTextureRect(sf::IntRect(200, 0, 60, 60)); map_s.setOrigin(-7,0); break;
				case '5': map_s.setTextureRect(sf::IntRect(260, 0, 60, 60)); map_s.setOrigin(-6, 0); break;
				case '6': map_s.setTextureRect(sf::IntRect(60, 200, 80, 60)); map_s.setOrigin(9, -13); break;
				case '7': map_s.setTextureRect(sf::IntRect(60, 65, 70, 60)); map_s.setOrigin(9, 0); break;
				case '8': map_s.setTextureRect(sf::IntRect(60, 130, 70, 60)); map_s.setOrigin(9, 0); break;
				case ' ':  map_s.setTextureRect(sf::IntRect(600, 0, 60, 60));  map_s.setOrigin(0, 0); break;
		//		case 'r':  map_s.setTextureRect(sf::IntRect(325, 0, 66, 60));  map_s.setOrigin(-6, 0); break;
		//		case 't':  map_s.setTextureRect(sf::IntRect(325, 65, 66, 60));  map_s.setOrigin(-6, 0); break;
		//		case 's':  map_s.setTextureRect(sf::IntRect(325, 130,66, 40));  map_s.setOrigin(-6, 0); break;

				default:  map_s.setTextureRect(sf::IntRect(0, 0, 60, 60));  map_s.setOrigin(0, 0); break;
				}
				map_s.setPosition(int((i - i_0) * 60), int((j - j_0) * 60));
				bg_texture.draw(map_s);

			}
		}


	Draw_Elements();
	
	bg_texture.display();
	last_map_pos[0] = /*round(*/V_c.x/*)*/;
	last_map_pos[1] = /*round(*/V_c.y/*)*/;
//	last_map_pos[0] = /*round(*/V_c.x/*)*/ ;
//	last_map_pos[1] = /*round(*/V_c.y/*)*/ ;
};
void Map::DrawMap_async(sf::RenderTexture& bg_texture)
{

	sf::Vector2f V_c = data.Get_Screen_Pos();
	sf::Vector2f V_s = camera.getSize();

	bg_texture.clear();
	int i_0 = int((V_c.x - 0.5*V_s.x) / sizeMapX) - buffer_background_texture.x;
	int i_l = int((V_c.x + 0.5*V_s.x) / sizeMapX) + buffer_background_texture.x;// +10;
	int j_0 = int((V_c.y - 0.5*V_s.y) / sizeMapY) - buffer_background_texture.y;
	int j_l = int((V_c.y + 0.5*V_s.y) / sizeMapY) + buffer_background_texture.y;


	for (int i = i_0; i <= i_l; ++i)
		for (int j = j_0; j <= j_l; ++j)
		{
			if (i >= 0 && i < MapWidth&& j >= 0 && j < MapHeight)
			{
				switch (TileMap[j][i])
				{
				case '0': map_s.setTextureRect(sf::IntRect(130, 65, 60, 60)); map_s.setOrigin(0, 0); break;
				case '1': map_s.setTextureRect(sf::IntRect(260, 65, 60, 60)); map_s.setOrigin(0, 0); break;
				case '2': map_s.setTextureRect(sf::IntRect(130, 130, 70, 60)); map_s.setOrigin(0, 0); break;
				case '3': map_s.setTextureRect(sf::IntRect(130, 0, 60, 60)); map_s.setOrigin(-8, 0); break;
				case '4': map_s.setTextureRect(sf::IntRect(200, 0, 60, 60)); map_s.setOrigin(-7, 0); break;
				case '5': map_s.setTextureRect(sf::IntRect(260, 0, 60, 60)); map_s.setOrigin(-6, 0); break;
				case '6': map_s.setTextureRect(sf::IntRect(60, 200, 80, 60)); map_s.setOrigin(9, -13); break;
				case '7': map_s.setTextureRect(sf::IntRect(60, 65, 70, 60)); map_s.setOrigin(9, 0); break;
				case '8': map_s.setTextureRect(sf::IntRect(60, 130, 70, 60)); map_s.setOrigin(9, 0); break;
				case ' ':  map_s.setTextureRect(sf::IntRect(600, 0, 60, 60));  map_s.setOrigin(0, 0); break;
					//		case 'r':  map_s.setTextureRect(sf::IntRect(325, 0, 66, 60));  map_s.setOrigin(-6, 0); break;
					//		case 't':  map_s.setTextureRect(sf::IntRect(325, 65, 66, 60));  map_s.setOrigin(-6, 0); break;
					//		case 's':  map_s.setTextureRect(sf::IntRect(325, 130,66, 40));  map_s.setOrigin(-6, 0); break;

				default:  map_s.setTextureRect(sf::IntRect(0, 0, 60, 60));  map_s.setOrigin(0, 0); break;
				}
				map_s.setPosition(int((i - i_0) * 60), int((j - j_0) * 60));
				bg_texture.draw(map_s);

			}
		}


	Draw_Elements();

	bg_texture.display();
	last_map_pos[0] = round(V_c.x/60);
	last_map_pos[1] = round(V_c.y/ 60);	//last_map_pos[1] = round(V_c.y);
};

sf::Vector2i Map::Get_Last_Pos()
{
	return sf::Vector2i(last_map_pos[0],last_map_pos[1]);
}

bool Map::IsMapChanged()
{//оптимизация - когда стоишь не перерисовывается экран
	//sf::Vector2f V_c = sf::Vector2f(Player.x,Player.y);
	sf::Vector2f V_c = data.Get_Screen_Pos();
	cout << endl << last_map_pos[0] << "  " << round(V_c.x) << " y   " << last_map_pos[1] << "   " << round(V_c.y);
return ((last_map_pos[0] != round(V_c.x/60) ) || (last_map_pos[1] != round(V_c.y/60) ));
//return true;
}



