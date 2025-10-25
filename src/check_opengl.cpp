// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <iostream>

// void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//     glViewport(0, 0, width, height);
// }

// int main() {
//     // Initialise GLFW
//     if (!glfwInit()) {
//         std::cerr << "Failed to initialise GLFW\n";
//         return -1;
//     }

//     // Configure GLFW (OpenGL 3.3 Core)
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//     // Create window
//     GLFWwindow* window = glfwCreateWindow(800, 600, "Neural Visualiser", nullptr, nullptr);
//     if (!window) {
//         std::cerr << "Failed to create GLFW window\n";
//         glfwTerminate();
//         return -1;
//     }
//     glfwMakeContextCurrent(window);

//     // Load GLAD
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//         std::cerr << "Failed to initialise GLAD\n";
//         return -1;
//     }

//     // Set viewport and callback
//     glViewport(0, 0, 800, 600);
//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

//     // Render loop
//     while (!glfwWindowShouldClose(window)) {
//         // Set background colour
//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);

//         // Swap buffers and poll events
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     glfwTerminate();
//     return 0;
// }
