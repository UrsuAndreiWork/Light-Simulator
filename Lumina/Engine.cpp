#include "Engine.h"

//* l-am trantit global
sf::RenderWindow window;

void Engine::ConsoleUpdate()
{
    if (eventt.type == sf::Event::TextEntered)
    {
        cout<< "A fost apasat:"<<static_cast<char>(eventt.text.unicode) << endl;
        char lit = static_cast<char>(eventt.text.unicode);
        if (lit == 'w')
        {
            player.movePlayer("sus");
       }
        else if (lit == 's')
        {
            player.movePlayer("jos");
        }
        else if (lit == 'a')
        {
            player.movePlayer("stanga");
        }
        else if (lit == 'd')
        {
            player.movePlayer("dreapta");
        }
    }
}

void Engine::creareCutii()
{
   Cutie cutie1(lenghtWindow,heightWindow,95,275);
   Cutie cutie2(lenghtWindow, heightWindow, 545, 455);
   Cutie cutie3(lenghtWindow, heightWindow, 275, 365);
   cutii.push_back(cutie1);
   cutii.push_back(cutie2);
   cutii.push_back(cutie3);
   lumina.adaugareObstacole(cutii);
}

void Engine::DrawWindow(int x, int y)
{
    window.create(sf::VideoMode(x, y), "SFML window");
    heightWindow = y;
    lenghtWindow = x;
   
    sf::Texture* t=new sf::Texture();
    t->loadFromFile("imagini/fundal.jpg");
    fundal.setTexture(*t);
    window.draw(fundal);
    window.display();
     
  

}
void Engine::DrawMap()
{
   //*linia de sus
    sf::RectangleShape line(sf::Vector2f(lenghtWindow, 5));
    line.setFillColor(sf::Color:: Magenta);
    window.draw(line);
    //*linia de stanga
    sf::RectangleShape line1(sf::Vector2f(5, heightWindow));
    line1.setFillColor(sf::Color::Green);
    window.draw(line1);
    //* linia din dreapta
    sf::RectangleShape line2(sf::Vector2f(5, heightWindow));
    line2.setPosition(lenghtWindow-5, 0);
    line2.setFillColor(sf::Color::Magenta);
    window.draw(line2);
    //*linia de jos
    sf::RectangleShape line3(sf::Vector2f(lenghtWindow, 5));
    line3.setPosition(0, heightWindow - 5);
    line3.setFillColor(sf::Color::Magenta);
    window.draw(line3);
    


    for (int i = 1; i <= heightWindow/90; i++)
    {
        sf::RectangleShape line4(sf::Vector2f(lenghtWindow, 5));
        line4.setPosition(0, i*90);
        line4.setFillColor(sf::Color::Magenta);
        window.draw(line4);
    }
    for (int i = 1; i <= lenghtWindow / 90; i++)
    {
        sf::RectangleShape line5(sf::Vector2f(5, heightWindow));
        line5.setPosition(i*90, 0);
        line5.setFillColor(sf::Color::Magenta);
        window.draw(line5);
    }

    for (int i = 0; i < cutii.size(); i++)
    {
        window.draw(cutii[i].getSprite());
    }
}

void Engine::Play()
{
    
    while (window.isOpen())
    {
        // Event processing
  

        while (window.pollEvent(eventt))
        {
            // Request for closing the window
            if (eventt.type == sf::Event::Closed)
                window.close();

            if (eventt.type == sf::Event::TextEntered)
            {
             ConsoleUpdate();
            }
           if (eventt.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i position = sf::Mouse::getPosition(window);
               //* std::cout << "mouse x: " << position.x << std::endl;
                //*std::cout << "mouse y: " << position.y << std::endl;
            }
        }
     
        window.draw(fundal);
        DrawMap();
        
        lumina.miscareRaze(player.getPozX(),player.getPozY());
        window.draw(player.getSprite());
        window.display();
        

         window.clear();
    }

}


int Engine::getHeigtWindow()
{
    return heightWindow;
}
int Engine::getLenghtWindow()
{
    return lenghtWindow;
}

