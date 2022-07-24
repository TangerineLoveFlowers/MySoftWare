#ifndef SOFTWARE_H
#define SOFTWARE_H

#include <QWidget>


class QVBoxLayout;
class Software : public QWidget
{
    Q_OBJECT

public:
    Software(QWidget *parent = nullptr);
    ~Software();

private:
    QWidget *m_showWidget;
    QWidget *m_titleBar;
    QWidget *m_middleWidget;

    QVBoxLayout *m_shadowLayout;
    QVBoxLayout *m_showWidgetLayout;
};
#endif // SOFTWARE_H
