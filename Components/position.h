#ifndef POSITION_H
#define POSITION_H

#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>

/********Example********

struct Position : public entityx::Component<Position>
{
Position(const sf::Vector2f & pos)
:pos(pos), prevPos(pos) {}
sf::Vector2f pos;
sf::Vector2f prevPos;
};
*/

#endif // POSITION_H
