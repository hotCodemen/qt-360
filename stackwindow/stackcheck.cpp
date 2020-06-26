#include <QLabel>
#include "stackcheck.h"

stackcheck::stackcheck(QWidget *parent) : QWidget(parent)
{
    //设置窗口尺寸
    setMinimumSize(900, 600);

    //上布局
    titleWidget();

    //中间布局
    centerWidget();

    //下布局
    bottomWidget();

    //主布局
    m_checkMainLayout = new QVBoxLayout(this);
    m_checkMainLayout->addWidget(m_checkTile);
    m_checkMainLayout->addWidget(m_checkCenter);
    m_checkMainLayout->addWidget(m_checkBottom);
    m_checkMainLayout->setMargin(0);
    m_checkMainLayout->setSpacing(0);
    setLayout(m_checkMainLayout);
}

void stackcheck::titleWidget()
{
    m_checkTile = new stackabstitle("border-image:url(:/image/logo_normal.png)", ":/image/start_btn.png", "您的电脑很安全！", "定期木马查杀,漏洞修复,时刻保持电脑健康", this);
    m_checkTile->setFixedHeight(150);
}

void stackcheck::centerWidget()
{
    m_checkCenter = new QWidget(this);

    //上布局
    QWidget *quickWidget = new QWidget();
    quickWidget->setFixedSize(150, 180);

    buttonbase2 *quickBtn = new buttonbase2(":/image/scan_button_quick_hover.png", 8, ":/image/scan_button_quick_hover.png", 8, quickWidget);
    quickBtn->setGeometry(0, 0, 140, 140);

    QLabel *quickLab = new QLabel("快速扫描", quickWidget);
    quickLab->setStyleSheet("color:rgb(68,68,68);font: 13pt 微软雅黑;");
    quickLab->setGeometry(35, 155, 150, 24);

    QWidget *fullWidget = new QWidget();
    fullWidget->setFixedSize(150, 180);

    buttonbase2 *fullBtn = new buttonbase2(":/image/scan_button_full_hover.png", 8, ":/image/scan_button_full_hover.png", 8, fullWidget);
    fullBtn->setGeometry(0, 0, 140, 140);

    QLabel *fullLab = new QLabel("全盘扫描", fullWidget);
    fullLab->setStyleSheet("color:rgb(68,68,68);font: 13pt 微软雅黑;");
    fullLab->setGeometry(35, 155, 150, 24);

    QWidget *customWidget = new QWidget();
    customWidget->setFixedSize(150, 180);

    buttonbase2 *customBtn = new buttonbase2(":/image/scan_button_custom_hover.png", 8, ":/image/scan_button_custom_hover.png", 8, customWidget);
    customBtn->setGeometry(0, 0, 140, 140);

    QLabel *customLab = new QLabel("自定义扫描", customWidget);
    customLab->setStyleSheet("color:rgb(68,68,68);font: 13pt 微软雅黑;");
    customLab->setGeometry(30, 155, 150, 24);

    QHBoxLayout *center_top = new QHBoxLayout();
    center_top->addWidget(quickWidget);
    center_top->addWidget(fullWidget);
    center_top->addWidget(customWidget);

    //下布局
    QWidget *normalWidget = new QWidget();
    normalWidget->setFixedSize(80, 100);

    buttonbase1 *normalBtn = new buttonbase1(":/image/system_fix.png", 4, normalWidget);
    normalBtn->setGeometry(0, 0, 60, 60);

    QLabel *normalLab=new QLabel("常规修复", normalWidget);
    normalLab->setStyleSheet("color:rgb(68,68,68);font: 14px 微软雅黑;");
    normalLab->setGeometry(0, 65, 80, 30);
    normalLab->adjustSize();

    QWidget *leakWidget = new QWidget();
    leakWidget->setFixedSize(80, 100);

    buttonbase1 *leakBtn = new buttonbase1(":/image/system_fix.png", 4, leakWidget);
    leakBtn->setGeometry(0, 0, 60, 60);

    QLabel *leakLab = new QLabel(" 漏洞修复", leakWidget);
    leakLab->setStyleSheet("color:rgb(68,68,68);font: 14px 微软雅黑;");
    leakLab->setGeometry(0, 65, 80, 30);
    leakLab->adjustSize();

    QHBoxLayout *center_bottom = new QHBoxLayout();
    center_bottom->addStretch();
    center_bottom->addWidget(normalWidget);
    center_bottom->addWidget(leakWidget);
    center_bottom->addSpacing(25);

    //主布局
    m_checkCenterLayout = new QVBoxLayout();
    m_checkCenterLayout->addStretch(2);
    m_checkCenterLayout->addLayout(center_top);
    m_checkCenterLayout->addStretch(1);
    m_checkCenterLayout->addLayout(center_bottom);
    m_checkCenter->setLayout(m_checkCenterLayout);
}

void stackcheck::bottomWidget()
{
    m_checkBottom = new QFrame(this);
    m_checkBottom->setStyleSheet("QFrame{border-top:1px solid #DDDDDD}");
    m_checkBottom->setFixedHeight(30);

    QLabel *m_lab=new QLabel("已启用查杀引擎：", m_checkBottom);
    m_lab->setStyleSheet("color: rgb(153,153,153);border-style:none");
    m_lab->setFixedSize(100, 24);

    buttonbase1*m_btndown1=new buttonbase1(":/image/engStateBtnAvira.png", 4, m_checkBottom);
    m_btndown1->setFixedSize(24, 24);

    buttonbase1*m_btndown2=new buttonbase1(":/image/engStateBtnCloud.png", 4, m_checkBottom);
    m_btndown2->setFixedSize(24, 24);

    buttonbase1*m_btndown3=new buttonbase1(":/image/engStateBtnQEX.png", 4, m_checkBottom);
    m_btndown3->setFixedSize(24, 24);

    buttonbase1*m_btndown4=new buttonbase1(":/image/engStateBtnQiFa.png", 4, m_checkBottom);
    m_btndown4->setFixedSize(24, 24);

    buttonbase1*m_btndown5=new buttonbase1(":/image/engStateBtnQVM.png", 4, m_checkBottom);
    m_btndown5->setFixedSize(24, 24);

    QPushButton *m_btndown6=new QPushButton("设置", m_checkBottom);
    m_btndown6->setIcon(QIcon(":/image/scan_setting1.png"));
    m_btndown6->setFixedSize(50, 24);
    m_btndown6->setStyleSheet("QPushButton{background:transparent;color: rgb(0,138,255);}"
                              "QPushButton::hover{color: rgb(0,180,255);}");

    QPushButton *m_btndown7=new QPushButton("信任区", m_checkBottom);
    m_btndown7->setFixedSize(50, 24);
    m_btndown7->setStyleSheet("QPushButton{background:transparent;color: rgb(0,138,255);}"
                              "QPushButton::hover{color: rgb(0,180,255);}");

    QPushButton *m_btndown8=new QPushButton("恢复区", m_checkBottom);
    m_btndown8->setFixedSize(50, 24);
    m_btndown8->setStyleSheet("QPushButton{background:transparent;color: rgb(0,138,255);}"
                              "QPushButton::hover{color: rgb(0,180,255);}");

    QPushButton *m_btndown9=new QPushButton("上报区", m_checkBottom);
    m_btndown9->setFixedSize(50, 24);
    m_btndown9->setStyleSheet("QPushButton{background:transparent;color: rgb(0,138,255);}"
                              "QPushButton::hover{color: rgb(0,180,255);}");

    m_checkBottomLayout = new QHBoxLayout(m_checkBottom);
    m_checkBottomLayout->addSpacing(25);
    m_checkBottomLayout->addWidget(m_lab);
    m_checkBottomLayout->addWidget(m_btndown1);
    m_checkBottomLayout->addSpacing(3);
    m_checkBottomLayout->addWidget(m_btndown2);
    m_checkBottomLayout->addWidget(m_btndown3);
    m_checkBottomLayout->addWidget(m_btndown4);
    m_checkBottomLayout->addWidget(m_btndown5);
    m_checkBottomLayout->addStretch();
    m_checkBottomLayout->addWidget(m_btndown6);
    m_checkBottomLayout->addWidget(m_btndown7);
    m_checkBottomLayout->addWidget(m_btndown8);
    m_checkBottomLayout->addWidget(m_btndown9);
    m_checkBottomLayout->setMargin(0);
    m_checkBottomLayout->setSpacing(0);
    m_checkBottom->setLayout(m_checkBottomLayout);
}
