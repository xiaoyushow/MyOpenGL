#version 330 core
layout (location = 0) in vec3 aPos;   // Position
layout (location = 1) in vec3 aColor; // Color
layout (location = 2) in vec2 aTexCoord; // Texture

out vec3 ourColor; // 向片段着色器输出一个颜色
uniform float xOffset;
uniform mat4 transform;

out vec3 Position;
out vec2 TexCoord;
void main()
{
    gl_Position = transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    ourColor = aColor; // 将ourColor设置为我们从顶点数据那里得到的输入颜色
    Position = aPos;
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}