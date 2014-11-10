#ifndef FYP_BODY_SPRITE_HPP_
#define FYP_BODY_SPRITE_HPP_


#include <memory>

#include <SFML/Graphics/Drawable.hpp>


class b2BodyDef;
class b2FixtureDef;


namespace fyp {


class World;


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