#pragma once
#include <boost/optional.hpp>
#include <memory>
#include "IBuffer.h"

/// Responsible for rendering a view into a buffer.
class Viewport {
 protected:
  /// The buffer being rendered.
  std::shared_ptr<IBuffer> buffer;
  /// The location in the buffer from which input is taken.
  Point buffer_location;
  /// The point on the screen where the viewport is drawn.
  Point screen_location;
  /// The width and height of the viewport, in characters.
  Size size;

 public:
  Viewport(const std::shared_ptr<IBuffer>& buffer,
           boost::optional<Size> size = boost::none,
           boost::optional<Point> buffer_location = boost::none,
           boost::optional<Point> screen_location = boost::none)
      : buffer(buffer) {
    this->size = size.value_or(buffer->get_size());
    this->buffer_location = buffer_location.value_or(Point{});
    this->screen_location = screen_location.value_or(Point{});
  }

  /// Gets the character the buffer is meant to show, or 0 if out of bounds.
  char operator()(int x, int y) const {
    if ((x >= screen_location.x) && x < (screen_location.x + size.width) &&
        (y >= screen_location.y) && y < (screen_location.y + size.height)) {
      return (*buffer)(x - screen_location.x, y - screen_location.y);
    }
    return 0;
  }
};
