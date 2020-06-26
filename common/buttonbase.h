#ifndef BUTTON_BASE_H
#define BUTTON_BASE_H

#include <QPainter>
#include <QPushButton>
#include <QString>
#include "buttoncommon.h"

class buttonbase : public QPushButton
{
public:
    buttonbase(QWidget *parent = nullptr);
    bool setButtonInit(const QString normalJpgPath, const QString hoverJpgPath, const QString checkedJpgPath, QPoint jpgPoint);
    bool setButtonInit(QPixmap &normalJpg, QPixmap &hoverJpg, QPixmap &checkedJpg, QPoint jpgPoint);
    void setButtonText(const QString text, QColor textColor, QPoint textPoint);
    void setButtonBorder(const QString borderPath, bool norBorder, bool hovBorder);
    void setButtonBorder(const QString borderPath, int borderNum, int showNum, bool norBorder, bool hovBorder);

protected:
    void enterEvent(QEvent *ev);
    void leaveEvent(QEvent *ev);
    void paintEvent(QPaintEvent *ev);

private:
    enJpgAction m_action;
    QPixmap m_normalJpg;
    QPixmap m_hoverJpg;
    QPixmap m_checkedJpg;
    QPixmap m_pixborder;
    QPoint  m_JpgPoint;
    QPoint  m_textPoint;
    QColor  m_textColor;
    QString m_text;
    bool    m_norShowBorder;
    bool    m_hovShowBorder;
};

#endif // BUTTON_BASE_H
