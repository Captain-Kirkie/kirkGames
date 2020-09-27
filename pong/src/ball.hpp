//
//  ball.hpp
//  pong
//
//  Created by Kirk Hietpas on 9/26/20.
//

#ifndef ball_hpp
#define ball_hpp
#include "paddle.hpp"


#include <stdio.h>
using namespace std;

class Ball{
private:
    float x;
    float y;
    float originalX;
    float originalY;
    float length;
    float width;
    float yUpperBounds;
    float yLowerBounds;
    float xUpperBounds;
    float xLowerBounds;
    float velocity;
    sf::CircleShape ball;
    bool isMovingLeft;
    bool isMovingDown;
    sf::FloatRect boundingBox;
    
public:
    void draw(sf::RenderWindow & window);
    
    void moveLeft();
    
    void moveRight();
  
    void moveUp();
   
    void moveDown();
    
    void move(Paddle& PADDLELeft, Paddle PADDLERight);
    
    //constructor
    Ball();
    
};


#endif /* ball_hpp */
