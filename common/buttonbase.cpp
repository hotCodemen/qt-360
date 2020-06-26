#include "buttonbase.h"
#include <QDebug>

buttonbase::buttonbase(QWidget *parent) : QPushButton(parent)
{
    m_action = BUTTON_NORMAL_ACTION;

    m_norShowBorder = false;
    m_hovShowBorder = false;
}

//设置图片
bool buttonbase::setButtonInit(const QString normalJpgPath, const QString hoverJpgPath, const QString checkedJpgPath, QPoint jpgPoint)
{
   m_normalJpg.load(normalJpgPath);
   m_hoverJpg.load(hoverJpgPath);
   m_checkedJpg.load(checkedJpgPath);
   m_JpgPoint = jpgPoint;
}

bool buttonbase::setButtonInit(QPixmap &normalJpg, QPixmap &hoverJpg, QPixmap &checkedJpg, QPoint jpgPoint)
{
   m_normalJpg  = normalJpg;
   m_hoverJpg   = hoverJpg;
   m_checkedJpg = checkedJpg;
   m_JpgPoint   = jpgPoint;
}

//设置文字
void buttonbase::setButtonText(const QString text, QColor textColor, QPoint textPoint)
{
    m_text = text;
    m_textColor = textColor;
    m_textPoint = textPoint;
}

//设置外边框
void buttonbase::setButtonBorder(const QString borderPath, bool norBorder, bool hovBorder)
{
    m_norShowBorder = norBorder;

    m_hovShowBorder = hovBorder;

    m_pixborder.load(borderPath);
}

void buttonbase::setButtonBorder(const QString borderPath, int borderNum, int showNum, bool norBorder, bool hovBorder)
{
    m_norShowBorder = norBorder;

    m_hovShowBorder = hovBorder;

    QPixmap borpix(borderPath);
    m_pixborder=borpix.copy(showNum*(borpix.width()/borderNum),0,borpix.width()/borderNum,borpix.height());
}

//鼠标进入
void buttonbase::enterEvent(QEvent *ev)
{
    m_action = BUTTON_HOVER_ACTION;
    setCursor(Qt::PointingHandCursor);
    update();
}

//鼠标离开
void buttonbase::leaveEvent(QEvent *ev)
{
     m_action = BUTTON_NORMAL_ACTION;
     update();
}

//窗口改变事件
void buttonbase::paintEvent(QPaintEvent *ev)
{
    QFont font;
    QFontMetrics fontmetr(font);
    QPainter painter;

    switch(m_action)
    {
        case BUTTON_NORMAL_ACTION:
            painter.begin(this);
            if(m_norShowBorder) {
                painter.drawPixmap(rect(),m_pixborder);
            }
            painter.drawPixmap(m_JpgPoint, m_normalJpg);
            painter.end();
            break;

        case BUTTON_HOVER_ACTION:
            painter.begin(this);
            if(m_hovShowBorder) {
                painter.drawPixmap(rect(),m_pixborder);
            }
            painter.drawPixmap(m_JpgPoint, m_hoverJpg);
            painter.end();
            break;

        case BUTTON_CHECK_ACTION:
            painter.begin(this);
            painter.drawPixmap(m_JpgPoint, m_checkedJpg);
            painter.end();
            break;
    }

    if(!m_text.isEmpty())
    {
//        int m_width= fontmetr.width(m_text);
        painter.begin(this);
        painter.setPen(m_textColor);
        painter.drawText(m_textPoint, m_text);
        painter.end();
    }

    return ;
}

