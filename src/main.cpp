#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;
    if (!glfwInit()) return -1; // initialize glfw

    window = glfwCreateWindow(1000, 1000, "renegl", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window); // create opengl rendering context

    if(glewInit() != GLEW_OK) return -1; // intialize glew

    GLfloat vertex_buffer_data[] = { -.5f, -.5f, 0.0f,
                                     0.5f, -.5f, 0.0f,
                                     0.0f,  .5f, 0.0f,
                                   };

    GLuint vertextbuffer;
    glGenBuffers(1, &vertextbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertextbuffer);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertex_buffer_data),vertex_buffer_data,GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT)*3, 0);

    while (!glfwWindowShouldClose(window) && !glfwGetKey(window,GLFW_KEY_ESCAPE))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window); // swap front and back buffers

        glfwPollEvents(); // poll for and process events
    }

    glfwTerminate();
    return 0;
}
