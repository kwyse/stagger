// fyp/World.hpp
#ifndef FYP_WORLD_HPP_
#define FYP_WORLD_HPP_


#include <SFML/Graphics/RenderWindow.hpp>


class b2World;


namespace fyp {


class BodySprite;


class World {
public:
  World(sf::RenderWindow& window, sf::Vector2f gravity, int pixelsPerMeter);
  World(const World&) = delete;
  World& operator=(const World&) = delete;
  ~World();

  b2World* getB2World();
  void addBody(BodySprite* body);
  void update();
  void render();

  void setTickRate(float ticksPerSecond);
  int getPixelsPerMeter() const;

private:
  class Impl;
  std::unique_ptr<Impl> mImpl;
};


} // namespace


#endif // FYP_WORLD_HPP_