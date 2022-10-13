#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include"Shader.h"
#include"Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include"stb_image.h"
#include"Vertex.h"
#include"WindowsInit.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;

// --------------------------------------------- 设置 (Start) ---------------------------------------------
#pragma region
    
    // settings
    const int SCR_WIDTH = 800;
    const int SCR_HEIGHT = 600;

    GLFWwindow* window = WindowsIint(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL");
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void processInput(GLFWwindow* window);

    
#pragma endregion
// ---------------------------------------------- 设置 (End) ----------------------------------------------



int main()
{

    std::cout << "Hello OpenGL!" << std::endl;

    // --------------------------------------------- 初始化 (Start) ---------------------------------------------
    #pragma region
    // Shader 对象的创建
    const char* vs = "D:\\dev\\OpenGL\\MyOpenGL\\MyOpenGL\\vertex_core.glsl";
    const char* fs = "D:\\dev\\OpenGL\\MyOpenGL\\MyOpenGL\\fragment_core.glsl";
    Shader m_shader(vs, fs);

    #pragma endregion
    // ---------------------------------------------- 初始化 (End) ----------------------------------------------

    // --------------------------------------------- 顶点数据 (Start) ---------------------------------------------
    #pragma region

    float vertices[] = {
        //     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
    };
    unsigned int indices[] = {
        0, 1, 3, // 第一个三角形
        1, 2, 3  // 第二个三角形
    };
    int prop[] = { 3, 3, 2 };

    Vertex vertex(vertices, sizeof(vertices), indices, sizeof(indices), prop, 3, 8);

    #pragma endregion
    // ---------------------------------------------- 顶点数据 (End) ----------------------------------------------


// --------------------------------------------- Texture (Start) ---------------------------------------------
    #pragma region
    //T1
    Texture2D tex1("D:\\dev\\OpenGL\\MyOpenGL\\MyOpenGL\\photographs\\container.jpg");

    //T2
    Texture2D tex2("D:\\dev\\OpenGL\\MyOpenGL\\MyOpenGL\\photographs\\awesomeface.png", GL_RGBA, GL_RGBA, 0, 1);


    #pragma endregion
    // ---------------------------------------------- Texture (End) ----------------------------------------------


// --------------------------------------------- 渲染循环 (Start) ---------------------------------------------
    #pragma region
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);// 线框模式
    m_shader.use();
    m_shader.setInt("ourTexture1", 0);
    m_shader.setInt("ourTexture2", 1);
    float offset = 0.5f;
    m_shader.setFloat("xOffset", offset);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float timeValue = glfwGetTime();
        float sinTime = sin(timeValue);
        mat4 trans = mat4(1.0f);
        trans = translate(trans, vec3(-0.5f, 0.5f, 0));
        trans = rotate(trans, (float)glfwGetTime(), vec3(0.0, 0.0, 1.0));
        trans = scale(trans, vec3(0.5, 0.5, 0.5));
        m_shader.setMat4("transform", trans);
        m_shader.setFloat("newColor", sinTime);
        m_shader.use();
        tex1.use();
        tex2.use();
        vertex.use();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwTerminate();
    return 0;

}

#pragma endregion
// ---------------------------------------------- 渲染循环 (End) ----------------------------------------------
