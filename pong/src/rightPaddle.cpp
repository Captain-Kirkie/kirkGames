////
////  rightPaddle.cpp
////  pong
////
////  Created by Kirk Hietpas on 9/26/20.
////
//
//#include "rightPaddle.hpp"
//RightPaddle::RightPaddle(){
//    x = 1150;
//    y = 300;
//    yLowerBounds = 600;
//    yUpperBounds = 0;
//    rightPaddleShape.setSize(sf::Vector2f(35.f, 200.f));
//    rightPaddleShape.setFillColor(sf::Color::Green);
//    rightPaddleShape.scale(1,1);
//    rightPaddleShape.setPosition(x, y);
//    boundingBox = rightPaddleShape.getGlobalBounds();
//}
//void RightPaddle::draw(sf::RenderWindow & window){
//    window.draw(rightPaddleShape);
//}
//
//
//void RightPaddle::moveUp(){
//    if(y > yUpperBounds){
//        y -= 35.f;
//        rightPaddleShape.setPosition(x, y);
//    }
//}
//
//void RightPaddle::moveDown(){
//    if(y < yLowerBounds){
//        y += 35.f;
//        rightPaddleShape.setPosition(x, y);
//    }
//}
//
//sf::FloatRect RightPaddle::getBoundingBox(){
//    return boundingBox;
//}
//
//
