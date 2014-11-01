#ifndef FYP_BODY_SPRITE_HPP_
#define FYP_BODY_SPRITE_HPP_


#include "World.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <Box2D/Dynamics/b2Fixture.h>


namespace fyp {


class BodySprite : public sf::Drawable
{
public:
  BodySprite(World& world, b2BodyDef& bodyDef, b2FixtureDef& fixtureDef);
  ~BodySprite();

  void update();
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void setTexture(sf::Texture& texture);
  void setSize(sf::Vector2f size);
  void setPosition(sf::Vector2f position);

private:
  struct Impl;
  std::unique_ptr<Impl> mImpl;
};


} // namespace


#endif // FYP_BODY_SPRITE_HPP_