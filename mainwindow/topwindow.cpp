#include <QPainter>
#include <QStyleOption>
#include "topwindow.h"

topwindow::topwindow(QWidget *parent) : QWidget(parent),m_MousePressed(false)
{
    //设置窗体大小
    setMinimumSize(900, 440);

    //设置样式
    setStyleSheet("topwindow{background:rgb(57,196,44);}"
                  "QLabel{background:transparent;color:white;}"
                  "QPushButton{background:transparent}");
    //设置标题栏
    titileInit();

    //设置内容栏
    centerInit();

    //主布局
    m_mainLayout = new QVBoxLayout();
    m_mainLayout->addWidget(m_topWidget);
    m_mainLayout->addWidget(m_bottomWidget);
    m_mainLayout->setMargin(0);
    setLayout(m_mainLayout);
}

void topwindow::titileInit()
{
    m_logoIco = new QLabel();
    m_logoIco->setFixedSize(16, 16);
    m_logoIco->setStyleSheet("border-image:url(:/image/360logo.png)");

    m_title  = new QLabel("360安全卫士领航版");
    m_title->setFixedSize(105, 16);

    m_updateBtn = new buttonbase1(":/image/update_btn.png", 4);
    m_skinBtn   = new buttonbase1(":/image/Skin.png",       4);
    m_msgBtn    = new buttonbase1(":/image/feedback.png",   4);
    m_setBtn    = new buttonbase1(":/image/Menu.png",       4);
    m_minBtn    = new buttonbase1(":/image/min.png",        4);
    m_closeBtn  = new buttonbase1(":/image/close.png",      4);

    m_updateBtn->setFixedSize(16, 16);
    m_skinBtn->setFixedSize(29, 24);
    m_msgBtn->setFixedSize(29, 24);
    m_setBtn->setFixedSize(29, 24);
    m_minBtn->setFixedSize(29, 24);
    m_closeBtn->setFixedSize(29, 24);

    m_topLayout = new QHBoxLayout();
    m_topLayout->addSpacing(10);           //添加空隙
    m_topLayout->addWidget(m_logoIco);
    m_topLayout->addSpacing(5);
    m_topLayout->addWidget(m_title);
    m_topLayout->addWidget(m_updateBtn);
    m_topLayout->addStretch();            //添加弹簧属性
    m_topLayout->addWidget(m_skinBtn);
    m_topLayout->addWidget(m_msgBtn);
    m_topLayout->addWidget(m_setBtn);
    m_topLayout->addWidget(m_minBtn);
    m_topLayout->addWidget(m_closeBtn);
    m_topLayout->addSpacing(5);
    m_topLayout->setMargin(0);
    m_topLayout->setSpacing(0);

    m_topWidget = new QWidget();
    m_topWidget->setFixedHeight(24);
    m_topWidget->setLayout(m_topLayout);
}

void topwindow::centerInit()
{
    QFont font2;
    font2.setFamily("黑体");
    font2.setPixelSize(36);

    //登录360
    QWidget *loginWidget = new QWidget();
    loginWidget->setFixedSize(80, 38);

    QPushButton *login = new QPushButton("登录360账号", loginWidget);
    login->setStyleSheet("color:white");
    login->setCursor(Qt::PointingHandCursor);
    login->setGeometry(0, 15, 80, 20);

    m_head = new buttonbase1(":/image/head_bkg.png", 2);
    m_head->setFixedSize(52, 52);

    QHBoxLayout *centerLayout1 = new QHBoxLayout();
    centerLayout1->addStretch();
    centerLayout1->addWidget(loginWidget);
    centerLayout1->addWidget(m_head);
    centerLayout1->addSpacing(10);

    //100分体验
    m_labscore = new buttonbase();
    m_labscore->setButtonInit(":/image/100.png", ":/image/100.png", ":/image/100.png", QPoint(38,60));
    m_labscore->setFixedSize(191, 191);
    m_labscore->setButtonBorder(":/image/examine_score.png", true, true);
    m_labscore->setButtonText("分", QColor(248,248,255), QPoint(148,125));

    QWidget *titleWidget = new QWidget();
    titleWidget->setFixedSize(600, 191);

    QLabel *m_title = new QLabel("上次电脑体检良好,请继续保持！",titleWidget);
    m_title->setStyleSheet("color:white;");
    m_title->setGeometry(0, 70, 600, 40);
    m_title->setFont(font2);

    QLabel *m_title2 = new QLabel("上次体检是1分钟以前,共发现5个问题,已全部处理",titleWidget);
    m_title2->setStyleSheet("color:white;font-size:14px;");
    m_title2->setGeometry(0, 120, 400, 32);

    //立即体验
    QHBoxLayout *centerLayout2 = new QHBoxLayout();
    centerLayout2->addSpacing(20);
    centerLayout2->addWidget(m_labscore);
    centerLayout2->addWidget(titleWidget);
    centerLayout2->addStretch();

    m_checkBtn = new buttonbase1(":/image/btn_examine_now.png",4);
    m_checkBtn->setFixedSize(212, 74);
    QHBoxLayout *centerLayout3 = new QHBoxLayout();
    centerLayout3->addStretch();
    centerLayout3->addWidget(m_checkBtn);
    centerLayout3->addStretch();
    centerLayout3->setMargin(0);

    //安全防护
    QWidget *securityWidget = new QWidget();
    securityWidget->setFixedSize(100, 60);

    m_securityBtn = new buttonbase(securityWidget);
    m_securityBtn->setButtonInit(":/image/security_safe_normal.png", ":/image/security_safe_hover.png", ":/image/security_safe_normal.png", QPoint(0,0));
    m_securityBtn->setGeometry(15, 0, 37, 37);

    QLabel *m_security = new QLabel("安全防护中心",securityWidget);
    m_security->setGeometry(0, 40, 100, 16);

    QLabel *label = new QLabel();
    label->setFixedWidth(1);
    label->setStyleSheet("background:transparent;border-image:url(:/image/guardline.png);");

    //网购理赔
    QWidget *payforWidget = new QWidget();
    payforWidget->setFixedSize(100, 60);

    m_payforBtn = new buttonbase(payforWidget);
    m_payforBtn->setButtonInit(":/image/payinsure_safe_normal.png", ":/image/payinsure_safe_hover.png", ":/image/payinsure_safe_normal.png", QPoint(0,0));
    m_payforBtn->setGeometry(30, 0, 37, 37);

    QLabel *m_payfor = new QLabel("网购先陪", payforWidget);
    m_payfor->setGeometry(25, 40, 60, 16);

    QHBoxLayout *centerLayout4 = new QHBoxLayout();
    centerLayout4->addSpacing(20);
    centerLayout4->addWidget(securityWidget);
    centerLayout4->addWidget(label);
    centerLayout4->addWidget(payforWidget);
    centerLayout4->addStretch();
    centerLayout4->setMargin(0);
    centerLayout4->setSpacing(0);

    //主布局
    m_bottomLayout = new QVBoxLayout();
    m_bottomLayout->addSpacing(25);
    m_bottomLayout->addLayout(centerLayout1);
    m_bottomLayout->addLayout(centerLayout2);
    m_bottomLayout->addLayout(centerLayout3);
    m_bottomLayout->addLayout(centerLayout4);
    m_bottomLayout->setMargin(0);
    m_bottomLayout->setSpacing(0);
    m_bottomLayout->addSpacing(20);

    m_bottomWidget = new QWidget(this);
    m_bottomWidget->setLayout(m_bottomLayout);
}

void topwindow::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    QStyleOption opt;

    opt.init(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void topwindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_WindowPos = this->parentWidget()->parentWidget()->parentWidget()->pos();
        m_MousePos  = event->globalPos();
        m_MousePressed = true;
    }
}

void topwindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_MousePressed = false;
    }
}

void topwindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_MousePressed) {
        this->parentWidget()->parentWidget()->parentWidget()->move(m_WindowPos + (event->globalPos() - m_MousePos));
    }
}
