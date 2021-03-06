//
//  leftPaddle.cpp
//  pong
//
//  Created by Kirk Hietpas on 9/26/20.
//

#include "paddle.hpp"
//default constructor
Paddle::Paddle(){
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
Paddle::Paddle(float xStart, float yStart){
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



void Paddle::draw(sf::RenderWindow & window){
    window.draw(PaddleShape);
}


void Paddle::moveUp(){
    if(y > yUpperBounds){
        y -= 35.f;
        PaddleShape.setPosition(x, y);
    }
}

void Paddle::moveDown(){
    if(y < yLowerBounds){
        y += 35.f;
        PaddleShape.setPosition(x, y);
    }
}


sf::FloatRect Paddle::getBoundingBox(){
    return boundingBox;
}








//getting paddle to track??
/*
 for(int p = 0; p < proj1.size(); p++){
     proj1[p].shape.move(((character.shape.getPosition().x - vecOfBadCoins[p].shape.getPosition().x) * .0001), ((character.shape.getPosition().y - vecOfBadCoins[p].shape.getPosition().y) *.0001)); //finds direction to where character is and moves projectiles in that direction; * .0001 to slow down projectiles to reasonable speed
 
 */
