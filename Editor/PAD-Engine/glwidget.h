#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QTimer>
#include <PAD Engine/Core/Engine.h>

class GLWidget final : public QOpenGLWidget
{
public:
    GLWidget() = delete;
    GLWidget(QWidget* _parent = nullptr, Qt::WindowFlags _f = Qt::WindowFlags(), pad::core::Engine& _engine) :
        QOpenGLWidget(_parent, _f),
        engine(_engine)
    {
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(PaintGL()));
        timer->start();
    }

    virtual ~GLWidget()
    {
        delete timer;
        pad::DestroyEngine();
    }
private:
    QTimer* timer;
    pad::core::Engine& engine;

public:
    virtual void PaintGL() override
    {
        engine.Simulate();
    }
}

#endif // GLWIDGET_H
