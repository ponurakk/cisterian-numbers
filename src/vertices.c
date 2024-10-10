#include "vertices.h"
#include <stdlib.h>

Shape to10(Shape shape) {
  Vertices v = {.arr = malloc(shape.vertices.size * sizeof(float)),
                .size = shape.vertices.size};

  for (size_t i = 0; i < shape.vertices.size; i++) {
    v.arr[i] = shape.vertices.arr[i];
  }

  if (shape.vertices.size > 15)
    v.arr[15] = -v.arr[15];
  if (shape.vertices.size > 21)
    v.arr[21] = -v.arr[21];

  Shape new_shape = {.vertices = v, .indices = shape.indices};

  return new_shape;
}

Shape to100(Shape shape) {
  Vertices v = {.arr = malloc(shape.vertices.size * sizeof(float)),
                .size = shape.vertices.size};

  for (size_t i = 0; i < shape.vertices.size; i++) {
    v.arr[i] = shape.vertices.arr[i];
  }

  if (shape.vertices.size > 13)
    v.arr[13] = v.arr[13] - 0.49f;
  if (shape.vertices.size > 16)
    v.arr[16] = v.arr[16] - 0.49f;
  if (shape.vertices.size > 19)
    v.arr[19] = v.arr[19] - 0.49f;
  if (shape.vertices.size > 22)
    v.arr[22] = v.arr[22] - 0.49f;

  Shape new_shape = {.vertices = v, .indices = shape.indices};

  return new_shape;
}

Shape to1000(Shape shape) {
  Vertices v = {.arr = malloc(shape.vertices.size * sizeof(float)),
                .size = shape.vertices.size};

  for (size_t i = 0; i < shape.vertices.size; i++) {
    v.arr[i] = shape.vertices.arr[i];
  }

  if (shape.vertices.size > 13)
    v.arr[13] = v.arr[13] - 0.49f;
  if (shape.vertices.size > 16)
    v.arr[16] = v.arr[16] - 0.49f;
  if (shape.vertices.size > 19)
    v.arr[19] = v.arr[19] - 0.49f;
  if (shape.vertices.size > 22)
    v.arr[22] = v.arr[22] - 0.49f;
  if (shape.vertices.size > 15)
    v.arr[15] = -v.arr[15];
  if (shape.vertices.size > 21)
    v.arr[21] = -v.arr[21];

  Shape new_shape = {.vertices = v, .indices = shape.indices};

  return new_shape;
}
