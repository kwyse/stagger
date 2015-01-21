// stagger/CircleBody.hpp
#ifndef SGR_CIRCLE_BODY_HPP_
#define SGR_CIRCLE_BODY_HPP_


#include <memory>
#include "stagger/Body.hpp"


namespace sgr
{


class CircleBody : public Body
{
public:
  CircleBody(World* world,
             float radius,
             BodyType type = BodyType::STATIC,
             unsigned int pointCount = 30);
  CircleBody(World* world,
             float radius,
             unsigned int pointCount,
             BodyType type = BodyType::STATIC);

  // TODO: Needs copy constructor
  // TODO: Needs setRotation()

  void setRadius(float radius);

  float getRadius() const;
  unsigned int getPointCount() const;
  sf::Vector2f getPoint(unsigned int index) const;

private:
  // TODO: Pimpl this
  float mRadius;
  unsigned int mPointCount;
};


} // namespace sgr


#endif // SGR_CIRCLE_BODY_HPP_