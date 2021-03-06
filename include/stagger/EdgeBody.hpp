// stagger/EdgeEntity.hpp
// Copyright (c) 2014-2015 Krishan Wyse (kwysek@gmail.com)
#ifndef STAGGER_EDGE_BODY_HPP_
#define STAGGER_EDGE_BODY_HPP_


#include <array>
#include <memory>
#include <Box2D/Dynamics/b2Body.h>
#include <SFML/Graphics/Drawable.hpp>
#include "stagger/Body.hpp"


///
/// \brief Namespace for Stagger
///
namespace sgr
{


class World;


///
/// \brief Class representing edge bodies
///
class EdgeBody : public Body
{
public:
  ///
  /// \brief Construct a new edge body
  ///
  /// \param world The sgr::World container for the body
  /// \param type The sgr::BodyType (static, dynamic or kinematic)
  ///
  EdgeBody(World& world, BodyType type = BodyType::STATIC);

  ///
  /// \brief Construct a new edge body
  ///
  /// \param world The sgr::World container for the body
  /// \param start The starting coordinates of the edge, in meters
  /// \param end The ending coordinates of the edge, in meters
  /// \param type The sgr::BodyType (static, dynamic or kinematic)
  ///
  EdgeBody(World& world,
           const sf::Vector2f& start,
           const sf::Vector2f& end,
           BodyType type = BodyType::STATIC);

  ///
  /// \brief Draw the edge to the render target
  ///
  /// It is necessary to override the implementation provided in sf::Shape
  /// because a different form of the RenderTarget::draw() method is used to
  /// draw one lines.
  ///
  /// \param target Render target to draw to
  /// \param states Current render states
  ///
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  ///
  /// \brief Set the start vertex for the edge
  ///
  /// \param x The x-coordinate for the vertex
  /// \param y The y-coordinate for the vertex
  ///
  /// \see getStartVertex
  ///
  void setStartVertex(float x, float y);

  ///
  /// \brief Set the start vertex for the edge
  ///
  /// \param vertex The coordinates for the vertex
  ///
  /// \see getStartVertex
  ///
  void setStartVertex(const sf::Vector2f& vertex);

  ///
  /// \brief Set the end vertex for the edge
  ///
  /// \param x The x-coordinate for the vertex
  /// \param y The y-coordinate for the vertex
  ///
  /// \see getEndVertex
  ///
  void setEndVertex(float x, float y);

  ///
  /// \brief Set the end vertex for the edge
  ///
  /// \param vertex The coordinates for the vertex
  ///
  /// \see getEndVertex
  ///
  void setEndVertex(const sf::Vector2f& vertex);

  ///
  /// \brief Get the start vertex for the edge
  ///
  /// \return The start vertex
  ///
  /// \see setStartVertex
  ///
  sf::Vector2f getStartVertex() const;

  ///
  /// \brief Get the end vertex for the edge
  ///
  /// \return the end vertex
  ///
  /// \see setEndVertex
  ///
  sf::Vector2f getEndVertex() const;

  ///
  /// \brief Get the point count of the rectangular body
  ///
  /// \return radius The point count for the rectangular body
  ///
  unsigned int getPointCount() const;

  ///
  /// \brief Get a point of the rectangular body
  ///
  /// \param index The index of the point to be returned
  ///
  /// \return An indexed point for the rectangular body
  ///
  sf::Vector2f getPoint(unsigned int index) const;

private:
  // TODO: Pimpl this

  ///
  /// \brief Sets the vertices of the edge
  ///
  void setEdgeVertices();

  std::array<sf::Vertex, 2> mEdge; ///< The coordinates of the edge
};


} // namespace sgr


#endif // STAGGER_EDGE_BODY_HPP_


///
/// \class sgr::EdgeBody
///
/// This class represents an edge body object. It inherits from sf::Shape,
/// and so can be manipulated like most other SFML shape objects.
///
/// Usage example:
/// \code
/// sgr::World world(window, gravity);
///
/// sf::Vector2f start(5.f, 10.f);
/// sf::Vector2f end(20.f, 15.f);
/// sgr::EdgeBody slope(&world, start, end);
/// \endcode
///