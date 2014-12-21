// fyp/Entity.hpp
#ifndef FYP_ENTITY_HPP_
#define FYP_ENTITY_HPP_


#include <memory>

#include <SFML/System/Vector2.hpp>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include <Box2D/Collision/Shapes/b2CircleShape.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <Box2D/Dynamics/b2World.h>
#include "BodySprite.hpp"
#include "fyp/World.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>


namespace sf
{
class RenderWindow;
}


namespace fyp
{


class BodySprite;


template<typename Shape>
class Entity : public sf::Drawable
{
public:
  Entity<Shape>(World *world);

  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void setPosition(sf::Vector2f position);

private:
  void initializeFixture(sf::CircleShape shape);
  void initializeFixture(sf::RectangleShape shape);

  Shape mShape;
  b2Body *mBody;
  int mPixelsPerMeter;
};

using CircleEntity = Entity<sf::CircleShape>;
using RectangleEntity = Entity<sf::RectangleShape>;
using ConvexEntity = Entity<sf::ConvexShape>;

template<typename Shape>
Entity<Shape>::Entity(World *world)
    : mPixelsPerMeter(world->getPixelsPerMeter())
{
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  mBody = world->getB2World()->CreateBody(&bodyDef);
  initializeFixture(mShape);

  world->addEntity(this);
}

template<typename Shape>
void Entity<Shape>::initializeFixture(sf::CircleShape shape)
{
  b2CircleShape fixtureShape;
  fixtureShape.m_radius = 2.f;
  mShape.setRadius(2.f * mPixelsPerMeter);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &fixtureShape;
  mBody->CreateFixture(&fixtureDef);
}

template<typename Shape>
void Entity<Shape>::initializeFixture(sf::RectangleShape shape)
{
  b2PolygonShape fixtureShape;
  fixtureShape.SetAsBox(2.f, 2.f);
  mShape.setSize(sf::Vector2f(4.f * mPixelsPerMeter, 4.f * mPixelsPerMeter));

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &fixtureShape;
  mBody->CreateFixture(&fixtureDef);
}

template<typename Shape>
void Entity<Shape>::setPosition(sf::Vector2f position)
{
  mBody->SetTransform(b2Vec2(position.x, position.y), mBody->GetAngle());
  mShape.setPosition(position.x * mPixelsPerMeter,
      position.y * mPixelsPerMeter);
}

template<typename Shape>
void Entity<Shape>::draw(sf::RenderTarget &target,
                         sf::RenderStates states) const
{
  // If Shape is an sf::Shape
  target.draw(mShape, states);
}
} // namespace


#endif // FYP_ENTITY_HPP_