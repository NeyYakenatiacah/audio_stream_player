#include "palette.h"

#include <QJsonObject>
#include <QVariant>

QJsonObject exportColorTo (const QColor & color)
{
    QJsonObject obj;

    obj["red"]   = color.red();
    obj["green"] = color.green();
    obj["blue"]  = color.blue();
    obj["alpha"] = color.alpha();

    return obj;
}

Palette::Palette(QObject *parent) : QObject(parent)
{
    defaultPalette();
}

Palette::Palette(const Palette &other)
{
    m_name = other.m_name;

    m_palette = other.m_palette;
}

void Palette::defaultPalette()
{
    setName("Default sheme");

    setWindowText("#9737c6");
    setWindow    ("#2f3237");
    setHighlight ("#a8c1ea");
    setButton    ("#9737c6");
}

void Palette::operator =(const Palette &other)
{
    m_name = other.m_name;

    m_palette = other.m_palette;
}

QString Palette::name() const
{
    return m_name;
}

void Palette::setName(const QString & name)
{
    m_name = name;

    emit nameChanged();
}

QString Palette::windowText() const
{
    return m_palette.color(QPalette::WindowText).name();
}

void Palette::setWindowText(const QString & color)
{
    m_palette.setColor(QPalette::WindowText, QColor(color));

    emit windowTextChanged();
}

QString Palette::button() const
{
    return m_palette.color(QPalette::Button).name();
}

void Palette::setButton(const QString & color)
{
    m_palette.setColor(QPalette::Button, color);

    emit buttonChanged();
}

QString Palette::light() const
{
    return m_palette.color(QPalette::Light).name();
}

void Palette::setLight(const QString & color)
{
    m_palette.setColor(QPalette::Light, QColor(color));

    emit lightChanged();
}

QString Palette::midlight() const
{
    return m_palette.color(QPalette::Midlight).name();
}

void Palette::setMidlight(const QString & color)
{
    m_palette.setColor(QPalette::Midlight, QColor(color));

    emit midlightChanged();
}

QString Palette::dark() const
{
    return m_palette.color(QPalette::Dark).name();
}

void Palette::setDark(const QString & color)
{
    m_palette.setColor(QPalette::Dark, QColor(color));

    emit darkChanged();
}

QString Palette::mid() const
{
    return m_palette.color(QPalette::Mid).name();
}

void Palette::setMid(const QString & color)
{
    m_palette.setColor(QPalette::Mid, QColor(color));

    emit midChanged();
}

QString Palette::text() const
{
    return m_palette.color(QPalette::Text).name();
}

void Palette::setText(const QString & color)
{
    m_palette.setColor(QPalette::Text, QColor(color));

    emit textChanged();
}

QString Palette::brightText() const
{
    return m_palette.color(QPalette::BrightText).name();
}

void Palette::setBrightText(const QString & color)
{
    m_palette.setColor(QPalette::BrightText, QColor(color));

    emit brightTextChanged();
}

QString Palette::buttonText() const
{
    return m_palette.color(QPalette::ButtonText).name();
}

void Palette::setButtonText(const QString & color)
{
    m_palette.setColor(QPalette::ButtonText, QColor(color));

    emit buttonTextChanged();
}

QString Palette::base() const
{
    return m_palette.color(QPalette::Base).name();
}

void Palette::setBase(const QString & color)
{
    m_palette.setColor(QPalette::Base, QColor(color));

    emit baseChanged();
}

QString Palette::window() const
{
    return m_palette.color(QPalette::Window).name();
}

void Palette::setWindow(const QString & color)
{
    m_palette.setColor(QPalette::Window, QColor(color));

    emit windowChanged();
}

QString Palette::shadow() const
{
    return m_palette.color(QPalette::Shadow).name();
}

void Palette::setShadow(const QString & color)
{
    m_palette.setColor(QPalette::Shadow, QColor(color));

    emit shadowChanged();
}

QString Palette::highlight() const
{
    return m_palette.color(QPalette::Highlight).name();
}

void Palette::setHighlight(const QString & color)
{
    m_palette.setColor(QPalette::Highlight, QColor(color));

    emit highlightChanged();
}

QString Palette::highlightedText() const
{
    return m_palette.color(QPalette::HighlightedText).name();
}

void Palette::setHighlightedText(const QString & color)
{
    m_palette.setColor(QPalette::HighlightedText, QColor(color));

    emit highlightedTextChanged();
}

QString Palette::link() const
{
    return m_palette.color(QPalette::Link).name();
}

void Palette::setLink(const QString & color)
{
    m_palette.setColor(QPalette::Link, QColor(color));

    emit linkChanged();
}

QString Palette::linkVisited() const
{
    return m_palette.color(QPalette::LinkVisited).name();
}

void Palette::setLinkVisited(const QString & color)
{
    m_palette.setColor(QPalette::LinkVisited, QColor(color));

    emit linkVisitedChanged();
}

QString Palette::alternateBase() const
{
    return m_palette.color(QPalette::AlternateBase).name();
}

void Palette::setAlternateBase(const QString & color)
{
    m_palette.setColor(QPalette::AlternateBase, QColor(color));

    emit alternateBaseChanged();
}

QString Palette::noRole() const
{
    return m_palette.color(QPalette::NoRole).name();
}

void Palette::setNoRole(const QString & color)
{
    m_palette.setColor(QPalette::NoRole, QColor(color));

    emit noRoleChanged();
}

QString Palette::tooltipBase() const
{
    return m_palette.color(QPalette::ToolTipBase).name();
}

void Palette::setTooltipBase(const QString & color)
{
    m_palette.setColor(QPalette::ToolTipBase, QColor(color));

    emit tooltipBaseChanged();
}

QString Palette::tooltipText() const
{
    return m_palette.color(QPalette::ToolTipText).name();
}

void Palette::setTooltipText(const QString &color)
{
    m_palette.setColor(QPalette::ToolTipText, QColor(color));

    emit tooltipTextChanged();
}

bool Palette::fromJson(const QJsonObject &obj)
{
    if(!obj.contains ("Name")  ) return false;
    if(!obj.contains ("Window")) return false;
    if(!obj.contains ("Button")) return false;
    if(!obj.contains ("Text")  ) return false;

    if(obj.contains ("Name")) setName(obj["Name"].toString());

    if(obj.contains ("WindowText"))           setWindowText (obj["WindowText"].toString());
    if(obj.contains ("Button"))                   setButton (obj["Button"].toString());
    if(obj.contains ("Light"))                     setLight (obj["Light"].toString());
    if(obj.contains ("Midlight"))               setMidlight (obj["Midlight"].toString());
    if(obj.contains ("Dark"))                       setDark (obj["Dark"].toString());
    if(obj.contains ("Mid"))                         setMid (obj["Mid"].toString());
    if(obj.contains ("Text"))                       setText (obj["Text"].toString());
    if(obj.contains ("BrightText"))           setBrightText (obj["BrightText"].toString());
    if(obj.contains ("ButtonText"))           setButtonText (obj["ButtonText"].toString());
    if(obj.contains ("Base"))                       setBase (obj["Base"].toString());
    if(obj.contains ("Window"))                   setWindow (obj["Window"].toString());
    if(obj.contains ("Shadow"))                   setShadow (obj["Shadow"].toString());
    if(obj.contains ("Highlight"))             setHighlight (obj["Highlight"].toString());
    if(obj.contains ("HighlightedText")) setHighlightedText (obj["HighlightedText"].toString());
    if(obj.contains ("Link"))                       setLink (obj["Link"].toString());
    if(obj.contains ("LinkVisited"))         setLinkVisited (obj["LinkVisited"].toString());
    if(obj.contains ("AlternateBase"))     setAlternateBase (obj["AlternateBase"].toString());
    if(obj.contains ("NoRole"))                   setNoRole (obj["NoRole"].toString());
    if(obj.contains ("ToolTipBase"))         setTooltipBase (obj["ToolTipBase"].toString());
    if(obj.contains ("ToolTipText"))         setTooltipText (obj["ToolTipText"].toString());

    return true;
}

QJsonObject Palette::toJson() const
{
    QJsonObject obj;

    obj["Name"] = m_name;


    obj["WindowText"]      = windowText();
    obj["Button"]          = button();
    obj["Light"]           = light();
    obj["Midlight"]        = midlight();
    obj["Dark"]            = dark();
    obj["Mid"]             = mid();
    obj["Text"]            = text();
    obj["BrightText"]      = brightText();
    obj["ButtonText"]      = buttonText();
    obj["Base"]            = base();
    obj["Window"]          = window();
    obj["Shadow"]          = shadow();
    obj["Highlight"]       = highlight();
    obj["HighlightedText"] = highlightedText();
    obj["Link"]            = link();
    obj["LinkVisited"]     = linkVisited();
    obj["AlternateBase"]   = alternateBase();
    obj["NoRole"]          = noRole();
    obj["ToolTipBase"]     = tooltipBase();
    obj["ToolTipText"]     = tooltipText();

    return obj;
}

void Palette::setPalette(const QPalette & palette)
{
    m_palette = palette;

    emit windowTextChanged();
    emit buttonChanged();
    emit lightChanged();
    emit midlightChanged();
    emit darkChanged();
    emit midChanged();
    emit textChanged();
    emit brightTextChanged();
    emit buttonTextChanged();
    emit baseChanged();
    emit windowChanged();
    emit shadowChanged();
    emit highlightChanged();
    emit highlightedTextChanged();
    emit linkChanged();
    emit linkVisitedChanged();
    emit alternateBaseChanged();
    emit noRoleChanged();
    emit tooltipBaseChanged();
    emit tooltipTextChanged();
}
