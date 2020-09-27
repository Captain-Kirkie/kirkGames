#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include <fstream>
#include "rightPaddle.hpp"
#include "leftPaddle.hpp"
#include "ball.hpp"

//create paddles
LeftPaddle leftPaddle1;
LeftPaddle rightPaddle1(1150, 300);
Ball ball1;
using namespace std;
int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1200, 800), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            
            if(event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::A){
                    leftPaddle1.moveDown();
                }
                if (event.key.code == sf::Keyboard::Q){
                    leftPaddle1.moveUp();
                }
              
                if (event.key.code == sf::Keyboard::Down){
                    rightPaddle1.moveDown();
                }
                if (event.key.code == sf::Keyboard::Up){
                    rightPaddle1.moveUp();
                }
                
            }
        }
        
        //ball movment
        ball1.move(leftPaddle1, rightPaddle1);
     //  ball1.moveDown();

        // clear the window with black color
        window.clear(sf::Color::Black);

        
        //paddle movement
        

        //draw  calls
//window.draw(shape);
    // window.draw(leftPaddle);
	
        leftPaddle1.draw(window);
        ball1.draw(window);
        rightPaddle1.draw(window);
        // end the current frame
        window.display();
    }

    return 0;
}
