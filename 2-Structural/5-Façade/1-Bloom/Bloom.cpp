#include "Console.h"
#include "TextBuffer.h"
#include "Window.h"
#include <boost/lexical_cast.hpp>

using namespace std;

int main() {
  // Console is a façade for Windows, Viewports, Buffers,... used by the terminal app
  auto window = Console::instance().multicolumn("Test", 2, 40, 40);

  for (size_t i = 0; i < 40; i++) {
    window->buffers[1]->add_string("This is line " + boost::lexical_cast<string>(i));
  }

  window->Show();

  return 0;
}
