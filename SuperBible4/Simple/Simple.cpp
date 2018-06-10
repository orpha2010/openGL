#include<GL\freeglut.h>
void RenderScene(void)
{
	//清除颜色缓冲区
	glClear(GL_COLOR_BUFFER_BIT);
	//刷新队列
	glFlush();

}
// 设置渲染状态
void SetupRC(void)
{
	// 蓝色 alpha = 1
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

// 主函数
int main(int argc, char* argv[])
{
	//初始化，并且传递参数
	glutInit(&argc, argv);
	// 单缓冲模式，RGBA为显示模式
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	// 创建一个窗口，标题为Simple
	glutCreateWindow("Simple测试");
	// 显示回调函数
	glutDisplayFunc(RenderScene);
	// 设置渲染状态
	SetupRC();
	// 循环，直到程序结束
	glutMainLoop();

	return 0;

}