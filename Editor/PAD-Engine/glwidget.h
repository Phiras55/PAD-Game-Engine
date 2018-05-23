#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <PAD Engine/Core/EngineDLL.h>
#include <QOpenGLWidget>
#include <QTimer>
#include <iostream>
#include <fstream>

#include <QtDebug>
#include <qopenglcontext.h>

class GLWidget final : public QOpenGLWidget
{
    Q_OBJECT
public:
    GLWidget() = delete;

    GLWidget(QWidget* _parent = 0, Qt::WindowFlags _f = Qt::WindowFlags()) :
        QOpenGLWidget(_parent, _f)
    {
            QTimer* timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()), this, SLOT(Update()));
            timer->start(0);
            setUpdateBehavior(UpdateBehavior::NoPartialUpdate);
    }

    ~GLWidget()
    {
    }
private:
    QTimer* timer;
    int loop = 0;
public:

    inline void Init() {}

public slots:
    inline void Update()
    {
        pad::Simulate();
        update();
    }
private:
    inline void paintGL() override
    {
        pad::Simulate();
    }
    inline void resizeGL(int w, int h) override
    {

    }
};

#endif
