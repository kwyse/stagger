// fyp/World.cpp
#include "fyp/World.hpp"

#include <vector>

#include <Box2D/Dynamics/b2World.h>
#include <SFML/Graphics/RenderWindow.hpp>

#include "fyp/BodySprite.hpp"


const int32 VEL_ITERATIONS = 6;
const int32 POS_ITERATIONS = 2;


namespace fyp
{


struct World::Impl
{
  Impl(sf::RenderWindow& window, sf::Vector2f gravity, int pixelsPerMeter)
  : mWindow(window)
  , mWorld(b2Vec2(gravity.x, gravity.y))
  , mBodies()
  , mPixelsPerMeter(pixelsPerMeter)
  , mTickRate(120.f)

  {
    // Nothing to do
  }

  sf::RenderWindow& mWindow;
  b2World mWorld;
  std::vector<BodySprite*> mBodies;
  int mPixelsPerMeter;
  float mTickRate;
};

World::World(sf::RenderWindow& window, sf::Vector2f gravity, int pixelsPerMeter)
: mImpl(new World::Impl(window, gravity, pixelsPerMeter))
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
  mImpl->mWorld.Step(1.f / mImpl->mTickRate, VEL_ITERATIONS, POS_ITERATIONS);
  for (BodySprite* body : mImpl->mBodies) body->update();
}

void World::render()
{
  for (BodySprite* body : mImpl->mBodies) mImpl->mWindow.draw(*body);
}

void World::setTickRate(float ticksPerSecond)
{
  mImpl->mTickRate = ticksPerSecond;
}

int World::getPixelsPerMeter() const
{
  return mImpl->mPixelsPerMeter;
}


} // namespace