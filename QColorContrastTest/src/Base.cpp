#include "QColorContrastTest/Base.h"

#include <QColor>
#include <QtMath>

namespace QColorContrastTest
{

Base::Base(QObject * parent) : QObject(parent) { }

bool Base::TestSmallTextAA(const QColor & c1, const QColor & c2) const
{
    const qreal contrast = ContrastRatio(c1, c2);

    return contrast > 4.5;
}

bool Base::TestSmallTextAAA(const QColor & c1, const QColor & c2) const
{
    const qreal contrast = ContrastRatio(c1, c2);

    return contrast > 7.0;
}

bool Base::TestLargeTextAA(const QColor & c1, const QColor & c2) const
{
    const qreal contrast = ContrastRatio(c1, c2);

    return contrast > 3;
}

bool Base::TestLargeTextAAA(const QColor & c1, const QColor & c2) const
{
    const qreal contrast = ContrastRatio(c1, c2);

    return contrast > 4.5;
}

qreal Base::ContrastRatio(const QColor & c1, const QColor & c2) const
{
    const qreal l1 = RelativeLuminance(c1);
    const qreal l2 = RelativeLuminance(c2);

    const qreal INC = 0.05f;
    const qreal ratio = (l1 > l2) ? ((l2 + INC) / (l1 + INC)) : ((l1 + INC) / (l2 + INC));
    return 1 / ratio;
}

qreal Base::RelativeLuminance(const QColor & color) const
{
    const qreal r = ConvertChannel(color.redF());
    const qreal g = ConvertChannel(color.greenF());
    const qreal b = ConvertChannel(color.blueF());

    return r * 0.2126 + g * 0.7152 + b * 0.0722;
}

qreal Base::ConvertChannel(qreal c) const
{
    if(c <= 0.03928)
        return c / 12.92;
    else
        return qPow((c + 0.055) / 1.055, 2.4);
}

} // namespace QColorContrastTest
