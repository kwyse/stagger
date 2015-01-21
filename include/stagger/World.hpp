// stagger/World.hpp
#ifndef SGR_WORLD_HPP_
#define SGR_WORLD_HPP_


#include <memory>
#include <SFML/System/Vector2.hpp>


class b2World;
namespace sf { class RenderWindow; }


namespace sgr
{


class Body;


class World
{
public:
  explicit World(sf::RenderWindow& window,
                 sf::Vector2f gravity = sf::Vector2f(0.f, 0.f));
  World(const World&) = delete;
  World& operator=(const World&) = delete;
  ~World();

  void processInput();
  void update();
  void render();

  void addBody(Body* body);
//  void removeBody(Body* body);

  void setGravity(float x, float y);
  void setGravity(const sf::Vector2f& gravity);
  void setPixelsPerMeter(int pixelsPerMeter);
  void setTicksPerSecond(float ticksPerSecond); // TODO: Should this be an int?

  const sf::Vector2f getGravity() const;
  int getPixelsPerMeter() const;
  float getTicksPerSecond() const;
  b2World* getB2World() const;

private:
  struct Impl;
  std::unique_ptr<Impl> mImpl;
};


} // namespace sgr


#endif // SGR_WORLD_HPP_