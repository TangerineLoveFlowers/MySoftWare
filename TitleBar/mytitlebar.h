#ifndef MYTITLEBAR_H
#define MYTITLEBAR_H

#include <QWidget>
#include "AbsFrameLessAutoSize.h"

class QPushButton;
class QLabel;
class QSize;

class MyTitleBar : public AbsFrameLessAutoSize
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
    QSize m_IconSize;
    AbsFrameLessAutoSize *m_AbsFrameLessAutoSize;

    //QPoint m_movePoint_Z;
private:


    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event)override;
//    void mouseDoubleClickEvent(QMouseEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event)override;


//    QPoint last;
//                 //鼠标移动

};

#endif // MYTITLEBAR_H
