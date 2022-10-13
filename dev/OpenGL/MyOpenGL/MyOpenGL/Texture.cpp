#include"Texture.h"
Texture2D::Texture2D(const string& path, unsigned int saveType, unsigned int imgType, int level,const int TextureNum)
{
    this->TextureNum = TextureNum;
	data = stbi_load(path.c_str(), &this->width, &this->height, &this->nrChannels, 0);
    if (!data)
    {
        std::cout << "Failed to load texture" << std::endl;
        exit(-1);
    }

    glGenTextures(1, &this->ID);
    stbi_set_flip_vertically_on_load(true);
    glActiveTexture(GL_TEXTURE0+TextureNum); // 在绑定纹理之前先激活纹理单元
    glBindTexture(GL_TEXTURE_2D, this->ID);
    // 为当前绑定的纹理对象设置环绕、过滤方式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, imgType, this->width, this->height, 0, imgType, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    stbi_image_free(data);
    data = nullptr;
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture2D::~Texture2D()
{
    glDeleteTextures(1, &this->ID);
}

void Texture2D::use() {
    glActiveTexture(GL_TEXTURE0 + this->TextureNum); // 在绑定纹理之前先激活纹理单元
    glBindTexture(GL_TEXTURE_2D, this->ID);

}
