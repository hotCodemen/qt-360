#include <QGridLayout>
#include "stackclean.h"
#include "cleanmainbtn.h"

stackclean::stackclean(QWidget *parent) : QWidget(parent)
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
    m_cleanMainLayout = new QVBoxLayout(this);
    m_cleanMainLayout->addWidget(m_cleanTile);
    m_cleanMainLayout->addWidget(m_cleanCenter);
    m_cleanMainLayout->addWidget(m_cleanBottom);
    m_cleanMainLayout->setMargin(0);
    m_cleanMainLayout->setSpacing(0);
    setLayout(m_cleanMainLayout);
}

void stackclean::titleWidget()
{
    m_cleanTile = new stackabstitle("border-image:url(:/image/logo_clean.png)", ":/image/btn_top_clean.png", "已选择6项清理类型", "经常清理,让电脑保持最轻松的状态", this);
    m_cleanTile->setFixedHeight(150);
}

void stackclean::centerWidget()
{
    QFont font;
    font.setFamily("宋体");
    font.setBold(true);
    font.setPixelSize(16);

    m_cleanCenter = new QWidget(this);

    //清理垃圾
    QWidget *rubbish = new QWidget();
    rubbish->setMinimumSize(150, 130);

    cleanMainBtn *bt1 = new cleanMainBtn(":/image/clean/clean_trash_check.png", ":/image/clean/clean_trash_uncheck.png"
                                         , ":/image/clean/clean_trash_anim.png", ":/image/clean/clean_trash_anim_gray.png", 13, rubbish);
    bt1->setGeometry(15, 0, 90, 90);

    QLabel *rubbishClen = new QLabel("清理垃圾", rubbish);
    rubbishClen->setStyleSheet("color:rgb(102,102,102);");
    rubbishClen->setFont(font);
    rubbishClen->setGeometry(25, 85, 110, 20);

    QLabel *rubbishLb=new QLabel("清理电脑中的垃圾文件", rubbish);
    rubbishLb->setStyleSheet("color:rgb(124,124,124);");
    rubbishLb->setGeometry(0, 110, 150, 20);

    //清理痕迹
    QWidget *mark = new QWidget();
    mark->setMinimumSize(150, 130);
    cleanMainBtn *bt2 = new cleanMainBtn(":/image/clean/clean_trace_check.png", ":/image/clean/clean_trace_uncheck.png"
                                         , ":/image/clean/clean_trace_anim.png", ":/image/clean/clean_trace_anim_gray.png", 17, mark);
    bt2->setGeometry(15, 0, 90, 90);

    QLabel *markClen = new QLabel("清理痕迹", mark);
    markClen->setStyleSheet("color:rgb(102,102,102);");
    markClen->setFont(font);
    markClen->setGeometry(25, 85, 110, 20);

    QLabel *markLb=new QLabel("清理浏览器使用痕迹", mark);
    markLb->setStyleSheet("color:rgb(124,124,124);");
    markLb->setGeometry(0, 110, 150, 20);

    //清理注册表
    QWidget *registry = new QWidget();
    registry->setMinimumSize(150, 130);

    cleanMainBtn *bt3 = new cleanMainBtn(":/image/clean/clean_reg_check.png",":/image/clean/clean_reg_uncheck.png"
                                       ,":/image/clean/clean_reg_anim.png",":/image/clean/clean_reg_anim_gray.png",17, registry);
    bt3->setGeometry(15, 0, 90, 90);

    QLabel *registryClen = new QLabel("清理注册表", registry);
    registryClen->setStyleSheet("color:rgb(102,102,102);");
    registryClen->setFont(font);
    registryClen->setGeometry(20, 85, 110, 20);

    QLabel *registryLb=new QLabel("清理无效的注册表项目", registry);
    registryLb->setStyleSheet("color:rgb(124,124,124);");
    registryLb->setGeometry(0, 110, 150, 20);


    //清理插件
    QWidget *plug = new QWidget();
    plug->setMinimumSize(150, 130);

    cleanMainBtn *bt4 = new cleanMainBtn(":/image/clean/clean_plugin_check.png",":/image/clean/clean_plugin_uncheck.png"
                                       ,":/image/clean/clean_plugin_anim.png",":/image/clean/clean_plugin_anim_gray.png",17, plug);
    bt4->setGeometry(15, 0, 90, 90);

    QLabel *plugClen = new QLabel("清理插件", plug);
    plugClen->setStyleSheet("color:rgb(102,102,102);");
    plugClen->setFont(font);
    plugClen->setGeometry(25, 85, 110, 20);

    QLabel *plugLb = new QLabel("清理无用的插件，降低打扰", plug);
    plugLb->setStyleSheet("color:rgb(124,124,124);");
    plugLb->setGeometry(0, 110, 150, 20);

    //清理软件
    QWidget *soft = new QWidget();
    soft->setMinimumSize(160, 130);

    cleanMainBtn *bt5 = new cleanMainBtn(":/image/clean/clean_soft_check.png",":/image/clean/clean_soft_uncheck.png"
                                       ,":/image/clean/clean_soft_anim.png",":/image/clean/clean_soft_anim_gray.png",17, soft);
    bt5->setGeometry(20, 0, 90, 90);

    QLabel *softClen = new QLabel("清理软件", soft);
    softClen->setStyleSheet("color:rgb(102,102,102);");
    softClen->setFont(font);
    softClen->setGeometry(30, 85, 110, 20);

    QLabel *softLb = new QLabel("清理推广，弹窗不常用的软件", soft);
    softLb->setStyleSheet("color:rgb(124,124,124);");
    softLb->setGeometry(0, 110, 160, 20);

    //清理Cookies
    QWidget *cookies = new QWidget();
    cookies->setMinimumSize(160, 130);

    cleanMainBtn *bt6 = new cleanMainBtn(":/image/clean/clean_cookies_check.png",":/image/clean/clean_cookies_uncheck.png"
                                       ,":/image/clean/clean_cookies_anim.png",":/image/clean/clean_cookies_anim_gray.png",20, cookies);
    bt6->setGeometry(20, 0, 90, 90);

    QLabel *cookiesClen = new QLabel("清理Cookies", cookies);
    cookiesClen->setStyleSheet("color:rgb(102,102,102);");
    cookiesClen->setFont(font);
    cookiesClen->setGeometry(25, 85, 110, 20);

    QLabel *cookiesLb = new QLabel("清理上网、游戏、购物等记录", cookies);
    cookiesLb->setStyleSheet("color:rgb(124,124,124);");
    cookiesLb->setGeometry(0, 110, 160, 20);

    //主布局
    QGridLayout *centerLayout = new QGridLayout();
    centerLayout->addWidget(rubbish, 0, 0, Qt::AlignVCenter|Qt::AlignHCenter);
    centerLayout->addWidget(mark, 0, 1, Qt::AlignVCenter|Qt::AlignHCenter);
    centerLayout->addWidget(registry, 0, 2, Qt::AlignVCenter|Qt::AlignHCenter);
    centerLayout->addWidget(plug, 1, 0, Qt::AlignVCenter|Qt::AlignHCenter);
    centerLayout->addWidget(soft, 1, 1, Qt::AlignVCenter|Qt::AlignHCenter);
    centerLayout->addWidget(cookies, 1, 2, Qt::AlignVCenter|Qt::AlignHCenter);
    m_cleanCenter->setLayout(centerLayout);
}

void stackclean::bottomWidget()
{
    m_cleanBottom = new QFrame(this);
    m_cleanBottom->setStyleSheet("QFrame{border-top:1px solid #DDDDDD}");
    m_cleanBottom->setFixedHeight(30);

    QPushButton *classicsBtn = new QPushButton("经典版电脑清理", m_cleanBottom);
    classicsBtn->adjustSize();
    classicsBtn->setFixedSize(100, 15);
    classicsBtn->setCursor(Qt::PointingHandCursor);
    classicsBtn->setStyleSheet("QPushButton::hover{color:rgb(36,147,229,180)}"
                            "QPushButton{background:transparent;color: rgb(36,147,229)}");

    QPushButton *wechatBtn = new QPushButton("微信清理", m_cleanBottom);
    wechatBtn->adjustSize();
    wechatBtn->setFixedSize(50, 15);
    wechatBtn->setCursor(Qt::PointingHandCursor);
    wechatBtn->setStyleSheet("QPushButton::hover{color:rgb(36,147,229,180)}"
                            "QPushButton{background:transparent;color: rgb(36,147,229)}");

    QPushButton *appleBtn = new QPushButton("苹果设备清理", m_cleanBottom);
    appleBtn->adjustSize();
    appleBtn->setFixedSize(80, 15);
    appleBtn->setCursor(Qt::PointingHandCursor);
    appleBtn->setStyleSheet("QPushButton::hover{color:rgb(36,147,229,180)}"
                            "QPushButton{background:transparent;color: rgb(36,147,229)}");

    QPushButton *systemBtn = new QPushButton("系统盘瘦身", m_cleanBottom);
    systemBtn->adjustSize();
    systemBtn->setFixedSize(60, 15);
    systemBtn->setCursor(Qt::PointingHandCursor);
    systemBtn->setStyleSheet("QPushButton::hover{color:rgb(36,147,229,180)}"
                            "QPushButton{background:transparent;color: rgb(36,147,229)}");

    QPushButton *findBtn = new QPushButton("查找大文件", m_cleanBottom);
    findBtn->adjustSize();
    findBtn->setFixedSize(60, 15);
    findBtn->setCursor(Qt::PointingHandCursor);
    findBtn->setStyleSheet("QPushButton::hover{color:rgb(36,147,229,180)}"
                            "QPushButton{background:transparent;color: rgb(36,147,229)}");


    QPushButton *autoBtn=new QPushButton("自动清理", m_cleanBottom);
    autoBtn->adjustSize();
    autoBtn->setFixedSize(50, 15);
    autoBtn->setCursor(Qt::PointingHandCursor);
    autoBtn->setStyleSheet("QPushButton::hover{color:rgb(36,147,229,180)}"
                            "QPushButton{background:transparent;color: rgb(36,147,229)}");

    QPushButton *recoveryBtn=new QPushButton("恢复区", m_cleanBottom);
    recoveryBtn->adjustSize();
    recoveryBtn->setFixedSize(50, 15);
    recoveryBtn->setCursor(Qt::PointingHandCursor);
    recoveryBtn->setStyleSheet("QPushButton::hover{color:rgb(36,147,229,180)}"
                            "QPushButton{background:transparent;color: rgb(36,147,229)}");

    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->addWidget(classicsBtn);
    bottomLayout->addStretch();
    bottomLayout->addWidget(wechatBtn);
    bottomLayout->addWidget(appleBtn);
    bottomLayout->addWidget(systemBtn);
    bottomLayout->addWidget(findBtn);
    bottomLayout->addWidget(autoBtn);
    bottomLayout->addWidget(recoveryBtn);

    m_cleanBottom->setLayout(bottomLayout);
}
