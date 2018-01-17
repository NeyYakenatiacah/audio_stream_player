#ifndef MEDIA_LIST_MANAGER_H
#define MEDIA_LIST_MANAGER_H

#include <QObject>

class MediaListManager : public QObject
{
    Q_OBJECT
public:
    explicit MediaListManager(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MEDIA_LIST_MANAGER_H