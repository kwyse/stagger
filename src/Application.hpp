// Application.hpp
#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_


class Application
{
public:
  Application();
  Application(const Application&) = delete;
  Application& operator=(const Application&) = delete;

  void launch();
};

#endif // APPLICATION_HPP_