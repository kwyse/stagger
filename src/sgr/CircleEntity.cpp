// sgr/CircleEntity.cpp
#include "sgr/CircleEntity.hpp"

#include <cmath>
#include <Box2D/Collision/Shapes/b2CircleShape.h>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2Fixture.h>


namespace sgr
{


CircleEntity::CircleEntity(World* world,
                           float radius,
                           BodyType type,
                           unsigned int pointCount)
: RenderEntity(world, type)
, mRadius(radius)
, mPointCount(pointCount)
{
  Shape::setOrigin(mRadius * mPixelsPerMeter, mRadius* mPixelsPerMeter);
  Shape::update();

  b2CircleShape fixtureShape;
  fixtureShape.m_radius = radius;
  initializeFixture(&fixtureShape);
}

CircleEntity::CircleEntity(World* world,
                           float radius,
                           unsigned int pointCount,
                           BodyType type)
: CircleEntity(world, radius, type, pointCount)
{
  // Nothing to do
}

void CircleEntity::update()
{
  b2Vec2 position = mBody->GetPosition();

  Shape::setRotation(-mBody->GetAngle() * DEGREES_PER_RADIAN);
  Shape::setPosition(position.x * mPixelsPerMeter,
                    -position.y * mPixelsPerMeter);
}

void CircleEntity::setRadius(float radius)
{
  mRadius = radius;
  mBody->GetFixtureList()->GetShape()->m_radius = radius;
  Shape::update();
}

void CircleEntity::setPosition(float x, float y)
{
  setPosition(sf::Vector2f(x, y));
}

void CircleEntity::setPosition(const sf::Vector2f& position)
{
  mBody->SetTransform(b2Vec2(position.x, -position.y), mBody->GetAngle());
  Shape::setPosition(position.x * mPixelsPerMeter,
                    -position.y * mPixelsPerMeter);
}

float CircleEntity::getRadius() const
{
  return mRadius;
}

unsigned int CircleEntity::getPointCount() const
{
  return mPointCount;
}

sf::Vector2f CircleEntity::getPoint(unsigned int index) const
{
  static const float pi = 3.141592654f;
  float pixelRadius = mRadius * mPixelsPerMeter;

  float angle = index * 2 * pi / mPointCount - pi / 2;
  float x = std::cos(angle) * pixelRadius + pixelRadius;
  float y = std::sin(angle) * pixelRadius + pixelRadius;

  return sf::Vector2f(x, y);
}


} // namespace sgr
