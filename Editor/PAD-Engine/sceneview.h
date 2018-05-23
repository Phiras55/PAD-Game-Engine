#ifndef SCENEVIEW_H
#define SCENEVIEW_H

#include <QTreeWidget>
#include <PAD Engine/System/ECS/PADObject.h>

class SceneView final : public QTreeWidget
{
    Q_OBJECT
public:
    SceneView(QWidget* parent = nullptr);

private:
    AddObject(pad::sys::ecs::PADObject* obj, pad::sys::ecs::PADObject* parent = nullptr);

private slots:
    SelectItem();

}

#endif // SCENEVIEW_H
