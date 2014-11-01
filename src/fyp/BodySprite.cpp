// BodySprite.cpp
#include "../../include/fyp/BodySprite.hpp"
#include <Box2D/Dynamics/b2World.h>
#include <SFML/Graphics/Sprite.hpp>


namespace fyp {


class BodySprite::Impl {
public:
  Impl(World& world, b2BodyDef& bodyDef, b2FixtureDef& fixtureDef)
  : mBody(world.getB2World()->CreateBody(&bodyDef))
  , mFixture(mBody->CreateFixture(&fixtureDef))
  , mPixelsPerMeter(world.getPixelsPerMeter())
  {
    float32 bodyRadius = mFixture->GetShape()->m_radius;
    mSize = sf::Vector2f(bodyRadius, bodyRadius);
  }

  b2Body* mBody;
  b2Fixture* mFixture;
  sf::Sprite mSprite;
  int mPixelsPerMeter;
  sf::Vector2f mSize;
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
  b2Vec2 pos = mImpl->mBody->GetPosition();
  mImpl->mSprite.setPosition(
      mImpl->mPixelsPerMeter * (pos.x - 0.5f * mImpl->mSize.x),
      mImpl->mPixelsPerMeter * (-pos.y - 0.5f * mImpl->mSize.y));
}

void BodySprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(mImpl->mSprite, states);
}

void BodySprite::setTexture(sf::Texture& texture)
{
  mImpl->mSprite.setTexture(texture);
}

void BodySprite::setSize(sf::Vector2f size)
{
  mImpl->mSize = size;
}

void BodySprite::setPosition(sf::Vector2f position)
{
  mImpl->mBody->SetTransform(b2Vec2(position.x, -position.y), 0);
  mImpl->mSprite.setPosition(
      mImpl->mPixelsPerMeter * (position.x - 0.5f * mImpl->mSize.x),
      mImpl->mPixelsPerMeter * (position.y - 0.5f * mImpl->mSize.y));
}


} // namespace