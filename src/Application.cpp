// Application.cpp
#include "Application.hpp"

#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>

#include "fyp/BodySprite.hpp"
#include "fyp/World.hpp"


Application::Application()
{
  // Nothing to do
}

void Application::launch()
{
  sf::RenderWindow window(sf::VideoMode(640, 480), "FYP Test Implementation");
  fyp::World world(window, sf::Vector2f(0.f, -9.8f), 16);

  float tickRate = 120.f;
  const sf::Time FRAME_DURATION = sf::milliseconds(1000.f / tickRate);
  world.setTickRate(tickRate);

  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  b2PolygonShape shape;
  shape.SetAsBox(1.f, 1.f);
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &shape;
  fixtureDef.density = 1.f;
  fixtureDef.friction = 0.3f;

  sf::Texture texture;
  texture.loadFromFile("../assets/images/box.png");
  fyp::BodySprite bodySprite(world, bodyDef, fixtureDef);
  bodySprite.setTexture(texture);
  bodySprite.setSize(sf::Vector2f(2.f, 2.f));
  bodySprite.setPosition(sf::Vector2f(1.f, 1.f));

  sf::Clock elapsedTime;
  sf::Time lag = sf::Time::Zero;

  while (window.isOpen()) {
    lag += elapsedTime.restart();
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    while (lag > FRAME_DURATION) {
      world.update();
      lag -= FRAME_DURATION;
    }

    window.clear();
    world.render();
    window.display();
  }
}