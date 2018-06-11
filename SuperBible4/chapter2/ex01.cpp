#include<GL\freeglut.h>
// 渲染场景
void RenderScene(void)
{
	// 清除颜色缓存
	glClear(GL_COLOR_BUFFER_BIT);
	// 红色
	glColor3f(1.0f,0.0f,0.0f);
	// 矩形左上到右下
	glRectf(-25.0f, 25.0f, 25.0f,-25.0f);
	// 刷新
	glFlush();
}


void SetupRC(void)
{
	// 清楚色（背景色）
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

// 改变尺寸
void ChangeSize(GLsizei w, GLsizei h)
{
	// 宽高比，且防止宽高比等于0
	GLfloat aspectRatio;
	if (h == 0)
		h = 1;

	// 视窗尺寸
	glViewport(0, 0, w, h);

	// 矩阵类型投射类型
	glMatrixMode(GL_PROJECTION);
	// 恢复初始坐标系
	glLoadIdentity();


	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w / h)
		glOrtho(-100.0, 100.0, -100.0 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
	else
		glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);
	// 切换到视窗矩阵 -----》 摄影机坐标
	glMatrixMode(GL_MODELVIEW);
	// 恢复初始坐标系
	glLoadIdentity();
}
//void main(void)
int main(int argc, char* argv[])
{
	//初始化，并且传递参数
	glutInit(&argc, argv);
	// 单缓冲模式，RGBA为显示模式
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// 创建window 标题GLrect
	glutCreateWindow("GLRect");
	// 显示回调函数RenderScene
	glutDisplayFunc(RenderScene);
	// 绘制形状函数 
	glutReshapeFunc(ChangeSize);
	// 设置渲染状态
	SetupRC();
	// 设置循环
	glutMainLoop();
	return 0;
};