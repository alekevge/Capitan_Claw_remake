#include "Upstairs.h"

using namespace std;

Up_Stair::Up_Stair(float x, float y, int height, sf::RenderTexture& bg_texture 
	
	,sf::Texture& map_t, General_Data& data):
	height(height), bg_texture(bg_texture),map_t(map_t),general_data(data)
{
	pos.x = x;
	pos.y = y;
	map_s.setTexture(map_t);
	
	sf::Sprite s_1;
	s_1.setTexture(map_t);
	s_1.setTextureRect(sf::IntRect(325, 0, 66, 60));
	s_1.setOrigin(0, 0);
	sprite_buffer[0] = s_1;

	
}



void Up_Stair::Draw()
{
	// << "DRAW_ STAIR";
	sf::Vector2f V_s = camera.getSize();
	sf::Vector2f cam_pos = general_data.Get_Screen_Pos();
	int j_0 = int((cam_pos.y - 0.5*V_s.y) / 60);

	map_s.setTextureRect(sf::IntRect(325, 0, 66, 60));  map_s.setOrigin(0, 0);
	float r = general_data.Get_Screen_Pos().x - int(general_data.Get_Screen_Pos().x / 60) * 60;
	 
	sprite_buffer[0].setPosition(sf::Vector2f((pos.x - cam_pos.x + V_s.x / 2 +  r), (pos.y - j_0 * 60)));
//	cout << endl << "stairx" << (pos.x - cam_pos.x + V_s.x / 2 + 0 * r) << "  " << (pos.y - j_0 * 60);
	bg_texture.draw(sprite_buffer[0]);
	for (int i = 1; i < height; i++)
	{
	    map_s.setTextureRect(sf::IntRect(325, 65, 66, 60));  map_s.setOrigin(0, 0); 
		map_s.setPosition(sf::Vector2f((pos.x-cam_pos.x+ V_s.x/2+r), (pos.y -j_0*60+i*60)));
		bg_texture.draw(map_s);

	}

	 map_s.setTextureRect(sf::IntRect(325, 130, 66, 40)); 
	 map_s.setOrigin(0, 0);
	 map_s.setPosition(sf::Vector2f(round(pos.x - cam_pos.x + V_s.x / 2 + r), round( pos.y - j_0 * 60 + height * 60)));
	 bg_texture.draw(map_s);


}
boolean Up_Stair::Camera_edge(float x,float y)
{
	sf::Vector2f cam_size = camera.getSize();
	sf::Vector2f cam_pos = general_data.Get_Screen_Pos();
	return  (x > cam_pos.x - cam_size.x / 2) && (x < cam_pos.x + cam_size.x / 2) &&
			(y > cam_pos.y - cam_size.y / 2) && (y < cam_pos.y + cam_size.y / 2);

}
boolean Up_Stair::Visibility()
{

	return   (Camera_edge(pos.x, pos.y) || Camera_edge(pos.x + 60, pos.y)
		   || Camera_edge(pos.x, pos.y + height * 60) 
		   || Camera_edge(pos.x + 60, pos.y + height * 60));

}

boolean Up_Stair::Interaction()
{
	return true;
}


boolean Up_Stair::Active(float x,float y)
{

	boolean a = x>pos.x&&x<pos.x+60 ;// pos.y<y + 100 && pos.y>y - 100;
	return a;
}

sf::Vector2f Up_Stair::Attach()
{
	sf::Vector2f cam_pos = general_data.Get_Screen_Pos();
	sf::Vector2f V_s = camera.getSize();
	float r = general_data.Get_Screen_Pos().x - int(general_data.Get_Screen_Pos().x) / 60 * 60;
//	cout << endl << "UP_POS" << cam_pos.x - V_s.x / 2 - pos.x  /*- cam_pos.x + V_s.x / 2 + r*/ << pos.y;
//cout << endl << "UP_POS" << pos.x - cam_pos.x + V_s.x / 2;
	//	getchar();
	pos.y + height * 60;
	return  sf::Vector2f(pos.x - cam_pos.x + V_s.x / 2+20, pos.y + height * 60 - cam_pos.y + V_s.y/2-32 );
}