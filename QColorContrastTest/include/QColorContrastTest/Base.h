#pragma once

#include "QColorContrastTest_global.h"

#include <QObject>
#include <QTest>

namespace QColorContrastTest
{

/// Base class to implement unit tests with Qt Test that check color contrast
/// according to the WCAG guidelines.
class QCOLORCONTRASTTEST_EXPORT Base : public QObject
{
    Q_OBJECT

public:
    Base(QObject * parent = nullptr);

    qreal ContrastRatio(const QColor & c1, const QColor & c2) const;

protected:
    bool TestSmallTextAA(const QColor & c1, const QColor & c2) const;
    bool TestSmallTextAAA(const QColor & c1, const QColor & c2) const;
    bool TestLargeTextAA(const QColor & c1, const QColor & c2) const;
    bool TestLargeTextAAA(const QColor & c1, const QColor & c2) const;

private:
    qreal RelativeLuminance(const QColor & color) const;
    qreal ConvertChannel(qreal c) const;
};

} // namespace QColorContrastTest
