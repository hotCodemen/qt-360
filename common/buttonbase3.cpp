#include <QPainter>
#include "buttonbase3.h"

buttonbase3::buttonbase3(QString pixcheckurl,QString pixuncheckurl,QWidget *parent) : QPushButton(parent)
{
    setCursor(Qt::PointingHandCursor);
    setFixedSize(150,150);
    m_checkindex=4;//checkbox的值
    m_uncheckindex=0;//checkbox的值
    m_checked=true;
    m_enter=false;

    m_pixcheck=QPixmap(pixcheckurl);
    m_pixuncheck=QPixmap(pixuncheckurl);

    QPixmap pixcheckbox(":/image/cat_checkbox.png");
    for(int i=0;i<12;i++)
        m_checklist<<pixcheckbox.copy(i*(pixcheckbox.width()/12),0,pixcheckbox.width(),pixcheckbox.height());
}

void buttonbase3::enterEvent(QEvent *ev)
{
    m_checkindex=5;//选中的
    m_uncheckindex=1;//黑色的
    m_enter=true;
    update();
}

void buttonbase3::leaveEvent(QEvent *ev)
{
    m_enter=false;
    m_checkindex=4;//checkbox的值
    m_uncheckindex=0;//checkbox的值
    update();
}

void buttonbase3::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton)
    {
        if(m_checked)
        m_checked=false;
        else
        m_checked=true;
        update();
        QPushButton::mousePressEvent(ev);
    }
}

void buttonbase3::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    QPainter p1(this);
    QPixmap m_pixcheckhover(":/image/cat_hover.png");
    QPixmap m_pixuncheckhover(":/image/cat_gray_hover.png");

    if(m_checked)//如果选中了
    {
        if(m_enter)
        {
            p.drawPixmap(rect(),m_pixcheckhover);
            p.drawPixmap(110,110,m_checklist.at(m_checkindex));
        }
        p1.drawPixmap(rect(),m_pixcheck);
        p1.drawPixmap(110,110,m_checklist.at(m_checkindex));
    }
    else//如果没选中了
    {
        if(m_enter)
        {
             p.drawPixmap(rect(),m_pixuncheckhover);
             p.drawPixmap(110,110,m_checklist.at(m_uncheckindex));
        }
        p1.drawPixmap(rect(),m_pixuncheck);
        p1.drawPixmap(110,110,m_checklist.at(m_uncheckindex));
    }
}
