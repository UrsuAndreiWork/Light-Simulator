#include "Cutie.h"



int Cutie::getPozX()
{
	return pozX;
}
int Cutie::getPozY()
{
	return pozY;
}
Cutie::Cutie(int lenghWindowV, int heightWindowV, int pozXv, int pozYv)
{
	pozX = pozXv;
	pozY = pozYv;
	lenghWindow = lenghWindowV;
	heightWindow = heightWindowV;
	sf::Texture* t = new sf::Texture();
	t->loadFromFile("imagini/cutie.png");
	cutieSprite.setTexture(*t);
	cutieSprite.setPosition(pozX, pozY);

}
Cutie::Cutie()
{
	pozX = 180;
	pozY = 180;
	lenghWindow = 900;
	heightWindow = 900;
	sf::Texture* t = new sf::Texture();
	t->loadFromFile("imagini/cutie.png");
	cutieSprite.setTexture(*t);
	cutieSprite.setPosition(pozX, pozY);
}
sf::Sprite Cutie::getSprite()
{
	return cutieSprite;
}
void Cutie::setPozitie(int pozXv, int pozYv)
{
	pozX = pozXv;
	pozY = pozYv;
}