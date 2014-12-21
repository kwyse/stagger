// fyp/Entity.cpp
#include "fyp/Entity.hpp"

#include <vector>

#include <Box2D/Dynamics/b2World.h>
#include <SFML/Graphics/RenderWindow.hpp>

#include "fyp/BodySprite.hpp"


namespace fyp
{


template <>
void Entity<sf::CircleShape>::update()
{
  b2Vec2 pos = mBody->GetPosition();
  mShape.setPosition(
      mPixelsPerMeter * (pos.x - 0.5f * 2.f),
      mPixelsPerMeter * (-pos.y - 0.5f * 2.f));
}

template <>
void Entity<sf::RectangleShape>::update()
{
  b2Vec2 pos = mBody->GetPosition();
  mShape.setPosition(
      mPixelsPerMeter * (pos.x - 0.5f * 2.f),
      mPixelsPerMeter * (-pos.y - 0.5f * 2.f));
}

template<>
void Entity<sf::CircleShape>::setPosition(sf::Vector2f position)
{
  // TODO: This must account for size of body
  mBody->SetTransform(b2Vec2(position.x, -position.y), mBody->GetAngle());
  mShape.setPosition(position.x * mPixelsPerMeter,
      position.y * mPixelsPerMeter);
}

template<>
void Entity<sf::RectangleShape>::setPosition(sf::Vector2f position)
{
  // TODO: This must account for size of body
  mBody->SetTransform(b2Vec2(position.x, -position.y), mBody->GetAngle());
  mShape.setPosition(position.x * mPixelsPerMeter,
      position.y * mPixelsPerMeter);
}

template<>
sf::Drawable& Entity<sf::CircleShape>::getRenderShape()
{
  return mShape;
}

template<>
sf::Drawable& Entity<sf::RectangleShape>::getRenderShape()
{
  return mShape;
}

template<>
void Entity<sf::CircleShape>::initializeFixture()
{
  b2CircleShape fixtureShape;
  fixtureShape.m_radius = 2.f;
  mShape.setRadius(2.f * mPixelsPerMeter);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &fixtureShape;
  fixtureDef.density = 1.f;
  fixtureDef.friction = 0.3f;
  mBody->CreateFixture(&fixtureDef);
}

template<>
void Entity<sf::RectangleShape>::initializeFixture()
{
  b2PolygonShape fixtureShape;
  fixtureShape.SetAsBox(2.f, 2.f);
  mShape.setSize(sf::Vector2f(4.f * mPixelsPerMeter, 4.f * mPixelsPerMeter));

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &fixtureShape;
  fixtureDef.density = 1.f;
  fixtureDef.friction = 0.3f;
  mBody->CreateFixture(&fixtureDef);
}

template<>
void Entity<b2EdgeShape>::initializeFixture()
{
  // TODO: Bodies are not colliding with edges
  b2Vec2 v1(0.f, 5.f);
  b2Vec2 v2(50.f, 50.f);
  mShape.Set(v1, v2);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &mShape;
  fixtureDef.density = 1.f;
  fixtureDef.friction = 0.3f;
  mBody->CreateFixture(&fixtureDef);
}


} // namespace