#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include "Cutie.h"
using namespace std;
class RazeLumina
{
protected:
	int intensitate=120;
	int lungime_raza=800;
	int diametru = 30;
	float raritateRaze = 0.1;
	int R=155, G=255, B=255;
	int R1 = 155, G1 = 55, B1 = 255,intensitate1=120;  //*cand linia atinge cutia
	float rotatieViteza=4.02;
	int rotatie = -34;
	float var = 0;
	bool mouse = true;
	vector<Cutie> cutiiCopie;
	sf::RectangleShape lanterna; //*ii practic raza
public:
	void miscareRaze(int pozX,int pozY);
	void aplicareRotatie(int pozXv,int pozYv,float unghi, int origineX, int origineY);
	void adaugareObstacole(vector<Cutie>cutii);
	float getUnghiMouse(float origineX, float origineY);
	//*constructor care primeste cutiile ca mi-a fost sila sa fac o clasa pentru fiecare raza
	//*kill me btw
};

