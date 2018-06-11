#include<GL\freeglut.h>
// ��Ⱦ����
void RenderScene(void)
{
	// �����ɫ����
	glClear(GL_COLOR_BUFFER_BIT);
	// ��ɫ
	glColor3f(1.0f,0.0f,0.0f);
	// �������ϵ�����
	glRectf(-25.0f, 25.0f, 25.0f,-25.0f);
	// ˢ��
	glFlush();
}


void SetupRC(void)
{
	// ���ɫ������ɫ��
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

// �ı�ߴ�
void ChangeSize(GLsizei w, GLsizei h)
{
	// ��߱ȣ��ҷ�ֹ��߱ȵ���0
	GLfloat aspectRatio;
	if (h == 0)
		h = 1;

	// �Ӵ��ߴ�
	glViewport(0, 0, w, h);

	// ��������Ͷ������
	glMatrixMode(GL_PROJECTION);
	// �ָ���ʼ����ϵ
	glLoadIdentity();


	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w / h)
		glOrtho(-100.0, 100.0, -100.0 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
	else
		glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);
	// �л����Ӵ����� -----�� ��Ӱ������
	glMatrixMode(GL_MODELVIEW);
	// �ָ���ʼ����ϵ
	glLoadIdentity();
}
//void main(void)
int main(int argc, char* argv[])
{
	//��ʼ�������Ҵ��ݲ���
	glutInit(&argc, argv);
	// ������ģʽ��RGBAΪ��ʾģʽ
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// ����window ����GLrect
	glutCreateWindow("GLRect");
	// ��ʾ�ص�����RenderScene
	glutDisplayFunc(RenderScene);
	// ������״���� 
	glutReshapeFunc(ChangeSize);
	// ������Ⱦ״̬
	SetupRC();
	// ����ѭ��
	glutMainLoop();
	return 0;
};