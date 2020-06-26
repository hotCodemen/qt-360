#ifndef STACKCHECK_H
#define STACKCHECK_H

#include <QWidget>
#include "stackabstitle.h"
#include "buttonbase1.h"
#include "buttonbase2.h"

class stackcheck : public QWidget
{
    Q_OBJECT
public:
    explicit stackcheck(QWidget *parent = nullptr);

    void titleWidget();

    void centerWidget();

    void bottomWidget();

public:
    stackabstitle *m_checkTile;

private:

    QWidget *m_checkCenter;
    QFrame  *m_checkBottom;

    QVBoxLayout *m_checkCenterLayout;
    QHBoxLayout *m_checkBottomLayout;
    QVBoxLayout *m_checkMainLayout;
};

#endif // STACKCHECK_H
