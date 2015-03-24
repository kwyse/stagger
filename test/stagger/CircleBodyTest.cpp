#include "stagger/Stagger.hpp"

#include <Box2D/Box2D.h>
#include <catch/catch.hpp>
#include <SFML/Graphics.hpp>


SCENARIO("A CircleBody is initialized", "[circleBody]") {
  GIVEN("A World object") {
    sgr::World world(sf::Vector2f(0.f, -9.8f));

    WHEN("The CircleBody constructor is called") {
      sgr::CircleBody circle(world, 5.f);

      THEN("Then all parameters are initialized") {
        REQUIRE(circle.getRadius() == 5.f);
        REQUIRE(circle.getPointCount() == 30);
      }
    }

    WHEN("The CircleBody constructor is called") {
      sgr::CircleBody circle(world, 10.f, sgr::BodyType::DYNAMIC);

      THEN("Then all parameters are initialized") {
        REQUIRE(circle.getRadius() == 10.f);
        REQUIRE(circle.getPointCount() == 30);
      }
    }

    WHEN("The CircleBody constructor is called") {
      sgr::CircleBody circle(world, 15.f, 12);

      THEN("Then all parameters are initialized") {
        REQUIRE(circle.getRadius() == 15.f);
        REQUIRE(circle.getPointCount() == 12);
      }
    }

    WHEN("The CircleBody constructor is called") {
      sgr::CircleBody circle(world, 20.f, sgr::BodyType::DYNAMIC, 50);

      THEN("Then all parameters are initialized") {
        REQUIRE(circle.getRadius() == 20.f);
        REQUIRE(circle.getPointCount() == 50);
      }
    }

    WHEN("The CircleBody constructor is called") {
      sgr::CircleBody circle(world, 20.f, 70, sgr::BodyType::DYNAMIC);

      THEN("Then all parameters are initialized") {
        REQUIRE(circle.getRadius() == 20.f);
        REQUIRE(circle.getPointCount() == 70);
      }
    }
  }
}

SCENARIO("CircleBody parameters are changed", "[circleBody]") {
  GIVEN("An initialized CircleBody object") {
    sgr::World world(sf::Vector2f(0.f, -9.8f));
    sgr::CircleBody circle(world, 5.f);

    WHEN("The radius is set") {
      circle.setRadius(10.f);

      THEN("The radius value is updated") {
        REQUIRE(circle.getRadius() == 10.f);
      }
    }
  }
}