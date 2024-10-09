#include "vertices.h"
#include <stdio.h>
#include <stdlib.h>

Shape to10(Shape shape) {
  float *new_vertices = malloc(shape.vertices.size * sizeof(float));
  if (!new_vertices) {
    perror("Failed to allocate memory for new vertices");
  }

  for (size_t i = 0; i < shape.vertices.size; i++) {
    new_vertices[i] = shape.vertices.arr[i];
  }

  if (shape.vertices.size > 15)
    new_vertices[15] = -new_vertices[15];
  if (shape.vertices.size > 21)
    new_vertices[21] = -new_vertices[21];

  Shape new_shape = {
      .vertices = {.arr = new_vertices, .size = sizeof(new_vertices)},
      .indices = shape.indices};

  return new_shape;
}

Shape to100(Shape shape) {
  float *new_vertices = malloc(shape.vertices.size * sizeof(float));
  if (!new_vertices) {
    perror("Failed to allocate memory for new vertices");
  }

  for (size_t i = 0; i < shape.vertices.size; i++) {
    new_vertices[i] = shape.vertices.arr[i];
  }

  if (shape.vertices.size > 13)
    new_vertices[13] = new_vertices[13] - 0.49f;
  if (shape.vertices.size > 16)
    new_vertices[16] = new_vertices[16] - 0.49f;
  if (shape.vertices.size > 19)
    new_vertices[19] = new_vertices[19] - 0.49f;
  if (shape.vertices.size > 22)
    new_vertices[22] = new_vertices[22] - 0.49f;

  Shape new_shape = {
      .vertices = {.arr = new_vertices, .size = sizeof(new_vertices)},
      .indices = shape.indices};

  return new_shape;
}

Shape to1000(Shape shape) {
  float *new_vertices = malloc(shape.vertices.size * sizeof(float));
  if (!new_vertices) {
    perror("Failed to allocate memory for new vertices");
  }

  for (size_t i = 0; i < shape.vertices.size; i++) {
    new_vertices[i] = shape.vertices.arr[i];
  }

  if (shape.vertices.size > 13)
    new_vertices[13] = new_vertices[13] - 0.49f;
  if (shape.vertices.size > 16)
    new_vertices[16] = new_vertices[16] - 0.49f;
  if (shape.vertices.size > 19)
    new_vertices[19] = new_vertices[19] - 0.49f;
  if (shape.vertices.size > 22)
    new_vertices[22] = new_vertices[22] - 0.49f;
  if (shape.vertices.size > 15)
    new_vertices[15] = -new_vertices[15];
  if (shape.vertices.size > 21)
    new_vertices[21] = -new_vertices[21];

  Shape new_shape = {
      .vertices = {.arr = new_vertices, .size = sizeof(new_vertices)},
      .indices = shape.indices};

  return new_shape;
}
