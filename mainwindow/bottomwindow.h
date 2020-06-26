#ifndef BOTTOM_WINDOW_H
#define BOTTOM_WINDOW_H

#include <QLabel>
#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "buttonbase.h"
//#include "buttonbase1.h"
#include "buttonbase2.h"

class bottomwindow : public QWidget
{
    Q_OBJECT
public:
    explicit bottomwindow(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *ev);

public:
    buttonbase2  *m_checkBtn;
    buttonbase2  *m_cleanBtn;
    buttonbase2  *m_optimizeBtn;

private:
    buttonbase  *m_windowBtn;
    buttonbase  *m_appBtn;
    buttonbase  *m_memBtn;
    buttonbase  *m_broadbandBtn;
    buttonbase  *m_questionBtn;
    buttonbase  *m_moreBtn;
    QVBoxLayout *m_rightLt;
    QHBoxLayout *m_rightTopLt;
    QHBoxLayout *m_rightBottomLt;
    QHBoxLayout *m_mainLayout;
};

#endif // BOTTOM_WINDOW_H
