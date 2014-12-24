#include "sgr/World.hpp"

#include <Box2D/Box2D.h>
#include <catch/catch.hpp>
#include <SFML/Graphics.hpp>


TEST_CASE("World is initialized", "world")
{
  sf::RenderWindow window(sf::VideoMode(640, 480), "Test");
  sf::Vector2f gravity(0.f, -9.8f);

  sgr::World world(window, gravity);
  REQUIRE(world.getPixelsPerMeter() == 16);
}