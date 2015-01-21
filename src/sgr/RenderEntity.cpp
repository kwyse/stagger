// sgr/RenderEntity.cpp
#include "sgr/RenderEntity.hpp"

#include <Box2D/Dynamics/b2Fixture.h>
#include <Box2D/Dynamics/b2World.h>
#include "sgr/World.hpp"


namespace sgr
{


RenderEntity::RenderEntity(World* world, BodyType type)
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
  world->addEntity(this);
}

void RenderEntity::update()
{
  b2Vec2 position = mBody->GetPosition();

  Shape::setRotation(-mBody->GetAngle() * DEGREES_PER_RADIAN);
  Shape::setPosition(position.x * mPixelsPerMeter,
                    -position.y * mPixelsPerMeter);
}

void RenderEntity::addShape(sf::Shape& shape)
{

}

void RenderEntity::setPosition(float x, float y)
{
  setPosition(sf::Vector2f(x, y));
}

void RenderEntity::setPosition(const sf::Vector2f& position)
{
  mBody->SetTransform(b2Vec2(position.x, -position.y), mBody->GetAngle());
  Shape::setPosition(position.x * mPixelsPerMeter,
                    -position.y * mPixelsPerMeter);
}

void RenderEntity::setAngularVelocity(float angle)
{
  mBody->SetAngularVelocity(angle / DEGREES_PER_RADIAN);
}

void RenderEntity::setLinearVelocity(float x, float y)
{
  setLinearVelocity(sf::Vector2f(x, y));
}

void RenderEntity::setLinearVelocity(const sf::Vector2f& velocity)
{
  mBody->SetLinearVelocity(b2Vec2(velocity.x, velocity.x));
}

sf::Vector2f RenderEntity::getPosition() const
{
  b2Vec2 position = mBody->GetPosition();
  return sf::Vector2f(position.x, position.y);
}

float RenderEntity::getAngle() const
{
  return mBody->GetAngle() * DEGREES_PER_RADIAN;
}

float RenderEntity::getAngularVelocity() const
{
  return mBody->GetAngularVelocity() * DEGREES_PER_RADIAN;
}

sf::Vector2f RenderEntity::getLinearVelocity() const
{
  b2Vec2 linearVelocity = mBody->GetLinearVelocity();
  return sf::Vector2f(linearVelocity.x, linearVelocity.y);
}

void RenderEntity::initializeFixture(b2Shape* shape)
{
  b2FixtureDef fixtureDef;
  fixtureDef.shape = shape;
  fixtureDef.density = 1.f;
  fixtureDef.friction = 0.3f;
  mBody->CreateFixture(&fixtureDef);
}


} // namespace sgr
