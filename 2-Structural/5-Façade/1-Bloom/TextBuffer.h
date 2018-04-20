#pragma once
#include <boost/circular_buffer.hpp>
#include <vector>
#include "IBuffer.h"
#include <sstream>

class TextBuffer : public IBuffer {
  boost::circular_buffer<std::string> lines;
  const std::string line_break = "\n";
  uint32_t width, height;

 public:
  TextBuffer(uint32_t width, uint32_t height);
  Size get_size() const override;
  std::string to_string();
  char operator()(uint32_t x, uint32_t y) override;
  void add_string(const std::string& s) override;
};
