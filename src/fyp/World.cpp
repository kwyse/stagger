// fyp/World.cpp
#include "../../include/fyp/World.hpp"
#include "../../include/fyp/BodySprite.hpp"


#include <Box2D/Dynamics/b2World.h>


const float32 TIME_STEP = 1.f / 120.f;
const int32 VELOCITY_ITERATIONS = 6;
const int32 POSITION_ITERATIONS = 2;


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

  sf::RenderWindow& mWindow;
  b2World mWorld;
  std::vector<BodySprite*> mBodies;
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

b2World* World::getB2World()
{
  return &mImpl->mWorld;
}

void World::addBody(BodySprite* body) {
  mImpl->mBodies.push_back(body);
}

void World::update()
{
  mImpl->mWorld.Step(TIME_STEP, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
  for (BodySprite* body : mImpl->mBodies) body->update();
}


} // namespace