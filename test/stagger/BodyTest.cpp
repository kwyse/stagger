#include "stagger/Stagger.hpp"

#include <Box2D/Box2D.h>
#include <catch/catch.hpp>
#include <SFML/Graphics.hpp>


SCENARIO("A Body-derived object is initialized", "[body]") {
  GIVEN("A World object") {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Test");
    sgr::World world(window, sf::Vector2f(0.f, -9.8f));

    WHEN("The Body-dervied object's constructor is called without a BodyType") {
      sgr::CircleBody body(&world, 1.f);

      THEN("Then all parameters are initialized") {
        REQUIRE(body.getPosition().x == 0.f);
        REQUIRE(body.getPosition().y == 0.f);
        REQUIRE(body.getAngle() == 0.f);
        REQUIRE(body.getAngularVelocity() == 0.f);
        REQUIRE(body.getLinearVelocity().x == 0.f);
        REQUIRE(body.getLinearVelocity().y == 0.f);
      }
    }

    WHEN("The Body-derived object's constructor is called with a BodyType") {
      sgr::CircleBody body(&world, 1.f, sgr::BodyType::DYNAMIC);

      THEN("Then all parameters are initialized") {
        REQUIRE(body.getPosition().x == 0.f);
        REQUIRE(body.getPosition().y == 0.f);
        REQUIRE(body.getAngle() == 0.f);
        REQUIRE(body.getAngularVelocity() == 0.f);
        REQUIRE(body.getLinearVelocity().x == 0.f);
        REQUIRE(body.getLinearVelocity().y == 0.f);
      }
    }
  }
}

SCENARIO("Body-dervied object parameters are changed", "[body]") {
  GIVEN("An initialized Body-dervied object") {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Test");
    sgr::World world(window, sf::Vector2f(0.f, -9.8f));
    sgr::CircleBody body(&world, 1.f, sgr::BodyType::DYNAMIC);

    WHEN("The position is set using floats") {
      body.setPosition(10.f, 20.f);

      THEN("The position value is updated") {
        REQUIRE(body.getPosition().x == 10.f);
        REQUIRE(body.getPosition().y == 20.f);
      }
    }

    WHEN("The position is set using a sf::Vector2f") {
      body.setPosition(sf::Vector2f(5.f, 15.f));

      THEN("The position value is updated") {
        REQUIRE(body.getPosition().x == 5.f);
        REQUIRE(body.getPosition().y == 15.f);
      }
    }

    WHEN("The anglular velocity is set") {
      body.setAngularVelocity(45.f);

      THEN("The angle value is updated") {
        REQUIRE(body.getAngularVelocity() == 45.f);
      }
    }

    WHEN("The linear velocity is set using floats") {
      body.setLinearVelocity(30.f, 35.f);

      THEN("The linear velocity value is updated") {
        REQUIRE(body.getLinearVelocity().x == 30.f);
        REQUIRE(body.getLinearVelocity().y == 35.f);
      }
    }

    WHEN("The linear velocity is set using a sf::Vector2f") {
      body.setLinearVelocity(sf::Vector2f(45.f, 25.f));

      THEN("The linear velocity value is updated") {
        REQUIRE(body.getLinearVelocity().x == 45.f);
        REQUIRE(body.getLinearVelocity().y == 25.f);
      }
    }
  }
}