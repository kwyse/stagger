// sgr/EdgeEntity.hpp
#ifndef SGR_EDGE_ENTITY_HPP_
#define SGR_EDGE_ENTITY_HPP_


#include <memory>
#include <Box2D/Dynamics/b2Body.h>
#include <SFML/Graphics/Drawable.hpp>
#include "sgr/RenderEntity.hpp"


namespace sgr
{


class World;


class EdgeEntity : public sf::Drawable
{
public:
  EdgeEntity(World* world,
             const sf::Vector2f& start,
             const sf::Vector2f& end,
             BodyType type = BodyType::STATIC);

  void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
  // TODO: Pimpl this
  b2Body* mBody;
  std::array<sf::Vertex, 2> mEdge;
};


} // namespace sgr


#endif // SGR_EDGE_ENTITY_HPP_