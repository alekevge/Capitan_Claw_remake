#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>
#include "Map.h"
#include "AnimationMainHero.h"
//#include "Camera.h"
#include "General_Data.h"
#include "Control.h"
#include "windows.h"
#include <future>





void ProcessResult(int s)
{
	cout<<endl <<"process_result " <<s
		;
	getchar();
}

void waiting_()
{
	cout<<endl << "waiting";
}
int called_from_async(int i) {
	cout << endl << "Async call" << i;

	Sleep(1000);

	return 6;
}

int main_async_work()
{

	bool key = true;
	int i = 0;
	while (key == true)
	{
		cout << "start";
		getchar();
		auto r = async(launch::async, [&] {return called_from_async(5); });
	//	r.wait_until(future_status::ready);
		cout << endl << "status" << (r.wait_for(chrono::seconds(0)) == future_status::timeout);

		while (r.wait_for(chrono::seconds(0)) == future_status::timeout/*&&r.wait_for(chrono::seconds(0))!=future_status::timeout*/)
		{
		
			//cout << endl << "valid  " << r.valid();
			waiting_();
			Sleep(3000);
			cout << endl<<"status" << (r.wait_for(chrono::seconds(0))==future_status::deferred);
		}	cout << endl << "valid_end " << r.valid();
		cout << endl << "status_end" << (r.wait_for(chrono::seconds(0)) == future_status::timeout);

		ProcessResult(r.get());
	//	cout << endl << "valid_end " << r._Get_value();
		i++;
		if (i == 3) key = false;
	}


	return 0;
}







int main__()
{
	sf::RenderTexture background_texture;
	background_texture.create(1200, 1000);
	bool count = false;
	sf::Sprite background_sprite, background_sprite_temp;
	background_sprite.setTexture(background_texture.getTexture());
	background_sprite_temp.setTexture(background_texture.getTexture());
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
	camera.reset(sf::FloatRect(0, 0, 1200, 800));
	float time, counter, tx, tz;
	counter = 0;
	counter = GetTickCount();
	sf::View my_view(sf::FloatRect(0, 0, 1200, 800));
	General_Data general_data = General_Data(600., 470., window);
	window.setFramerateLimit(90);
	//	window.setVerticalSyncEnabled(true);
	Map map(background_texture, background_texture, window, general_data);
	Character Player = Character(1, time, general_data, map);
	sf::Clock gl_clock;
	sf::Clock clock;
	bool pr = false;

	Control controls = Control(Player, general_data, gl_clock);
	state State = standing;
	float runspeed = 0.007;
	//	InitMap(background_texture);
//	Entity en(400, 300, 0, 0);
	sf::Time updateTime;

	float last[2] = {0, 0};
	auto	r = async(launch::async, [&] { return called_from_async(5); });

//	while (window.isOpen()) {
//		// Event handling is performed here
//
//		// Determine the time that passed
//		sf::Time delta = clock.restart();
//		bool t = false;
//		updateTime += delta; // add up previous leftover time
//
//		int IIIAG = 2;
//		int loops = std::min<int>((int)(updateTime / sf::milliseconds(IIIAG)), IIIAG); // determine the number of iterations to do (100 fps; capped at 10)
//		while (loops--)
//		{
//			en.update(IIIAG);
//	//		if (loops%2==0)
//			{
//			
//				window.clear();
//				// rendering
//en.render(window);
//				window.display();
//			}
//
//			//	updateSingleStep(); // update by one fixed timestep
//		}
//        updateTime %= sf::milliseconds(IIIAG); // drop leftover frames
//
//		en.update(updateTime.asMilliseconds()/* / 10*/); // update based on time passed
//		
//		window.clear();
//		// rendering
//		en.render(window);
//		window.display();		//sf::sleep(sf::microseconds(10));
//		sf::sleep(sf::microseconds(IIIAG));
//		// sleep a minimum amount of time to ensure there's always at least some delta time (assuming very, very fast CPUs).
//	}


	while (window.isOpen())

	{
	sf::Event e;

	counter = GetTickCount();
	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	time /= 800;



	while (window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
			window.close();
	}
	


	controls.control();
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		Player.ResetFrame();
		if (Player.Status == test) Player.test_();
		Player.Status = test;
	}

		



	/*	if (r.wait_for(chrono::seconds(0)) == future_status::timeout)
		{
					cout<<endl << "waiting"<<r.valid();
		}
		else
		{
	
			r = async(launch::async, [&] {  map.DrawMap_save(background_texture); return 0;	 });
		}*/

//		ProcessResult(r.get());

//	if (map.IsMapChanged())
	//{	
	//	


	//	map.DrawMap_save(background_texture);	
	//

	//				
	//}


	int delta = -40;
//	tx = (general_data.Get_Screen_Pos().x) - trunc((map.Get_Last_Pos().x)*60 / 60) * 60;
//	tz = (general_data.Get_Screen_Pos().y) + delta - trunc((map.Get_Last_Pos().y*60 + delta) / 60) * 60;
//	tx = (general_data.Get_Screen_Pos().x) - trunc((map.Get_Last_Pos().x)  / 60) * 60;
//	tz = (general_data.Get_Screen_Pos().y) + delta - trunc((map.Get_Last_Pos().y  + delta) / 60) * 60;

	if ("async" == "async")
	{

		if (r.wait_for(chrono::seconds(0)) == future_status::timeout)
		{
			cout << endl << "waiting" << r.valid();


		}
		else
		{
			if (trunc(general_data.Get_Screen_Pos().x/60)!=int(map.Get_Last_Pos().x/60)
				|| trunc(general_data.Get_Screen_Pos().y / 60) != int(map.Get_Last_Pos().y / 60)
				//&& (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
				)
				r = async(launch::async, [&] {  map.DrawMap_save(background_texture); return 0;	 });
//ввести ограничение на перерисовку через move и при delta >1
		}
	//	tx = (general_data.Get_Screen_Pos().x) -round((general_data.Get_Screen_Pos().x) / 60) * 60;
//		tz = (general_data.Get_Screen_Pos().y) + delta - round((general_data.Get_Screen_Pos().y + delta) / 60) * 60;


		

		cout << endl << "waiting_else y " << general_data.Get_Screen_Pos().x << " - " << map.Get_Last_Pos().x << " = " <<
			general_data.Get_Screen_Pos().x - map.Get_Last_Pos().x;
	//	tx += /*roundf*/(-general_data.Get_Screen_Pos().x + map.Get_Last_Pos().x);
	//	tz += /*roundf*/(-general_data.Get_Screen_Pos().y + map.Get_Last_Pos().y);

	
		//	tx = (general_data.Get_Screen_Pos().x) - int((map.Get_Last_Pos().x) / 60) * 60;
		//	tz = (general_data.Get_Screen_Pos().y) + delta - int((map.Get_Last_Pos().y + delta) / 60) * 60;

		//tx += map.buffer_background_texture.x*map.sizeMapX;
		//	tz += map.buffer_background_texture.y*map.sizeMapY;
	//	tx += map.buffer_background_texture.x*map.sizeMapX;
	//	tz += map.buffer_background_texture.y*map.sizeMapY + 0 * delta;
	
		
		tx = int(map.Get_Last_Pos().x) % 60 ;
		tz = int(map.Get_Last_Pos().y + 20)%60 ;

		
		
		
		tx += general_data.Get_Screen_Pos().x - map.Get_Last_Pos().x;
		tz += general_data.Get_Screen_Pos().y - map.Get_Last_Pos().y;
		tx += map.buffer_background_texture.x*map.sizeMapX;
		tz += map.buffer_background_texture.y*map.sizeMapY  ;
		
		tx = /*trunc*/(tx);
		tz = /*trunc*/(tz);

	
		if (tx - last[0] >= 1 || tx - last[0] <= -1
			|| tz - last[1] >= 1 || tz - last[1] <= -1)
		{
			background_sprite.setPosition(sf::Vector2f(round(-(tx/*-last[0]*/)), 
				round(-(tz/*-last[1]*/))));
			last[0] = tx;
			last[1] = tz;
		
		}

	
	}
	else
	{
		
		if (trunc(general_data.Get_Screen_Pos().x / 60) != int(map.Get_Last_Pos().x / 60)
			|| trunc(general_data.Get_Screen_Pos().y / 60) != int(map.Get_Last_Pos().y / 60))
		map.DrawMap_save(background_texture);
		
		
		
		tx = (general_data.Get_Screen_Pos().x) - int((map.Get_Last_Pos().x) / 60) * 60;
			tz = (general_data.Get_Screen_Pos().y) + delta - int((map.Get_Last_Pos().y + delta) / 60) * 60;
		tx += map.buffer_background_texture.x*map.sizeMapX;
		tz += map.buffer_background_texture.y*map.sizeMapY + 0 * delta;
	//	background_sprite.setPosition(sf::Vector2f(round(-tx), round(-tz)));
		float d = 1;
		
		if ((int(tx) - int(last[0])) >= d ||
			(int(tx) - int(last[0]) <= -d) ||
			(int(tz) - int(last[1]) >= d) ||
			(int(tz) - int(last[1]) <= -d))

	//	if (tx - last[0] >= d || tx - last[0] <= -d
	//		|| tz - last[1] >= d || tz - last[1] <= -d)
		{
			
			background_sprite.setPosition(sf::Vector2f(round(-(tx)), round(-(tz ))));

			//cout << endl << "time  " << int(tz) - int(last[1])<< " "<<
				//int(tx) - int(last[0]);

			last[0] = tx;
			last[1] = tz;
		}

	
	
	}


	
	window.clear();

//	background_sprite.setPosition(sf::Vector2f(round(-map.buffer_background_texture.x*map.sizeMapX), round(-map.buffer_background_texture.y*map.sizeMapY)));
	window.draw(background_sprite);
		
	Player.UpdateHero();
	window.draw(Player.herosprite);
	window.display();

	}
			

	return 0;

}


int main___() {
	bool key = true;
	int i = 0;
	auto	 r = async(launch::async, [&] {   return called_from_async(i);  });
	while (key)
	{
		if (i == 100)  r.get();

		i++;

		if (r.wait_for(chrono::seconds(0)) != future_status::ready)

		{


			//	key = false;
			cout << endl << "waiting"; //<< r.get();
									   //getchar();
									   //		r = async(launch::async, [&] {called_from_async(i);    return true; });
			i = 0;
		}



		cout << endl << "waiting" << i;


	}
	getchar();
}


struct Entity
{
	Entity(float x_l, float y_l, float vx_l, float vy_l)
	{
		x = x_l;
		y = y_l;
		vx = vx_l;
		vy = vy_l;
		tex.loadFromFile("Images\\PC Computer - Captain Claw - Level 1 Tiles_2.png");
		tex.setSmooth(false);

		sprite.setTexture(tex);
		sprite.setTextureRect(sf::IntRect(130, 65, 600, 600));
		sprite.setOrigin(0, 0);
		//		sprite.setScale(1.5, 1.5);
		//		sprite.setScale(2, 2);
	}
public:
	/* Current position. */
	float x;
	float y;

	/* Velocity per unit of time. */
	float vx = 0;
	float vy;
	bool lag = false;
	sf::Sprite sprite;

	sf::Texture tex;


public:

	void update(float dt)
	{
		vy = 0;
		//vx = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (abs(vx)<2)  vx -= 0.2;
			//	vx -= 2;

		}
		else { if (vx < 0 && abs(vx)>0.2) vx += 0.2; };

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (!lag)
			{
				lag = true;

				cout << endl << "lag_ true";
			}
			if (abs(vx)<2

				)  vx += 0.2;
			//	vx += 2;
		}
		else {
			if (lag)
			{
				lag = false;
				cout << endl << "lag_ false";
			}

			if (vx > 0 && abs(vx)>0.2) vx -= 0.2;
		};



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			vy += -2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			vy += 2;
		}
		if (abs(vx)>0.2) x += vx*0.25 * dt;
		//	y += vy * dt*0.65;
		//		x += vx*dt*0.65;

		y += vy * dt*0.25;
		//	x += vx*dt*0.1;
	}

	void render(sf::RenderTarget& rt)
	{
		float x_l = sprite.getPosition().x;
		float y_l = sprite.getPosition().y;

		if (round(x_l) != round(x) || round(y_l) != round(y))
			sprite.setPosition({ round(x),round(y) });
		rt.draw(sprite);

	}
};









class Render
{
	float& time,tz,tx;
	Character& Player;
	Control controls;
	General_Data& general_data;
	Map& map;
	sf::RenderTexture& background_texture; 
	sf::Sprite& background_sprite;
	float last[2] = { 0,0 };
	sf::Clock  clock;
public:
	std::future<void> foo = std::async(launch::async, [&] { try_as(); });

	void try_as()
	{
		Sleep(5000);
	//	map.DrawMap_save(background_texture);
	}
	
	Render(float& time, Map& map,Character& Player,
		sf::RenderTexture& bg_texture, sf::Sprite& bg_sprite,
		General_Data& general_data):Player(Player),
		controls(Control(Player, general_data, clock)),time(time),
		general_data(general_data), map(map), background_texture(bg_texture),
		background_sprite(bg_sprite)
	{
	//	auto	r = async(launch::async, [&] { return 0; });
	};


	void update()
	{

		//foo = std::async(launch::async, [&] {return  });


		controls.control();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			Player.ResetFrame();
			if (Player.Status == test) Player.test_();
			Player.Status = test;
		}


		if (trunc(general_data.Get_Screen_Pos().x / 60) != int(map.Get_Last_Pos().x / 60)
			|| trunc(general_data.Get_Screen_Pos().y / 60) != int(map.Get_Last_Pos().y / 60))
			map.DrawMap_save(background_texture);

		int delta = -40;
		tz = (general_data.Get_Screen_Pos().y) + delta - int((map.Get_Last_Pos().y + 0*delta) / 60) * 60;


		tx = (general_data.Get_Screen_Pos().x) - int((map.Get_Last_Pos().x) / 60) * 60;
		tx += map.buffer_background_texture.x*map.sizeMapX;
		float d = 0.1;

	/*	if ((int(tx) - int(last[0])) >= d ||
			(int(tx) - int(last[0]) <= -d) ||
			(int(tz) - int(last[1]) >= d) ||
			(int(tz) - int(last[1]) <= -d))*/
		cout <<endl<< tz;
		{

			background_sprite.setPosition(sf::Vector2f(round(-(tx)), round(-(tz))));

			last[0] = tx;
			last[1] = tz;
		}



		


	};

};







int main_async()
{
	sf::RenderTexture background_texture;
background_texture.create(1200, 1000);
bool count = false;
sf::Sprite background_sprite, background_sprite_temp;
background_sprite.setTexture(background_texture.getTexture());
background_sprite_temp.setTexture(background_texture.getTexture());
sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
camera.reset(sf::FloatRect(0, 0, 1200, 800));
float time, counter, tx, tz;
counter = 0;
counter = GetTickCount();
sf::View my_view(sf::FloatRect(0, 0, 1200, 800));
General_Data general_data = General_Data(600., 470., window);
window.setFramerateLimit(90);
	window.setVerticalSyncEnabled(true);
Map map(background_texture, background_texture, window, general_data);
Character Player = Character(1, time, general_data, map);
sf::Clock gl_clock;
sf::Clock clock;
bool pr = false;

Control controls = Control(Player, general_data, gl_clock);
state State = standing;
float runspeed = 0.007;
//	InitMap(background_texture);
	Entity en(400, 300, 0, 0);
sf::Time updateTime;

Render render = Render(time,map,Player, background_texture,
	background_sprite,
	general_data);


float last[2] = { 0, 0 };



	while (window.isOpen()) {
		// Event handling is performed here

		// Determine the time that passed
		sf::Time delta = clock.restart();
		bool t = false;
		updateTime += delta; // add up previous leftover time

		time = 0;

		int IIIAG = 10;
		int loops = std::min<int>((int)(updateTime / sf::milliseconds(IIIAG)), 3); // determine the number of iterations to do (100 fps; capped at 10)
	
//		int loops =((int)(updateTime / sf::milliseconds(IIIAG)), IIIAG);
		while (loops--)
		{
				time =( (updateTime / sf::milliseconds(IIIAG), IIIAG)-loops)*IIIAG;

				time /= 3;

				render.update();


		



				window.clear();

				window.draw(background_sprite);

				Player.UpdateHero();
				window.draw(Player.herosprite);
				window.display();
			//	sf::sleep(sf::microseconds(3));
				sf::sleep(sf::microseconds(IIIAG));
			
		}
        
		




	time=int(	updateTime.asMilliseconds())%IIIAG ;
	{


		time /= 3;

		render.update();
	
		window.clear();

		window.draw(background_sprite);

		Player.UpdateHero();
		window.draw(Player.herosprite);
		window.display();

		sf::sleep(sf::microseconds(IIIAG));
	}

	
		sf::sleep(sf::microseconds(IIIAG));
	}
	return 0;
}


int main_2()
{
	sf::RenderTexture background_texture;
	background_texture.create(1200, 1000);
	bool count = false;
	sf::Sprite background_sprite, background_sprite_temp;
	background_sprite.setTexture(background_texture.getTexture());
	background_sprite_temp.setTexture(background_texture.getTexture());
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
	camera.reset(sf::FloatRect(0, 0, 1200, 800));
	float time, counter, tx, tz,dop_time;
	counter = 0;
	counter = GetTickCount();
	sf::View my_view(sf::FloatRect(0, 0, 1200, 800));
	General_Data general_data = General_Data(600., 470., window);
	window.setFramerateLimit(90);
	//	window.setVerticalSyncEnabled(true);
	Map map(background_texture, background_texture, window, general_data);
	Character Player = Character(1, time, general_data, map);
	sf::Clock gl_clock;
	sf::Clock clock;
	bool pr = false;

	Control controls = Control(Player, general_data, gl_clock);
	state State = standing;
	float runspeed = 0.007;

	sf::Time updateTime;

	float last[2] = { 0, 0 };
	



	while (window.isOpen())

	{
		sf::Event e;

		counter = GetTickCount();
		dop_time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time /= 800;




		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}



		controls.control();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			Player.ResetFrame();
			if (Player.Status == test) Player.test_();
			Player.Status = test;
		}



		{

			if (trunc(general_data.Get_Screen_Pos().x / 60) != int(map.Get_Last_Pos().x / 60)
				|| trunc(general_data.Get_Screen_Pos().y / 60) != int(map.Get_Last_Pos().y / 60))
				map.DrawMap_save(background_texture);


			int delta = -40;
			tz = (general_data.Get_Screen_Pos().y) + delta - int((map.Get_Last_Pos().y + delta) / 60) * 60;

			tx = (general_data.Get_Screen_Pos().x) - int((map.Get_Last_Pos().x) / 60) * 60;
			tx += map.buffer_background_texture.x*map.sizeMapX;
			float d = 1;

			if ((int(tx) - int(last[0])) >= d ||
				(int(tx) - int(last[0]) <= -d) ||
				(int(tz) - int(last[1]) >= d) ||
				(int(tz) - int(last[1]) <= -d))

					{

				background_sprite.setPosition(sf::Vector2f(round(-(tx)), round(-(tz))));

				last[0] = tx;
				last[1] = tz;
			}



		}



		window.clear();

		window.draw(background_sprite);

		Player.UpdateHero();
		window.draw(Player.herosprite);
		window.display();

	}


	return 0;

}




//if ("async" == "async")
//{
//
//	if (r.wait_for(chrono::seconds(0)) == future_status::timeout)
//	{
//		cout << endl << "waiting" << r.valid();
//
//
//	}
//	else
//	{
//		if (trunc(general_data.Get_Screen_Pos().x / 60) != int(map.Get_Last_Pos().x / 60)
//			|| trunc(general_data.Get_Screen_Pos().y / 60) != int(map.Get_Last_Pos().y / 60)
//			//&& (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
//			)
//			r = async(launch::async, [&] {  map.DrawMap_save(background_texture); return 0;	 });
//		//ввести ограничение на перерисовку через move и при delta >1
//	}
//
//
//
//
//
//
//	tx = int(map.Get_Last_Pos().x) % 60;
//	tz = int(map.Get_Last_Pos().y + 20) % 60;
//
//
//
//
//	tx += general_data.Get_Screen_Pos().x - map.Get_Last_Pos().x;
//	tz += general_data.Get_Screen_Pos().y - map.Get_Last_Pos().y;
//	tx += map.buffer_background_texture.x*map.sizeMapX;
//	tz += map.buffer_background_texture.y*map.sizeMapY;
//
//	tx = /*trunc*/(tx);
//	tz = /*trunc*/(tz);
//
//
//	if (tx - last[0] >= 1 || tx - last[0] <= -1
//		|| tz - last[1] >= 1 || tz - last[1] <= -1)
//	{
//		background_sprite.setPosition(sf::Vector2f(round(-(tx/*-last[0]*/)),
//			round(-(tz/*-last[1]*/))));
//		last[0] = tx;
//		last[1] = tz;
//
//	}
//
//
//}
//else







class Render_save
{
	float& time, tz, tx;
	Character& Player;
	Control controls;
	General_Data& general_data;
	Map& map;
	sf::RenderTexture& background_texture;
	sf::Sprite& background_sprite;
	float last[2] = { 0,0 };

public:
	Render_save(float& time, Map& map, Character& Player,
		sf::RenderTexture& bg_texture, sf::Sprite& bg_sprite,
		General_Data& general_data, sf::Clock press_clock) :Player(Player),
		controls(Control(Player, general_data, press_clock)), time(time),
		general_data(general_data), map(map), background_texture(bg_texture),
		background_sprite(bg_sprite)
	
	{
	};


	bool update()
	{
		controls.control();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			Player.ResetFrame();
			if (Player.Status == test) Player.test_();
			Player.Status = test;
		}


		if (trunc(general_data.Get_Screen_Pos().x / 60) != int(map.Get_Last_Pos().x / 60)
			|| trunc(general_data.Get_Screen_Pos().y / 60) != int(map.Get_Last_Pos().y / 60))
		{
			map.DrawMap_save(background_texture);
		}
			int delta = -40;
			tz = (general_data.Get_Screen_Pos().y) + delta - int((map.Get_Last_Pos().y + delta) / 60) * 60;


			tx = (general_data.Get_Screen_Pos().x) - int((map.Get_Last_Pos().x) / 60) * 60;
			tx += map.buffer_background_texture.x*map.sizeMapX;
			float d = 1;

			if ((int(tx) - int(last[0])) >= d ||
				(int(tx) - int(last[0]) <= -d) ||
				(int(tz) - int(last[1]) >= d) ||
				(int(tz) - int(last[1]) <= -d))

			{

				background_sprite.setPosition(sf::Vector2f(round(-(tx)), round(-(tz))));

				last[0] = tx;
				last[1] = tz;
				return true;
			}
			else return false;


		


	};

};

int main___1()
{
	sf::RenderTexture background_texture;
	background_texture.create(1200, 1000);
	bool count = false;
	sf::Sprite background_sprite, background_sprite_temp;
	background_sprite.setTexture(background_texture.getTexture());
	background_sprite_temp.setTexture(background_texture.getTexture());
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
	camera.reset(sf::FloatRect(0, 0, 1200, 800));
	float time, counter, tx, tz;
	counter = 0;
	counter = GetTickCount();
	sf::View my_view(sf::FloatRect(0, 0, 1200, 800));
	General_Data general_data = General_Data(600., 470., window);
	window.setFramerateLimit(90);
	//	window.setVerticalSyncEnabled(true);
	Map map(background_texture, background_texture, window, general_data);
	Character Player = Character(1, time, general_data, map);
	sf::Clock gl_clock;
	sf::Clock clock;
	bool pr = false;

	Control controls = Control(Player, general_data, gl_clock);
	state State = standing;
	float runspeed = 0.007;
	//	InitMap(background_texture);
	Entity en(400, 300, 0, 0);
	sf::Time updateTime;

	Render_save render = Render_save(time, map, Player, background_texture,
		background_sprite,
		general_data, gl_clock);


	float last[2] = { 0, 0 };



	while (window.isOpen()) {
		// Event handling is performed here

		// Determine the time that passed
		sf::Time delta = clock.restart();
		bool t = false;
		updateTime += delta; // add up previous leftover time

		time = 0;

		int IIIAG = 10;
		//	int loops = std::min<int>((int)(updateTime / sf::milliseconds(IIIAG)), IIIAG); // determine the number of iterations to do (100 fps; capped at 10)

		int loops = ((int)(updateTime / sf::milliseconds(IIIAG)), IIIAG);
		while (loops--)
		{

			{

				time = ((updateTime / sf::milliseconds(IIIAG), IIIAG) - loops)*IIIAG;

				time /= 3;

				if (render.update());

				{



		
					window.clear();

					window.draw(background_sprite);
				}
				Player.UpdateHero();
				window.draw(Player.herosprite);
				window.display();
				//	sf::sleep(sf::microseconds(3));
				sf::sleep(sf::microseconds(IIIAG));
			}

			//	updateSingleStep(); // update by one fixed timestep
		}


		//updateTime %= sf::milliseconds(IIIAG); // drop leftover frames
		//		time=sf::microseconds(updateTime)% sf::milliseconds(IIIAG); // drop leftover frames



		//	en.update(updateTime.asMilliseconds()/* / 10*/); // update based on time passed




		time = int(updateTime.asMilliseconds()) % IIIAG;
		{


			time /= 3;

			render.update();

			window.clear();

			window.draw(background_sprite);

			Player.UpdateHero();
			window.draw(Player.herosprite);
			window.display();

			sf::sleep(sf::microseconds(IIIAG));
		}

		//	updateSingleStep(); // update by one fixed timestep

		//	window.clear();
		// rendering
		//	en.render(window);
		//	window.display();		//sf::sleep(sf::microseconds(10));
		sf::sleep(sf::microseconds(IIIAG));
		// sleep a minimum amount of time to ensure there's always at least some delta time (assuming very, very fast CPUs).
	}
	return 0;
}




int main_last()
{
	sf::RenderTexture background_texture;
	background_texture.create(1200, 1000);
	bool count = false;
	sf::Sprite background_sprite, background_sprite_temp;
	background_sprite.setPosition(60,-50-60);
	background_sprite.setTexture(background_texture.getTexture());
	background_sprite_temp.setTexture(background_texture.getTexture());
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
	camera.reset(sf::FloatRect(0, 0, 1200, 800));
	float time, counter, tx, tz;
	counter = 0;
	counter = GetTickCount();
	sf::View my_view(sf::FloatRect(0, 0, 1200, 800));
	General_Data general_data = General_Data(600., 470., window);
	window.setFramerateLimit(90);
	//	window.setVerticalSyncEnabled(true);
	Map map(background_texture, background_texture, window, general_data);
	Character Player = Character(1, time, general_data, map);
	sf::Clock gl_clock;
	sf::Clock clock;
	bool pr = false;

	Control controls = Control(Player, general_data, gl_clock);
	state State = standing;
	float runspeed = 0.007;
	//	InitMap(background_texture);
	//	Entity en(400, 300, 0, 0);
	sf::Time updateTime;
	camera.move(0, -40);
	float last[2] = { 0, 0 };
	auto	r = async(launch::async, [&] { return called_from_async(5); });

	//	while (window.isOpen()) {
	//		// Event handling is performed here
	//
	//		// Determine the time that passed
	//		sf::Time delta = clock.restart();
	//		bool t = false;
	//		updateTime += delta; // add up previous leftover time
	//
	//		int IIIAG = 2;
	//		int loops = std::min<int>((int)(updateTime / sf::milliseconds(IIIAG)), IIIAG); // determine the number of iterations to do (100 fps; capped at 10)
	//		while (loops--)
	//		{
	//			en.update(IIIAG);
	//	//		if (loops%2==0)
	//			{
	//			
	//				window.clear();
	//				// rendering
	//en.render(window);
	//				window.display();
	//			}
	//
	//			//	updateSingleStep(); // update by one fixed timestep
	//		}
	//        updateTime %= sf::milliseconds(IIIAG); // drop leftover frames
	//
	//		en.update(updateTime.asMilliseconds()/* / 10*/); // update based on time passed
	//		
	//		window.clear();
	//		// rendering
	//		en.render(window);
	//		window.display();		//sf::sleep(sf::microseconds(10));
	//		sf::sleep(sf::microseconds(IIIAG));
	//		// sleep a minimum amount of time to ensure there's always at least some delta time (assuming very, very fast CPUs).
	//	}

	
	while (window.isOpen())

	{
		sf::Event e;

	//	if (clock.getElapsedTime().asMicroseconds() < 10000)
		//	Sleep(10000 - clock.getElapsedTime().asMicroseconds());
		if (clock.getElapsedTime().asMicroseconds() > 16000)
		{
			cout << endl << "time" << clock.getElapsedTime().asMicroseconds();
			counter = GetTickCount();
			time = clock.getElapsedTime().asMicroseconds();
			clock.restart();

			time /= 800;



			while (window.pollEvent(e))
			{
				if (e.type == sf::Event::Closed)
					window.close();
			}


		
			controls.control();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
			{
				Player.ResetFrame();
				if (Player.Status == test) Player.test_();
				Player.Status = test;
			}





			/*	if (r.wait_for(chrono::seconds(0)) == future_status::timeout)
			{
			cout<<endl << "waiting"<<r.valid();
			}
			else
			{

			r = async(launch::async, [&] {  map.DrawMap_save(background_texture); return 0;	 });
			}*/

			//		ProcessResult(r.get());

			//	if (map.IsMapChanged())
			//{	
			//	


			//	map.DrawMap_save(background_texture);	
			//

			//				
			//}


			int delta = -40;
			//	tx = (general_data.Get_Screen_Pos().x) - trunc((map.Get_Last_Pos().x)*60 / 60) * 60;
			//	tz = (general_data.Get_Screen_Pos().y) + delta - trunc((map.Get_Last_Pos().y*60 + delta) / 60) * 60;
			//	tx = (general_data.Get_Screen_Pos().x) - trunc((map.Get_Last_Pos().x)  / 60) * 60;
			//	tz = (general_data.Get_Screen_Pos().y) + delta - trunc((map.Get_Last_Pos().y  + delta) / 60) * 60;

			if ("async_" == "async")
			{

				if (r.wait_for(chrono::seconds(0)) == future_status::timeout)
				{
					cout << endl << "waiting" << r.valid();


				}
				else
				{
					if (trunc(general_data.Get_Screen_Pos().x / 60) != int(map.Get_Last_Pos().x / 60)
						|| trunc(general_data.Get_Screen_Pos().y / 60) != int(map.Get_Last_Pos().y / 60)
						//&& (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
						)
						r = async(launch::async, [&] {  map.DrawMap_save(background_texture); return 0;	 });
					//ввести ограничение на перерисовку через move и при delta >1
				}
				//	tx = (general_data.Get_Screen_Pos().x) -round((general_data.Get_Screen_Pos().x) / 60) * 60;
				//		tz = (general_data.Get_Screen_Pos().y) + delta - round((general_data.Get_Screen_Pos().y + delta) / 60) * 60;




				cout << endl << "waiting_else y " << general_data.Get_Screen_Pos().x << " - " << map.Get_Last_Pos().x << " = " <<
					general_data.Get_Screen_Pos().x - map.Get_Last_Pos().x;
				//	tx += /*roundf*/(-general_data.Get_Screen_Pos().x + map.Get_Last_Pos().x);
				//	tz += /*roundf*/(-general_data.Get_Screen_Pos().y + map.Get_Last_Pos().y);


				//	tx = (general_data.Get_Screen_Pos().x) - int((map.Get_Last_Pos().x) / 60) * 60;
				//	tz = (general_data.Get_Screen_Pos().y) + delta - int((map.Get_Last_Pos().y + delta) / 60) * 60;

				//tx += map.buffer_background_texture.x*map.sizeMapX;
				//	tz += map.buffer_background_texture.y*map.sizeMapY;
				//	tx += map.buffer_background_texture.x*map.sizeMapX;
				//	tz += map.buffer_background_texture.y*map.sizeMapY + 0 * delta;


				tx = int(map.Get_Last_Pos().x) % 60;
				tz = int(map.Get_Last_Pos().y + 20) % 60;




				tx += general_data.Get_Screen_Pos().x - map.Get_Last_Pos().x;
				tz += general_data.Get_Screen_Pos().y - map.Get_Last_Pos().y;
				tx += map.buffer_background_texture.x*map.sizeMapX;
				tz += map.buffer_background_texture.y*map.sizeMapY;

				tx = /*trunc*/(tx);
				tz = /*trunc*/(tz);


				if (tx - last[0] >= 1 || tx - last[0] <= -1
					|| tz - last[1] >= 1 || tz - last[1] <= -1)
				{
					background_sprite.setPosition(sf::Vector2f(round(-(tx/*-last[0]*/)),
						round(-(tz/*-last[1]*/))));
					last[0] = tx;
					last[1] = tz;

				}


			}
			else
			{

				if (trunc(general_data.Get_Screen_Pos().x / 60) != int(map.Get_Last_Pos().x / 60)
					|| trunc(general_data.Get_Screen_Pos().y / 60) != int(map.Get_Last_Pos().y / 60))
				{
					map.DrawMap_save(background_texture);
				//	camera.move( - last[0], roun- last[1]);
				}


				tx = (general_data.Get_Screen_Pos().x) - int((map.Get_Last_Pos().x) / 60) * 60;
				tz = (general_data.Get_Screen_Pos().y) + delta - int((map.Get_Last_Pos().y + delta) / 60) * 60;
				tx += map.buffer_background_texture.x*map.sizeMapX;

				tx += map.buffer_background_texture.x*map.sizeMapX;
				tz += map.buffer_background_texture.y*map.sizeMapY + 0 * delta;
				//	background_sprite.setPosition(sf::Vector2f(round(-tx), round(-tz)));
				float d = 1;

				if ((int(tx) - int(last[0])) >= d ||
					(int(tx) - int(last[0]) <= -d) ||
					(int(tz) - int(last[1]) >= d) ||
					(int(tz) - int(last[1]) <= -d))

					//	if (tx - last[0] >= d || tx - last[0] <= -d
					//		|| tz - last[1] >= d || tz - last[1] <= -d)
				{
					camera.move(round(tx)-last[0], round(tz)-last[1]);
					camera.setCenter(round(tx)+600,400+ round(tz));
					//background_sprite.setPosition(sf::Vector2f(round(-(tx)), round(-(tz))));

					//cout << endl << "time  " << int(tz) - int(last[1])<< " "<<
					//int(tx) - int(last[0]);

					last[0] = tx;
					last[1] = tz;
				}



			}


			window.setView(camera);
			window.clear();

			//	background_sprite.setPosition(sf::Vector2f(round(-map.buffer_background_texture.x*map.sizeMapX), round(-map.buffer_background_texture.y*map.sizeMapY)));
			window.draw(background_sprite);

			Player.UpdateHero();
			window.draw(Player.herosprite);
			window.display();
		}
	}


	return 0;

}

int main6()
{
	sf::RenderTexture background_texture;
	background_texture.create(1200, 1000);
	bool count = false;
	int fps = 0;
	sf::Sprite background_sprite;
	background_sprite.setTexture(background_texture.getTexture());
	int con = 0;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
	camera.reset(sf::FloatRect(0, 0, 1200, 800));
//	camera.setCenter(1000*1.f, 400*1.f);
	window.setView(camera);
	float time, counter, tx, tz;
	counter = 0;
	counter = GetTickCount();
	General_Data general_data = General_Data(600., 470., window);
	window.setFramerateLimit(90);
		window.setVerticalSyncEnabled(true);
	Map map(background_texture, background_texture, window, general_data);
	Character Player = Character(1, time, general_data, map);
	sf::Clock gl_clock;
	sf::Clock clock,fps_clock;
	bool pr = false;

	Control controls = Control(Player, general_data, gl_clock);
	state State = standing;
	float runspeed = 0.007;
	//	InitMap(background_texture);
	//	Entity en(400, 300, 0, 0);
	sf::Time updateTime;

	float last[2] = { 0, 0 };
	background_sprite.setScale(1.3, 1.3);


	while (window.isOpen())

	{
		sf::Event e;
		//cout << endl << "time"<< clock.getElapsedTime().asMicroseconds();
		if (clock.getElapsedTime().asMilliseconds() > int(1000/60))
		{
		counter = GetTickCount();
		time = clock.getElapsedTime().asMicroseconds();
		fps++;
		if (fps_clock.getElapsedTime().asMilliseconds() > 1000)
		{
			fps_clock.restart();
			cout << endl << fps;
			fps = 0;
			
		}
		clock.restart();
			time /= 800;



			while (window.pollEvent(e))
			{
				if (e.type == sf::Event::Closed)
					window.close();
			}



			controls.control();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
			{
				Player.ResetFrame();
				if (Player.Status == test) Player.test_();
				Player.Status = test;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
			{
				con = 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
			{
				con = -1;
			}


			int delta = -40;





			if (trunc(general_data.Get_Screen_Pos().x / 60) != int(map.Get_Last_Pos().x / 60)
				|| trunc(general_data.Get_Screen_Pos().y / 60) != int(map.Get_Last_Pos().y / 60))
				map.DrawMap_save(background_texture);



			tx = (general_data.Get_Screen_Pos().x) - int((map.Get_Last_Pos().x) / 60) * 60;
			tz = (general_data.Get_Screen_Pos().y) + delta - int((map.Get_Last_Pos().y + delta) / 60) * 60;
			tx += map.buffer_background_texture.x*map.sizeMapX;
			tz += map.buffer_background_texture.y*map.sizeMapY + 0 * delta;
			//	background_sprite.setPosition(sf::Vector2f(round(-tx), round(-tz)));
			float d = 1;

			if ((int(tx) - int(last[0])) >= d ||
				(int(tx) - int(last[0]) <= -d) ||
				(int(tz) - int(last[1]) >= d) ||
				(int(tz) - int(last[1]) <= -d))

			{

				background_sprite.setPosition(sf::Vector2f(round(-(tx)), round(-(tz))));



				last[0] = tx;
				last[1] = tz;
			}
	
		

			
		//	if (con == 10)
			{
				camera.setCenter((int)camera.getCenter().x+0,(int) camera.getCenter().y+con);
			//	camera.move(0, con);
			//	con = 0;
			}
			window.setView(camera);
			window.clear();
			
			//	background_sprite.setPosition(sf::Vector2f(round(-map.buffer_background_texture.x*map.sizeMapX), round(-map.buffer_background_texture.y*map.sizeMapY)));
			window.draw(background_sprite);

			Player.UpdateHero();
			window.draw(Player.herosprite);
			window.display();
		}
		
	}

	return 0;

}


int main_smooth()
{
	sf::RenderTexture background_texture;
	background_texture.create(1200, 1000);
	bool count = false;
	int fps = 0;
	sf::Texture tex;
	sf::Sprite background_sprite,sprite;
	background_sprite.setTexture(background_texture.getTexture());
	int con = 0;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
	camera.reset(sf::FloatRect(0, 0, 1200, 800));
	//	camera.setCenter(1000*1.f, 400*1.f);
	window.setView(camera);
	float time, counter, tx, tz;
	counter = 0;
	counter = GetTickCount();
window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(false);
	sf::Clock gl_clock;
	sf::Clock clock, fps_clock;
	bool pr = false;

	float runspeed = 0.007;
	//	InitMap(background_texture);
	//	Entity en(400, 300, 0, 0);
	sf::Time updateTime;

	float last[2] = { 0, 0 };

	tex.loadFromFile("Images\\PC Computer - Captain Claw - Level 1 Tiles_2.png", sf::IntRect(130, 65, 600, 600));
	tex.setSmooth(true);
//sprite.setScale(1.3, 1.3);
	sprite.setTexture(tex);
	sprite.setTextureRect(sf::IntRect(0, 0, 600, 600));
	sprite.setOrigin(0, 0);
	window.draw(sprite);
	sf::Sprite ar[30] = {};
//	sprite.setTextureRect(sf::IntRect(0, 0, 66, 60));  sprite.setOrigin(0, 0);

	while (window.isOpen())

	{
		sf::Event e;
		//cout << endl << "time"<< clock.getElapsedTime().asMicroseconds();
	//	if (clock.getElapsedTime().asMilliseconds() > int(1000 / 60))
		{
			counter = GetTickCount();
			time = clock.getElapsedTime().asMicroseconds();
			fps++;
			if (fps_clock.getElapsedTime().asMilliseconds() > 1000)
			{
				fps_clock.restart();
				cout << endl << fps;
				fps = 0;

			}
			clock.restart();
			time /= 800;



			while (window.pollEvent(e))
			{
				if (e.type == sf::Event::Closed)
					window.close();
			}



		

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
			{
				con =1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
			{
				con = -1;
			}

		
			{
				camera.setCenter(round(camera.getCenter().x + 0), round(camera.getCenter().y + con));
		
			}

			if ((int)camera.getCenter().y == (int)camera.getCenter().y + con)
				cout << endl << "int "<< (int)camera.getCenter().y;
				//		sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y+con);
			window.clear();

	//		window.draw(sprite);
			window.draw(sprite);

			window.setView(camera);
		//	window.clear();
	
	
			window.display();
		
		}

	}

	return 0;

}




int main__this()
{
	sf::RenderTexture background_texture;
	background_texture.create(1200, 1000);
	bool count = false;
	int fps = 0,last_fps=0;
	sf::Texture tex;
	sf::Sprite background_sprite, sprite;
	background_sprite.setTexture(background_texture.getTexture());
	int con = 0;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
	camera.reset(sf::FloatRect(0, 0, 1200, 800));
	//	camera.setCenter(1000*1.f, 400*1.f);
	window.setView(camera);
	float time, counter, tx, tz;
	counter = 0;
	counter = GetTickCount();
//	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(false);
	sf::Clock gl_clock;
	sf::Clock clock, fps_clock;
	bool pr = false;

	float runspeed = 0.007;
	//	InitMap(background_texture);
	//	Entity en(400, 300, 0, 0);
	sf::Time updateTime;

	float last[2] = { 0, 0 };

	tex.loadFromFile("Images\\PC Computer - Captain Claw - Level 1 Tiles_2.png", sf::IntRect(130, 65, 600, 600));
	tex.setSmooth(true);
	//sprite.setScale(1.3, 1.3);
	sprite.setTexture(tex);
	sprite.setTextureRect(sf::IntRect(0, 0, 600, 600));
	sprite.setOrigin(0, 0);
	window.draw(sprite);
	sf::Sprite ar[30] = {};
	//	sprite.setTextureRect(sf::IntRect(0, 0, 66, 60));  sprite.setOrigin(0, 0);

	while (window.isOpen())

	{
		sf::Event e;
		//cout << endl << "time"<< clock.getElapsedTime().asMicroseconds();
		if (clock.getElapsedTime().asMilliseconds() > int(1000 / 60))
		{
			counter = GetTickCount();
			time = clock.getElapsedTime().asMicroseconds();
			fps++;
			if (fps_clock.getElapsedTime().asMilliseconds() > 1000)
			{
				fps_clock.restart();

				if (fps != last_fps)
				{
					cout << endl << fps;
					last_fps = fps;
				}

				fps = 0;

			}
			//	clock.restart();
			time /= 800;



			while (window.pollEvent(e))
			{
				if (e.type == sf::Event::Closed)
					window.close();
			}





			if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
			{
				con = 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
			{
				con = -1;
			}






			sf::Time delta = clock.restart();
			bool t = false;
			updateTime = delta; // add up previous leftover time

			time = 0;

			int IIIAG = 16;
			int loops = std::min<int>((int)(updateTime / sf::milliseconds(IIIAG)), 4); // determine the number of iterations to do (100 fps; capped at 10)
			int max = loops;
			//	cout << endl<<"re"<<updateTime.asMilliseconds()/IIIAG;
			if (loops > 0)	
			{
				//		int loops =((int)(updateTime / sf::milliseconds(IIIAG)), IIIAG);
				while (loops--)
				{
					time = (max - loops)*IIIAG;

					time /= 3;

					camera.setCenter((camera.getCenter().x + 0), (camera.getCenter().y + con));



					window.clear();

					window.draw(sprite);

					window.setView(camera);


					window.display();
					//	sf::sleep(sf::microseconds(3));
					if (loops > 0)
						{
							cout << endl << "loops" << loops;

							sf::sleep(sf::microseconds(IIIAG / 3));

						}
				}





				time = int(updateTime.asMilliseconds()) % IIIAG;

			}
			else time = int(updateTime.asMilliseconds());





			


				/*time /= 3;

				camera.setCenter(round(camera.getCenter().x + 0), round(camera.getCenter().y + con));



				window.clear();

				window.draw(sprite);

				window.setView(camera);


				window.display();*/

				sf::sleep(sf::microseconds(IIIAG-time));
			






			


		}

	}

	return 0;

}



int main_tr()
{
	sf::RenderTexture background_texture;
	background_texture.create(1200, 1000);
	bool count = false;
	int fps = 0;
	sf::Texture tex;
	sf::Sprite background_sprite, sprite;
	background_sprite.setTexture(background_texture.getTexture());
	int con = 0;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
	camera.reset(sf::FloatRect(0, 0, 1200, 800));
	//	camera.setCenter(1000*1.f, 400*1.f);
	window.setView(camera);
	float time, counter, tx, tz;
	counter = 0;
	counter = GetTickCount();
//	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(false);
	sf::Clock gl_clock;
	sf::Clock clock, fps_clock;
	bool pr = false;

	float runspeed = 0.007;
	//	InitMap(background_texture);
	//	Entity en(400, 300, 0, 0);
	sf::Time updateTime;

	float last[2] = { 0, 0 };

	tex.loadFromFile("Images\\PC Computer - Captain Claw - Level 1 Tiles_2.png", sf::IntRect(130, 65, 600, 600));
	tex.setSmooth(true);
	//sprite.setScale(1.3, 1.3);
	sprite.setTexture(tex);
	sprite.setTextureRect(sf::IntRect(0, 0, 600, 600));
	sprite.setOrigin(0, 0);
	window.draw(sprite);
	sf::Sprite ar[30] = {};
	float delta_t = 0;
	//	sprite.setTextureRect(sf::IntRect(0, 0, 66, 60));  sprite.setOrigin(0, 0);

	while (window.isOpen())

	{
		sf::Event e;
		//cout << endl << "time"<< clock.getElapsedTime().asMicroseconds();
			if (clock.getElapsedTime().asMilliseconds()+delta_t > int(1000 / 60))
		{
			counter = GetTickCount();
			time = clock.getElapsedTime().asMicroseconds();
			fps++;
			if (fps_clock.getElapsedTime().asMilliseconds() > 1000)
			{
				fps_clock.restart();
				cout << endl << fps;
				fps = 0;

			}
			delta_t = clock.getElapsedTime().asMilliseconds() - int(1000 / 60);
			delta_t = 0;
			clock.restart();


			time /= 800;



			while (window.pollEvent(e))
			{
				if (e.type == sf::Event::Closed)
					window.close();
			}





			if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
			{
				con = 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
			{
				con = -1;
			}


			{
				camera.setCenter(round(camera.getCenter().x + 0), round(camera.getCenter().y + con));
			//	camera.move(round(0), round(con));
			}

			if ((int)camera.getCenter().y == (int)camera.getCenter().y + con)
				cout << endl << "int " << (int)camera.getCenter().y;
			//		sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y+con);
			window.clear();

			//		window.draw(sprite);
			window.draw(sprite);

			window.setView(camera);
			//	window.clear();


			window.display();
			Sleep(int(1000/60 - delta_t));
		}

	}

	return 0;

}



int mainzz()
{
	int fps = 0, last_fps = 0;
	sf::Texture tex;
	sf::Sprite sprite;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
	camera.reset(sf::FloatRect(0, 0, 1200, 800));

	window.setView(camera);
	//	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(false);

	sf::Time updateTime;
	int con = 0;


	tex.loadFromFile("Images\\PC Computer - Captain Claw - Level 1 Tiles_2.png", sf::IntRect(130, 65, 600, 600));
	tex.setSmooth(true);

	sprite.setTexture(tex);
	sprite.setTextureRect(sf::IntRect(0, 0, 600, 600));
	sprite.setOrigin(0, 0);
	window.draw(sprite);

	sf::Clock updateClock,fps_clock,clock;
	updateClock.restart();

	float delta_t = 0;
		while (window.isOpen()) {
			
			if (clock.getElapsedTime().asMilliseconds() + delta_t > int(1000 / 60))
			{
				//	counter = GetTickCount();
				//	time = clock.getElapsedTime().asMicroseconds();
				fps++;
				if (fps_clock.getElapsedTime().asMilliseconds() > 1000)
				{
					fps_clock.restart();
					cout << endl << fps;
					fps = 0;

				}
				delta_t = clock.getElapsedTime().asMilliseconds() - int(1000 / 60);
				delta_t = 0;
				clock.restart();
			}
			// Event handling is performed here

			// Determine the time that passed
			sf::Time delta = updateClock.getElapsedTime();
			cout << endl << "delta" << delta.asMilliseconds();


			updateTime += delta; // add up previous leftover time
			cout << endl<<"update_time" << updateTime.asMilliseconds();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
			{
				con = +1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
			{
				con = -1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				con = 0;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				getchar();
			}
			float loops = (updateTime / sf::milliseconds(16));// determine the number of iterations to do (100 fps; capped at 10)
			cout << endl << "loops" << loops;
			if (loops>0.97)
			{
				camera.setCenter(camera.getCenter().x + 0, camera.getCenter().y + con*0.5);
				window.clear();


				window.draw(sprite);

				window.setView(camera);
				// rendering
				window.display();
				updateClock.restart();
				updateTime = updateClock.restart();
				cout << endl << "update_time2 " << updateTime.asMilliseconds();
			//	getchar();
			}//updateSingleStep(); // update by one fixed timestep


		//	updateTime %= sf::milliseconds(10); // drop leftover frames

		//	updateDeltaTime(delta); // update based on time passed

	


			
			sf::sleep(sf::microseconds(1)); // sleep a minimum amount of time to ensure there's always at least some delta time (assuming very, very fast CPUs).
		}
}
int main11()
{
	int fps = 0, last_fps = 0;
	sf::Texture tex;
	sf::Sprite sprite;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
	camera.reset(sf::FloatRect(0, 0, 1200, 800));

	window.setView(camera);
		window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	sf::Time updateTime;
	int con = 0;


	tex.loadFromFile("Images\\PC Computer - Captain Claw - Level 1 Tiles_2.png", sf::IntRect(130, 65, 600, 600));
	tex.setSmooth(true);

	sprite.setTexture(tex);
	sprite.setTextureRect(sf::IntRect(0, 0, 600, 600));
	sprite.setOrigin(0, 0);
	window.draw(sprite);

	sf::Clock updateClock, fps_clock, clock;
	updateClock.restart();
	clock.restart();
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	float delta_t = 0;
	sf::Time  TimePerFrame =sf::seconds(1.f / 60.f);
	while (window.isOpen()) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			con = +1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			con = -1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			con = 0;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			getchar();
		}

	
			timeSinceLastUpdate += clock.restart();
		//	cout << endl << "time " << timeSinceLastUpdate.asMicroseconds();
			while (timeSinceLastUpdate > TimePerFrame)
			{
				timeSinceLastUpdate -= TimePerFrame;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
				{
					con = +1;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
				{
					con = -1;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					con = 0;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
				{
					getchar();
				}

				camera.setCenter(camera.getCenter().x + 0, camera.getCenter().y + con);
			

				window.setView(camera);
			}
		
	


		//timeSinceLastUpdate += clock.restart();

		// rendering
			window.clear();


			window.draw(sprite);
		window.display();
		//while (timeSinceLastUpdate.asMicroseconds() > int(1000/60))
		//{
		//	cout <<endl<< "time " << timeSinceLastUpdate.asMicroseconds();
		//	timeSinceLastUpdate -= sf::microseconds(int(1000/60));
		//	//camera.setCenter(camera.getCenter().x + 0, camera.getCenter().y + con*0.5);
		//	camera.setCenter(camera.getCenter().x + 0, camera.getCenter().y + con);
		//	window.clear();


		//	window.draw(sprite);

		//	window.setView(camera);
		//	// rendering
		//	window.display();
		//}
	
		// Event handling is performed here

		// Determine the time that passed
		
	
	
		

	//updateSingleStep(); // update by one fixed timestep


		 //	updateTime %= sf::milliseconds(10); // drop leftover frames

		 //	updateDeltaTime(delta); // update based on time passed





 // sleep a minimum amount of time to ensure there's always at least some delta time (assuming very, very fast CPUs).
	}
}
//
//void Game::run()
//{
//	sf::Clock clock;
//	sf::Time timeSinceLastUpdate = sf::Time::Zero;
//	while (mWindow.isOpen())
//	{
//		processEvents();
//		timeSinceLastUpdate += clock.restart();
//		while (timeSinceLastUpdate > TimePerFrame)
//		{
//			timeSinceLastUpdate -= TimePerFrame;
//			processEvents();
//			update(TimePerFrame);
//		}
//		render();
//	}
//}

class Game
{
//public:
//	Game();
//	void run();
//private:
//	void processEvents();
//	void update();
//	void render();
//private:
	sf::RenderWindow mWindow;
	sf::Sprite mPlayer;
	sf::View camera;
	sf::Texture tex;


	int x=0, y = 0;
public:

	Game::Game()
		: mWindow(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default)
		, mPlayer()
	{
		cout << "x "<< x;
		cout << "y " << y;
		//mWindow.setFramerateLimit(60);
		mWindow.setVerticalSyncEnabled(true);
		camera.reset(sf::FloatRect(0, 0, 1200, 800));
		//mPlayer.setRadius(100.f);
		//mPlayer.setPosition(100.f, 100.f);
		//mPlayer.setFillColor(sf::Color::Cyan);
		tex.loadFromFile("Images\\PC Computer - Captain Claw - Level 1 Tiles_2.png", sf::IntRect(130, 65, 600, 600));
	//	tex.setSmooth(true);
		mPlayer.setTexture(tex);
		mPlayer.setTextureRect(sf::IntRect(0, 0, 600, 600));
		mPlayer.setOrigin(0, 0);
	
	}

	void Game::run()
	{
		/*while (mWindow.isOpen())
		{
			processEvents();
			update();
			render();
		}*/

		sf::Clock clock;
		sf::Time timeSinceLastUpdate = sf::Time::Zero;
		sf::Time TimePerFrame;
		TimePerFrame = sf::seconds(1.f / 60.f);
		while (mWindow.isOpen())
		{
			processEvents();
			timeSinceLastUpdate += clock.restart();
			while (timeSinceLastUpdate > TimePerFrame)
			{
				timeSinceLastUpdate -= TimePerFrame;
				processEvents();
				update();
				render();
				sf::sleep(sf::milliseconds(7));
			}
			render();
			sf::sleep(sf::milliseconds(1));
		}
	}


	void Game::processEvents()
	{
		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				mWindow.close();
				break;
			}
		}
	}
	void Game::handlePlayerInput(sf::Keyboard::Key key,
		bool isPressed)
	{
		if (key == sf::Keyboard::W)
			y=-1;
		else if (key == sf::Keyboard::S)
		y=1;
		else if (key == sf::Keyboard::A)
		{
		
			x = -1;
		}
		else if (key == sf::Keyboard::D)
		{
			
			x = 1;
		}
	}
	void Game::render()
	{
		mWindow.clear();
		mWindow.draw(mPlayer);
		mWindow.display();
	}


	void Game::update()
	{
	camera.setCenter(int(camera.getCenter().x -x),int( camera.getCenter().y-y) );
		mWindow.setView(camera);
	}
};


int main22()
{

Game  game;
	game.run();
}

void draw( sf::RenderWindow& window)
{
	cout<<endl << "draw";
	window.display();
	cout << endl << "draw_end";
	//return 0;

}


int maincc()//__this()
{
	sf::RenderTexture background_texture;
	background_texture.create(1200, 1000);
	bool count = false;
	int fps = 0, last_fps = 0;
	sf::Texture tex;
	sf::Sprite background_sprite, sprite;
	background_sprite.setTexture(background_texture.getTexture());
	int con = 0;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
	camera.reset(sf::FloatRect(0, 0, 1200, 800));
	//	camera.setCenter(1000*1.f, 400*1.f);
	window.setView(camera);
	float time, counter, tx, tz;
	counter = 0;
	counter = GetTickCount();
	window.setFramerateLimit(60);
window.setVerticalSyncEnabled(true);
	sf::Clock gl_clock;
	sf::Clock clock, fps_clock;
	bool pr = false;

	float runspeed = 0.007;
	//	InitMap(background_texture);
	//	Entity en(400, 300, 0, 0);
	sf::Time updateTime=sf::Time::Zero;

	float last[2] = { 0, 0 };

	tex.loadFromFile("Images\\PC Computer - Captain Claw - Level 1 Tiles_2.png", sf::IntRect(130, 65, 600, 600));
	tex.setSmooth(true);
	//sprite.setScale(1.3, 1.3);
	sprite.setTexture(tex);
	sprite.setTextureRect(sf::IntRect(0, 0, 600, 600));
	sprite.setOrigin(0, 0);
	window.draw(sprite);
	sf::Sprite ar[30] = {};
	//	sprite.setTextureRect(sf::IntRect(0, 0, 66, 60));  sprite.setOrigin(0, 0);
	sf::Vector2f pos = camera.getCenter();
	auto r = async(launch::async, [&] {return 0; });
//sf::Thread drowThread(draw(window));
	while (window.isOpen())

	{
		sf::Event e;
	//	window.display();


			while (window.pollEvent(e))
			{
				if (e.type == sf::Event::Closed)
					window.close();
			}





			if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
			{
				con = 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
			{
				con = -1;
			}






			sf::Time delta = clock.restart();
			updateTime += delta; // add up previous leftover time

			time = 0;
			//cout<<
			int IIIAG = 16;
			int loops = std::min<int>((int)(updateTime / sf::milliseconds(1000/60)),	4); // determine the number of iterations to do (100 fps; capped at 10)
			int max = loops;
		//	cout << endl << updateTime.asMilliseconds();
loops = (int)(updateTime / sf::milliseconds(1000/60));
			if (loops > 0)
			{
				bool gate = 0;
	
						if (!loops)
						{
							updateTime -= sf::milliseconds(1000 / 60);
							clock.restart();
						}
		
						pos.x += 0;
						pos.y += con*(1);
						camera.setCenter(int(pos.x), int(pos.y));
						window.setView(camera);



						window.clear();

						window.draw(sprite);
				//		drowThread.launch();
						//; return 0;	 });
		/*	if (r.wait_for(chrono::seconds(0)) == future_status::timeout)
			{
			 cout<<endl << "waiting"<<r.valid();
			 r = async(launch::async, [&] {draw(window);  return 0;	 });
			}
			else
			{ 
																   }
*/

			
			//	}
			//	clock.restart();
				
			//	cout << "   " << updateTime.asMilliseconds();
				//
				//updateTime %= sf::milliseconds(IIIAG);
			}
		
		}

	return 0;

}
int h(sf::RenderWindow* win) {
	//do something
	win->display();
	//win->close();
	this_thread::sleep_for(chrono::milliseconds(10));
	while(true)
	{
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout<<endl << "ddd";
	}
	
	return 0;
}


int maidn() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	sf::Thread t1(h, &window);
	sf::sleep(sf::seconds(6));
	window.setActive(false);
	t1.launch();
	return 0;
}


void renderingThread(sf::RenderWindow* window)
{
	sf::Texture tex;
	sf::Sprite  sprite;
	sf::Clock clock;
	tex.loadFromFile("Images\\PC Computer - Captain Claw - Level 1 Tiles_2.png", sf::IntRect(130, 65, 600, 600));
	tex.setSmooth(true);
	
	window->setActive(true);

	sprite.setTexture(tex);
	sprite.setTextureRect(sf::IntRect(0, 0, 600, 600));
	sprite.setOrigin(0, 0);

	while (window->isOpen())
	{
		window->setView(camera);
		window->clear();
		window->draw(sprite);
	
		window->display();
		
	//	sf::sleep(sf::milliseconds(10));
	}
}

int main_best()
{
	// create the window (remember: it's safer to create it in the main thread due to OS limitations)
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default);
	window.setVerticalSyncEnabled(true);
	window.setView(camera);

	camera.reset(sf::FloatRect(0, 0, 1200, 800));
	// deactivate its OpenGL context
	window.setActive(false);

	// launch the rendering thread
	sf::Vector2f pos = camera.getCenter();
	
	sf::Thread thread(&renderingThread, &window);

	sf::Thread thread2([]() {

	});

	thread.launch();
	thread2.launch();
	sf::Clock clock;
	float time = 0;
	int con = 0;

	// the event/logic/whatever loop
	while (window.isOpen())
	{

		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time /= 800;

		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			//cout << endl << "sss";
			con = 1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			
			con = -1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{

			window.close();

		}

		pos.x += (time*0)*1.0f;
		pos.y += /*(time*0.05*con)*/con*0.07f;

			camera.setCenter({ pos.x,(pos.y) });

		sf::sleep(sf::milliseconds(1));
	}

	return 0;
}



class game 
{

	sf::RenderWindow window;
	sf::View Camera;
	sf::Thread render_thread;
	sf::Clock gl_clock;

	int con = 0;
	float time = 0.f;

public:
	game()
		: window(sf::VideoMode(1200, 800), "SFML works!", sf::Style::Default),
		  render_thread (&game::render, this)
	{
		window.setVerticalSyncEnabled(true);
		Camera.reset(sf::FloatRect(0, 0, 1200, 800));

	};



	void run();

		   void render();
		   void game_logic();
};

void game :: render()
{
	sf::Texture tex;
	sf::Sprite  sprite;
	sf::Clock clock;
	tex.loadFromFile("Images\\PC Computer - Captain Claw - Level 1 Tiles_2.png", sf::IntRect(130, 65, 600, 600));
	tex.setSmooth(true);

	window.setActive(true);

	sprite.setTexture(tex);
	sprite.setTextureRect(sf::IntRect(0, 0, 600, 600));
	sprite.setOrigin(0, 0);

	while (window.isOpen())
	{
		window.setView(Camera);
		window.clear();
		window.draw(sprite);

		window.display();

		//	sf::sleep(sf::milliseconds(10));
	}
};

void game::run()
{
	window.setActive(false);
	render_thread.launch();
	game_logic();
};

void game::game_logic()
{
	sf::Vector2f pos = camera.getCenter();
	while (window.isOpen())
	{

		time = gl_clock.getElapsedTime().asMicroseconds();
		gl_clock.restart();

		time /= 800;

		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			//cout << endl << "sss";
			con = 1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{

			con = -1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{

			window.close();

		}


		Camera.move({ 0,con*0.07f });
		sf::sleep(sf::milliseconds(1));
	}
}

int main()
{
	game g;
	g.run();


	return 0;
}
