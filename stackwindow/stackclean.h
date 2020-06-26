#ifndef STACKCLEAN_H
#define STACKCLEAN_H

#include "stackabstitle.h"

class stackclean : public QWidget
{
    Q_OBJECT
public:
    explicit stackclean(QWidget *parent = nullptr);

    void titleWidget();

    void centerWidget();

    void bottomWidget();

public:
    stackabstitle *m_cleanTile;

private:
    QWidget *m_cleanCenter;
    QFrame  *m_cleanBottom;

    QVBoxLayout *m_cleanMainLayout;
};

#endif // STACKCLEAN_H
