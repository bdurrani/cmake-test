#include <iostream>
#include "adder.h"
#include "GLFW/glfw3.h"

using namespace std;

int main()
{
  std::cout << "Hello cmake";
  cout << adder(1, 3.0) << endl;
  GLFWwindow *window;
  glfwInit();
}