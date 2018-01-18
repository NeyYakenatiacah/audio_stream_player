#ifndef PALETTE_H
#define PALETTE_H

#include <QObject>
#include <QPalette>

class Palette : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name            READ name            WRITE setName            NOTIFY nameChanged              )
    Q_PROPERTY(QColor  windowText      READ windowText      WRITE setWindowText      NOTIFY windowTextChanged        )
    Q_PROPERTY(QColor  button          READ button          WRITE setButton          NOTIFY buttonChanged            )
    Q_PROPERTY(QColor  light           READ light           WRITE setLight           NOTIFY lightChanged             )
    Q_PROPERTY(QColor  midlight        READ midlight        WRITE setMidlight        NOTIFY midlightChanged          )
    Q_PROPERTY(QColor  dark            READ dark            WRITE setDark            NOTIFY darkChanged              )
    Q_PROPERTY(QColor  mid             READ mid             WRITE setMid             NOTIFY midChanged               )
    Q_PROPERTY(QColor  text            READ text            WRITE setText            NOTIFY textChanged              )
    Q_PROPERTY(QColor  brightText      READ brightText      WRITE setBrightText      NOTIFY brightTextChanged        )
    Q_PROPERTY(QColor  buttonText      READ buttonText      WRITE setButtonText      NOTIFY buttonTextChanged        )
    Q_PROPERTY(QColor  base            READ base            WRITE setBase            NOTIFY baseChanged              )
    Q_PROPERTY(QColor  window          READ window          WRITE setWindow          NOTIFY windowChanged            )
    Q_PROPERTY(QColor  shadow          READ shadow          WRITE setShadow          NOTIFY shadowChanged            )
    Q_PROPERTY(QColor  highlight       READ highlight       WRITE setHighlight       NOTIFY highlightChanged         )
    Q_PROPERTY(QColor  highlightedText READ highlightedText WRITE setHighlightedText NOTIFY highlightedTextChanged   )
    Q_PROPERTY(QColor  link            READ link            WRITE setLink            NOTIFY linkChanged              )
    Q_PROPERTY(QColor  linkVisited     READ linkVisited     WRITE setLinkVisited     NOTIFY linkVisitedChanged       )
    Q_PROPERTY(QColor  alternateBase   READ alternateBase   WRITE setAlternateBase   NOTIFY alternateBaseChanged     )
    Q_PROPERTY(QColor  noRole          READ noRole          WRITE setNoRole          NOTIFY noRoleChanged            )
    Q_PROPERTY(QColor  tooltipBase     READ tooltipBase     WRITE setTooltipBase     NOTIFY tooltipBaseChanged       )
    Q_PROPERTY(QColor  tooltipText     READ tooltipText     WRITE setTooltipText     NOTIFY tooltipTextChanged       )

public:
    explicit Palette(QObject *parent = nullptr);

    QString name() const;
    void setName(const QString & name);

    QColor windowText() const;
    void setWindowText(const QColor & color);

    QColor button() const;
    void setButton(const QColor & color);

    QColor light() const;
    void setLight(const QColor & color);

    QColor midlight() const;
    void setMidlight(const QColor & color);

    QColor dark() const;
    void setDark(const QColor & color);

    QColor mid() const;
    void setMid(const QColor & color);

    QColor text() const;
    void setText(const QColor & color);

    QColor brightText() const;
    void setBrightText(const QColor & color);

    QColor buttonText() const;
    void setButtonText(const QColor & color);

    QColor base() const;
    void setBase(const QColor & color);

    QColor window() const;
    void setWindow(const QColor & color);

    QColor shadow() const;
    void setShadow(const QColor & color);

    QColor highlight() const;
    void setHightlight(const QColor & color);

    QColor highlightedText() const;
    void setHighlightedText(const QColor & color);

    QColor link() const;
    void setLink(const QColor & color);

    QColor linkVisited() const;
    void setLinkVisited(const QColor & color);

    QColor alternateBase() const;
    void setAlternateBase(const QColor & color);

    QColor noRole() const;
    void setNoRole(const QColor & color);

    QColor tooltipBase() const;
    void setTooltipBase(const QColor & color);

    QColor tooltipText() const;
    void setTooltipText(const QColor & color);

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
