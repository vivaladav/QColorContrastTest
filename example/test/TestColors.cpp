#include <QColorContrastTest/Base.h>

#include <QColor>

class TestColors : public QColorContrastTest::Base
{
    Q_OBJECT

private slots:
    void TestAA();
    void TestAAA();
};

void TestColors::TestAA()
{
    QVERIFY2(TestSmallTextAA(Qt::white, Qt::black), "AA #FFFFFF on #000000");
    QVERIFY2(TestSmallTextAA(Qt::black, Qt::white), "AA #000000 on #FFFFFF");

    QVERIFY2(!TestSmallTextAA(Qt::white, Qt::white), "AA #FFFFFF on #FFFFFF");

    QVERIFY2(TestSmallTextAA(Qt::white, QColor(0xC6, 0x28, 0x28)), "AA #FFFFFF on #C62828");
    QVERIFY2(TestSmallTextAA(Qt::white, QColor(0x1B, 0x5E, 0x20)), "AA #FFFFFF on #1B5E20");
    QVERIFY2(TestSmallTextAA(Qt::white, QColor(0x19, 0x76, 0xD2)), "AA #FFFFFF on #1976D2");
}

void TestColors::TestAAA()
{
    QVERIFY2(TestSmallTextAAA(Qt::white, Qt::black), "AAA #FFFFFF on #000000");
    QVERIFY2(TestSmallTextAAA(Qt::black, Qt::white), "AAA #000000 on #FFFFFF");

    QVERIFY2(!TestSmallTextAA(Qt::white, Qt::white), "AA #FFFFFF on #FFFFFF");

    QVERIFY2(!TestSmallTextAAA(Qt::white, QColor(0xC6, 0x28, 0x28)), "AAA #FFFFFF on #C62828");
    QVERIFY2(TestSmallTextAAA(Qt::white, QColor(0x1B, 0x5E, 0x20)), "AAA #FFFFFF on #1B5E20");
    QVERIFY2(!TestSmallTextAAA(Qt::white, QColor(0x19, 0x76, 0xD2)), "AAA #FFFFFF on #1976D2");
}

QTEST_MAIN(TestColors)
#include "TestColors.moc"
