#include"Vertex.h"

Vertex::Vertex(float vertices[], int verSize, unsigned int indices[], int indSize, int prop[], int propSize, int Sum) {

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    //绑定
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, verSize, vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indSize, indices, GL_STATIC_DRAW);
    //glBufferData是一个专门用来把用户定义的数据复制到当前绑定缓冲的函数。
    //它的第一个参数是目标缓冲的类型：顶点缓冲对象当前绑定到GL_ARRAY_BUFFER目标上。
    //第二个参数指定传输数据的大小(以字节为单位)；用一个简单的sizeof计算出顶点数据大小就行。
    //第三个参数是我们希望发送的实际数据。
    //第四个参数指定了我们希望显卡如何管理给定的数据。
    //GL_STATIC_DRAW ：数据不会或几乎不会改变。
    //GL_DYNAMIC_DRAW：数据会被改变很多。
    //GL_STREAM_DRAW ：数据每次绘制时都会改变。
    setFor(prop, propSize, Sum);
    //顶点属性  
    //vertex.setProperty(0, 3, 8, 0);
    //颜色属性
    //vertex.setProperty(1, 3, 8, 3);
    //UV
    //vertex.setProperty(2, 2, 8, 6);
}

Vertex::~Vertex() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Vertex::setProperty(int pId, int pSize, int vSize, int pOffset) {
    //顶点属性        属性ID 属性size type normalized     顶点size     属性偏移   
    glVertexAttribPointer(pId, pSize, GL_FLOAT, GL_FALSE, vSize * sizeof(float), (void*)(pOffset * sizeof(float)));
    glEnableVertexAttribArray(pId);
}

void Vertex::use() {
    glBindVertexArray(VAO);
}

void Vertex::setFor(int prop[], int propSize, int Sum) {
    int stepNum = 0;
    for (int i = 0; i < propSize; i++) {
        setProperty(i, prop[i], Sum, stepNum);
        stepNum += prop[i];
    }
}
