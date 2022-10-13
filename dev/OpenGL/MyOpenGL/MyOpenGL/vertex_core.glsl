#version 330 core
layout (location = 0) in vec3 aPos;   // Position
layout (location = 1) in vec3 aColor; // Color
layout (location = 2) in vec2 aTexCoord; // Texture

out vec3 ourColor; // ��Ƭ����ɫ�����һ����ɫ
uniform float xOffset;
uniform mat4 transform;

out vec3 Position;
out vec2 TexCoord;
void main()
{
    gl_Position = transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    ourColor = aColor; // ��ourColor����Ϊ���ǴӶ�����������õ���������ɫ
    Position = aPos;
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}