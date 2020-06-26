#ifndef CLEANMAINBTN_H
#define CLEANMAINBTN_H

#include <QPushButton>
#include <QPropertyAnimation>

class cleanMainBtn : public QPushButton
{
    Q_OBJECT
public:
    explicit cleanMainBtn(QString normal,QString gray,QString aninormal,QString anigray,int number, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void leaveEvent(QEvent *);
private:
    QList<QPixmap> m_pixaninormallist;
    QList<QPixmap> m_pixanigraylist;
    QPixmap m_pixnormal;
    QPixmap m_pixgray;
    int m_normalindex;
    int count;
    QPropertyAnimation *m_aninormal;

    bool m_enter;
    bool m_ischeck;
private slots:
    void slot_normalaimachange(QVariant var){m_normalindex=var.toInt();update();}
};

#endif // CLEANMAINBTN_H
