#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level : BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt) override;
	void update(float dt)override;
	void render()override;

private:
	// Default functions for rendering to the screen.
	
	sf::CircleShape circle;
	sf::RectangleShape rect;
	float speed;
	float ballSpeedX =500;
	float ballSpeedY = 500;



	sf::CircleShape circle2;
	// Default variables for level class.
	
};