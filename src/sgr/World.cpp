// sgr/World.cpp
#include "sgr/World.hpp"

#include <vector>
#include <Box2D/Dynamics/b2World.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include "sgr/RenderEntity.hpp"


const int32 VEL_ITERATIONS = 6;
const int32 POS_ITERATIONS = 2;


namespace sgr
{


struct World::Impl
{
  Impl(sf::RenderWindow& window, sf::Vector2f gravity)
  : mWindow(window)
  , mWorld(b2Vec2(gravity.x, gravity.y))
  , mPixelsPerMeter(16)
  , mTicksPerSecond(120.f)
  , mEntities()
  {
    // Nothing to do
  }

  sf::RenderWindow& mWindow;
  b2World mWorld; // TODO: Should this be dynamically allocated?
  int mPixelsPerMeter;
  float mTicksPerSecond;
  std::vector<RenderEntity*> mEntities;
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

void World::processInput()
{
  // Nothing to do
}

void World::update()
{
  mImpl->mWorld.Step(1.f / mImpl->mTicksPerSecond,
                     VEL_ITERATIONS,
                     POS_ITERATIONS);
  for (RenderEntity* entity : mImpl->mEntities) entity->update();
}

void World::render() {
  for (RenderEntity* entity : mImpl->mEntities) mImpl->mWindow.draw(*entity);
}

void World::addEntity(RenderEntity* entity)
{
  mImpl->mEntities.push_back(entity);
}

void World::setGravity(float x, float y)
{
  mImpl->mWorld.SetGravity(b2Vec2(x, y));
}

void World::setGravity(const sf::Vector2f& gravity)
{
  mImpl->mWorld.SetGravity(b2Vec2(gravity.x, gravity.y));
}

void World::setPixelsPerMeter(int pixels)
{
  mImpl->mPixelsPerMeter = pixels;
}

void World::setTicksPerSecond(float ticksPerSecond)
{
  mImpl->mTicksPerSecond = ticksPerSecond;
}

const sf::Vector2f World::getGravity() const
{
  b2Vec2 gravity = mImpl->mWorld.GetGravity();
  return sf::Vector2f(gravity.x, gravity.y);
}

int World::getPixelsPerMeter() const
{
  return mImpl->mPixelsPerMeter;
}

b2World* World::getB2World() const
{
  return &mImpl->mWorld;
}


} // namespace sgr
