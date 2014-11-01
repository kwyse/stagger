// Application.cpp
#include "Application.hpp"


#include <SFML/Window/Event.hpp>


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

  while (mWindow.isOpen()) {
    lag += elapsedTime.restart();
    sf::Event event;

    while (mWindow.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        mWindow.close();
    }

    while (lag > FRAME_DURATION) {
      lag -= FRAME_DURATION;
    }

    mWindow.clear();
    mWindow.display();
  }
}