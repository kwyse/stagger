// Application.hpp
#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_


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
};

#endif // APPLICATION_HPP_