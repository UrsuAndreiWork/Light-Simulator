// Lumina.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include "Engine.h"

using namespace std;

int main()
{
   Engine motor;
   motor.DrawWindow(900, 800);
   motor.creareCutii();
   motor.Play();
   

}
