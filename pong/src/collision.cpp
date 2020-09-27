//
//  collision.cpp
//  pong
//
//  Created by Kirk Hietpas on 9/26/20.
//

#include "collision.hpp"
#include <stdio.h>
#include <SFML/Graphics.hpp>

bool CollisionTest(const sf::Shape& object1, const sf::Shape& object2){
    return(object1.getGlobalBounds().intersects(object2.getGlobalBounds()));
}
