#include "RazeLumina.h"


void RazeLumina::adaugareObstacole(vector<Cutie>cutii)
{
    cutiiCopie = cutii;
}

void RazeLumina::aplicareRotatie(int pozXcapat, int pozYcapat, float unghi,int origineX,int origineY)
{
    float pi = 3.14159;
    float alpha =pi/(180/unghi)*(-1);
    float x = cos(alpha) * (pozXcapat - origineX) + (pozYcapat - origineY) * sin(alpha) + origineX;
    float y = -sin(alpha) * (pozXcapat - origineX) + cos(alpha) * (pozYcapat - origineY) + origineY;

   
    //*ecuatia dreptei
    float m = (y - origineY)/(x-origineX);
    
    float ecY;
    
  

    //*cout << m << " " << b<<endl;
    //*ec dreptei: y=m*i+b;   i->x         -m*x=b-y;  x=(b-y)/m*(-1)
    //*  cout << "Ecuatia dreptei: y=" << m << "*x+" << b<<endl;    
    float d = 0;   //*y
   //* cout << "(" << origineX << "," << origineY << ")" << " " << "(" << x << "," << y << ")" << endl;
    float i = origineX-1.1; 


    extern sf::RenderWindow window;
    
    //*sf::CircleShape shape(1);
    //*shape.setFillColor(sf::Color(150, 50, 250));

   lanterna.setFillColor(sf::Color(R, G, B, intensitate));
    float ok = true;


    //*partea dreapta de ecran
    if (origineX <= x)
    do {
 
        d = m * (i - origineX) + origineY;
        for (int j = 0; j < cutiiCopie.size(); j++)
        {
            if (cutiiCopie[j].getPozX() < i && cutiiCopie[j].getPozX() + 85 > i)
            {
                if (cutiiCopie[j].getPozY() < d && (cutiiCopie[j].getPozY() + 85) > d)
                {
                    lanterna.setFillColor(sf::Color(R1, G1, B1, intensitate1));
                     sf::Vector2f dist(sqrt((i - origineX) * (i - origineX) + (d - origineY) * (d - origineY)), 2);  //* sa pun dist buna 
                    lanterna.setSize(dist);
                    //*shape.setPosition(i, d);
                    //*window.draw(shape);
                    ok = false;
                    break;
                }
            }
        }  
        if (ok == false)
        { 
            
            break;
        }
        i = i + 1;
        //*shape.setPosition(i, d);
        //*window.draw(shape);
        
        
    } while (i <=x);
             //*partea stanga
    if (origineX >= x)
    {
        float i = origineX - 1.1;
        do {
        
            d = m * (i - origineX) + origineY;
            for (int j = 0; j < cutiiCopie.size(); j++)
            {
                if (cutiiCopie[j].getPozX() < i && cutiiCopie[j].getPozX() + 85 > i)
                {
                    if (cutiiCopie[j].getPozY() < d && (cutiiCopie[j].getPozY() + 85) > d)
                    {
                        lanterna.setFillColor(sf::Color(R1, G1, B1, intensitate1));
                        sf::Vector2f dist(sqrt((i-origineX)* (i - origineX)+(d-origineY)* (d - origineY)), 2);  //* sa pun dist buna 
                        lanterna.setSize(dist);
                       //* shape.setPosition(i, d);
                        //*window.draw(shape);
                        ok = false;
                        break;
                    }
                }
            }
            if (ok == false)
            {
                break;
            }
            i = i - 1;
            //*shape.setPosition(i, d);
          //*  window.draw(shape);


        } while (i > x);


    }
    //*window.draw(shape);
}
float RazeLumina:: getUnghiMouse(float origineX,float origineY)
{
  
    float pi = 3.14159;
    float mouseX, mouseY;
    sf::Event eventt;
    extern sf::RenderWindow window;
    sf::Vector2i position = sf::Mouse::getPosition(window);
    mouseX = position.x;
    mouseY = position.y;

    float m1 = 0;
    float m2 = (mouseY - origineY) / (mouseX - origineX);

    float alpha = atan((m2 - m1) / (1 + m1 * m2));

    if (mouseX<origineX)
    {
   
        return alpha * (180 / pi)-180;
    }

    return alpha*(180/pi);
}
void RazeLumina::miscareRaze(int pozX, int pozY)
{
    for (float i = 0; i < diametru; i = i + raritateRaze)
     {
   
        sf::RectangleShape lanterna1(sf::Vector2f(lungime_raza, 1));
        lanterna1.setPosition(pozX + 80, pozY + 40);
        float alpha=getUnghiMouse(pozX + 80, pozY + 40);
       
        lanterna1.setFillColor(sf::Color(R, G, B, intensitate));
        
        //*aflu coordonatele in care se afla punctul dupa rotatie
        if (mouse == true)
        {
            lanterna1.rotate(getUnghiMouse(pozX + 80, pozY + 40) + i);
            lanterna = lanterna1;
            aplicareRotatie(lungime_raza + pozX + 80, pozY + 41, getUnghiMouse(pozX + 80, pozY + 40) + i, pozX + 80, pozY + 40);

        }
        else { lanterna1.rotate(rotatie + var + i); 
        lanterna = lanterna1;
        aplicareRotatie(lungime_raza + pozX + 80, pozY + 41, rotatie + var + i, pozX + 80, pozY + 40);
        }
        
        //* extern cauta acel lucru global
        extern sf::RenderWindow window;
        window.draw(lanterna);
    }
    var = var + rotatieViteza;

}
