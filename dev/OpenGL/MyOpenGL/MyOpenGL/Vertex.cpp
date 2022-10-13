#include"Vertex.h"

Vertex::Vertex(float vertices[], int verSize, unsigned int indices[], int indSize, int prop[], int propSize, int Sum) {

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    //��
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, verSize, vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indSize, indices, GL_STATIC_DRAW);
    //glBufferData��һ��ר���������û���������ݸ��Ƶ���ǰ�󶨻���ĺ�����
    //���ĵ�һ��������Ŀ�껺������ͣ����㻺�����ǰ�󶨵�GL_ARRAY_BUFFERĿ���ϡ�
    //�ڶ�������ָ���������ݵĴ�С(���ֽ�Ϊ��λ)����һ���򵥵�sizeof������������ݴ�С���С�
    //����������������ϣ�����͵�ʵ�����ݡ�
    //���ĸ�����ָ��������ϣ���Կ���ι�����������ݡ�
    //GL_STATIC_DRAW �����ݲ���򼸺�����ı䡣
    //GL_DYNAMIC_DRAW�����ݻᱻ�ı�ܶࡣ
    //GL_STREAM_DRAW ������ÿ�λ���ʱ����ı䡣
    setFor(prop, propSize, Sum);
    //��������  
    //vertex.setProperty(0, 3, 8, 0);
    //��ɫ����
    //vertex.setProperty(1, 3, 8, 3);
    //UV
    //vertex.setProperty(2, 2, 8, 6);
}

Vertex::~Vertex() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Vertex::setProperty(int pId, int pSize, int vSize, int pOffset) {
    //��������        ����ID ����size type normalized     ����size     ����ƫ��   
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
