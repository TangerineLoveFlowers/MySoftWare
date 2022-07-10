#include "mytitlebar.h"
#include <QLabel>
#include <QPushButton>
#include <QSize>
#include <QHBoxLayout>

MyTitleBar::MyTitleBar(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());//隐藏默认标题栏
    //setAttribute(Qt::WA_TranslucentBackground, true);//背景透明
    installEventFilter(this);//标题栏安装事件过滤器
    initTitleBar();
    initSingleSlot();
}

MyTitleBar::~MyTitleBar()
{

}

void MyTitleBar::onClicked()
{

}

void MyTitleBar::setIconSize(int w,int h)
{
    m_IconSize.setHeight(h);
    m_IconSize.setWidth(w);
}

void MyTitleBar::initTitleBar()
{

    setFixedHeight(35);
    m_pIconLable = new QLabel(this);
    m_pTitleLable = new QLabel(this);

    m_pMaximizeButton = new QPushButton(this);
    m_pMinimizeButton = new QPushButton(this);
    m_pCloseButton    = new QPushButton(this);


    m_IconSize.setHeight(25);
    m_IconSize.setWidth(30);
    m_pMaximizeButton->setIcon(QIcon(":/Images/titlebar/max.png"));
    m_pMaximizeButton->setIconSize(m_IconSize);
    /*
    想要去掉按钮的边框，让pushbutton按钮跟背景色融为一体，可以用函数QPushbutton::setFlat(true)来实现
    表面上得到了想要效果。但是在点击按钮时，还是会出现原来按钮背景。想要消除的话，可以用QSS来设置。
    用background-color:transparent allSelect->setStyleSheet("QPushButton{color:white; background-color:transparent;}");
    */
    m_pMaximizeButton->setFlat(true);
    m_pMinimizeButton->setIcon(QIcon(":/Images/titlebar/min.png"));
    m_pMinimizeButton->setIconSize(m_IconSize);
    m_pMinimizeButton->setFlat(true);
    m_pCloseButton->setIcon(QIcon(":/Images/titlebar/close.png"));
    m_pCloseButton->setIconSize(m_IconSize);
    m_pCloseButton->setFlat(true);

    /*
        水平：Expanding（控件可以自行增大或者缩小）
        垂直：（大小不能改变）
    */

    //设置控件的最大值和最小值
    m_pTitleLable->setFixedSize(m_IconSize);
    //设置图片自适应控件大小
    m_pTitleLable->setScaledContents(true);
    m_pTitleLable->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    m_pMaximizeButton->setFixedSize(m_IconSize);
    m_pMinimizeButton->setFixedSize(m_IconSize);
    m_pCloseButton->setFixedSize(m_IconSize);

    m_pMaximizeButton->setObjectName("maxButton");
    m_pMinimizeButton->setObjectName("minButton");
    m_pCloseButton->setObjectName("closeButton");
    m_pTitleLable->setObjectName("titleLable");
    m_pIconLable->setObjectName("iconLable");

    //提示信息
    m_pMaximizeButton->setToolTip(QString::fromLocal8Bit("最大化"));
    m_pMinimizeButton->setToolTip(QString::fromLocal8Bit("最小化"));
    m_pCloseButton->setToolTip(QString::fromLocal8Bit("关闭"));

    QHBoxLayout *pLayout= new QHBoxLayout(this);
    pLayout->addWidget(m_pIconLable);
    pLayout->addSpacing(5);
    pLayout->addWidget(m_pTitleLable);
    pLayout->addWidget(m_pMinimizeButton);
    pLayout->addWidget(m_pMaximizeButton);
    pLayout->addWidget(m_pCloseButton);
    pLayout->addSpacing(1);
    pLayout->setContentsMargins(5,0,5,0);
    setLayout(pLayout);
}

void MyTitleBar::initSingleSlot()
{
    connect(m_pMinimizeButton, &QPushButton::clicked, this, &MyTitleBar::onClicked);
    connect(m_pMaximizeButton,  &QPushButton::clicked, this, &MyTitleBar::onClicked);
    connect(m_pCloseButton,  &QPushButton::clicked, this, &MyTitleBar::onClicked);
}
