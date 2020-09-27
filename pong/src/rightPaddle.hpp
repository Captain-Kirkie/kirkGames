//
//  rightPaddle.hpp
//  pong
//
//  Created by Kirk Hietpas on 9/26/20.
//

#ifndef rightPaddle_hpp
#define rightPaddle_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class RightPaddle{
    
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
    RightPaddle();
    
    //methods
    void moveUp();
    void moveDown();
    void draw(sf::RenderWindow & window);
    sf::RectangleShape rightPaddleShape;//could write getter method
    
    
    sf::FloatRect getBoundingBox();
};







#endif /* rightPaddle_hpp */
