#include "stackabstitle.h"

stackabstitle::stackabstitle(const QString icnJpg, QString btnJpg, QString title, QString title1, QWidget *parent) : QWidget(parent)
{
    titleWidget();

    topWidget(icnJpg, btnJpg, title, title1);

    m_TitleMainLayout = new QVBoxLayout();
    m_TitleMainLayout->addWidget(m_titleWidget);
    m_TitleMainLayout->addWidget(m_topWidget);
    m_TitleMainLayout->setMargin(0);
    m_TitleMainLayout->setSpacing(0);
    setLayout(m_TitleMainLayout);
}

void stackabstitle::titleWidget(QWidget *parent)
{
    m_returnBtn = new buttonbase1(":/image/return.png", 4);
    m_returnBtn->setFixedSize(115, 38);

    m_skinBtn   = new buttonbase1(":/image/Skin.png",       4);
    m_msgBtn    = new buttonbase1(":/image/feedback.png",   4);
    m_setBtn    = new buttonbase1(":/image/Menu.png",       4);
    m_minBtn    = new buttonbase1(":/image/min.png",        4);
    m_closeBtn  = new buttonbase1(":/image/close.png",      4);

    m_skinBtn->setFixedSize(29, 24);
    m_msgBtn->setFixedSize(29, 24);
    m_setBtn->setFixedSize(29, 24);
    m_minBtn->setFixedSize(29, 24);
    m_closeBtn->setFixedSize(29, 24);

    m_titleWidget = new QWidget(this);
    m_titleWidget->setStyleSheet("background:rgb(57,196,44);");
    m_titleWidget->setFixedHeight(38);

    m_TitleLayout = new QHBoxLayout(m_titleWidget);
    m_TitleLayout->addWidget(m_returnBtn);
    m_TitleLayout->addStretch();
    m_TitleLayout->addWidget(m_skinBtn, 0, Qt::AlignLeft | Qt::AlignTop);
    m_TitleLayout->addWidget(m_msgBtn,  0, Qt::AlignLeft | Qt::AlignTop);
    m_TitleLayout->addWidget(m_setBtn,  0, Qt::AlignLeft | Qt::AlignTop);
    m_TitleLayout->addWidget(m_minBtn,  0, Qt::AlignLeft | Qt::AlignTop);
    m_TitleLayout->addWidget(m_closeBtn, 0, Qt::AlignLeft | Qt::AlignTop);
    m_TitleLayout->setMargin(0);
    m_TitleLayout->setSpacing(0);

    m_titleWidget->setLayout(m_TitleLayout);
}

void stackabstitle::topWidget(const QString icnJpg, QString btnJpg, QString title, QString title1)
{
    QFont font2;
    font2.setFamily("黑体");
    font2.setPixelSize(27);
    font2.setBold(true);

    m_topWidget = new QWidget(this);
    m_topWidget->setFixedHeight(112);
    m_topWidget->setStyleSheet("background:rgb(57,196,44);");

    QLabel *m_logo = new QLabel(m_topWidget);
    m_logo->setStyleSheet(icnJpg);
    m_logo->setFixedSize(76, 75);

    QWidget *titleWidget = new QWidget(m_topWidget);
    titleWidget->setFixedSize(400,65);

    QLabel *m_title = new QLabel(title, titleWidget);
    m_title->setStyleSheet("color:white;font:24");
    m_title->setGeometry(0, 0, 400, 32);
    m_title->setFont(font2);

    QLabel *m_title2 = new QLabel(title1, titleWidget);
    m_title2->setStyleSheet("color:white;");
    m_title2->setGeometry(0, 35, 400, 32);

    m_startscanBtn = new buttonbase1(btnJpg, 4, m_topWidget);
    m_startscanBtn->setFixedSize(164,64);

    m_TopLayout = new QHBoxLayout();
    m_TopLayout->setMargin(0);
    m_TopLayout->setSpacing(0);

    //添加到上布局中
    m_TopLayout->addSpacing(50);
    m_TopLayout->addWidget(m_logo);
    m_TopLayout->addSpacing(25);
    m_TopLayout->addWidget(titleWidget);
    m_TopLayout->addStretch();
    m_TopLayout->addWidget(m_startscanBtn);
    m_TopLayout->addSpacing(35);
    m_topWidget->setLayout(m_TopLayout);
}

void stackabstitle::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    QStyleOption opt;

    opt.init(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void stackabstitle::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_WindowPos = this->parentWidget()->parentWidget()->parentWidget()->pos();
        m_MousePos  = event->globalPos();
        m_MousePressed = true;
    }
}

void stackabstitle::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_MousePressed = false;
    }
}

void stackabstitle::mouseMoveEvent(QMouseEvent *event)
{
    if (m_MousePressed) {
        this->parentWidget()->parentWidget()->parentWidget()->move(m_WindowPos + (event->globalPos() - m_MousePos));
    }
}
