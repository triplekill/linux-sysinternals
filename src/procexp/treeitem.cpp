#include "treeitem.h"

TreeItem::TreeItem(const QList<QVariant>& data, TreeItem* parent)
    : m_data(data),
      m_parent(parent)
{

}

TreeItem::~TreeItem()
{
    qDeleteAll(m_children);
}

void TreeItem::appendChild(TreeItem *item)
{
    m_children.append(item);
    item->setParent(this);
}

TreeItem *TreeItem::child(int row)
{
    return m_children.value(row);
}

int TreeItem::childCount() const
{
    return m_children.count();
}

int TreeItem::row() const
{
    if (m_parent)
        return m_parent->m_children.indexOf(const_cast<TreeItem*>(this));

    return 0;
}

int TreeItem::columnCount() const
{
    return m_data.count();
}

QVariant TreeItem::data(int column) const
{
    return m_data.value(column);
}

TreeItem *TreeItem::parent()
{
    return m_parent;
}

void TreeItem::setParent(TreeItem *item)
{
    m_parent = item;
}

TreeItem* TreeItem::findPid(int pid)
{
    // pid is stored in m_data[1]
    int cur_pid = m_data[1].toInt();
    if (cur_pid == pid)
        return this;
    // find in children
    for (TreeItem* item : m_children)
    {
        TreeItem* found = item->findPid(pid);
        if (found == nullptr)
            continue;
        else
            return found;
    }

    // not found
    return nullptr;
}
