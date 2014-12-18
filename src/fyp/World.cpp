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
  Impl(sf::RenderWindow& window, sf::Vector2f gravity)
  : mWindow(window)
  , mWorld(b2Vec2(gravity.x, gravity.y))
  , mPixelsPerMeter(16)
  , mTickRate(120.f)
  , mBodies()
  {
    // Nothing to do
  }

  sf::RenderWindow& mWindow;
  b2World mWorld;
  int mPixelsPerMeter;
  float mTickRate;
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

void World::processInput()
{
  // Nothing to do
}

void World::update()
{
  mImpl->mWorld.Step(1.f / mImpl->mTickRate, VEL_ITERATIONS, POS_ITERATIONS);
  for (BodySprite* body : mImpl->mBodies) body->update();
}

void World::render() {
  for (BodySprite *body : mImpl->mBodies) mImpl->mWindow.draw(*body);
}

void World::addBody(BodySprite* body) {
  mImpl->mBodies.push_back(body);
}
void World::setGravity(sf::Vector2f gravity)
{
  mImpl->mWorld.SetGravity(b2Vec2(gravity.x, gravity.y));
}

void World::setPixelsPerMeter(int pixels)
{
  mImpl->mPixelsPerMeter = pixels;
}

void World::setTickRate(float ticksPerSecond)
{
  mImpl->mTickRate = ticksPerSecond;
}

sf::Vector2f World::getGravity() const
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


} // namespace