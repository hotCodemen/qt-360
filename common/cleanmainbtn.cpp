#include "cleanmainbtn.h"
#include <QPainter>
#include <QMouseEvent>

cleanMainBtn::cleanMainBtn(QString normal,QString gray,QString aninormal,QString anigray,int number,QWidget *parent):QPushButton(parent)
{
    m_pixnormal=QPixmap(normal);
    m_pixgray=QPixmap(gray);

    QPixmap pixani(aninormal);
    QPixmap pixanigray(anigray);
    count=number;
    for(int i=0;i<count;i++)//正常
        m_pixaninormallist<<pixani.copy(i*(pixani.width()/count),0,pixani.width()/count,pixani.height());
    for(int i=0;i<count;i++)//gray
        m_pixanigraylist<<pixanigray.copy(i*(pixanigray.width()/count),0,pixanigray.width()/count,pixanigray.height());

    setCursor(Qt::PointingHandCursor);

    m_enter=false;
    m_ischeck=true;
    m_normalindex=0;

    m_aninormal=new QPropertyAnimation(this,"");
    m_aninormal->setStartValue(0);
    m_aninormal->setEndValue(count-1);
    m_aninormal->setDuration(1200);
    connect(m_aninormal,SIGNAL(valueChanged(QVariant)),this,SLOT(slot_normalaimachange(QVariant)));
}
void cleanMainBtn::paintEvent(QPaintEvent *)
{
    QPixmap pixcheck(":/image/clean/group_check.png");
    QPixmap pixuncheck(":/image/clean/group_uncheck.png");

    QPixmap pixcheck_hoverborder(":/image/clean/select_hover.png");
    QPixmap pixcheckborder(":/image/clean/select_normal.png");

    QPixmap pixuncheck_hoverborder(":/image/clean/notselect_hover.png");
    QPixmap pixuncheckborder(":/image/clean/notselect_normal.png");
    QPainter p(this);
    QPainter p2(this);
    if(m_enter)//如果进入就启动动画
    {
        if(m_ischeck)//选中动画

        {
            p.drawPixmap((width()-pixcheckborder.width())/2,(height()-pixcheckborder.height())/2,pixcheckborder);
            p2.drawPixmap((width()-pixcheck_hoverborder.width())/2,(height()-pixcheck_hoverborder.height())/2,pixcheck_hoverborder);
            p.drawPixmap((width()-m_pixaninormallist.at(m_normalindex).width())/2,(height()-m_pixaninormallist.at(m_normalindex).height())/2
                         ,m_pixaninormallist.at(m_normalindex));
            p.drawPixmap(width()-pixcheck.width(),height()-1.5*(pixcheck.height()),pixcheck);
        }
            else//非选中动画
        {
            p.drawPixmap((width()-pixuncheckborder.width())/2,(height()-pixuncheckborder.height())/2,pixuncheckborder);
            p2.drawPixmap(rect(),pixuncheck_hoverborder);
            p.drawPixmap((width()-m_pixanigraylist.at(m_normalindex).width())/2,(height()-m_pixanigraylist.at(m_normalindex).height())/2
                         ,m_pixanigraylist.at(m_normalindex));
            p.drawPixmap(width()-pixuncheck.width(),height()-1.5*(pixuncheck.height()),pixuncheck);
        }
    }
    else//如果不进入
    {
        if(m_ischeck)//如果是选中就做选中动画//起始位置
        {
            p.drawPixmap((width()-m_pixnormal.width())/2,(height()-m_pixnormal.height())/2,m_pixnormal);
            p.drawPixmap(width()-pixcheck.width(),height()-1.5*(pixcheck.height()),pixcheck);
        }
            else
        {
            p.drawPixmap((width()-m_pixgray.width())/2,(height()-m_pixgray.height())/2,m_pixgray);
            p.drawPixmap(width()-pixuncheck.width(),height()-1.5*(pixuncheck.height()),pixuncheck);
        }
    }
}
void cleanMainBtn::enterEvent(QEvent *)
{
    m_enter=true;
    m_aninormal->start();
}
void cleanMainBtn::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        if(m_ischeck)
            m_ischeck=false;
        else
            m_ischeck=true;
        m_aninormal->start();
        QPushButton::mousePressEvent(e);
    }
}
void cleanMainBtn::leaveEvent(QEvent *)//如果离开
{
    m_enter=false;
    m_aninormal->stop();
    m_normalindex=0;
}
