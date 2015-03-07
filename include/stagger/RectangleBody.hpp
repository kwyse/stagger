// stagger/RectangleBody.hpp
// Copyright (c) 2014-2015 Krishan Wyse (kwysek@gmail.com)
#ifndef STAGGER_RECTANGLE_BODY_HPP_
#define STAGGER_RECTANGLE_BODY_HPP_


#include <memory>
#include "stagger/Body.hpp"


///
/// \brief Namespace for Stagger
///
namespace sgr
{


///
/// \brief Class representing rectangle bodies
///
class RectangleBody : public Body
{
public:
  ///
  /// \brief Construct a new rectangular body
  ///
  /// \param world The sgr::World container for the body
  /// \param size The size of the body, in meters
  /// \param type The sgr::BodyType (static, dynamic or kinematic)
  ///
  RectangleBody(World* world,
                const sf::Vector2f& size,
                BodyType type = BodyType::STATIC);

  // TODO: Needs copy constructor
  // TODO: Needs setRotation()

  ///
  /// \brief Set the size of the rectangular body
  ///
  /// \param width The new width of the rectangular body
  /// \param height The new height of the rectangular body
  ///
  /// \see getSize
  ///
  void setSize(float width, float height);

  ///
  /// \brief Set the size of the rectangular body
  ///
  /// \param size The new size of the rectangular body
  ///
  /// \see getSize
  ///
  void setSize(const sf::Vector2f& size);

  ///
  /// \brief Get the size of the rectangular body
  ///
  /// \return The size of the rectangular body
  ///
  /// \see setSize
  ///
  const sf::Vector2f& getSize() const;

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
  sf::Vector2f mSize; ///< The size of the rectangular body
};


} // namespace sgr


#endif // STAGGER_RECTANGLE_BODY_HPP_


///
/// \class sgr::RectangleBody
///
/// This class represents a rectangular body object. It inherits from sf::Shape,
/// and so can be manipulated like most other SFML shape objects. The
/// interface is designed to mimic that of the sf::RectangleShape class.
///
/// Usage example:
/// \code
/// sgr::World world(window, gravity);
///
/// sgr::RectangleBody rect(&world, sf::Vector2f(0.25f, 10.f),sgr::BodyType::DYNAMIC);
//  rect.setPosition(25.f, 10.f);
//  rect.setFillColor(sf::Color::Green);
/// \endcode
///