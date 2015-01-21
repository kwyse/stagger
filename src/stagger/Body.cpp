// stagger/Body.cpp
#include "stagger/Body.hpp"

#include <Box2D/Dynamics/b2Fixture.h>
#include <Box2D/Dynamics/b2World.h>
#include "stagger/World.hpp"


namespace sgr
{


Body::Body(World* world, BodyType type)
: mBody()
, mPixelsPerMeter(world->getPixelsPerMeter())
{
  b2BodyDef bodyDef;
  switch(type) {
    case BodyType::STATIC:
      // Default type is b2_staticBody
      break;
    case BodyType::DYNAMIC:
      bodyDef.type = b2_dynamicBody;
      break;
    case BodyType::KINEMATIC:
      bodyDef.type = b2_kinematicBody;
      break;
  }

  mBody = world->getB2World()->CreateBody(&bodyDef);
  world->addBody(this);
}

void Body::update()
{
  b2Vec2 position = mBody->GetPosition();

  Shape::setRotation(-mBody->GetAngle() * DEGREES_PER_RADIAN);
  Shape::setPosition(position.x * mPixelsPerMeter,
                    -position.y * mPixelsPerMeter);
}

void Body::addShape(sf::Shape& shape)
{

}

void Body::setPosition(float x, float y)
{
  setPosition(sf::Vector2f(x, y));
}

void Body::setPosition(const sf::Vector2f& position)
{
  mBody->SetTransform(b2Vec2(position.x, -position.y), mBody->GetAngle());
  Shape::setPosition(position.x * mPixelsPerMeter,
                    -position.y * mPixelsPerMeter);
}

void Body::setAngularVelocity(float angle)
{
  mBody->SetAngularVelocity(angle / DEGREES_PER_RADIAN);
}

void Body::setLinearVelocity(float x, float y)
{
  setLinearVelocity(sf::Vector2f(x, y));
}

void Body::setLinearVelocity(const sf::Vector2f& velocity)
{
  mBody->SetLinearVelocity(b2Vec2(velocity.x, velocity.x));
}

sf::Vector2f Body::getPosition() const
{
  b2Vec2 position = mBody->GetPosition();
  return sf::Vector2f(position.x, position.y);
}

float Body::getAngle() const
{
  return mBody->GetAngle() * DEGREES_PER_RADIAN;
}

float Body::getAngularVelocity() const
{
  return mBody->GetAngularVelocity() * DEGREES_PER_RADIAN;
}

sf::Vector2f Body::getLinearVelocity() const
{
  b2Vec2 linearVelocity = mBody->GetLinearVelocity();
  return sf::Vector2f(linearVelocity.x, linearVelocity.y);
}

void Body::initializeFixture(b2Shape* shape)
{
  b2FixtureDef fixtureDef;
  fixtureDef.shape = shape;
  fixtureDef.density = 1.f;
  fixtureDef.friction = 0.3f;
  mBody->CreateFixture(&fixtureDef);
}


} // namespace sgr
