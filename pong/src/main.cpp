#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include <fstream>
#include "paddle.hpp"
#include "ball.hpp"

//create paddles
Paddle leftPaddle1;
Paddle rightPaddle1(1150, 300);
Ball ball1;

//score
int scoreLeft = 0;
int scoreRight = 0;
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
            //paddle movement
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
        
        //simple score
        if(ball1.getX() <= -199){//there is a bettter way to do this
            scoreLeft++;
            cout << "Player left score: " << scoreLeft << endl;
            cout << "Player right score: " << scoreRight << endl;
        }
        if(ball1.getX() >= 1500){
            scoreRight++;
            cout << "Player left score: " << scoreLeft << endl;
            cout << "Player right score: " << scoreRight << endl;
        }
       
        //ball movment
        ball1.move(leftPaddle1, rightPaddle1);
     //  ball1.moveDown();

        // clear the window with black color
        window.clear(sf::Color::Black);

 
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
