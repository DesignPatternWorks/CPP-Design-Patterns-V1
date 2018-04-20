#pragma once

#include <ft2build.h>
#include <freetype/freetype.h>

#include <GL/glew.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>

#include "ShaderUtils.h"

struct TextRenderer {
  FT_Library library;
  FT_Face face;
  GLuint program;
  GLint attribute_coord;
  GLint uniform_tex;
  GLint uniform_color;
  GLuint vbo;
  size_t char_width, char_height;

  TextRenderer() { Initialize(); }

  ~TextRenderer() { /* glDeleteProgram(program); */ }

  /// Initializes FreeType and sets all structure fields.
  void Initialize();

  void DrawText(const char *text, float x, float y, float sx, float sy) const;
};
