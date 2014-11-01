// Application.hpp
#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_


#include "../include/fyp/World.hpp"
#include <SFML/Graphics/RenderWindow.hpp>


class Application
{
public:
  Application();
  Application(const Application&) = delete;
  Application& operator=(const Application&) = delete;

  void launch();

private:
  sf::RenderWindow mWindow;
  fyp::World mWorld;
};

#endif // APPLICATION_HPP_