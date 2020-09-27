//
//  ball.cpp
//  pong
//
//  Created by Kirk Hietpas on 9/26/20.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.hpp"
#include "collision.hpp"

void Ball::draw(sf::RenderWindow & window){
    window.draw(ball);
}

Ball::Ball(){
    originalX = 400;
    originalY = 400;
    x = originalX;
    y = originalY;
    yUpperBounds = 0;
    yLowerBounds = 800;
    xUpperBounds = 1500;
    xLowerBounds = -200;
    isMovingLeft = true;
    isMovingDown = true;
    ball.setRadius(20.f);
    ball.setFillColor(sf::Color::Yellow);
    ball.scale(1,1);
    ball.setPosition(x, y); //should change this to x and y eventually
    boundingBox = ball.getGlobalBounds();
}
//ball.movement
void Ball::move(Paddle& PADDLELeft, Paddle PADDLERight){
    if(isMovingLeft && (!CollisionTest(ball, PADDLELeft.PaddleShape))){ //move left bool true and not colliding move left
        moveLeft();
    }
    
    if(!isMovingLeft &&(!CollisionTest(ball, PADDLERight.PaddleShape))){ //move left false and not colliding move right
        moveRight();
    }
    
    if(CollisionTest(ball, PADDLELeft.PaddleShape)){ //if colliding with left paddle set isMovingleftbool to false
        isMovingLeft = false;
    }
    
    if(CollisionTest(ball, PADDLERight.PaddleShape)){ //if colliding with right paddle set isMovingLeftBool to true
        isMovingLeft = true;
    }
    
    if(isMovingDown){
        moveDown();
        if(y >= 775){
            isMovingDown = false;
        }
    }
    if(!isMovingDown){
        moveUp();
        if(y <= 0){
            isMovingDown = true;
        }
    }
    if (ball.getPosition().x < xLowerBounds || ball.getPosition().x > xUpperBounds){
        reset();
    }
}
    
void Ball::reset(){
        x = 600;
        y = 400;
}

void Ball::moveLeft(){
    x-= .05;
    ball.setPosition(x, y);
}

void Ball::moveRight(){
        x+= .05;
        ball.setPosition(x, y);
}

void Ball::moveUp(){
        y-= .05;
        ball.setPosition(x, y);
}

void Ball::moveDown(){
        y+= .05;
        ball.setPosition(x, y);
}
