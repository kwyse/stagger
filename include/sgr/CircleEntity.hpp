// sgr/CircleEntity.hpp
#ifndef SGR_CIRCLE_ENTITY_HPP_
#define SGR_CIRCLE_ENTITY_HPP_


#include <memory>
#include "sgr/RenderEntity.hpp"


namespace sgr
{


class CircleEntity : public RenderEntity
{
public:
  CircleEntity(World* world,
               float radius,
               BodyType type = BodyType::STATIC,
               unsigned int pointCount = 30);
  CircleEntity(World* world,
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


#endif // SGR_CIRCLE_ENTITY_HPP_