#ifndef FYP_BODY_SPRITE_HPP_
#define FYP_BODY_SPRITE_HPP_


#include <SFML/Graphics/Drawable.hpp>
#include <Box2D/Dynamics/b2Fixture.h>
#include "../../include/fyp/World.hpp"


namespace fyp {


class BodySprite : public sf::Drawable
{
public:
  BodySprite(World& world, b2BodyDef& bodyDef, b2FixtureDef& fixtureDef);
  ~BodySprite();

  void update();
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
  class Impl;
  std::unique_ptr<Impl> mImpl;
};


} // namespace


#endif // FYP_BODY_SPRITE_HPP_