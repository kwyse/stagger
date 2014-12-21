// fyp/Entity.hpp
#ifndef FYP_ENTITY_HPP_
#define FYP_ENTITY_HPP_


#include <memory>

#include <SFML/System/Vector2.hpp>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include <Box2D/Collision/Shapes/b2CircleShape.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Box2D/Collision/Shapes/b2EdgeShape.h>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <Box2D/Dynamics/b2World.h>
#include "BodySprite.hpp"
#include "fyp/World.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <iostream>


namespace sf
{
class RenderWindow;
}


namespace fyp
{


class BodySprite;


template<typename Shape>
class Entity
{
public:
  Entity(World *world, float radius); // sf::CircleShape
  Entity(World *world, sf::Vector2f size); // sf::RectangleShape
  Entity(World *world, sf::Vector2f start, sf::Vector2f end); // b2EdgeShape

  void update();

  void setPosition(sf::Vector2f position);
  sf::Drawable& getRenderShape();

private:
  Shape mShape;
  b2Body *mBody;
  int mPixelsPerMeter;
};

using CircleEntity = Entity<sf::CircleShape>;
using RectangleEntity = Entity<sf::RectangleShape>;
using ConvexEntity = Entity<sf::ConvexShape>;
using EdgeEntity = Entity<b2EdgeShape>;


} // namespace


#endif // FYP_ENTITY_HPP_