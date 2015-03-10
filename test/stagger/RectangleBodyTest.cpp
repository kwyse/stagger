#include "stagger/Stagger.hpp"

#include <Box2D/Box2D.h>
#include <catch/catch.hpp>
#include <SFML/Graphics.hpp>


SCENARIO("A RectangleBody is initialized", "[rectangleBody]") {
  GIVEN("A World object") {
    sgr::World world(sf::Vector2f(0.f, -9.8f));

    WHEN("The RectangleBody constructor is called without a BodyType") {
      sgr::RectangleBody rect(world, sf::Vector2f(5.f, 10.f));

      THEN("Then all parameters are initialized") {
        REQUIRE(rect.getSize().x == 5.f);
        REQUIRE(rect.getSize().y == 10.f);
        REQUIRE(rect.getPointCount() == 4);
      }
    }

    WHEN("The RectangleBody constructor is called with a BodyType") {
      sgr::RectangleBody rect(world, sf::Vector2f(10.f, 15.f), sgr::BodyType::DYNAMIC);

      THEN("Then all parameters are initialized") {
        REQUIRE(rect.getSize().x == 10.f);
        REQUIRE(rect.getSize().y == 15.f);
        REQUIRE(rect.getPointCount() == 4);
      }
    }
  }
}

SCENARIO("RectangleBody parameters are changed", "[rectangleBody]") {
  GIVEN("An initialized RectangleBody object") {
    sgr::World world(sf::Vector2f(0.f, -9.8f));
    sgr::RectangleBody rect(world, sf::Vector2f(5.f, 10.f));

    WHEN("The size is set using floats") {
      rect.setSize(20.f, 2.f);

      THEN("The size value is updated") {
        REQUIRE(rect.getSize().x == 20.f);
        REQUIRE(rect.getSize().y == 2.f);
      }
    }

    WHEN("The size is set using a sf::Vector2f") {
      rect.setSize(sf::Vector2f(4.f, 16.f));

      THEN("The size value is updated") {
        REQUIRE(rect.getSize().x == 4.f);
        REQUIRE(rect.getSize().y == 16.f);
      }
    }
  }
}