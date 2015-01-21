// stagger/CircleBody.cpp
#include "stagger/CircleBody.hpp"

#include <cmath>
#include <Box2D/Collision/Shapes/b2CircleShape.h>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2Fixture.h>


namespace sgr
{


CircleBody::CircleBody(World* world,
                       float radius,
                       BodyType type,
                       unsigned int pointCount)
: Body(world, type)
, mRadius(radius)
, mPointCount(pointCount)
{
  Shape::setOrigin(mRadius * mPixelsPerMeter, mRadius* mPixelsPerMeter);
  Shape::update();

  b2CircleShape fixtureShape;
  fixtureShape.m_radius = radius;
  initializeFixture(&fixtureShape);
}

CircleBody::CircleBody(World* world,
                       float radius,
                       unsigned int pointCount,
                       BodyType type)
: CircleBody(world, radius, type, pointCount)
{
  // Nothing to do
}

void CircleBody::setRadius(float radius)
{
  mRadius = radius;
  mBody->GetFixtureList()->GetShape()->m_radius = radius;
  Shape::update();
}

float CircleBody::getRadius() const
{
  return mRadius;
}

unsigned int CircleBody::getPointCount() const
{
  return mPointCount;
}

sf::Vector2f CircleBody::getPoint(unsigned int index) const
{
  static const float pi = 3.141592654f;
  float pixelRadius = mRadius * mPixelsPerMeter;

  float angle = index * 2 * pi / mPointCount - pi / 2;
  float x = std::cos(angle) * pixelRadius + pixelRadius;
  float y = std::sin(angle) * pixelRadius + pixelRadius;

  return sf::Vector2f(x, y);
}


} // namespace sgr
