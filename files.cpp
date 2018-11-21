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

    QFileInfoList fileList = QDir::drives();
    for (int i = 0; i < fileList.count(); ++i)
    {
        QFileInfo fileInfo = fileList.value(i);
        list->insertItem(i, new QListWidgetItem(fileInfo.absoluteFilePath()));
    }

    QObject::connect(list, &QListWidget::itemDoubleClicked, this, &Files::updateList);

    mainLayout->addWidget(list, 0, 0);

    setLayout(mainLayout);
}

void Files::updateList(QListWidgetItem *item)
{
    list->clear();

    QListWidgetItem it = *item;

    qdir = new QDir(it.text());

    QFileInfoList fileList = qdir->entryInfoList();
    for (int i = 0; i < fileList.count(); ++i)
    {
        QFileInfo fileInfo = fileList.value(i);
        list->insertItem(i, new QListWidgetItem(fileInfo.absoluteFilePath()));
    }
}