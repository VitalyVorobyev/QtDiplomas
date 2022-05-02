#include <QtTest>

// add necessary includes here

class testCase1 : public QObject
{
    Q_OBJECT

public:
    testCase1();
    ~testCase1();

private slots:
    void test_case1();

};

testCase1::testCase1()
{

}

testCase1::~testCase1()
{

}

void testCase1::test_case1()
{

}

QTEST_APPLESS_MAIN(testCase1)

#include "tst_testcase1.moc"
