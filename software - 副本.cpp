#include "software.h"
#include <QGraphicsDropShadowEffect>
#include <QVBoxLayout>

Software::Software(QWidget *parent)
    : QWidget(parent)
{
//    if(parent->objectName().isEmpty())
//        parent->setObjectName("widget");

    this->resize(600,400);

    m_shadowLayout= new QVBoxLayout(this);
    m_shadowLayout->setObjectName("shadowLayout");

    m_showWidget = new QWidget(this);
    m_showWidget->setObjectName("showWidget");
    m_showWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 255, 145);"));


    m_showWidgetLayout= new QVBoxLayout(m_showWidget);
    m_showWidgetLayout->setObjectName("showWidgetLayoyt");
    m_showWidgetLayout->setSpacing(0);
    m_showWidgetLayout->setContentsMargins(0,0,0,0);

    m_titleBar = new QWidget(m_showWidget);
    m_titleBar->setObjectName("titleBar");
    m_titleBar->setStyleSheet(QString("background-color:rgb(20,255,145);"));

    m_middleWidget = new QWidget(m_showWidget);
    m_middleWidget->setObjectName("middleWidget");
    m_middleWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 252, 252);"));



    QSizePolicy sizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(m_titleBar->sizePolicy().hasHeightForWidth());

    m_titleBar->setSizePolicy(sizePolicy);
    m_titleBar->setMaximumSize(QSize(this->width(),50));

    m_showWidgetLayout->addWidget(m_titleBar);
    m_showWidgetLayout->addWidget(m_middleWidget);

    m_shadowLayout->addWidget(m_showWidget);

    //QMetaObject::connectSlotsByName(this);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
       //设置无边框
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setStyleSheet(QString("border-radius:8px;"));
    //实例阴影shadow
      QGraphicsDropShadowEffect* shadow= new QGraphicsDropShadowEffect(this);
    //设置阴影距离
    shadow->setOffset(0, 0);
    //设置阴影颜色
    shadow->setColor(QColor("#00BFFF"));
    //设置阴影圆角
    shadow->setBlurRadius(30);
    //给嵌套QWidget设置阴影
    m_showWidget->setGraphicsEffect(shadow);
    //给垂直布局器设置边距(此步很重要, 设置宽度为阴影的宽度)
    m_shadowLayout->setMargin(24);
}

Software::~Software()
{
}

