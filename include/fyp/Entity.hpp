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
  Entity<Shape>(World *world);

  void update();

  void setPosition(sf::Vector2f position);
  sf::Drawable& getRenderShape();

private:
  void initializeFixture();

  Shape mShape;
  b2Body *mBody;
  int mPixelsPerMeter;
};

using CircleEntity = Entity<sf::CircleShape>;
using RectangleEntity = Entity<sf::RectangleShape>;
using ConvexEntity = Entity<sf::ConvexShape>;
using EdgeEntity = Entity<b2EdgeShape>;

template<typename Shape>
Entity<Shape>::Entity(World *world)
: mPixelsPerMeter(world->getPixelsPerMeter())
{
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  mBody = world->getB2World()->CreateBody(&bodyDef);
  initializeFixture();

  world->addEntity(this);
}


} // namespace


#endif // FYP_ENTITY_HPP_