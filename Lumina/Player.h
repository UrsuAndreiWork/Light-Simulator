#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;
class Player
{
protected:
	int pozX, pozY,lenghWindow, heightWindow;
	sf::Sprite playerSprite;
public:
	void movePlayer(string directie);
	int getPozX();
	int getPozY();
	sf::Sprite getSprite();
	Player(int lenghWindow,int heightWindow);
	Player();
};

