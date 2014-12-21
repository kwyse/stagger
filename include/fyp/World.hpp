// fyp/World.hpp
#ifndef FYP_WORLD_HPP_
#define FYP_WORLD_HPP_


#include <memory>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


class b2World;


namespace sf
{
class RenderWindow;
}


namespace fyp
{


class BodySprite;
template <typename Shape>
class Entity;


class World
{
public:
  World(sf::RenderWindow& window,
        sf::Vector2f gravity = sf::Vector2f(0.f, 0.f));
  World(const World&) = delete;
  World& operator=(const World&) = delete;
  ~World();

  void processInput();
  void update();
  void render();

  void addBody(BodySprite* body);
  void addEntity(Entity<sf::CircleShape>* entity);
  void addEntity(Entity<sf::RectangleShape>* entity);

  void setGravity(sf::Vector2f gravity);
  void setPixelsPerMeter(int pixels);
  void setTickRate(float ticks);

  sf::Vector2f getGravity() const;
  int getPixelsPerMeter() const;
  b2World* getB2World() const;

private:
  struct Impl;
  std::unique_ptr<Impl> mImpl;
};


} // namespace


#endif // FYP_WORLD_HPP_