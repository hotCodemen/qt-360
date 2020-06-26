#ifndef STACKOPTIMIZE_H
#define STACKOPTIMIZE_H

#include "stackabstitle.h"
#include "buttonbase3.h"

class stackoptimize : public QWidget
{
    Q_OBJECT
public:
    explicit stackoptimize(QWidget *parent = nullptr);

    void titleWidget();

    void centerWidget();

    void bottomWidget();

public:
    stackabstitle *m_optimizeTile;

private:
    buttonbase3 *m_startingBtn;
    buttonbase3 *m_systemBtn;
    buttonbase3 *m_networkBtn;
    buttonbase3 *m_diskBtn;

    QWidget *m_optimizeCenter;
    QFrame  *m_optimizeBottom;

    QVBoxLayout *m_optimizeMainLayout;
};

#endif // STACKOPTIMIZE_H
