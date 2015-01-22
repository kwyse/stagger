// stagger/Body.hpp
// Copyright (C) 2014-2015 Krishan Wyse (kwysek@gmail.com)
#ifndef STAGGER_BODY_HPP_
#define STAGGER_BODY_HPP_


#include <memory>
#include <SFML/Graphics/Shape.hpp>


class b2Body;
class b2Shape;

///
/// \brief Namespace for Stagger
///
namespace sgr
{


class World;

///
/// \brief Enumeration for the three types of simulated bodies
///
enum class BodyType
{
  STATIC, ///< Bodies that do not move and ignore forces applied to them
  DYNAMIC, ///< Bodies that move and react to applied forces
  KINEMATIC ///< Bodies that can move, but do not react to applied forces
};

///
/// \brief Base class for shapes to be simulated
///
class Body : public sf::Shape
{
public:
  ///
  /// \brief Construct a new body
  ///
  /// This constructor is called from the subclass shape objects to initialize
  /// the body, the pixels-per-meter value, and add the body the World
  /// container.
  ///
  /// \param world The containing world object for the body
  /// \param type The type of the body (static, dynamic or kinematic)
  ///
  explicit Body(World* world, BodyType type = BodyType::STATIC);

  ///
  /// \brief Update the position of the body for rendering
  ///
  /// This method updates the SFML coordinates of the body so that it can be
  /// rendered, taking into account the pixel-per-meter ratio.
  ///
  void update();

  void addShape(sf::Shape& shape);

  ///
  /// \brief Set the position of the body
  ///
  /// This method sets the position of the body in meters from the top left
  /// corner.
  ///
  /// \param x The distance, in meters, from the left side
  /// \param y The distance, in meters, from the top side
  ///
  /// \see getPosition
  ///
  void setPosition(float x, float y);

  ///
  /// \brief Set the position of the body
  ///
  /// This method sets the position of the body in meters from the top left
  /// corner.
  ///
  /// \param position A vector containing the lengths, in meters, from the sides
  ///
  /// \see getPosition
  ///
  void setPosition(const sf::Vector2f& position);

  ///
  /// \brief Set the angular velocity of the body
  ///
  /// \param angle The new angular velocity
  ///
  /// \see getAngularVelocity
  ///
  void setAngularVelocity(float angle);

  ///
  /// \brief Set the linear velocity of the body
  ///
  /// \param x The new velocity along the x-axis
  /// \param y The new velocity along the y-axis
  ///
  /// \see getLinearVelocity
  ///
  void setLinearVelocity(float x, float y);

  ///
  /// \brief Set the linear velocity of the body
  ///
  /// \param velocity The new linear velocity
  ///
  /// \see getLinearVelocity
  ///
  void setLinearVelocity(const sf::Vector2f& velocity);

  ///
  /// \brief Get the position of the body, in meters from the top left corner
  ///
  /// \return The position of the body, in meters
  ///
  /// \see setPosition
  ///
  sf::Vector2f getPosition() const;

  ///
  /// \brief Get the angle of the body, in degrees
  ///
  /// \return The angle of the body, in degrees
  ///
  float getAngle() const;

  ///
  /// \brief Get the anglular velocity of the body, in degrees
  ///
  /// \return The anglular velocity of the body, in degrees
  ///
  /// \see setAngularVelocity
  ///
  float getAngularVelocity() const;

  ///
  /// \brief Get the linear velocity of the body, in meters
  ///
  /// \return The linear velocity of the body, in meters
  ///
  /// \see setLinearVelocity
  ///
  sf::Vector2f getLinearVelocity() const;

protected:

  ///
  /// \brief Set a fixture's default values and attach it to the body
  ///
  /// \param shape The b2Shape subclass object to be used as the fixture
  ///
  void initializeFixture(b2Shape* shape);

  static constexpr float DEGREES_PER_RADIAN = 57.2957795f;

  b2Body* mBody; ///< Underlying body being simulated
  int mPixelsPerMeter; ///< Ratio of pixels to meters
};


} // namespace sgr


#endif // STAGGER_BODY_HPP_


///
/// \class sgr::Body
///
/// This class inherits the methods from sf::Shape, so its subclasses can be
/// manipulated just like the subclasses of sf::Shape. New methods follow the
/// naming conventions of these classes.
///
/// \see sgr::CircleBody, sgr::RectangleBody, sgr::EdgeBody
///