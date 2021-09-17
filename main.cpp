#include <iostream>
#include "GLFW/glfw3.h"
#include "cmaketestConfig.h"

using namespace std;

int main(int argc, char *argv[])
{
  std::cout << "Hello cmake" << endl;

#ifdef USE_ADDER
  cout << "adder " << adder(1, 3.0) << endl;
#else
  cout << "built-in " << 1.0f + 3.0f << endl;
#endif

  cout << argv[0] << " Version " << cmaketest_VERSION_MAJOR << "." << cmaketest_VERSION_MINOR << endl;

  GLFWwindow *window;
  glfwInit();
}