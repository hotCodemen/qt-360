#ifndef BUTTON_BASE2_H
#define BUTTON_BASE2_H

#include <QPixmap>
#include <QPainter>
#include <QPushButton>
#include <QPropertyAnimation>

#include "buttoncommon.h"

class buttonbase2 : public QPushButton
{
    Q_OBJECT
public:
    explicit buttonbase2(const QString enterJpg, int enterNum, const QString leaveJpg, int leaveNum, QWidget *parent = nullptr);

protected:
    void enterEvent(QEvent *ev);
    void leaveEvent(QEvent *ev);
    void paintEvent(QPaintEvent *ev);

private:
    bool m_enter;
    bool m_leave;

    int m_actionIndex;
    int m_enterWidth;
    int m_leaveWidth;

    QPropertyAnimation *m_enteranimation;
    QPropertyAnimation *m_leaveanimation;

    QList<QPixmap> m_enterList;
    QList<QPixmap> m_leaveList;

    QPixmap m_normalJpg;
    QPixmap m_enterJpg;
    QPixmap m_leaveJpg;
};

#endif // BUTTON_BASE2_H
