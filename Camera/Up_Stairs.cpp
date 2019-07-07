#include "Upstairs.h"

using namespace std;

Up_Stair::Up_Stair(float x, float y, int height, sf::RenderTexture& bg_texture 
	
	,sf::Texture& map_t, General_Data& data):
	height(height), bg_texture(bg_texture),map_t(map_t),general_data(data)
{
	pos.x = x;
	pos.y = y;
	map_s.setTexture(map_t);
}



void Up_Stair::Draw()
{
	sf::Vector2f V_s = camera.getSize();
	sf::Vector2f cam_pos = general_data.Get_Screen_Pos();
	int j_0 = int((cam_pos.y - 0.5*V_s.y) / 60);

	map_s.setTextureRect(sf::IntRect(325, 0, 66, 60));  map_s.setOrigin(0, 0);
	float r = general_data.Get_Screen_Pos().x - int(general_data.Get_Screen_Pos().x) / 60 * 60;
	 
	map_s.setPosition(pos.x - cam_pos.x + V_s.x/2 + r, pos.y -j_0*60 );
	bg_texture.draw(map_s);
	for (int i = 1; i < height; i++)
	{
		
	  map_s.setTextureRect(sf::IntRect(325, 65, 66, 60));  map_s.setOrigin(0, 0); 
		map_s.setPosition(pos.x-cam_pos.x+ V_s.x/2+r, pos.y -j_0*60+i*60);
		bg_texture.draw(map_s);

	}

	 map_s.setTextureRect(sf::IntRect(325, 130, 66, 40)); 
	 map_s.setOrigin(0, 0);
	 map_s.setPosition(pos.x - cam_pos.x + V_s.x / 2 + r, pos.y - j_0 * 60 + height * 60);
	 bg_texture.draw(map_s);

	bg_texture.display();

}