/*#include <glwidget.h>

GLWidget::GLWidget(QWidget * _parent, Qt::WindowFlags _f) :
	QOpenGLWidget(_parent, _f)
{
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(paintGL()));
	timer->start(0);
}

void GLWidget::paintGL()
{
	qInfo("Working!");
	pad::Simulate();
}
*/