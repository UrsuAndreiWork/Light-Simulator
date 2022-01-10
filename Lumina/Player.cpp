#include "Player.h"
//*se transfera include-urile 


int Player::getPozX()
{
	return pozX;
}
int Player::getPozY()
{
	return pozY;
}
 Player::Player(int lenghWindowV,int heightWindowV)
{
	 pozX = 5;
	 pozY = 5;
	 lenghWindow = lenghWindowV;
	 heightWindow = heightWindowV;
     sf::Texture* t = new sf::Texture();
	 t->loadFromFile("imagini/player.png");
	 playerSprite.setTexture(*t);
	 playerSprite.setPosition(pozX, pozY);
	
}
 Player::Player()
 {
	 pozX = 5;
	 pozY = 5;
	 lenghWindow = 900;
	 heightWindow = 900;
	 sf::Texture* t = new sf::Texture();
	 t->loadFromFile("imagini/player.png");
	 playerSprite.setTexture(*t);
	 playerSprite.setPosition(pozX, pozY);
 }
 sf::Sprite Player::getSprite()
 {
	 return playerSprite;
 }
void Player::movePlayer(string directie)
{
	if (directie == "stanga")
	{
		if (pozX > 5)
		{
			pozX = pozX - 90;
		}
	}
	else if (directie == "dreapta")
	{
		if (pozX+90 < lenghWindow )
		{
			pozX = pozX + 90;
		}
	}
	else if (directie == "sus")
	{
		if (pozY-90 >0)
		{
			pozY = pozY - 90;
		}
	}
	else if (directie == "jos")
	{
		if (pozY+90<heightWindow)
		{
			pozY = pozY + 90;
		}
	}
	playerSprite.setPosition(pozX, pozY);
}