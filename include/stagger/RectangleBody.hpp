// stagger/RectangleBody.hpp
// Copyright (C) 2014-2015 Krishan Wyse (kwysek@gmail.com)
#ifndef STAGGER_RECTANGLE_BODY_HPP_
#define STAGGER_RECTANGLE_BODY_HPP_


#include <memory>
#include "stagger/Body.hpp"


namespace sgr
{


class RectangleBody : public Body
{
public:
  RectangleBody(World* world,
                const sf::Vector2f& size,
                BodyType type = BodyType::STATIC);

  // TODO: Needs copy constructor
  // TODO: Needs setRotation()

  void setSize(float width, float height);
  void setSize(const sf::Vector2f& size);

  const sf::Vector2f& getSize() const;
  unsigned int getPointCount() const;
  sf::Vector2f getPoint(unsigned int index) const;

private:
  // TODO: Pimpl this
  sf::Vector2f mSize;
};


} // namespace sgr


#endif // STAGGER_RECTANGLE_BODY_HPP_