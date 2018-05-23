#include <sceneview.h>
#include <scenenode.h>

SceneView::SceneView(QWidget *parent) :
    QTreeWidget(parent)
{
    QTreeWidgetItem* scene = new QTreeWidgetItem();

    addTopLevelItem(scene);
}

SceneView::AddObject(pad::sys::ecs::PADObject* obj, SceneNode* after)
{
    if(parent)
        SceneNode(obj, parent, parent);
    else
        SceneNode(obj, topLevelItem(), topLevelItem());
}
