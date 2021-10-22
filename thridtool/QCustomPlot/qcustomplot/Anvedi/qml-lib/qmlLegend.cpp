#include "qmlLegend.h"

QString qmlLegend::getFontString() const
{
	return font.toString();
}
/**
 * @brief qmlLegend::setFontString
 * @param Fontfamily
 * Point size
 * Pixel size
 * Style hint
 * Font weight
 * Font style
 * Underline
 * Strike out
 *  Fixed pitch Always 0 Capitalization Letter spacing Word spacing  Stretch Style strategy

 */
void qmlLegend::setFontString(const QString& f)
{
	font.fromString(f);
}

const QFont& qmlLegend::getFont() const
{
	return font;
}
