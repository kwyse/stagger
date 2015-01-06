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

  void update();

  void setPosition(float x, float y);
  void setPosition(const sf::Vector2f& position);

  void setAngularVelocity(float angle);
  void setLinearVelocity(float x, float y);
  void setLinearVelocity(const sf::Vector2f& velocity);

  sf::Vector2f getPosition() const;
  float getAngle() const;
  float getAngularVelocity() const;
  sf::Vector2f getLinearVelocity() const;

protected:
  void initializeFixture(b2Shape* shape);

  static constexpr float DEGREES_PER_RADIAN = 57.2957795f;

  b2Body* mBody;
  int mPixelsPerMeter;
};


} // namespace sgr


#endif // SGR_RENDER_ENTITY_HPP_