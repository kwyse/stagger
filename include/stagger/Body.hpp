// stagger/Body.hpp
#ifndef SGR_BODY_HPP_
#define SGR_BODY_HPP_


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

class Body : public sf::Shape
{
public:
  explicit Body(World* world, BodyType type = BodyType::STATIC);

  void update();

  void addShape(sf::Shape& shape);

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


#endif // SGR_BODY_HPP_