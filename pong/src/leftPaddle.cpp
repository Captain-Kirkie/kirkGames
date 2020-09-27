//
//  leftPaddle.cpp
//  pong
//
//  Created by Kirk Hietpas on 9/26/20.
//

#include "leftPaddle.hpp"
//default constructor
LeftPaddle::LeftPaddle(){
    x = 15;
    //originalY = 100;
    y = 300;
    yLowerBounds = 600;
    yUpperBounds = 0;
    PaddleShape.setSize(sf::Vector2f(35.f, 200.f));
    PaddleShape.setFillColor(sf::Color::Red);
    PaddleShape.scale(1,1);
    PaddleShape.setPosition(x, y);
    boundingBox = PaddleShape.getGlobalBounds();
}

//constructor for right paddle
LeftPaddle::LeftPaddle(float xStart, float yStart){
    x = xStart;
    //originalY = 100;
    y = yStart;
    yLowerBounds = 600;
    yUpperBounds = 0;
    PaddleShape.setSize(sf::Vector2f(35.f, 200.f));
    PaddleShape.setFillColor(sf::Color::Green);
    PaddleShape.scale(1,1);
    PaddleShape.setPosition(x, y); 
    boundingBox = PaddleShape.getGlobalBounds();
    
}







void LeftPaddle::draw(sf::RenderWindow & window){
    window.draw(PaddleShape);
}


void LeftPaddle::moveUp(){
    if(y > yUpperBounds){
        y -= 35.f;
        PaddleShape.setPosition(x, y);
    }
}

void LeftPaddle::moveDown(){
    if(y < yLowerBounds){
        y += 35.f;
        PaddleShape.setPosition(x, y);
    }
}


sf::FloatRect LeftPaddle::getBoundingBox(){
    return boundingBox;
}


