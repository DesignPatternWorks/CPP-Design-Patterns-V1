#include <iostream>

struct Renderer {
  virtual void render_circle(float x, float y, float radius) = 0;
};

struct VectorRender : Renderer {
  void render_circle(float x, float y, float radius) override {
    std::cout << "Drawing a vector circle of radius " << radius << std::endl;
  }
};

struct RasterRenderer : Renderer {
  void render_circle(float x, float y, float radius) override {
    std::cout << "Rasterizing a circle of radius " << radius << std::endl;
  }
};

struct Shape {
 protected:
  Renderer& renderer;
  Shape(Renderer& renderer) : renderer{renderer} {}

 public:
  virtual void draw() = 0;
  virtual void resize(float factor) = 0;
};

struct Circle : Shape {
  void draw() override { renderer.render_circle(x, y, radius); }

  void resize(float factor) override { radius *= factor; }

  float x, y, radius;

  Circle(Renderer& renderer, const float x, const float y, const float radius)
      : Shape{renderer}, x{x}, y{y}, radius{radius} {}
};

int main() {
  RasterRenderer rasterRenderer;
  // Circle uses a raster renderer which is a reference to a Renderer.
  Circle raster_circle{rasterRenderer, 10, 10, 5};
  raster_circle.draw();
  raster_circle.resize(2);
  raster_circle.draw();

  return 0;
}
