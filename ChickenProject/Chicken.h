#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Chicken
{
public:
	float posX;
	float posY;
	float dim;
	float velX;
	float velY;
	Color color;
	
	Chicken(float posX, float posY, float dim, float velX, float velY, Color color)
	{
		this->posX = posX;
		this->posY = posY;
		this->dim = dim;
		this->velX = velX;
		this->velY = velY;
		this->color = color;
	}
};

