#ifndef BUTTON_BASE1_H
#define BUTTON_BASE1_H

#include <QPainter>
#include <QPushButton>
#include <QString>
#include "buttoncommon.h"

class buttonbase1 : public QPushButton
{
    Q_OBJECT
public:
    explicit buttonbase1(const QString jpgPath, int jpgNum, QWidget *parent = nullptr);

protected:
    void enterEvent(QEvent *ev);
    void leaveEvent(QEvent *ev);
    void paintEvent(QPaintEvent *ev);

private:
    int         m_jpgNum;
    int         m_jpgWidth;
    int         m_jpgHeight;
    enJpgAction m_action;
    QPixmap     m_actionJpg;
};

#endif // BUTTON_BASE1_H
