// sgr/EdgeEntity.cpp
#include "sgr/EdgeEntity.hpp"

#include <Box2D/Collision/Shapes/b2EdgeShape.h>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include <Box2D/Dynamics/b2World.h>
#include <SFML/Graphics/RenderTarget.hpp>
#include "sgr/World.hpp"


namespace sgr
{


EdgeEntity::EdgeEntity(World* world,
                       const sf::Vector2f& start,
                       const sf::Vector2f& end,
                       BodyType type)
: mBody()
, mEdge({ sf::Vertex(start), sf::Vertex(end) })
{
  b2BodyDef bodyDef;
  switch(type) {
    case BodyType::STATIC:
      // Default type is b2_staticBody
      break;
    case BodyType::DYNAMIC:
      bodyDef.type = b2_dynamicBody;
      break;
    case BodyType::KINEMATIC:
      bodyDef.type = b2_kinematicBody;
      break;
  }

  mBody = world->getB2World()->CreateBody(&bodyDef);
  world->addEntity(this);

  b2EdgeShape fixtureShape;
  fixtureShape.Set(b2Vec2(start.x, -start.y), b2Vec2(end.x, -end.y));

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &fixtureShape;
  fixtureDef.density = 1.f;
  fixtureDef.friction = 0.3f;
  mBody->CreateFixture(&fixtureDef);
}

void EdgeEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  sf::Vector2f v1(mEdge[0].position.x * 16, mEdge[0].position.y * 16);
  sf::Vector2f v2(mEdge[1].position.x * 16, mEdge[1].position.y * 16);

  sf::Vertex edge[] = { sf::Vertex(v1), sf::Vertex(v2) };
  target.draw(edge, 2, sf::Lines, states);
}


} // namespace sgr