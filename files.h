#ifndef FILES_H
#define FILES_H

#include <QWidget>
#include <QListWidgetItem>
#include <QDir>
#include <QObject>

class Files : public QWidget
{
    Q_OBJECT

public:
    Files(QWidget *parent = 0);

private slots:
    void updateList(QListWidgetItem*);

private:
	QWidget *widget;
	QListWidget *list;
	QDir *qdir;
};

#endif