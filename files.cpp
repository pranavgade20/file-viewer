#define _GLIBCXX_USE_CXX11_ABI 0
#include <string>
#include <QtWidgets>
#include <QListWidget> 
#include "files.h"

Files::Files(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setContentsMargins(0, 0, 0, 0);

    list = new QListWidget(this);

    qdir = new QDir;
    QFileInfoList fileList = QDir::drives();
    for (int i = 0; i < fileList.count(); ++i)
    {
        QFileInfo fileInfo = fileList.value(i);
        list->insertItem(i, new QListWidgetItem(fileInfo.absoluteFilePath()));
    }

    connect(list, SIGNAL(itemDoubleClicked(QListWidgetItem)), this, SLOT(updateList(QListWidgetItem)));

    mainLayout->addWidget(list, 0, 0);

    setLayout(mainLayout);
}

void Files::updateList(QListWidgetItem item)
{
    list->clear();
}