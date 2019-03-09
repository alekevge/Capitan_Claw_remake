#include "Camera.h"
using namespace std;
 sf::View camera;


//void CameraGoForHero(float x,float y)
//{
//	sf::Vector2f V_s = camera.getSize();
//	sf::Vector2f V_c = camera.getCenter();
//	if (x < (V_s.x / 2 - 100) || y < (V_s.y) / 2 + 70)
//	{
//		if (x < (V_s.x / 2 - 100) && !(y < (V_s.y) / 2 + 70)) camera.setCenter(sf::Vector2f(V_c.x, y-70));
//		
//		if (!(x < (V_s.x / 2 - 100)) && (y < (V_s.y) / 2 + 70)) camera.setCenter(sf::Vector2f(x+100, V_c.y));
//		/*if (x <= (V.x / 2 - 100) && y > (V.y) / 2 + 70) camera.setCenter(sf::Vector2f(x, V.y));
//
//		if (y <= (V.y) / 2 + 70  && x > (V.x / 2 - 100)) camera.setCenter(sf::Vector2f(V.x, y));*/
//
//	
//	}
//	else camera.setCenter(sf::Vector2f(x + 100, y - 70));
//
//
//}