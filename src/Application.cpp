// Application.cpp
#include "Application.hpp"


#include <SFML/Window/Event.hpp>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include "../include/fyp/BodySprite.hpp"


Application::Application()
: mWindow(sf::VideoMode(640, 480), "FYP Test Implementation")
, mWorld(mWindow, sf::Vector2f(0.f, -9.8f))
{
  // Nothing to do
}

void Application::launch()
{
  const sf::Time FRAME_DURATION = sf::milliseconds(1000 / 120);
  sf::Clock elapsedTime;
  sf::Time lag = sf::Time::Zero;

  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  b2PolygonShape shape;
  shape.SetAsBox(1.f, 1.f);
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &shape;
  fixtureDef.density = 1.f;
  fixtureDef.friction = 0.3f;
  fyp::BodySprite bodySprite(mWorld, bodyDef, fixtureDef);

  while (mWindow.isOpen()) {
    lag += elapsedTime.restart();
    sf::Event event;

    while (mWindow.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        mWindow.close();
    }

    while (lag > FRAME_DURATION) {
      mWorld.update();
      lag -= FRAME_DURATION;
    }

    mWindow.clear();
    mWindow.display();
  }
}