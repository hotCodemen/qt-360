#include "bottomwindow.h"

bottomwindow::bottomwindow(QWidget *parent) : QWidget(parent)
{
    QPixmap srcMoreJpg;
    QPixmap norMoreJpg;
    QPixmap hoMoreJpg;
    QPixmap chMoreJpg;

    //窗口大小
    setMinimumSize(900,160);

    //背景颜色
    setStyleSheet("background:white;");

    //加载更多按钮图片
    srcMoreJpg.load(":/image/btn_more.png");
    norMoreJpg = srcMoreJpg.copy(0,0,srcMoreJpg.width()/4, srcMoreJpg.height());
    hoMoreJpg = srcMoreJpg.copy(srcMoreJpg.width()/4,0,srcMoreJpg.width()/4, srcMoreJpg.height());
    chMoreJpg = srcMoreJpg.copy(srcMoreJpg.width()/2,0,srcMoreJpg.width()/4, srcMoreJpg.height());

    //查杀修复
    QWidget *checkWidget = new QWidget();
    checkWidget->setFixedSize(120,120);

    m_checkBtn = new buttonbase2(":/image/safe_Hover.png", 10, ":/image/safe_Leave.png", 8, checkWidget);
//    m_checkBtn->setButtonInit(":/image/safe.png", ":/image/safe.png", ":/image/safe.png", QPoint(0,0));
    m_checkBtn->setGeometry(0, 0, 95, 95);

    QLabel *checkLabel = new QLabel(checkWidget);
    checkLabel->setStyleSheet("background-image:url(:/image/csxf.png)");
    checkLabel->setGeometry(15, 100, 70,20);

    //电脑清理
    QWidget *cleanWidget = new QWidget();
    cleanWidget->setFixedSize(120, 120);

    m_cleanBtn = new buttonbase2(":/image/clean_Hover.png", 10, ":/image/clean_Leave.png", 8, cleanWidget);
//    m_cleanBtn->setButtonInit(":/image/clean.png", ":/image/clean.png", ":/image/clean.png", QPoint(0,0));
    m_cleanBtn->setGeometry(0, 0, 95, 95);

    QLabel *cleanLabel = new QLabel(cleanWidget);
    cleanLabel->setStyleSheet("background-image:url(:/image/dnql.png)");
    cleanLabel->setGeometry(15, 100, 70, 20);

    //优化加速
    QWidget *optimizeWidget = new QWidget();
    optimizeWidget->setFixedSize(120, 120);

    m_optimizeBtn = new buttonbase2(":/image/youhua_Hover.png", 10, ":/image/youhua_Leave.png", 8, optimizeWidget);
//    m_optimizeBtn->setButtonInit(":/image/youhua.png", ":/image/youhua.png", ":/image/youhua.png", QPoint(0,0));
    m_optimizeBtn->setGeometry(0, 0, 95, 95);

    QLabel *optimizeLabel = new QLabel(optimizeWidget);
    optimizeLabel->setStyleSheet("background-image:url(:/image/yhjs.png)");
    optimizeLabel->setGeometry(15, 100, 70, 20);

    m_appBtn = new buttonbase();
    m_appBtn->setButtonInit(":/image/rjgj.png", ":/image/rjgj.png", ":/image/rjgj.png", QPoint(19,12));
    m_appBtn->setFixedSize(71,70);
    m_appBtn->setButtonBorder(":/image/btnborder.png", 3, 2, false, true);
    m_appBtn->setButtonText("软件管家", QColor(124, 124, 124), QPoint(11,66));

    m_memBtn = new buttonbase();
    m_memBtn->setButtonInit(":/image/rgfw.png", ":/image/rgfw.png", ":/image/rgfw.png", QPoint(19,12));
    m_memBtn->setFixedSize(71,70);
    m_memBtn->setButtonBorder(":/image/btnborder.png", 3, 2, false, true);
    m_memBtn->setButtonText("人工服务", QColor(124, 124, 124), QPoint(11,66));

    m_broadbandBtn = new buttonbase();
    m_broadbandBtn->setButtonInit(":/image/kdcsq.png", ":/image/kdcsq.png", ":/image/kdcsq.png", QPoint(19,12));
    m_broadbandBtn->setFixedSize(71,70);
    m_broadbandBtn->setButtonBorder(":/image/btnborder.png", 3, 2, false, true);
    m_broadbandBtn->setButtonText("宽带测试", QColor(124, 124, 124), QPoint(11,66));

    m_questionBtn = new buttonbase();
    m_questionBtn->setButtonInit(":/image/360wd.png", ":/image/360wd.png", ":/image/360wd.png", QPoint(19,12));
    m_questionBtn->setFixedSize(71,70);
    m_questionBtn->setButtonBorder(":/image/btnborder.png", 3, 2, false, true);
    m_questionBtn->setButtonText("360问答", QColor(124, 124, 124), QPoint(14,66));

    m_moreBtn = new buttonbase();
    m_moreBtn->setButtonInit(norMoreJpg, hoMoreJpg, chMoreJpg, QPoint(19,12));
    m_moreBtn->setFixedSize(71,70);
    m_moreBtn->setButtonText("更多", QColor(0,0,255), QPoint(23,66));

    //右下水平布局
    m_rightBottomLt = new QHBoxLayout();
    m_rightBottomLt->addStretch();
    m_rightBottomLt->addWidget(m_appBtn);
    m_rightBottomLt->addWidget(m_memBtn);
    m_rightBottomLt->addWidget(m_broadbandBtn);
    m_rightBottomLt->addWidget(m_questionBtn);
    m_rightBottomLt->addWidget(m_moreBtn);
    m_rightBottomLt->setMargin(0);
    m_rightBottomLt->setSpacing(0);

    //右上布局
    m_windowBtn = new buttonbase();
    m_windowBtn->setButtonInit(":/image/win10_normal.png", ":/image/win10_hover.png", ":/image/win10_pressed.png", QPoint(0,0));
    m_windowBtn->setFixedSize(173,32);

    m_rightTopLt = new QHBoxLayout();
    m_rightTopLt->addStretch();
    m_rightTopLt->addWidget(m_windowBtn);
    m_rightTopLt->addSpacing(20);
    m_rightTopLt->setMargin(0);
    m_rightTopLt->setSpacing(0);

    //右主布局
    m_rightLt = new QVBoxLayout();
    m_rightLt->addSpacing(20);
    m_rightLt->addLayout(m_rightTopLt);
    m_rightLt->addLayout(m_rightBottomLt);
    m_rightLt->setMargin(0);
    m_rightLt->setSpacing(0);

    //主水平布局
    m_mainLayout = new QHBoxLayout();
    m_mainLayout->addSpacing(30);
    m_mainLayout->addWidget(checkWidget);
    m_mainLayout->addWidget(cleanWidget);
    m_mainLayout->addWidget(optimizeWidget);
    m_mainLayout->addStretch();
    m_mainLayout->addLayout(m_rightLt);
    m_mainLayout->setMargin(0);
    m_mainLayout->setSpacing(0);
    setLayout(m_mainLayout);
}

void bottomwindow::paintEvent(QPaintEvent *ev)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

