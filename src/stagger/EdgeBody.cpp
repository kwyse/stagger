// stagger/EdgeBody.cpp
// Copyright (c) 2014-2015 Krishan Wyse (kwysek@gmail.com)
#include "stagger/EdgeBody.hpp"

#include <Box2D/Collision/Shapes/b2EdgeShape.h>
#include <SFML/Graphics/RenderTarget.hpp>
#include "stagger/World.hpp"


namespace sgr
{


EdgeBody::EdgeBody(World& world, BodyType type)
: Body(world, type)
, mEdge({ sf::Vertex(), sf::Vertex() })
{
  b2EdgeShape fixtureShape;
  initializeFixture(fixtureShape);
}

EdgeBody::EdgeBody(World& world,
                   const sf::Vector2f& start,
                   const sf::Vector2f& end,
                   BodyType type)
: Body(world, type)
, mEdge({ sf::Vertex(start), sf::Vertex(end) })
{
  b2EdgeShape fixtureShape;
  fixtureShape.Set(b2Vec2(start.x, -start.y), b2Vec2(end.x, -end.y));
  initializeFixture(fixtureShape);
}

void EdgeBody::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  sf::Vector2f v1(mEdge[0].position.x * mPixelsPerMeter, mEdge[0].position.y * mPixelsPerMeter);
  sf::Vector2f v2(mEdge[1].position.x * mPixelsPerMeter, mEdge[1].position.y * mPixelsPerMeter);

  sf::Vertex edge[] = { sf::Vertex(v1), sf::Vertex(v2) };
  target.draw(edge, 2, sf::Lines, states);
}

void EdgeBody::setStartVertex(float x, float y)
{
  setStartVertex(sf::Vector2f(x, y));
}

void EdgeBody::setStartVertex(const sf::Vector2f& vertex)
{
  mEdge[0] = sf::Vertex(vertex);
  setEdgeVertices();
}

void EdgeBody::setEndVertex(float x, float y)
{
  setEndVertex(sf::Vector2f(x, y));
}

void EdgeBody::setEndVertex(const sf::Vector2f& vertex)
{
  mEdge[1] = sf::Vertex(vertex);
  setEdgeVertices();
}

sf::Vector2f EdgeBody::getStartVertex() const
{
  return sf::Vector2f(mEdge[0].position.x, mEdge[0].position.y);
}

sf::Vector2f EdgeBody::getEndVertex() const
{
  return sf::Vector2f(mEdge[1].position.x, mEdge[1].position.y);
}

unsigned int EdgeBody::getPointCount() const
{
  return 2;
}

sf::Vector2f EdgeBody::getPoint(unsigned int index) const
{
  return sf::Vector2f(mEdge[index].position.x, mEdge[index].position.y);
}

void EdgeBody::setEdgeVertices()
{
  b2EdgeShape fixtureShape;
  fixtureShape.Set(b2Vec2(mEdge[0].position.x, -mEdge[0].position.y),
                   b2Vec2(mEdge[1].position.x, -mEdge[1].position.y));
  reinitializeFixture(*mBody->GetFixtureList(), fixtureShape);
}


} // namespace sgr