#include "buttonbase2.h"

buttonbase2::buttonbase2(const QString enterJpg, int enterNum, const QString leaveJpg, int leaveNum, QWidget *parent) :
    QPushButton(parent), m_actionIndex(0)
{
    int i = 0;

    m_enterJpg.load(enterJpg);
    m_leaveJpg.load(leaveJpg);

    m_enterWidth = m_enterJpg.width()/enterNum;
    m_leaveWidth = m_leaveJpg.width()/leaveNum;

    for(int i = 0; i < 10; i++)
    {
        m_enterList<<m_enterJpg.copy(i*m_enterWidth, 0, m_enterWidth, m_enterJpg.height());
    }

    for(int i = 0; i < 10; i++)
    {
        m_leaveList<<m_leaveJpg.copy(i*m_leaveWidth, 0, m_leaveWidth, m_leaveJpg.height());
    }

    m_normalJpg = m_enterJpg.copy(0, 0, m_enterWidth, m_enterJpg.height());

    //进入动画
    m_enteranimation=new QPropertyAnimation(this, "");
    m_enteranimation->setStartValue(0);
    m_enteranimation->setEndValue(enterNum - 1);
    m_enteranimation->setDuration((enterNum/2)*100 + 100);

    //离开动画
    m_leaveanimation=new QPropertyAnimation(this, "");
    m_leaveanimation->setStartValue(0);
    m_leaveanimation->setEndValue(leaveNum - 1);
    m_leaveanimation->setDuration((enterNum/2)*100 + 100);

    connect(m_enteranimation, &QPropertyAnimation::valueChanged, [=](QVariant Variant){
        m_actionIndex = Variant.toInt();
        update();
    });

    connect(m_leaveanimation, &QPropertyAnimation::valueChanged, this, [=](QVariant Variant){
        m_actionIndex = Variant.toInt();
        update();
    });

    connect(m_leaveanimation,  &QPropertyAnimation::finished, [=](){
        m_leave = false;
        update();
    });
}

void buttonbase2::enterEvent(QEvent *ev)
{
    m_enter = true;
    m_leave = false;
    setCursor(Qt::PointingHandCursor);
    m_enteranimation->start();
}

void buttonbase2::leaveEvent(QEvent *ev)
{
    m_enter = false;
    m_leave = true;
    m_leaveanimation->start();
}

void buttonbase2::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);

    if(m_enter)
        painter.drawPixmap(rect(), m_enterList.at(m_actionIndex));

    if(m_leave)
        painter.drawPixmap(rect(), m_leaveList.at(m_actionIndex));

    if(!m_leave && !m_enter)
        painter.drawPixmap(rect(), m_normalJpg);
}
