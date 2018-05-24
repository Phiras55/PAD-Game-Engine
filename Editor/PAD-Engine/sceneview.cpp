#include <sceneview.h>
#include <scenenode.h>

SceneView::SceneView(QWidget *parent) :
    QTreeWidget(parent)
{
    QTreeWidgetItem* scene = new QTreeWidgetItem();

}

void SceneView::AddObject(pad::sys::ecs::PADObject* obj, SceneNode* after)
{
    SceneNode* current;
    if(after)
        current = new SceneNode(obj, after, after);
    else
    {
        addTopLevelItem(new SceneNode(obj));
        current = static_cast<SceneNode*>(topLevelItem(topLevelItemCount()-1));
    }
    current->setText(0, "Pad Object");
}
