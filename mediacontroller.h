#ifndef MEDIACONTROLLER_H
#define MEDIACONTROLLER_H

#include <QObject>

class MediaController : public QObject
{
    Q_OBJECT
public:
    explicit MediaController(QObject *parent = nullptr);

    QStringList availableModes() const;


signals:

public slots:
};

#endif // MEDIACONTROLLER_H
