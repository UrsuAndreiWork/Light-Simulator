#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
using namespace std;
class Cutie
{
protected:
	int pozX, pozY, lenghWindow, heightWindow;
	sf::Sprite cutieSprite;
public:

	int getPozX();
	int getPozY();
	void setPozitie(int pozXv, int pozYv);
	sf::Sprite getSprite();
	Cutie(int lenghWindow, int heightWindow,int pozXv, int pozYv);
	Cutie();
};

