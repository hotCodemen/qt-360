#include "buttonbase1.h"

buttonbase1::buttonbase1(const QString jpgPath, int jpgNum, QWidget *parent) : QPushButton(parent)
{
    m_action = BUTTON_NORMAL_ACTION;

    m_jpgNum = jpgNum;
    m_actionJpg.load(jpgPath);

    m_jpgWidth  = m_actionJpg.width()/m_jpgNum;
    m_jpgHeight = m_actionJpg.height();

    connect(this, &QPushButton::pressed,  [=](){m_action = BUTTON_CHECK_ACTION;update();});
    connect(this, &QPushButton::released, [=](){m_action = BUTTON_NORMAL_ACTION;update();});
}

//鼠标进入
void buttonbase1::enterEvent(QEvent *ev)
{
    m_action = BUTTON_HOVER_ACTION;
    setCursor(Qt::PointingHandCursor);
    update();
}

//鼠标离开
void buttonbase1::leaveEvent(QEvent *ev)
{
     m_action = BUTTON_NORMAL_ACTION;
     update();
}

//窗口改变事件
void buttonbase1::paintEvent(QPaintEvent *ev)
{
    QPainter painter;

    switch(m_action)
    {
        case BUTTON_NORMAL_ACTION:
            painter.begin(this);
            painter.drawPixmap(0,0,m_jpgWidth, m_jpgHeight, m_actionJpg.copy(0,0,m_jpgWidth,m_jpgHeight));
            painter.end();
            break;

        case BUTTON_HOVER_ACTION:
            painter.begin(this);
            painter.drawPixmap(0,0,m_jpgWidth, m_jpgHeight, m_actionJpg.copy(m_jpgWidth,0,m_jpgWidth,m_jpgHeight));
            painter.end();
            break;

        case BUTTON_CHECK_ACTION:
            painter.begin(this);
            painter.drawPixmap(0,0,m_jpgWidth, m_jpgHeight, m_actionJpg.copy(m_jpgWidth,0,m_jpgWidth,m_jpgHeight));
            painter.end();
            break;
    }

    return ;
}
