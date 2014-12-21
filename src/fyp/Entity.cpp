// fyp/Entity.cpp
#include "fyp/Entity.hpp"

#include <vector>

#include <Box2D/Dynamics/b2World.h>
#include <SFML/Graphics/RenderWindow.hpp>

#include "fyp/BodySprite.hpp"


void initializeFixture(sf::CircleShape* shape,
                       b2Body* body,
                       float radius,
                       int pixelsPerMeter);
void initializeFixture(sf::RectangleShape* shape,
                       b2Body* body,
                       sf::Vector2f size,
                       int pixelsPerMeter);
void initializeFixture(b2Body* body, sf::Vector2f start, sf::Vector2f end);
void setDefaultFixtureSettings(b2Body* body, b2Shape* fixtureShape);


namespace fyp
{


template<>
Entity<sf::CircleShape>::Entity(World *world, float radius)
: mShape()
, mBody()
, mPixelsPerMeter(world->getPixelsPerMeter())
{
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  mBody = world->getB2World()->CreateBody(&bodyDef);
  initializeFixture(&mShape, mBody, radius, mPixelsPerMeter);

  world->addEntity(this);
}

template<>
Entity<sf::RectangleShape>::Entity(World *world, sf::Vector2f size)
: mShape()
, mBody()
, mPixelsPerMeter(world->getPixelsPerMeter())
{
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  mBody = world->getB2World()->CreateBody(&bodyDef);
  initializeFixture(&mShape, mBody, size, mPixelsPerMeter);

  world->addEntity(this);
}

template<>
Entity<b2EdgeShape>::Entity(World *world, sf::Vector2f start, sf::Vector2f end)
: mShape()
, mBody()
, mPixelsPerMeter(world->getPixelsPerMeter())
{
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  mBody = world->getB2World()->CreateBody(&bodyDef);
  initializeFixture(mBody, start, end);

  world->addEntity(this);
}

template <>
void Entity<sf::CircleShape>::update()
{
  b2Vec2 pos = mBody->GetPosition();
  mShape.setPosition(mPixelsPerMeter * (pos.x - 0.5f * 2.f),
                     mPixelsPerMeter * (-pos.y - 0.5f * 2.f));
}

template <>
void Entity<sf::RectangleShape>::update()
{
  b2Vec2 pos = mBody->GetPosition();
  mShape.setPosition(mPixelsPerMeter * (pos.x - 0.5f * 2.f),
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


} // namespace


void initializeFixture(sf::CircleShape* shape,
                       b2Body* body,
                       float radius,
                       int pixelsPerMeter)
{
  b2CircleShape fixtureShape;
  fixtureShape.m_radius = radius;
  shape->setRadius(radius * pixelsPerMeter);

  setDefaultFixtureSettings(body, &fixtureShape);
}

void initializeFixture(sf::RectangleShape* shape,
                       b2Body* body,
                       sf::Vector2f size,
                       int pixelsPerMeter)
{
  b2PolygonShape fixtureShape;
  fixtureShape.SetAsBox(size.x / 2, size.y / 2);
  shape->setSize(sf::Vector2f(size.x * pixelsPerMeter,
                              size.y * pixelsPerMeter));

  setDefaultFixtureSettings(body, &fixtureShape);
}

void initializeFixture(b2Body* body, sf::Vector2f start, sf::Vector2f end)
{
  b2EdgeShape fixtureShape;
  b2Vec2 v1(start.x, start.y);
  b2Vec2 v2(end.x, end.y);
  fixtureShape.Set(v1, v2);

  setDefaultFixtureSettings(body, &fixtureShape);
}

void setDefaultFixtureSettings(b2Body* body, b2Shape* fixtureShape)
{
  b2FixtureDef fixtureDef;
  fixtureDef.shape = fixtureShape;
  fixtureDef.density = 1.f;
  fixtureDef.friction = 0.3f;
  body->CreateFixture(&fixtureDef);
}