#include <sceneview.h>
#include <scenenode.h>
#include <PAD Engine/Core/EngineDLL.h>
#include <QKeyEvent>

SceneView::SceneView(QWidget *parent) :
    QTreeWidget(parent)
{
    //QTreeWidgetItem* scene = new QTreeWidgetItem();
    setSelectionMode(QAbstractItemView::SingleSelection);
    setDragEnabled(true);
    viewport()->setAcceptDrops(true);
    setDropIndicatorShown(true);
    setDragDropMode(QAbstractItemView::InternalMove);
    model()->setHeaderData(0, Qt::Horizontal, "Scene");
    connect(this, SIGNAL(itemSelectionChanged()), this, SLOT(SetSelectedAsCurrent()));
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
    current->setFlags(current->flags() |
                      Qt::ItemIsEditable | Qt::ItemIsEnabled
                      | Qt::ItemIsSelectable);
    current->setText(0, "Pad Object");
}

void SceneView::currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    currentObject = static_cast<SceneNode*>(itemFromIndex(current))->obj;
}

void SceneView::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Delete)
    {
        if(selectedItems().size() > 0 && selectedItems()[0])
        {
            //pad::DeletePadObject(currentObject);
            delete(selectedItems()[0]);
        }
    }
    if (event->key() == Qt::Key_F2 || event->key() == Qt::Key_R)
    {
        if(selectedItems().size() > 0 && selectedItems()[0])
        {
           editItem(selectedItems()[0]);
        }
    }
}

void SceneView::SetSelectedAsCurrent()
{
    currentObject = static_cast<SceneNode*>(selectedItems()[0])->obj;
}

void SceneView::ParseScene()
{
    pad::sys::ecs::Scene* sc = pad::GetScene();
    std::list<pad::sys::ecs::PADObject*> objs = sc->GetMasterObject()->GetChildren();

    for (int i = 0; i < objs.size(); ++i)
    {
        AddObject(objs[i]);
    }

}

