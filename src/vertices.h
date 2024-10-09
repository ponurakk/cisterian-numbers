#ifndef VERTICES_H
#define VERTICES_H

#include <stddef.h>

typedef struct {
  size_t size;
  float *arr;
} Vertices;

typedef struct {
  size_t size;
  unsigned int *arr;
} Indices;

typedef struct {
  Vertices vertices;
  Indices indices;
} Shape;

Shape to10(Shape shape);
Shape to100(Shape shape);
Shape to1000(Shape shape);

#endif // !VERTICES_H
