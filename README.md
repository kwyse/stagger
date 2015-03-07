# Stagger - A Box2D wrapper for SFML

## WARNING

Stagger is in heavy development and interface changes are likely!

## Depenencies

Stagger requires both [SFML](http://www.sfml-dev.org/) and
[Box2D](http://box2d.org/) when building. It also requires
[Catch](https://github.com/philsquared/Catch) for the unit tests, but this is
packaged alongside Stagger.

## Usage

A world object must first be created to hold all the interacting bodies. The
constructor accepts an `sf::RenderWindow` object and an optional gravity
vector.

```cpp
sf::RenderWindow window(sf::VideoMode(640, 480), "Example");
sgr::World world(window, sf::Vector2f(0.f, -9.8f));
```

You can create objects akin to each of the `sh::Shape` derived classes, in
addition to edges. All of these objects will automatically process collisions
and their interfaces are compatible with their SFML counterparts, with the
notable exception that the unit used is meters, not pixels. You must
therefore pass arguments in terms of meters, and can set the ratio between
the two using `World::setPixelsPerMeter()`.

```cpp
sgr::CircleBody circle(world, 1.f, sgr::BodyType::DYNAMIC);
circle.setPosition(10.f, 5.f);
circle.setFillColor(sf::Color::Red);
```

In the game loop, calling `World::update()` and `World::render()` will update
the positions of the objects and render the objects respectively.

## A Simple Example

```cpp
int main()
{
  sf::RenderWindow window(sf::VideoMode(640, 480), "Example");
  sgr::World world(window, sf::Vector2f(0.f, -9.8f));

  sgr::CircleBody circle(world, 1.f, sgr::BodyType::DYNAMIC);
  circle.setPosition(10.f, 5.f);
  circle.setFillColor(sf::Color::Red);

  sf::Vector2f start(5.f, 10.f);
  sf::Vector2f end(20.f, 15.f);
  sgr::EdgeBody slope(world, start, end);

  sf::Clock elapsedTime;
  sf::Time lag = sf::Time::Zero;
  static const sf::Time FRAME_DURATION = sf::milliseconds(1000.f / 60.f);

  while (window.isOpen()) {
    lag += elapsedTime.restart();
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    if (lag > FRAME_DURATION) {
      world.update();
      lag -= FRAME_DURATION;
    }

    window.clear();
    world.render();
    window.display();
  }
}
```

The three variables declared above the outer `while` loop are necessary to
ensure a smooth simulation. Without capping the number of calls to
`World::update()` per second, the simulation would likely run far too fast on a
modern computer.
