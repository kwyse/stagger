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

  void update();

  void setRadius(float radius);
  void setPosition(float x, float y);
  void setPosition(const sf::Vector2f& position);

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