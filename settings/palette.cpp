#include "palette.h"

#include <QJsonObject>

QColor importColorFrom (const QJsonObject & obj)
{
    QColor color;

    if (obj.contains("red"))   color.setRed   (obj["red"].toInt());
    if (obj.contains("green")) color.setGreen (obj["green"].toInt());
    if (obj.contains("blue"))  color.setBlue  (obj["blue"].toInt());
    if (obj.contains("alpha")) color.setAlpha (obj["alpha"].toInt());

    return color;
}

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
    m_name = tr("Default theme");

    //load default
}

QString Palette::name() const
{
    return m_name;
}

void Palette::setName(const QString &name)
{
    m_name = name;

    emit nameChanged();
}

QColor Palette::windowText() const
{
    return m_palette.color(QPalette::WindowText);
}

void Palette::setWindowText(const QColor & color)
{
    m_palette.setColor(QPalette::WindowText, color);

    emit windowTextChanged();
}

QColor Palette::button() const
{
    return m_palette.color(QPalette::Button);
}

void Palette::setButton(const QColor & color)
{
    m_palette.setColor(QPalette::Button, color);

    emit buttonChanged();
}

QColor Palette::light() const
{
    return m_palette.color(QPalette::Light);
}

void Palette::setLight(const QColor & color)
{
    m_palette.setColor(QPalette::Light, color);

    emit lightChanged();
}

QColor Palette::midlight() const
{
    return m_palette.color(QPalette::Midlight);
}

void Palette::setMidlight(const QColor & color)
{
    m_palette.setColor(QPalette::Midlight, color);

    emit midlightChanged();
}

QColor Palette::dark() const
{
    return m_palette.color(QPalette::Dark);
}

void Palette::setDark(const QColor & color)
{
    m_palette.setColor(QPalette::Dark, color);

    emit darkChanged();
}

QColor Palette::mid() const
{
    return m_palette.color(QPalette::Mid);
}

void Palette::setMid(const QColor & color)
{
    m_palette.setColor(QPalette::Mid, color);

    emit midChanged();
}

QColor Palette::text() const
{
    return m_palette.color(QPalette::Text);
}

void Palette::setText(const QColor & color)
{
    m_palette.setColor(QPalette::Text, color);

    emit textChanged();
}

QColor Palette::brightText() const
{
    return m_palette.color(QPalette::BrightText);
}

void Palette::setBrightText(const QColor & color)
{
    m_palette.setColor(QPalette::BrightText, color);

    emit brightTextChanged();
}

QColor Palette::buttonText() const
{
    return m_palette.color(QPalette::ButtonText);
}

void Palette::setButtonText(const QColor & color)
{
    m_palette.setColor(QPalette::ButtonText, color);

    emit buttonTextChanged();
}

QColor Palette::base() const
{
    return m_palette.color(QPalette::Base);
}

void Palette::setBase(const QColor & color)
{
    m_palette.setColor(QPalette::Base, color);

    emit baseChanged();
}

QColor Palette::window() const
{
    return m_palette.color(QPalette::Window);
}

void Palette::setWindow(const QColor & color)
{
    m_palette.setColor(QPalette::Window, color);

    emit windowChanged();
}

QColor Palette::shadow() const
{
    return m_palette.color(QPalette::Shadow);
}

void Palette::setShadow(const QColor & color)
{
    m_palette.setColor(QPalette::Shadow, color);

    emit shadowChanged();
}

QColor Palette::highlight() const
{
    return m_palette.color(QPalette::Highlight);
}

void Palette::setHightlight(const QColor & color)
{
    m_palette.setColor(QPalette::Highlight, color);

    emit highlightChanged();
}

QColor Palette::highlightedText() const
{
    return m_palette.color(QPalette::HighlightedText);
}

void Palette::setHighlightedText(const QColor & color)
{
    m_palette.setColor(QPalette::HighlightedText, color);

    emit highlightedTextChanged();
}

QColor Palette::link() const
{
    return m_palette.color(QPalette::Link);
}

void Palette::setLink(const QColor & color)
{
    m_palette.setColor(QPalette::Link, color);

    emit linkChanged();
}

QColor Palette::linkVisited() const
{
    return m_palette.color(QPalette::LinkVisited);
}

void Palette::setLinkVisited(const QColor & color)
{
    m_palette.setColor(QPalette::LinkVisited, color);

    emit linkVisitedChanged();
}

QColor Palette::alternateBase() const
{
    return m_palette.color(QPalette::AlternateBase);
}

void Palette::setAlternateBase(const QColor & color)
{
    m_palette.setColor(QPalette::AlternateBase, color);

    emit alternateBaseChanged();
}

QColor Palette::noRole() const
{
    return m_palette.color(QPalette::NoRole);
}

void Palette::setNoRole(const QColor & color)
{
    m_palette.setColor(QPalette::NoRole, color);

    emit noRoleChanged();
}

QColor Palette::tooltipBase() const
{
    return m_palette.color(QPalette::ToolTipBase);
}

void Palette::setTooltipBase(const QColor & color)
{
    m_palette.setColor(QPalette::ToolTipBase, color);

    emit tooltipBaseChanged();
}

QColor Palette::tooltipText() const
{
    return m_palette.color(QPalette::ToolTipText);
}

void Palette::setTooltipText(const QColor & color)
{
    m_palette.setColor(QPalette::ToolTipText, color);

    emit tooltipTextChanged();
}

bool Palette::fromJson(const QJsonObject &obj)
{
    if(!obj.contains ("Name")  ) return false;
    if(!obj.contains ("Window")) return false;
    if(!obj.contains ("Button")) return false;
    if(!obj.contains ("Text")  ) return false;

    if(obj.contains ("Name")) setName(obj["Name"].toString());

    if(obj.contains ("WindowText"))           setWindowText (importColorFrom (obj["WindowText"].toObject()));
    if(obj.contains ("Button"))                   setButton (importColorFrom (obj["Button"].toObject()));
    if(obj.contains ("Light"))                     setLight (importColorFrom (obj["Light"].toObject()));
    if(obj.contains ("Midlight"))               setMidlight (importColorFrom (obj["Midlight"].toObject()));
    if(obj.contains ("Dark"))                       setDark (importColorFrom (obj["Dark"].toObject()));
    if(obj.contains ("Mid"))                         setMid (importColorFrom (obj["Mid"].toObject()));
    if(obj.contains ("Text"))                       setText (importColorFrom (obj["Text"].toObject()));
    if(obj.contains ("BrightText"))           setBrightText (importColorFrom (obj["BrightText"].toObject()));
    if(obj.contains ("ButtonText"))           setButtonText (importColorFrom (obj["ButtonText"].toObject()));
    if(obj.contains ("Base"))                       setBase (importColorFrom (obj["Base"].toObject()));
    if(obj.contains ("Window"))                   setWindow (importColorFrom (obj["Window"].toObject()));
    if(obj.contains ("Shadow"))                   setShadow (importColorFrom (obj["Shadow"].toObject()));
    if(obj.contains ("Highlight"))            setHightlight (importColorFrom (obj["Highlight"].toObject()));
    if(obj.contains ("HighlightedText")) setHighlightedText (importColorFrom (obj["HighlightedText"].toObject()));
    if(obj.contains ("Link"))                       setLink (importColorFrom (obj["Link"].toObject()));
    if(obj.contains ("LinkVisited"))         setLinkVisited (importColorFrom (obj["LinkVisited"].toObject()));
    if(obj.contains ("AlternateBase"))     setAlternateBase (importColorFrom (obj["AlternateBase"].toObject()));
    if(obj.contains ("NoRole"))                   setNoRole (importColorFrom (obj["NoRole"].toObject()));
    if(obj.contains ("ToolTipBase"))         setTooltipBase (importColorFrom (obj["ToolTipBase"].toObject()));
    if(obj.contains ("ToolTipText"))         setTooltipText (importColorFrom (obj["ToolTipText"].toObject()));

    return true;
}

QJsonObject Palette::toJson() const
{
    QJsonObject obj;

    obj["name"] = m_name;


    obj["WindowText"]      = exportColorTo(windowText());
    obj["Button"]          = exportColorTo(button());
    obj["Light"]           = exportColorTo(light());
    obj["Midlight"]        = exportColorTo(midlight());
    obj["Dark"]            = exportColorTo(dark());
    obj["Mid"]             = exportColorTo(mid());
    obj["Text"]            = exportColorTo(text());
    obj["BrightText"]      = exportColorTo(brightText());
    obj["ButtonText"]      = exportColorTo(buttonText());
    obj["Base"]            = exportColorTo(base());
    obj["Window"]          = exportColorTo(window());
    obj["Shadow"]          = exportColorTo(shadow());
    obj["Highlight"]       = exportColorTo(highlight());
    obj["HighlightedText"] = exportColorTo(highlightedText());
    obj["Link"]            = exportColorTo(link());
    obj["LinkVisited"]     = exportColorTo(linkVisited());
    obj["AlternateBase"]   = exportColorTo(alternateBase());
    obj["NoRole"]          = exportColorTo(noRole());
    obj["ToolTipBase"]     = exportColorTo(tooltipBase());
    obj["ToolTipText"]     = exportColorTo(tooltipText());

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
