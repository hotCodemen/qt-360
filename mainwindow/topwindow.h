#ifndef TOP_WINDOW_H
#define TOP_WINDOW_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMouseEvent>

#include "buttonbase.h"
#include "buttonbase1.h"

class topwindow : public QWidget
{
    Q_OBJECT
public:
    explicit topwindow(QWidget *parent = nullptr);

    void titileInit();
    void centerInit();

protected:
    void paintEvent(QPaintEvent *ev);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public:
    buttonbase1 *m_minBtn;
    buttonbase1 *m_closeBtn;

private:
    QLabel *m_logoIco;
    QLabel *m_title;
    buttonbase1 *m_updateBtn;
    buttonbase1 *m_skinBtn;
    buttonbase1 *m_msgBtn;
    buttonbase1 *m_setBtn;

    QWidget     *m_topWidget;
    QHBoxLayout *m_topLayout;

    buttonbase  *m_labscore;
    buttonbase1 *m_head;
    buttonbase1 *m_checkBtn;
    buttonbase  *m_securityBtn;
    buttonbase  *m_payforBtn;
    QWidget     *m_bottomWidget;
    QVBoxLayout *m_bottomLayout;

    bool        m_MousePressed;
    QPoint      m_WindowPos;
    QPoint      m_MousePos;
    QVBoxLayout *m_mainLayout;
};

#endif // TOP_WINDOW_H
