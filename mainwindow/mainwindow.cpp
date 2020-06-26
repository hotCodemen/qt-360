#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),m_stackIndex(0)
{
    //设置窗口大小
    setFixedSize(900,600);

    //去掉默认标题栏
    setWindowFlag(Qt::FramelessWindowHint);

    //设置应用程序图标
    setWindowIcon(QIcon(":/image/360logo.ico"));

    //主界面上下布局
    m_top    = new topwindow(this);
    m_bottom = new bottomwindow(this);

    //隐藏主界面动画
    m_upwincloseani=new QPropertyAnimation(m_top,"pos");
    m_lowwincloseani=new QPropertyAnimation(m_bottom,"pos");

    m_upwincloseani->setStartValue(QPoint(0,0));
    m_upwincloseani->setEndValue(QPoint(0,-440));
    m_upwincloseani->setDuration(200);

    m_lowwincloseani->setStartValue(QPoint(0,440));
    m_lowwincloseani->setEndValue(QPoint(0,600));
    m_lowwincloseani->setDuration(200);

    //展示主界面动画
    m_upwinshowani=new QPropertyAnimation(m_top,"pos");
    m_lowwinshowani=new QPropertyAnimation(m_bottom,"pos");

    m_upwinshowani->setStartValue(QPoint(0,-440));
    m_upwinshowani->setEndValue(QPoint(0,0));
    m_upwinshowani->setDuration(300);

    m_lowwinshowani->setStartValue(QPoint(0,600));
    m_lowwinshowani->setEndValue(QPoint(0,440));
    m_lowwinshowani->setDuration(300);

    //主窗口布局
    m_mainLayout = new QVBoxLayout();
    m_mainLayout->addWidget(m_top);
    m_mainLayout->addWidget(m_bottom);
    m_mainLayout->setSpacing(0);
    m_mainLayout->setMargin(0);
    m_mainwindow = new QWidget();
    m_mainwindow->setLayout(m_mainLayout);

    //栈布局
    m_stackWid = new QStackedWidget(this);
    m_stackCheck     = new stackcheck(m_stackWid);
    m_stackClean     = new stackclean(m_stackWid);
    m_statckOptimize = new stackoptimize(m_stackWid);
    m_stackWid->addWidget(m_mainwindow);
    m_stackWid->addWidget(m_stackCheck);
    m_stackWid->addWidget(m_stackClean);
    m_stackWid->addWidget(m_statckOptimize);
    setCentralWidget(m_stackWid);

    //动画完成隐藏上下页面
    connect(m_upwincloseani,  &QPropertyAnimation::finished, [=](){m_top->hide();});
    connect(m_lowwincloseani, &QPropertyAnimation::finished, [=](){m_bottom->hide();m_stackWid->setCurrentIndex(m_stackIndex);});

    //主界面关闭动画开启
    connect(m_bottom->m_checkBtn,    &QPushButton::clicked, [=](){m_upwincloseani->start();m_lowwincloseani->start();m_stackIndex=1;});
    connect(m_bottom->m_cleanBtn,    &QPushButton::clicked, [=](){m_upwincloseani->start();m_lowwincloseani->start();m_stackIndex=2;});
    connect(m_bottom->m_optimizeBtn, &QPushButton::clicked, [=](){m_upwincloseani->start();m_lowwincloseani->start();m_stackIndex=3;});

    //主界面开启动画开启
    connect(m_stackCheck->m_checkTile->m_returnBtn,        &QPushButton::clicked, [=](){m_top->show();m_bottom->show();m_upwinshowani->start();m_lowwinshowani->start();m_stackIndex=0;m_stackWid->setCurrentIndex(m_stackIndex);});
    connect(m_stackClean->m_cleanTile->m_returnBtn,        &QPushButton::clicked, [=](){m_top->show();m_bottom->show();m_upwinshowani->start();m_lowwinshowani->start();m_stackIndex=0;m_stackWid->setCurrentIndex(m_stackIndex);});
    connect(m_statckOptimize->m_optimizeTile->m_returnBtn, &QPushButton::clicked, [=](){m_top->show();m_bottom->show();m_upwinshowani->start();m_lowwinshowani->start();m_stackIndex=0;m_stackWid->setCurrentIndex(m_stackIndex);});

    //最小化和关闭
    connect(m_top->m_minBtn,              &QPushButton::clicked, this, &QMainWindow::showMinimized);
    connect(m_top->m_closeBtn,            &QPushButton::clicked, this, &QMainWindow::close);
    connect(m_stackCheck->m_checkTile->m_minBtn,       &QPushButton::clicked, this, &QMainWindow::showMinimized);
    connect(m_stackCheck->m_checkTile->m_closeBtn,     &QPushButton::clicked, this, &QMainWindow::close);
    connect(m_stackClean->m_cleanTile->m_minBtn,       &QPushButton::clicked, this, &QMainWindow::showMinimized);
    connect(m_stackClean->m_cleanTile->m_closeBtn,     &QPushButton::clicked, this, &QMainWindow::close);
    connect(m_statckOptimize->m_optimizeTile->m_minBtn,   &QPushButton::clicked, this, &QMainWindow::showMinimized);
    connect(m_statckOptimize->m_optimizeTile->m_closeBtn, &QPushButton::clicked, this, &QMainWindow::close);
}

MainWindow::~MainWindow()
{
    delete m_top;
    delete m_bottom;
    delete m_mainLayout;
}

