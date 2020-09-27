//
//  ball.hpp
//  pong
//
//  Created by Kirk Hietpas on 9/26/20.
//

#ifndef ball_hpp
#define ball_hpp
#include "leftPaddle.hpp"


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
    sf::FloatRect boundingBox;
    
public:
    void draw(sf::RenderWindow & window);
    
    void moveLeft();
    
    void moveRight();
  
    void moveUp();
   
    void moveDown();
    
    void move(LeftPaddle& leftPaddle);
    
    //constructor
    Ball();
    
};


#endif /* ball_hpp */
