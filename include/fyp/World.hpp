// fyp/World.hpp
#ifndef FYP_WORLD_HPP_
#define FYP_WORLD_HPP_


#include <SFML/Graphics/RenderWindow.hpp>


namespace fyp {


class World {
public:
  World(sf::RenderWindow& window, sf::Vector2f gravity);
  ~World();

private:
  class Impl;
  std::unique_ptr<Impl> mImpl;
};


} // namespace


#endif // FYP_WORLD_HPP_