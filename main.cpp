#include <iostream>
#include "adder.h"
#include "GLFW/glfw3.h"
#include "cmaketestConfig.h"

using namespace std;

int main(int argc, char *argv[])
{
  std::cout << "Hello cmake";
  cout << adder(1, 3.0) << endl;
  cout << argv[0] << " Version " << cmaketest_VERSION_MAJOR << "." << cmaketest_VERSION_MINOR << endl;

  GLFWwindow *window;
  glfwInit();
}