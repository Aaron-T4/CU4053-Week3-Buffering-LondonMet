#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	circle.setRadius(15);
	circle.setPosition(300, 300);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Magenta);
	circle.setOutlineThickness(2.f);


	circle2.setRadius(18);
	circle2.setPosition(300, 300);
	circle2.setFillColor(sf::Color::Magenta);
	circle2.setOutlineColor(sf::Color::Red);
	circle2.setOutlineThickness(2.f);
	
	rect.setSize(sf::Vector2f(50, 50));
	rect.setFillColor(sf::Color::Red);

	
	speed = 250.f;

}

Level::~Level()
{
	
}

// handle user input
void Level::handleInput(float dt)
{
	if(input->isKeyDown(sf::Keyboard::W)){

		rect.move(0, -500 * dt);
		//input->setKeyUp(sf::Keyboard::W);
	}
	if (input->isKeyDown(sf::Keyboard::S)) {

		rect.move(0, 500 * dt);
	//	input->setKeyUp(sf::Keyboard::S);
	}
	if (input->isKeyDown(sf::Keyboard::A)) {

		rect.move(-500 * dt, 0);
	//	(input->setKeyUp(sf::Keyboard::A));
	}
	if (input->isKeyDown(sf::Keyboard::D)) {

		rect.move(500 * dt, 0);
		//input->setKeyUp(sf::Keyboard::D);
	}


	//increasing ballspeed
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		input->setKeyUp(sf::Keyboard::Right);
		ballSpeedX += 750.f;
		ballSpeedY += 750.f;

	}


	//decreasing ballspeed
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		input->setKeyUp(sf::Keyboard::Left);
		ballSpeedX -= 750.f;
		ballSpeedY -= 750.f;

	}

}

// Update game objects
void Level::update(float dt)
{
	if (circle.getPosition().x > window->getSize().x)
	{
		speed = -speed;
	}
	if (circle.getPosition().x < 0)
	{
		speed = 1000;		
	}


	circle.move(speed * dt, 0);
	circle2.move(ballSpeedX* dt, ballSpeedY * dt);
	window->getSize();


	if (circle2.getPosition().x <= 0 || circle2.getPosition().x >= window->getSize().x - circle2.getRadius() * 2) {
		ballSpeedX = -ballSpeedX;

	}

	if (circle2.getPosition().y <= 0 || circle2.getPosition().y >= window->getSize().y - circle2.getRadius() * 2) {
		ballSpeedY = -ballSpeedY;

	}
}
	

// Render level
void Level::render()
{
	beginDraw();

	window->draw(circle);
	window->draw(circle2);

	window->draw(rect);

	endDraw();
}

