// stagger/CircleBody.hpp
// Copyright (C) 2014-2015 Krishan Wyse (kwysek@gmail.com)
#ifndef STAGGER_CIRCLE_BODY_HPP_
#define STAGGER_CIRCLE_BODY_HPP_


#include <memory>
#include "stagger/Body.hpp"


///
/// \brief Namespace for Stagger
///
namespace sgr
{


///
/// \brief Class representing circle bodies
///
class CircleBody : public Body
{
public:
  ///
  /// \brief Construct a new circular body
  ///
  /// This constructor creates a new circular body object. Like sf::CircleShape,
  /// it takes an optional point count argument and therefore the class can
  /// represent arbitrarily sided polygons.
  ///
  /// \param world The sgr::World container for the body
  /// \param radius The radius of the body, in meters
  /// \param type The sgr::BodyType (static, dynamic or kinematic)
  /// \param pointCount The number of vertices making up the circle
  ///
  CircleBody(World* world,
             float radius,
             BodyType type = BodyType::STATIC,
             unsigned int pointCount = 30);

  ///
  /// \brief Construct a new circular body
  ///
  /// This constructor creates a new circular body object. Like sf::CircleShape,
  /// it takes an optional point count argument and therefore the class can
  /// represent arbitrarily sided polygons.
  ///
  /// \param world The sgr::World container for the body
  /// \param radius The radius of the body, in meters
  /// \param pointCount The number of vertices making up the circle
  /// \param type The sgr::BodyType (static, dynamic or kinematic)
  ///
  CircleBody(World* world,
             float radius,
             unsigned int pointCount,
             BodyType type = BodyType::STATIC);

  // TODO: Needs copy constructor
  // TODO: Needs setRotation()

  ///
  /// \brief Set the radius of the circular body
  ///
  /// \param radius The new radius of the circular body
  ///
  /// \see getRadius
  ///
  void setRadius(float radius);

  ///
  /// \brief Get the radius of the circular body
  ///
  /// \return The new radius of the circular body
  ///
  /// \see setRadius
  ///
  float getRadius() const;

  ///
  /// \brief Get the point count of the circular body
  ///
  /// \return radius The point count for the circular body
  ///
  unsigned int getPointCount() const;

  ///
  /// \brief Get a point of the circular body
  ///
  /// \param index The index of the point to be returned
  ///
  /// \return An indexed point for the circular body
  ///
  sf::Vector2f getPoint(unsigned int index) const;

private:
  // TODO: Pimpl this
  float mRadius; ///< The radius of the circular body
  unsigned int mPointCount; ///< The point count of the circular object
};


} // namespace sgr


#endif // STAGGER_CIRCLE_BODY_HPP_


///
/// \class sgr::CircleBody
///
/// This class represents a circular body object. It inherits from sf::Shape,
/// and so can be manipulated like most other SFML shape objects. The
/// interface is designed to mimic that of the sf::CircleShape class. Like
/// sf::CircleShape, it can represent an arbitrarily sided polygon by
/// changing the point count.
///
/// Usage example:
/// \code
/// sgr::World world(window, gravity);
///
/// sgr::CircleBody body(&world, 1.f, sgr::BodyType::DYNAMIC);
/// body.setPosition(10.f, 5.f);
/// body.setFillColor(sf::Color::Red);
/// \endcode
///