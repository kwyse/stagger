// BodySprite.cpp
#include "../../include/fyp/BodySprite.hpp"
#include <Box2D/Dynamics/b2World.h>


namespace fyp {


class BodySprite::Impl {
public:
  Impl(World& world, b2BodyDef& bodyDef, b2FixtureDef& fixtureDef)
  : mBody(world.getB2World()->CreateBody(&bodyDef))
  , mFixture(mBody->CreateFixture(&fixtureDef))
  {
    // Nothing to do
  }

  b2Body* mBody;
  b2Fixture* mFixture;
};

BodySprite::BodySprite(World& world, b2BodyDef& bodyDef, b2FixtureDef& fixtureDef)
: mImpl(new BodySprite::Impl(world, bodyDef, fixtureDef))
{
  world.addBody(this);
}

BodySprite::~BodySprite()
{
  // Nothing to do
}

void BodySprite::update()
{
  // Update
}

void BodySprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  // Draw target
}


} // namespace