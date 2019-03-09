#pragma once 
#include <SFML/Graphics.hpp>
#include "General_Data.h"
#include "Camera.h"
#include <set>

 class Map
{
	int MapHeight = 25;
	
	// Character& Player;

	sf::RenderTexture& background_texture;
	sf::RenderWindow& window;
	General_Data& data;
public:
	string TileMap[100] = {
		//	 1234567890123456789012345678901234567890
		"01                                     0",
		"01                                     0",
		"01                                     0",
		"0000000000000000000000000000000000000000",
		"01                                     0",
		"01                                     0",
		"01                                     0",
		"01                                     0",
		"01                                     0",
		"01                                     0",
		"01                            63345  630",
		"01                            70001  700",
		"02333333333345          63333380001  700",
		"00000000000001        6380000000     700",
		"000000000000023345   68000000000     700",
		"00000000000000000233380000000000  633800",
		"01               000000           700000",
		"01                                     0",
		"01                                     0",
		"01                                     0",
		"0233333333333333333333333333333333333330",
		"0000000000000000000000000000000000000000",
		"0                                      0",
		"0                                      0",
		"0000000000000000000000000000000000000000",
	}; 
	set<char> left_wall = { '1','2' };
	set<char> ground = {  };
	set<char> right_wall = { '6','7','8' };

	int g = 4;
	Map(sf::RenderTexture&,sf::RenderWindow&, General_Data& ) ;
	void Map::DrawMap();
	void Map::DisplayMap();
	bool Map::IsMapChanged();
	
};

const int MapHeight=25;


//bool InteractionWithMapX(sf::RenderWindow& window, sf::Vector2f V, sf::Vector2f S, float width, float height, float delta);
//bool InteractionWithMapY(sf::RenderWindow& window, sf::Vector2f V, sf::Vector2f S, float dy, bool dir,float time);