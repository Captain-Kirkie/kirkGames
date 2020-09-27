//
//  leftPaddle.hpp
//  pong
//
//  Created by Kirk Hietpas on 9/26/20.
//

#ifndef leftPaddle_hpp
#define leftPaddle_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class LeftPaddle{
    
private:
    float x;
    float y;
    float originalY;
    float length;
    float width;
    float yUpperBounds;
    float yLowerBounds;
    
    sf::FloatRect boundingBox;
    
    
public:
    //constructor
    LeftPaddle();
    LeftPaddle(float x, float y);
    
    //methods
    void moveUp();
    void moveDown();
    void draw(sf::RenderWindow & window);
    sf::RectangleShape PaddleShape;//could write getter method
    
    
    sf::FloatRect getBoundingBox();
};



#endif /* leftPaddle_hpp */
