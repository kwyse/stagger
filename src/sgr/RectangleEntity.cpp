// sgr/RectangleEntity.cpp
#include "sgr/RectangleEntity.hpp"

#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2Fixture.h>


namespace sgr
{


RectangleEntity::RectangleEntity(World* world,
                                 const sf::Vector2f& size,
                                 BodyType type)
: RenderEntity(world, type)
, mSize(size)
{
  Shape::setOrigin((mSize.x / 2) * mPixelsPerMeter,
                   (mSize.y / 2) * mPixelsPerMeter);
  Shape::update();

  b2PolygonShape fixtureShape;
  fixtureShape.SetAsBox(size.x / 2, size.y / 2);
  initializeFixture(&fixtureShape);
}

void RectangleEntity::update()
{
  b2Vec2 position = mBody->GetPosition();

  Shape::setRotation(-mBody->GetAngle() * DEGREES_PER_RADIAN);
  Shape::setPosition(position.x * mPixelsPerMeter,
                    -position.y * mPixelsPerMeter);
}

void RectangleEntity::setSize(float width, float height)
{
  setSize(sf::Vector2f(width, height));
}

void RectangleEntity::setSize(const sf::Vector2f& size)
{
  mSize = size;

  mBody->DestroyFixture(mBody->GetFixtureList());
  b2PolygonShape fixtureShape;
  fixtureShape.SetAsBox(size.x / 2, size.y / 2);
  initializeFixture(&fixtureShape);

  Shape::update();
}

const sf::Vector2f& RectangleEntity::getSize() const
{
  return mSize;
}

unsigned int RectangleEntity::getPointCount() const
{
  return 4;
}

sf::Vector2f RectangleEntity::getPoint(unsigned int index) const
{
  switch (index) {
    default:
    case 0:
      return sf::Vector2f(0, 0);
    case 1:
      return sf::Vector2f(mSize.x * mPixelsPerMeter, 0);
    case 2:
      return sf::Vector2f(mSize.x * mPixelsPerMeter, mSize.y * mPixelsPerMeter);
    case 3:
      return sf::Vector2f(0, mSize.y * mPixelsPerMeter);
  }
}


} // namespace sgr