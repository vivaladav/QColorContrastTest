#pragma once

#include "QColorContrastTest_global.h"

#include <QObject>
#include <QTest>

namespace QColorContrastTest
{

class QCOLORCONTRASTTEST_EXPORT Base : public QObject
{
    Q_OBJECT

public:
    Base(QObject * parent = nullptr);

protected:
    bool TestSmallTextAA(const QColor & c1, const QColor & c2) const;
    bool TestSmallTextAAA(const QColor & c1, const QColor & c2) const;
    bool TestLargeTextAA(const QColor & c1, const QColor & c2) const;
    bool TestLargeTextAAA(const QColor & c1, const QColor & c2) const;

private:
    qreal ContrastRatio(const QColor & c1, const QColor & c2) const;
    qreal RelativeLuminance(const QColor & color) const;
    qreal ConvertChannel(qreal c) const;
};

} // namespace QColorContrastTest
