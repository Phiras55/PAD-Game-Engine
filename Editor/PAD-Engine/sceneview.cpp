#include <sceneview.h>
#include <scenenode.h>

SceneView::SceneView(QWidget *parent) :
    QTreeWidget(parent)
{
    QTreeWidgetItem scene;

    addTopLevelItem(scene);
}

SceneView::AddObject(pad::sys::ecs::PADObject* obj)
{
    SceneNode(obj, topLevelItem(), topLevelItem());
}
