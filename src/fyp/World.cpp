// fyp/World.cpp
#include "../../include/fyp/World.hpp"


#include <Box2D/Dynamics/b2World.h>


namespace fyp
{


class World::Impl
{
public:
  Impl(sf::RenderWindow& window, sf::Vector2f gravity)
  : mWindow(window)
  , mWorld(b2Vec2(gravity.x, gravity.y))
  {
    // Nothing to do
  }

private:
  sf::RenderWindow& mWindow;
  b2World mWorld;
};

World::World(sf::RenderWindow& window, sf::Vector2f gravity)
: mImpl(new World::Impl(window, gravity))
{
    // Nothing to do
}

World::~World()
{
  // Nothing to do
}


} // namespace