#include<GL\freeglut.h>
void RenderScene(void)
{
	//�����ɫ������
	glClear(GL_COLOR_BUFFER_BIT);
	//ˢ�¶���
	glFlush();

}
// ������Ⱦ״̬
void SetupRC(void)
{
	// ��ɫ alpha = 1
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

// ������
int main(int argc, char* argv[])
{
	//��ʼ�������Ҵ��ݲ���
	glutInit(&argc, argv);
	// ������ģʽ��RGBAΪ��ʾģʽ
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	// ����һ�����ڣ�����ΪSimple
	glutCreateWindow("Simple����");
	// ��ʾ�ص�����
	glutDisplayFunc(RenderScene);
	// ������Ⱦ״̬
	SetupRC();
	// ѭ����ֱ���������
	glutMainLoop();

	return 0;

}