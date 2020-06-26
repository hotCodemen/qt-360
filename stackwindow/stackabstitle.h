#ifndef STACKABSTITLE_H
#define STACKABSTITLE_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QStyleOption>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

#include "buttonbase1.h"

class stackabstitle : public QWidget
{
    Q_OBJECT
public:
    explicit stackabstitle(const QString icnJpg, QString btnJpg, QString title, QString title1, QWidget *parent = nullptr);

private:
    void titleWidget(QWidget *parent = nullptr);
    void topWidget(const QString right, QString left, QString title, QString title1);

protected:
    void paintEvent(QPaintEvent *ev);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public:
    buttonbase1 *m_minBtn;
    buttonbase1 *m_closeBtn;
    buttonbase1 *m_returnBtn;
    buttonbase1 *m_startscanBtn;
    QWidget     *m_titleWidget;
    QWidget     *m_topWidget;

private:
    bool        m_MousePressed;
    QPoint      m_WindowPos;
    QPoint      m_MousePos;

    buttonbase1 *m_skinBtn;
    buttonbase1 *m_msgBtn;
    buttonbase1 *m_setBtn;
    QHBoxLayout *m_TitleLayout;
    QHBoxLayout *m_TopLayout;
    QVBoxLayout *m_TitleMainLayout;
};

#endif // STACKABSTITLE_H
