// stagger/Body.cpp
// Copyright (c) 2014-2015 Krishan Wyse (kwysek@gmail.com)
#include "stagger/Body.hpp"

#include <Box2D/Dynamics/b2Fixture.h>
#include <Box2D/Dynamics/b2World.h>
#include "stagger/World.hpp"


namespace sgr
{


Body::Body(World& world, BodyType type)
: mBody()
, mPixelsPerMeter(world.getPixelsPerMeter())
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

  mBody = world.getB2World()->CreateBody(&bodyDef);
  world.addBody(*this);
}

void Body::update()
{
  b2Vec2 position = mBody->GetPosition();

  Shape::setRotation(-mBody->GetAngle() * DEGREES_PER_RADIAN);
  Shape::setPosition(position.x * mPixelsPerMeter,
                    -position.y * mPixelsPerMeter);
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
  mBody->SetLinearVelocity(b2Vec2(velocity.x, velocity.y));
}

void Body::applyForceToCenter(float x, float y)
{
  applyForceToCenter(sf::Vector2f(x, y));
}

void Body::applyForceToCenter(const sf::Vector2f& force)
{
  mBody->ApplyForceToCenter(b2Vec2(force.x, force.y), true);
}

sf::Vector2f Body::getPosition() const
{
  b2Vec2 position = mBody->GetPosition();
  return sf::Vector2f(position.x, -position.y);
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

void Body::setFriction(float friction)
{
  if (friction > 1.f) friction = 1.f;
  if (friction < 0.f) friction = 0.f;
  mBody->GetFixtureList()->SetFriction(friction);
}

void Body::setDensity(float density)
{
  mBody->GetFixtureList()->SetDensity(density);
  mBody->ResetMassData();
}

void Body::setRestitution(float restitution)
{
  if (restitution > 1.f) restitution = 1.f;
  if (restitution < 0.f) restitution = 0.f;
  mBody->GetFixtureList()->SetRestitution(restitution);
}

float Body::getFriction() const
{
  return mBody->GetFixtureList()->GetFriction();
}

float Body::getDensity() const
{
  return mBody->GetFixtureList()->GetDensity();
}

float Body::getRestitution() const
{
  return mBody->GetFixtureList()->GetRestitution();
}

void Body::initializeFixture(b2Shape& shape)
{
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &shape;
  fixtureDef.density = 1.f;
  fixtureDef.friction = 0.3f;
  fixtureDef.restitution = 0.3f;
  mBody->CreateFixture(&fixtureDef);
}

void Body::reinitializeFixture(b2Fixture& fixture, b2Shape& shape)
{
  float density = fixture.GetDensity();
  float friction = fixture.GetFriction();
  float restitution = fixture.GetRestitution();

  mBody->DestroyFixture(&fixture);
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &shape;
  fixtureDef.density = density;
  fixtureDef.friction = friction;
  fixtureDef.restitution = restitution;
  mBody->CreateFixture(&fixtureDef);
}


} // namespace sgr
