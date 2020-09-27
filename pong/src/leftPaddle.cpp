//
//  leftPaddle.cpp
//  pong
//
//  Created by Kirk Hietpas on 9/26/20.
//

#include "leftPaddle.hpp"

LeftPaddle::LeftPaddle(){
    x = 15;
    //originalY = 100;
    y = 300;
    yLowerBounds = 600;
    yUpperBounds = 0;
    leftPaddleShape.setSize(sf::Vector2f(35.f, 200.f));
    leftPaddleShape.setFillColor(sf::Color::Red);
    leftPaddleShape.scale(1,1);
    leftPaddleShape.setPosition(x, y); //should change this to x and y eventually
    boundingBox = leftPaddleShape.getGlobalBounds();
}
void LeftPaddle::draw(sf::RenderWindow & window){
    window.draw(leftPaddleShape);
}


void LeftPaddle::moveUp(){
    if(y > yUpperBounds){
        y -= 35.f;
        leftPaddleShape.setPosition(x, y);
    }
}

void LeftPaddle::moveDown(){
    if(y < yLowerBounds){
        y += 35.f;
        leftPaddleShape.setPosition(x, y);
    }
}


sf::FloatRect LeftPaddle::getBoundingBox(){
    return boundingBox;
}

