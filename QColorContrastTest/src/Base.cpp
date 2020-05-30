#include "QColorContrastTest/Base.h"

#include <QColor>
#include <QtMath>

namespace QColorContrastTest
{
/**
 * @brief Constructor.
 * @param parent Pointer to parent object, if any.
 */
Base::Base(QObject * parent) : QObject(parent) { }

/**
 * @brief Checks the contrast between 2 colors for small text (AA requirements).
 *
 * This can be used when testing a color combination that should pass the AA requirements.
 * Size of small text is less than 18pt or 14pt when bold.
 *
 * @param c1 Color of the text.
 * @param c2 Color of the background.
 * @return TRUE if the contrast is passing the AA test, FALSE otherwise.
 */
bool Base::TestSmallTextAA(const QColor & c1, const QColor & c2) const
{
    const qreal contrast = ContrastRatio(c1, c2);

    return contrast > 4.5;
}

/**
 * @brief Checks the contrast between 2 colors for small text (AAA requirements).
 *
 * This can be used when testing a color combination that should pass the AAA requirements.
 * Size of small text is less than 18pt or 14pt when bold.
 *
 * @param c1 Color of the text.
 * @param c2 Color of the background.
 * @return TRUE if the contrast is passing the AA test, FALSE otherwise.
 */
bool Base::TestSmallTextAAA(const QColor & c1, const QColor & c2) const
{
    const qreal contrast = ContrastRatio(c1, c2);

    return contrast > 7.0;
}

/**
 * @brief Checks the contrast between 2 colors for large text (AA requirements).
 *
 * This can be used when testing a color combination that should pass the AA requirements.
 * Size of large text is at least 18pt or at least 14pt when bold.
 *
 * @param c1 Color of the text.
 * @param c2 Color of the background.
 * @return TRUE if the contrast is passing the AA test, FALSE otherwise.
 */
bool Base::TestLargeTextAA(const QColor & c1, const QColor & c2) const
{
    const qreal contrast = ContrastRatio(c1, c2);

    return contrast > 3;
}

/**
 * @brief Checks the contrast between 2 colors for large text (AAA requirements).
 *
 * This can be used when testing a color combination that should pass the AA requirements.
 * Size of large text is at least 18pt or at least 14pt when bold.
 *
 * @param c1 Color of the text.
 * @param c2 Color of the background.
 * @return TRUE if the contrast is passing the AAA test, FALSE otherwise.
 */
bool Base::TestLargeTextAAA(const QColor & c1, const QColor & c2) const
{
    const qreal contrast = ContrastRatio(c1, c2);

    return contrast > 4.5;
}

/**
 * @brief Computes the contrast ratio between 2 colors.
 * @param c1 Color 1.
 * @param c2 Color 2.
 * @return A value in the range [1, 21]
 */
qreal Base::ContrastRatio(const QColor & c1, const QColor & c2) const
{
    const qreal l1 = RelativeLuminance(c1);
    const qreal l2 = RelativeLuminance(c2);

    const qreal INC = 0.05;
    const qreal ratio = (l1 > l2) ? ((l2 + INC) / (l1 + INC)) : ((l1 + INC) / (l2 + INC));

    return 1.0 / ratio;
}

/**
 * @brief Computes the relative luminance of a color.
 * @param color Color.
 * @return A value in the range [0, 1]
 */
qreal Base::RelativeLuminance(const QColor & color) const
{
    const qreal r = ConvertChannel(color.redF());
    const qreal g = ConvertChannel(color.greenF());
    const qreal b = ConvertChannel(color.blueF());

    // magic numbers from WCAG
    return r * 0.2126 + g * 0.7152 + b * 0.0722;
}

/**
 * @brief Utility function that converts a color channel for the relative luminance formula.
 * @param c A color channel in the range [0, 1]
 * @return A converted value to use in the luminance formula.
 */
qreal Base::ConvertChannel(qreal c) const
{
    // more magic numbers from WCAG
    if(c <= 0.03928)
        return c / 12.92;
    else
        return qPow((c + 0.055) / 1.055, 2.4);
}

} // namespace QColorContrastTest
