// stagger/EdgeEntity.hpp
#ifndef STAGGER_EDGE_BODY_HPP_
#define STAGGER_EDGE_BODY_HPP_


#include <array>
#include <memory>
#include <Box2D/Dynamics/b2Body.h>
#include <SFML/Graphics/Drawable.hpp>
#include "stagger/Body.hpp"


namespace sgr
{


class World;


class EdgeBody : public Body
{
public:
  EdgeBody(World* world,
           const sf::Vector2f& start,
           const sf::Vector2f& end,
           BodyType type = BodyType::STATIC);

  void update();
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  unsigned int getPointCount() const;
  sf::Vector2f getPoint(unsigned int index) const;

private:
  // TODO: Pimpl this
  std::array<sf::Vertex, 2> mEdge;
};


} // namespace sgr


#endif // STAGGER_EDGE_BODY_HPP_
