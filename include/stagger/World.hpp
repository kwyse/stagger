// stagger/World.hpp
// Copyright (c) 2014-2015 Krishan Wyse (kwysek@gmail.com)
#ifndef STAGGER_WORLD_HPP_
#define STAGGER_WORLD_HPP_


#include <memory>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>


class b2World;
namespace sf { class RenderWindow; }


///
/// \brief Namespace for Stagger
///
namespace sgr
{


class Body;
class EdgeBody;


///
/// \brief Class for containing and managing Body-derived objects
///
class World
{
public:

  ///
  /// \brief Construct a new world
  ///
  /// This constructor constructs a new World object, accepting an optional
  /// gravity vector.
  ///
  /// \param gravity The gravity vector used to simulate the bodies, in m/s^2
  ///
  explicit World(sf::Vector2f gravity = sf::Vector2f(0.f, 0.f));

  ///
  /// \brief Construct a new world
  ///
  /// This constructor constructs a new World object from an sf::RenderWindow
  /// object. It also takes an optional gravity vector.
  ///
  /// \param window The sf::RenderWindow to render the bodies to
  /// \param gravity The gravity vector used to simulate the bodies, in m/s^2
  ///
  explicit World(sf::RenderWindow& window,
                 sf::Vector2f gravity = sf::Vector2f(0.f, 0.f));

  World(const World&) = delete;
  World& operator=(const World&) = delete;

  ///
  /// \brief Destructor
  ///
  ~World();

  ///
  /// \brief Step through the simulation and update the bodies
  ///
  /// \param delta The time interval since last update
  ///
  void update(sf::Time delta);

  ///
  /// \brief Draw the bodies the window
  ///
  void render();

  ///
  /// \brief Add a body to the world
  ///
  /// \param body A Body-derived object to undergo simulation
  ///
  void addBody(Body& body);

  ///
  /// \brief Add an EdgeBody to the world
  ///
  /// \param body An EdgeBody object to undergo simulation
  ///
  void addBody(EdgeBody& body);

  ///
  /// \brief Set the gravity vector for the world
  ///
  /// \param x The vertical component for the gravity vector
  /// \param y The horizontal component for the gravity vector
  ///
  /// \see getGravity
  ///
  void setGravity(float x, float y);

  ///
  /// \brief Set the gravity vector for the world
  ///
  /// \param gravity The gravity vector
  ///
  /// \see getGravity
  ///
  void setGravity(const sf::Vector2f& gravity);

  ///
  /// \brief Set the pixels-per-meter ration for the world
  ///
  /// \param pixelsPerMeter The new value for the ratio
  ///
  /// \see getPixelsPerMeter
  ///
  void setPixelsPerMeter(int pixelsPerMeter);

  ///
  /// \brief Get the gravity vector for the world
  ///
  /// \return The gravity vector for the world
  ///
  /// \see setGravity
  ///
  const sf::Vector2f getGravity() const;

  ///
  /// \brief Get the pixels-per-meter ratio for the world
  ///
  /// \return The pixels-per-meter ratio for the world
  ///
  /// \see setPixelsPerMeter
  ///
  int getPixelsPerMeter() const;

  ///
  /// \brief Get the underlying b2World object manipulating the objects
  ///
  /// \return The underlying b2World object
  ///
  b2World* getB2World() const;

  ///
  /// \brief Toggle the rendering of EdgeBodies
  ///
  /// \return The new toggle value
  /// \param flag Toggle value
  ///
  bool enableEdgeRendering(bool flag);

private:
  struct Impl;
  std::unique_ptr<Impl> mImpl;
};


} // namespace sgr


#endif // STAGGER_WORLD_HPP_


///
/// \class sgr::World
///
/// This class acts as a container for sgr::Body-derived objects. It holds an
/// underlying b2World object and steps through it to simulate forces on the
/// bodies.
///
/// Usage example:
/// \code
/// sf::RenderWindow window(sf::VideoMode(640, 480), "Example");
/// sf::Vector2f gravity(0.f, -9.8f);
/// sgr::World world(window, gravity);
///
/// // Add a body object
/// sgr::CircleBody body(&world, 1.f, sgr::BodyType::DYNAMIC);
///
/// // Run the simulation
/// while (window.isOpen()) {
///   sf::Event event;
///
///   while (window.pollEvent(event)) {
///     world.update();
///     window.clear();
///     world.render();
///     window.display();
///   }
/// }
/// \endcode
///