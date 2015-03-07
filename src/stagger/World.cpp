// stagger/World.cpp
// Copyright (c) 2014-2015 Krishan Wyse (kwysek@gmail.com)
#include "stagger/World.hpp"

#include <vector>
#include <Box2D/Dynamics/b2World.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include "stagger/Body.hpp"
#include "stagger/EdgeBody.hpp"


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
  , mBodies()
  , mEdges()
  , bRenderEdges(false)
  {
    // Nothing to do
  }

  sf::RenderWindow& mWindow;
  b2World mWorld; // TODO: Should this be dynamically allocated?
  int mPixelsPerMeter;
  float mTicksPerSecond;
  std::vector<Body*> mBodies;
  std::vector<EdgeBody*> mEdges;
  bool bRenderEdges;
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

void World::update()
{
  mImpl->mWorld.Step(1.f / mImpl->mTicksPerSecond,
                     VEL_ITERATIONS,
                     POS_ITERATIONS);
  for (Body* body : mImpl->mBodies) body->update();
}

void World::render() {
  for (Body* body : mImpl->mBodies) {
    EdgeBody* edgeBody = dynamic_cast<EdgeBody*>(body);
    if (edgeBody && !(mImpl->bRenderEdges)) continue;
    mImpl->mWindow.draw(*body);
  }
}

void World::addBody(Body* body)
{
  mImpl->mBodies.push_back(body);
}

void World::addBody(EdgeBody* body)
{
  mImpl->mEdges.push_back(body);
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

float World::getTicksPerSecond() const
{
  return mImpl->mTicksPerSecond;
}

b2World* World::getB2World() const
{
  return &mImpl->mWorld;
}

bool World::enableEdgeRendering(bool flag)
{
  mImpl->bRenderEdges = flag;
  return mImpl->bRenderEdges;
}


} // namespace sgr
