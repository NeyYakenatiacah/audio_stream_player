#ifndef PALETTE_H
#define PALETTE_H

#include <QObject>
#include <QPalette>

class Palette : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name            READ name            WRITE setName            NOTIFY nameChanged            )
    Q_PROPERTY(QString windowText      READ windowText      WRITE setWindowText      NOTIFY windowTextChanged      )
    Q_PROPERTY(QString button          READ button          WRITE setButton          NOTIFY buttonChanged          )
    Q_PROPERTY(QString light           READ light           WRITE setLight           NOTIFY lightChanged           )
    Q_PROPERTY(QString midlight        READ midlight        WRITE setMidlight        NOTIFY midlightChanged        )
    Q_PROPERTY(QString dark            READ dark            WRITE setDark            NOTIFY darkChanged            )
    Q_PROPERTY(QString mid             READ mid             WRITE setMid             NOTIFY midChanged             )
    Q_PROPERTY(QString text            READ text            WRITE setText            NOTIFY textChanged            )
    Q_PROPERTY(QString brightText      READ brightText      WRITE setBrightText      NOTIFY brightTextChanged      )
    Q_PROPERTY(QString buttonText      READ buttonText      WRITE setButtonText      NOTIFY buttonTextChanged      )
    Q_PROPERTY(QString base            READ base            WRITE setBase            NOTIFY baseChanged            )
    Q_PROPERTY(QString window          READ window          WRITE setWindow          NOTIFY windowChanged          )
    Q_PROPERTY(QString shadow          READ shadow          WRITE setShadow          NOTIFY shadowChanged          )
    Q_PROPERTY(QString highlight       READ highlight       WRITE setHighlight       NOTIFY highlightChanged       )
    Q_PROPERTY(QString highlightedText READ highlightedText WRITE setHighlightedText NOTIFY highlightedTextChanged )
    Q_PROPERTY(QString link            READ link            WRITE setLink            NOTIFY linkChanged            )
    Q_PROPERTY(QString linkVisited     READ linkVisited     WRITE setLinkVisited     NOTIFY linkVisitedChanged     )
    Q_PROPERTY(QString alternateBase   READ alternateBase   WRITE setAlternateBase   NOTIFY alternateBaseChanged   )
    Q_PROPERTY(QString noRole          READ noRole          WRITE setNoRole          NOTIFY noRoleChanged          )
    Q_PROPERTY(QString tooltipBase     READ tooltipBase     WRITE setTooltipBase     NOTIFY tooltipBaseChanged     )
    Q_PROPERTY(QString tooltipText     READ tooltipText     WRITE setTooltipText     NOTIFY tooltipTextChanged     )

public:
    explicit Palette(QObject *parent = nullptr);
    Palette(const Palette & other);

    void defaultPalette();

    void operator = (const Palette & other);

    QString name() const;
    void setName(const QString & name);

    QString windowText() const;
    void setWindowText(const QString &color);

    QString button() const;
    void setButton(const QString &color);

    QString light() const;
    void setLight(const QString & color);

    QString midlight() const;
    void setMidlight(const QString &color);

    QString dark() const;
    void setDark(const QString &color);

    QString mid() const;
    void setMid(const QString & color);

    QString text() const;
    void setText(const QString & color);

    QString brightText() const;
    void setBrightText(const QString & color);

    QString buttonText() const;
    void setButtonText(const QString & color);

    QString base() const;
    void setBase(const QString & color);

    QString window() const;
    void setWindow(const QString &color);

    QString shadow() const;
    void setShadow(const QString &color);

    QString highlight() const;
    void setHighlight(const QString & color);

    QString highlightedText() const;
    void setHighlightedText(const QString & color);

    QString link() const;
    void setLink(const QString & color);

    QString linkVisited() const;
    void setLinkVisited(const QString & color);

    QString alternateBase() const;
    void setAlternateBase(const QString & color);

    QString noRole() const;
    void setNoRole(const QString & color);

    QString tooltipBase() const;
    void setTooltipBase(const QString &color);

    QString tooltipText() const;
    void setTooltipText(const QString & color);

    bool fromJson(const QJsonObject & obj);
    QJsonObject toJson() const;

    void setPalette(const QPalette & palette);

signals:
    void nameChanged();
    void windowTextChanged();
    void buttonChanged();
    void lightChanged();
    void midlightChanged();
    void darkChanged();
    void midChanged();
    void textChanged();
    void brightTextChanged();
    void buttonTextChanged();
    void baseChanged();
    void windowChanged();
    void shadowChanged();
    void highlightChanged();
    void highlightedTextChanged();
    void linkChanged();
    void linkVisitedChanged();
    void alternateBaseChanged();
    void noRoleChanged();
    void tooltipBaseChanged();
    void tooltipTextChanged();

private:

    QString m_name;

    QPalette m_palette;
};

#endif // PALETTE_H
