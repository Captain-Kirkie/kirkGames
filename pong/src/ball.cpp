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
    xUpperBounds = 1200;
    xLowerBounds = 0;
    isMovingLeft = true;
    isMovingDown = true;
    ball.setRadius(20.f);
    ball.setFillColor(sf::Color::Yellow);
    ball.scale(1,1);
    ball.setPosition(x, y); //should change this to x and y eventually
    boundingBox = ball.getGlobalBounds();
}

void Ball::move(LeftPaddle& PADDLELeft, LeftPaddle PADDLERight){
    if(isMovingLeft && (!CollisionTest(ball, PADDLELeft.leftPaddleShape))){ //move left bool true and not colliding move left
        moveLeft();
    }
    
    if(!isMovingLeft &&(!CollisionTest(ball, PADDLERight.leftPaddleShape))){ //move left false and not colliding move right
        moveRight();
    }
    
    if(CollisionTest(ball, PADDLELeft.leftPaddleShape)){ //if colliding with left paddle set isMovingleftbool to false
        isMovingLeft = false;
    }
    
    if(CollisionTest(ball, PADDLERight.leftPaddleShape)){ //if colliding with right paddle set isMovingLeftBool to true
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
    
    
}
    
    
    
//    if(CollisionTest(ball, PADDLELeft.leftPaddleShape)){ //if colliding move
//        isMovingLeft = false;
//    }
//    else if(!isMovingLeft){
//        moveRight();
//    }
//    else if(!isMovingLeft && CollisionTest(ball, PADDLELeft.leftPaddleShape)){
//        isMovingLeft = true;
//    }
    
    
    
    
    
    



    
//void Ball::move(LeftPaddle& LEFT){
//    if(isMovingLeft && (!CollisionTest(ball, LEFT.leftPaddleShape))){ //moving left and down
//            moveLeft();
//    }
//    else{
//        isMovingLeft = false;
//    }
//    if(!isMovingLeft){
//        moveRight();
//    }
//    if(isMovingDown){
//        moveDown();
//        if(y >= 775){
//            isMovingDown = false;
//        }
//    }
//    if(!isMovingDown){
//        moveUp();
//        if(y <= 0){
//            isMovingDown = true;
//        }
//    }
//
//}
   
    
    
    
    
    
    
    
    
    
    
   
    






//if y >= 800 go up
//if y <= 0 go down
//if x <= 0 score
//if x >= 1200



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



//enum eDir{STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6}; //watch snake video for this
////these are just const ints
//class Ball{
//private:
//    int x, y;
//    int originalX, originalY;
//    eDir direction;
//
//public:
//    Ball(int posX, int posY){
//
//        originalX = posX;
//        originalY = posY;
//        x = posX;
//        y = posY;
//        direction = STOP;
//    }
//
//    void Reset(){
//        x = originalX; y = originalY;
//        direction = STOP;
//    }
//    void changeDirection(eDir d){
//        direction = d;
//    }
//
//
//    void randomDirection(){
//
//        direction = (eDir) (rand() % 6 + 1);
//    }
//
//    void Move(){
//        switch (direction) {
//            case STOP:
//                break;
//
//            case LEFT:
//                x--;
//                break;
//            case RIGHT:
//                x++;
//                break;
//
//            case UPLEFT:
//                x--; y--;
//                break;
//
//            case DOWNLEFT:
//                x--; y++;
//                break;
//
//            case UPRIGHT:
//                x++; y--;
//                break;
//
//            case DOWNRIGHT:
//                x++; y++;
//                break;
//            default:
//                break;
//        }
//    }
//    friend ostream & operator << (ostream & o, Ball c){
//        o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]" << endl;
//        return o;
//    }
//
//
//};
