#ifndef SOFTWARE_H
#define SOFTWARE_H

#include <QWidget>


class QVBoxLayout;
class MyTitleBar;
class MiddleWidget;

class Software : public QWidget
{
    Q_OBJECT

public:
    Software(QWidget *parent = nullptr);
    ~Software();

private:
    void initUI();

private:
    QWidget *m_showWidget;
    //QWidget *m_titleBar;
    MyTitleBar *m_titleBar;

    //QWidget *m_middleWidget;
    MiddleWidget*m_middleWidget;

    QVBoxLayout *m_shadowLayout;
    QVBoxLayout *m_showWidgetLayout;
};
#endif // SOFTWARE_H
