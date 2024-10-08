#include "vertices.h"
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *vertexShaderSource =
    "#version 460 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *fragmentShaderSource =
    "#version 460 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
    "}\n";

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

unsigned int draw(Shape shape) {
  unsigned int VBO, VAO, EBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, shape.vertices.size, shape.vertices.arr,
               GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, shape.indices.size, shape.indices.arr,
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  return VAO;
}

int main() {
  int success;
  char info_log[512];

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window =
      glfwCreateWindow(800, 600, "Cisterian Numbers", NULL, NULL);
  if (window == NULL) {
    printf("Failed to create window\n");
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    printf("Failed to initialize GLAD\n");
    return -1;
  }

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, info_log);
    printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", info_log);
  }

  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, info_log);
    printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", info_log);
  }

  unsigned int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shaderProgram, 512, NULL, info_log);
    printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n", info_log);
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  float vertices[] = {
      0.0f, 0.0f, 0.0f,  // bl
      0.01f, 0.0f, 0.0f, // br
      0.0f, 0.5f, 0.0f,  // tl
      0.01f, 0.5f, 0.0f, // tr
                         /// 12
      0.0f, 0.49f, 0.0f, // 2bl
      0.1f, 0.49f, 0.0f, // 2br
      0.0f, 0.5f, 0.0f,  // 2tl
      0.1f, 0.5f, 0.0f,  // 2tr
  };

  unsigned int indices[] = {
      0, 1, 2, // tr l
      1, 2, 3, // tr r
               ///
      4, 5, 6, // 2tr b
      5, 6, 7  // 2tr t
  };

  Shape n1 = {.vertices = {.arr = vertices, .size = sizeof(vertices)},
              .indices = {.arr = indices, .size = sizeof(indices)}};
  Shape m;

  unsigned int VAO[4] = {0, 0, 0, 0};

  VAO[0] = draw(n1);
  m = to10(n1);
  VAO[1] = draw(m);
  m = to100(n1);
  VAO[2] = draw(m);
  m = to1000(n1);
  VAO[3] = draw(m);

  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  int val[] = {0, 0, 0, 0};
  int idx = 0;
  int key_pressed = 0;

  while (!glfwWindowShouldClose(window)) {
    processInput(window);

    glClearColor(0.102f, 0.102f, 0.102f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);

    if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS && !key_pressed) {
      if (idx < 4 && val[idx] == 0) {
        val[idx++] = 0;
      }
      key_pressed = 1;
    }

    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS && !key_pressed) {
      if (idx < 4 && val[idx] == 0) {
        val[idx++] = 1;
      }
      key_pressed = 1;
    }

    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS && !key_pressed) {
      if (idx < 4 && val[idx] == 0) {
        val[idx++] = 2;
      }
      key_pressed = 1;
    }

    if (glfwGetKey(window, GLFW_KEY_BACKSPACE) == GLFW_PRESS && !key_pressed) {
      if (idx > 0) {
        val[--idx] = 0;
      }
      key_pressed = 1;
    }

    if (glfwGetKey(window, GLFW_KEY_0) == GLFW_RELEASE &&
        glfwGetKey(window, GLFW_KEY_1) == GLFW_RELEASE &&
        glfwGetKey(window, GLFW_KEY_2) == GLFW_RELEASE &&
        glfwGetKey(window, GLFW_KEY_BACKSPACE) == GLFW_RELEASE) {
      key_pressed = 0;
    }

    // printf("%i, %i, %i, %i -> %i\n", val[0], val[1], val[2], val[3], idx);

    for (int i = 3; i >= 0; --i) {
      printf("%d", val[i]);
    }
    printf("\n");

    for (int i = 0; i < sizeof(VAO) / sizeof(VAO[0]); ++i) {
      if (VAO[i] == 0)
        continue;

      if (val[i] != 0) {
        glBindVertexArray(VAO[i]);
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(indices[0]),
                       GL_UNSIGNED_INT, 0);
      }
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, VAO);
  // glDeleteBuffers(1, &VBO);
  // glDeleteBuffers(1, &EBO);
  glDeleteProgram(shaderProgram);

  glfwTerminate();
  return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, 1);
  }
}
