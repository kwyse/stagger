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

void RenderEntity::initializeFixture(b2Shape* shape)
{
  b2FixtureDef fixtureDef;
  fixtureDef.shape = shape;
  fixtureDef.density = 1.f;
  fixtureDef.friction = 0.3f;
  mBody->CreateFixture(&fixtureDef);
}


} // namespace sgr
