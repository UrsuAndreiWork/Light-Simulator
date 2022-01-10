
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "RazeLumina.h"
#include "Cutie.h"
#include "windows.h" 
using namespace std;

class Engine
{

protected:
	sf::Event eventt;
	sf::Sprite fundal;
	int heightWindow, lenghtWindow;
	Player player;
	vector<Cutie>cutii;
	RazeLumina lumina;
private:

public:
	void DrawWindow(int x, int y);
	void DrawMap();
	void Play();
	void ConsoleUpdate();
	int getHeigtWindow();
	int getLenghtWindow();
	void creareCutii();
};
