#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>
using namespace std;

 class Animated_Obj
{
	float cur_frame = 0.;
	int last_frame = 0;


	virtual void Update() { cout << "Update Animation"; };



};

