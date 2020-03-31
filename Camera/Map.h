#pragma once 
#include <SFML/Graphics.hpp>
#include "General_Data.h"
#include "Camera.h"
#include <set>
#include "Upstairs.h"


 class Map
{

	
	// Character& Player;

	sf::RenderTexture& background_texture_1;

	sf::RenderTexture& background_texture_2;
	sf::RenderTexture map_texture;
	sf::RenderWindow& window;
	General_Data& data;
public:
	sf::Vector2i buffer_background_texture = sf::Vector2i (1, 1);
	const float sizeMapX = 60.;
	const float sizeMapY = 60.;

	bool toogle_bg_tex = false;

	string TileMap[100] = {
		//	 1234567890123456789012345678901234567890
		"01                                                    0",
		"01                                                    0",
		"01                                                    0",
		"01                                                    0",
		"01                                                    0",
		"01                                                    0",
		"01                                                    0",
		"01                                                    0",
		"0000000000000000000000000000000000000000000000      000",
		"01                                       70           0",
		"01                                       70           0",
		"01                              r        70           0",
		"01                              t        70           0",
		"01                              t        70           0",
		"01                              s        70           0",
		"01                             63345  63380           0",
		"023333333345                   70001  7000            0",
		"00000000000245           63333380001  70              0",
		"00000000000001         6380000000     70              0",
		"0000   00000023345   638000000000     70              0",
		"0000   00000000002333800000000001  63380              0",
		"01               000000         1  70000              0",
		"01                              1                     0",
		"01                              1                     0",
		"01                              1                     0",
		"0233   33333333333333333333333331                 33330",
		"0000   00000000000000000000000001                 00000",
		"0                               1                    70",
		"0                               1                    70",
		"0                               1                    70",
		"0                               1                    70",
		"0                               1                    70",
		"0233333333333333333333333333333323333333333333333333380",
		"0000000000000000000000000000000000000000000000000000000",
	}; 
	set<char> left_wall = { '1','2' };
	set<char> ground = {  };
	set<char> right_wall = { '6','7','8' };

	int g = 4;


	Map(sf::RenderTexture&, sf::RenderTexture&,sf::RenderWindow&, General_Data& ) ;

	sf::Sprite  sprite_buffer[10];


	void Map::DrawMap_new();

	void Map::DrawMap(sf::RenderTexture&,float,float);
	void Map::DrawMap_save(sf::RenderTexture&);
	void Map::DrawMap_async(sf::RenderTexture&);
	void Map::Draw_Elements();
	void Map::Init();
	bool Map::IsMapChanged();
	sf::Vector2i Get_Last_Pos();
	Up_Stair stair;
	bool Map::Check_();


	int all_stairs_length;
//	Up_Stair **all_stairs;
	vector<Up_Stair> all_stairs;
};

const int MapHeight=34;


//bool InteractionWithMapX(sf::RenderWindow& window, sf::Vector2f V, sf::Vector2f S, float width, float height, float delta);
//bool InteractionWithMapY(sf::RenderWindow& window, sf::Vector2f V, sf::Vector2f S, float dy, bool dir,float time);