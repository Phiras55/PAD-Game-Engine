#ifndef SCENEVIEW_H
#define SCENEVIEW_H

#include <QTreeWidget>
#include <PAD Engine/System/ECS/PADObject.h>
#include <scenenode.h>

class SceneView final : public QTreeWidget
{
    Q_OBJECT
public:
    SceneView(QWidget* parent = nullptr);
    void AddObject(pad::sys::ecs::PADObject* obj, SceneNode* after = nullptr);

};

#endif // SCENEVIEW_H
