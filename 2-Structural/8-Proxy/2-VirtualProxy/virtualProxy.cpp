#include <iostream>
#include <memory>
#include <sstream>
#include <string>

using namespace std;

struct Image {
  virtual ~Image() = default;
  virtual void draw() = 0;
};

struct Bitmap : Image {
  Bitmap(const string& filename) { cout << "Loading image from " << filename << endl; }

  void draw() override { cout << "Drawing image" << endl; }
};

struct LazyBitmap : Image {
  LazyBitmap(const string& filename) : filename(filename) {}
  ~LazyBitmap() { delete bmp; }
  void draw() override {
    if (!bmp) bmp = new Bitmap(filename);
    bmp->draw();
  }

 private:
  Bitmap* bmp{nullptr};
  string filename;
};

void draw_image(Image& img) {
  cout << "About to draw the image" << endl;
  img.draw();
  cout << "Done drawing the image"
       << "\n---------------------------\n";
}

int main() {
  LazyBitmap img{"pokemon.png"};
  // Image will only be loaded on first attempt to draw the image.
  draw_image(img);
  draw_image(img);
  draw_image(img);

  return 0;
}
