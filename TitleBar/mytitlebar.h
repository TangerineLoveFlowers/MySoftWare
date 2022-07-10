#ifndef MYTITLEBAR_H
#define MYTITLEBAR_H

#include <QWidget>
class QPushButton;
class QLabel;
class QSize;

class MyTitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit MyTitleBar(QWidget *parent = nullptr);
    ~MyTitleBar();

signals:


public slots:

    void onTitleClicked();

public:
    void setIconSize(int w,int h);

private:
    void initTitleBar();

    void initSingleSlot();

private:
    QPushButton *m_pMinimizeButton;
    QPushButton *m_pMaximizeButton;
    QPushButton *m_pCloseButton;

    QLabel *m_pIconLable;
    QLabel *m_pTitleLable;

private:

    QSize m_IconSize;


};

#endif // MYTITLEBAR_H
