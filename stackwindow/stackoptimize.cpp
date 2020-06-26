#include <QLabel>
#include "stackoptimize.h"

stackoptimize::stackoptimize(QWidget *parent) : QWidget(parent)
{
    //设置窗口尺寸
     setMinimumSize(900, 600);

     //上布局
     titleWidget();

     //中布局
     centerWidget();

     //下布局
     bottomWidget();

     //主布局
     m_optimizeMainLayout = new QVBoxLayout(this);
     m_optimizeMainLayout->addWidget(m_optimizeTile);
     m_optimizeMainLayout->addWidget(m_optimizeCenter);
     m_optimizeMainLayout->addWidget(m_optimizeBottom);
     m_optimizeMainLayout->setMargin(0);
     m_optimizeMainLayout->setSpacing(0);
     setLayout(m_optimizeMainLayout);
}

void stackoptimize::titleWidget()
{
    m_optimizeTile = new stackabstitle("border-image:url(:/image/logo_speed.png)", ":/image/btn_start_scan.png", "一键优化，让电脑快如闪电!", "全面提升电脑开机速度,系统速度,上网速度,硬盘速度", this);
    m_optimizeTile->setFixedHeight(150);
}

void stackoptimize::centerWidget()
{
    QFont font;
    font.setFamily("宋体");
    font.setBold(true);
    font.setPixelSize(16);

    m_optimizeCenter = new QWidget(this);

    //开机加速
    QWidget *startingWgt = new QWidget(this);
    startingWgt->setFixedSize(150, 280);

    m_startingBtn = new buttonbase3(":/image/start_check.png",":/image/start_uncheck.png", startingWgt);
    m_startingBtn->setFixedSize(150, 150);

    QLabel *startLab = new QLabel("开机加速", startingWgt);
    startLab->setStyleSheet("color:rgb(102,102,102);");
    startLab->setFont(font);
    startLab->setGeometry(45, 140, 150, 60);

    QLabel *startLab2 = new QLabel("优化软件自启动状态", startingWgt);
    startLab2->setStyleSheet("color:rgb(124,124,124);");
    startLab2->setGeometry(30, 175, 150, 60);

    //系统加速
    QWidget *systemWgt = new QWidget(this);
    systemWgt->setFixedSize(150, 280);

    m_systemBtn = new buttonbase3(":/image/sys_check.png", ":/image/sys_uncheck.png", systemWgt);
    m_systemBtn->setFixedSize(150, 150);

    QLabel *systemLab = new QLabel("系统加速", systemWgt);
    systemLab->setStyleSheet("color:rgb(102,102,102);");
    systemLab->setFont(font);
    systemLab->setGeometry(45, 140, 150, 60);

    QLabel *systemLab2 = new QLabel("优化系统和内存设置", systemWgt);
    systemLab2->setStyleSheet("color:rgb(124,124,124);");
    systemLab2->setGeometry(30, 175, 150, 60);

    //网络加速
    QWidget *networkWgt = new QWidget(this);
    networkWgt->setFixedSize(150, 280);

    m_networkBtn = new buttonbase3(":/image/net_check.png", ":/image/net_uncheck.png", networkWgt);
    m_networkBtn->setFixedSize(150, 150);

    QLabel *networkLab = new QLabel("网络加速", networkWgt);
    networkLab->setStyleSheet("color:rgb(102,102,102);");
    networkLab->setFont(font);
    networkLab->setGeometry(45, 140, 150, 60);

    QLabel *networkLab2 = new QLabel("优化网络配置与性能", networkWgt);
    networkLab2->setStyleSheet("color:rgb(124,124,124);");
    networkLab2->setGeometry(30, 175, 150, 60);

    //硬盘加速
    QWidget *diskWgt = new QWidget(this);
    diskWgt->setFixedSize(150, 280);

    m_diskBtn = new buttonbase3(":/image/disk_check.png", ":/image/disk_uncheck.png", diskWgt);
    m_diskBtn->setFixedSize(150, 150);

    QLabel *diskLab = new QLabel("硬盘加速", diskWgt);
    diskLab->setStyleSheet("color:rgb(102,102,102);");
    diskLab->setFont(font);
    diskLab->setGeometry(45, 140, 150, 60);

    QLabel *diskLab2 = new QLabel("优化硬盘传输效率", diskWgt);
    diskLab2->setStyleSheet("color:rgb(124,124,124);");
    diskLab2->setGeometry(30, 175, 150, 60);

    //主布局
    QHBoxLayout *centerLayout = new QHBoxLayout();
    centerLayout->addWidget(startingWgt);
    centerLayout->addWidget(systemWgt);
    centerLayout->addWidget(networkWgt);
    centerLayout->addWidget(diskWgt);

    m_optimizeCenter->setLayout(centerLayout);
}

void stackoptimize::bottomWidget()
{
    m_optimizeBottom = new QFrame(this);
    m_optimizeBottom->setStyleSheet("QFrame{border-top:1px solid #DDDDDD}");
    m_optimizeBottom->setFixedHeight(30);

    QPushButton *m_btnlow=new QPushButton("启动项(70)", m_optimizeBottom);
    m_btnlow->setFixedSize(85, 15);
    m_btnlow->setCursor(Qt::PointingHandCursor);
    m_btnlow->setIcon(QIcon(QPixmap(":/image/yhjs_down1.png")));
    m_btnlow->setStyleSheet("QPushButton::hover{color:rgb(36,147,229,180)}"
                            "QPushButton{background:transparent;color: rgb(36,147,229)}");

    QPushButton *m_btnlow1=new QPushButton("开机时间", m_optimizeBottom);
    m_btnlow1->setFixedSize(85, 15);
    m_btnlow1->setCursor(Qt::PointingHandCursor);
    m_btnlow1->setIcon(QIcon(QPixmap(":/image/yhjs_down2.png")));
    m_btnlow1->setStyleSheet("QPushButton::hover{color:rgb(36,147,229,180)}"
                             "QPushButton{background:transparent;color: rgb(36,147,229)}");

    QPushButton *m_btnlow2=new QPushButton("已忽略(5)", m_optimizeBottom);
    m_btnlow2->setFixedSize(55, 15);
    m_btnlow2->setCursor(Qt::PointingHandCursor);
    m_btnlow2->setStyleSheet("QPushButton::hover{color:rgb(36,147,229,180)}"
                             "QPushButton{background:transparent;color: rgb(36,147,229)}");

    QPushButton *m_btnlow3=new QPushButton("优化记录(50)", m_optimizeBottom);
    m_btnlow3->setFixedSize(75, 15);
    m_btnlow3->setCursor(Qt::PointingHandCursor);
    m_btnlow3->setStyleSheet("QPushButton::hover{color:rgb(36,147,229,180)}"
                             "QPushButton{background:transparent;color: rgb(36,147,229)}");

    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->addStretch();
    bottomLayout->addWidget(m_btnlow);
    bottomLayout->addWidget(m_btnlow1);
    bottomLayout->addWidget(m_btnlow2);
    bottomLayout->addSpacing(5);
    bottomLayout->addWidget(m_btnlow3);
    bottomLayout->addSpacing(30);

    m_optimizeBottom->setLayout(bottomLayout);
}
