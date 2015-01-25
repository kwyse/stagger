#include "stagger/Stagger.hpp"

#include <Box2D/Box2D.h>
#include <catch/catch.hpp>
#include <SFML/Graphics.hpp>


SCENARIO("A EdgeBody is initialized", "[edgeBody]") {
  GIVEN("A World object") {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Test");
    sgr::World world(window, sf::Vector2f(0.f, -9.8f));

    WHEN("The EdgeBody constructor is called without a BodyType") {
      sf::Vector2f start(5.f, 10.f);
      sf::Vector2f end(20.f, 15.f);
      sgr::EdgeBody edge(&world, start, end);

      THEN("Then all parameters are initialized") {
        REQUIRE(edge.getPointCount() == 2);
        REQUIRE(edge.getStartVertex().x == 5.f);
        REQUIRE(edge.getStartVertex().y == 10.f);
        REQUIRE(edge.getEndVertex().x == 20.f);
        REQUIRE(edge.getEndVertex().y == 15.f);
      }
    }

    WHEN("The EdgeBody constructor is called with a BodyType") {
      sf::Vector2f start(15.f, 5.f);
      sf::Vector2f end(2.f, 35.f);
      sgr::EdgeBody edge(&world, start, end, sgr::BodyType::STATIC);

      THEN("Then all parameters are initialized") {
        REQUIRE(edge.getPointCount() == 2);
        REQUIRE(edge.getStartVertex().x == 15.f);
        REQUIRE(edge.getStartVertex().y == 5.f);
        REQUIRE(edge.getEndVertex().x == 2.f);
        REQUIRE(edge.getEndVertex().y == 35.f);
      }
    }
  }
}

SCENARIO("EdgeBody parameters are changed", "[edgeBody]") {
  GIVEN("An initialized EdgeBody object") {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Test");
    sgr::World world(window, sf::Vector2f(0.f, -9.8f));
    sf::Vector2f start(0.f, -10.f);
    sf::Vector2f end(-20.f, -15.f);
    sgr::EdgeBody edge(&world, start, end);

    WHEN("The start vertex is set using floats") {
      edge.setStartVertex(15.f, 5.f);

      THEN("The start vertex value is updated") {
        REQUIRE(edge.getStartVertex().x == 15.f);
        REQUIRE(edge.getStartVertex().y == 5.f);
      }
    }

    WHEN("The start vertex is set using a sf::Vector2f") {
      edge.setStartVertex(sf::Vector2f(25.f, 45.f));

      THEN("The start vertex value is updated") {
        REQUIRE(edge.getStartVertex().x == 25.f);
        REQUIRE(edge.getStartVertex().y == 45.f);
      }
    }

    WHEN("The end vertex is set using floats") {
      edge.setEndVertex(10.f, 0.f);

      THEN("The end vertex value is updated") {
        REQUIRE(edge.getEndVertex().x == 10.f);
        REQUIRE(edge.getEndVertex().y == 0.f);
      }
    }

    WHEN("The end vertex is set using a sf::Vector2f") {
      edge.setEndVertex(sf::Vector2f(20.f, 40.f));

      THEN("The end vertex value is updated") {
        REQUIRE(edge.getEndVertex().x == 20.f);
        REQUIRE(edge.getEndVertex().y == 40.f);
      }
    }
  }
}