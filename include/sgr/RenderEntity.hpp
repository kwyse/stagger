// sgr/RenderEntity.hpp
#ifndef SGR_RENDER_ENTITY_HPP_
#define SGR_RENDER_ENTITY_HPP_


#include <memory>
#include <SFML/Graphics/Shape.hpp>


class b2Body;
class b2Shape;


namespace sgr
{


class World;


enum class BodyType
{
  STATIC,
  DYNAMIC,
  KINEMATIC
};

class RenderEntity : public sf::Shape
{
public:
  explicit RenderEntity(World* world, BodyType type = BodyType::STATIC);

  virtual void update() = 0;

protected:
  void initializeFixture(b2Shape* shape);

  b2Body* mBody;
  int mPixelsPerMeter;
};


} // namespace sgr


#endif // SGR_RENDER_ENTITY_HPP_