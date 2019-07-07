#pragma once 
#include <SFML/Graphics.hpp>
#include "General_Data.h"
#include "Camera.h"
#include <set>
#include "Upstairs.h"

 class Map
{

	
	// Character& Player;

	sf::RenderTexture& background_texture;
	sf::RenderTexture map_texture;
	sf::RenderWindow& window;
	General_Data& data;
public:
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
		"01                                       70           0",
		"01                                       70           0",
		"01                                       70           0",
		"01                 r                     70           0",
		"01                 t           63345  63380           0",
		"023333333345       t           70001  7000            0",
		"00000000000245     s     63333380001  70              0",
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
	Map(sf::RenderTexture&,sf::RenderWindow&, General_Data& ) ;

	void Map::DrawMap();
	void Map::Draw_Elements();
	bool Map::IsMapChanged();
	Up_Stair stair;
	bool Map::Check_();
};

const int MapHeight=34;


//bool InteractionWithMapX(sf::RenderWindow& window, sf::Vector2f V, sf::Vector2f S, float width, float height, float delta);
//bool InteractionWithMapY(sf::RenderWindow& window, sf::Vector2f V, sf::Vector2f S, float dy, bool dir,float time);