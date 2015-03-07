#include "stagger/Stagger.hpp"

#include <Box2D/Box2D.h>
#include <catch/catch.hpp>
#include <SFML/Graphics.hpp>


SCENARIO("A World is initialized", "[world]") {
  GIVEN("A RenderWindow") {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Test");

    WHEN("The World constuctor is called") {
      sgr::World world(window);

      THEN("The other parameters are initialized") {
        REQUIRE(world.getGravity().x == 0.f);
        REQUIRE(world.getGravity().y == -0.f);
        REQUIRE(world.getPixelsPerMeter() == 16);
        REQUIRE(world.getTicksPerSecond() == 120.f);
      }
    }
  }

  GIVEN("A RenderWindow and a gravity vector") {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Test");
    sf::Vector2f gravity(5.f, 5.f);

    WHEN("The World constuctor is called") {
      sgr::World world(window, gravity);

      THEN("The other parameters are initialized") {
        REQUIRE(world.getGravity().x == gravity.x);
        REQUIRE(world.getGravity().y == gravity.y);
        REQUIRE(world.getPixelsPerMeter() == 16);
        REQUIRE(world.getTicksPerSecond() == 120.f);
      }
    }
  }
}

SCENARIO("World parameters are changed", "[world]") {
  GIVEN("An initialized World object") {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Test");
    sgr::World world(window);

    WHEN("The gravity is set to a new value using floats") {
      world.setGravity(5.f, -5.f);

      THEN("The gravity vector is updated") {
        REQUIRE(world.getGravity().x == 5.f);
        REQUIRE(world.getGravity().y == -5.f);
      }
    }

    WHEN("The gravity is set to a new value using a sf::Vector2f") {
      sf::Vector2f gravity(5.f, -5.f);
      world.setGravity(gravity);

      THEN("The gravity vector is updated") {
        REQUIRE(world.getGravity().x == gravity.x);
        REQUIRE(world.getGravity().y == gravity.y);
      }
    }

    WHEN("The pixels-per-meter value is set") {
      world.setPixelsPerMeter(32);

      THEN("The pixels-per-meter is updated") {
        REQUIRE(world.getPixelsPerMeter() == 32);
      }
    }

    WHEN("The ticks-per-second value is set") {
      world.setTicksPerSecond(60.f);

      THEN("The ticks-per-second value is updated") {
        REQUIRE(world.getTicksPerSecond() == 60.f);
      }
    }

    WHEN("The rendered edges toggle is set to true") {
      bool result = world.enableEdgeRendering(true);

      THEN("The rendered edges toggle is updated") {
        REQUIRE(result);
      }
    }

    WHEN("The rendered edges toggle is set to false") {
      bool result = world.enableEdgeRendering(false);

      THEN("The rendered edges toggle is updated") {
        REQUIRE_FALSE(result);
      }
    }
  }
}

SCENARIO("Body objects can be added to World objects", "[world]")
{
  GIVEN("An initialized World object")
  {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Test");
    sf::Vector2f gravity(10.f, 0.f);
    sgr::World world(window, gravity);

    WHEN("A static CircleBody object is added") {
      sgr::CircleBody circle(world, 1.f, sgr::BodyType::STATIC);

      THEN("The static CircleBody object is not acted upon by forces") {
        sf::Vector2f startPosition = circle.getPosition();
        world.update();
        REQUIRE(circle.getPosition().x == startPosition.x);
      }
    }

    WHEN("A dynamic CircleBody object is added") {
      sgr::CircleBody circle(world, 1.f, sgr::BodyType::DYNAMIC);

      THEN("The dynamic CircleBody object is acted upon by forces") {
        sf::Vector2f startPosition = circle.getPosition();
        world.update();
        REQUIRE(circle.getPosition().x != startPosition.x);
      }
    }

    WHEN("A static RectangleBody object is added") {
      sgr::CircleBody rect(world, 1.f, sgr::BodyType::STATIC);

      THEN("The static RectangleBody object is not acted upon by forces") {
        sf::Vector2f startPosition = rect.getPosition();
        world.update();
        REQUIRE(rect.getPosition().x == startPosition.x);
      }
    }

    WHEN("A dynamic RectangleBody object is added") {
      sgr::CircleBody rect(world, 1.f, sgr::BodyType::DYNAMIC);

      THEN("The dynamic RectangleBody object is acted upon by forces") {
        sf::Vector2f startPosition = rect.getPosition();
        world.update();
        REQUIRE(rect.getPosition().x != startPosition.x);
      }
    }

    WHEN("A static EdgeBody object is added") {
      sf::Vector2f start = sf::Vector2f(0.f, 0.f);
      sf::Vector2f end = sf::Vector2f(10.f, 0.f);
      sgr::EdgeBody edge(world, start, end);

      THEN("The static Edge object is not acted upon by forces") {
        sf::Vector2f startPosition = edge.getPosition();
        world.update();
        REQUIRE(edge.getPosition().x == startPosition.x);
      }
    }
  }
}
