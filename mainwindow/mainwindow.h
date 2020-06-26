#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QStackedWidget>
#include "topwindow.h"
#include "bottomwindow.h"
#include "stackcheck.h"
#include "stackclean.h"
#include "stackoptimize.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPropertyAnimation *m_upwincloseani;
    QPropertyAnimation *m_lowwincloseani;

    QPropertyAnimation *m_upwinshowani;
    QPropertyAnimation *m_lowwinshowani;

    int              m_stackIndex;
    topwindow        *m_top;
    bottomwindow     *m_bottom;
    stackcheck       *m_stackCheck;
    stackclean       *m_stackClean;
    stackoptimize    *m_statckOptimize;
    QStackedWidget   *m_stackWid;

    QWidget          *m_mainwindow;
    QVBoxLayout      *m_mainLayout;
};
#endif // MAIN_WINDOW_H
