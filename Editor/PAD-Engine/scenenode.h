#ifndef SCENENODE_H
#define SCENENODE_H
#include <QTreeWidgetItem>
#include <PAD Engine/System/ECS/PADObject.h>

struct SceneNode final : public QTreeWidgetItem
{
    SceneNode() = delete;
    SceneNode(pad::sys::ecs::PADObject* _obj, QTreeWidgetItem* parent, QTreeWidgetItem* after, int type = Type) :
        QTreeWidgetItem(parent, after, type),
        obj(_obj)
    {

    }

    pad::sys::ecs::PADObject* obj;
}
#endif // SCENENODE_H
