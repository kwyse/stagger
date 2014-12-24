// sgr/RectangleEntity.hpp
#ifndef SGR_RECTANGLE_ENTITY_HPP_
#define SGR_RECTANGLE_ENTITY_HPP_


#include <memory>
#include "sgr/RenderEntity.hpp"


namespace sgr
{


class RectangleEntity : public RenderEntity
{
public:
  RectangleEntity(World* world,
                  const sf::Vector2f& size,
                  BodyType type = BodyType::STATIC);

  void update();

  void setSize(float width, float height);
  void setSize(const sf::Vector2f& size);
  void setPosition(float x, float y);
  void setPosition(const sf::Vector2f& position);

  const sf::Vector2f& getSize() const;
  unsigned int getPointCount() const;
  sf::Vector2f getPoint(unsigned int index) const;

private:
  // TODO: Pimpl this
  sf::Vector2f mSize;
};


} // namespace sgr


#endif // SGR_RECTANGLE_ENTITY_HPP_