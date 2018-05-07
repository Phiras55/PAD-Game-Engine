#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <PAD Engine/Core/EngineDLL.h>
#include <QOpenGLWidget>
#include <QTimer>
#include <iostream>


class GLWidget final : public QOpenGLWidget
{
public:
    GLWidget() = delete;

    GLWidget(QWidget* _parent = 0, Qt::WindowFlags _f = Qt::WindowFlags()) :
        QOpenGLWidget(_parent, _f)
    {
    }

    virtual ~GLWidget()
    {
    }
private:
    QTimer* timer;

public:

    void Init()
    {
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(paintGL()));
        timer->start(0);
    }

    void paintGL() override
    {
        qInfo( "Working!" );
        pad::Simulate();
    }
public:
    void toto()
    {
        qInfo( "toto!" );
        pad::Simulate();
    }
};

#endif
