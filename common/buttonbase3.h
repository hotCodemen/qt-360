#ifndef BUTTONBASE3_H
#define BUTTONBASE3_H

#include <QPixmap>
#include <QPushButton>
#include <QMouseEvent>

class buttonbase3 : public QPushButton
{
    Q_OBJECT
public:
    explicit buttonbase3(QString pixcheckurl,QString pixuncheckurl,QWidget *parent = nullptr);

protected:
    void enterEvent(QEvent *ev);
    void leaveEvent(QEvent *ev);
    void paintEvent(QPaintEvent *ev);
    void mousePressEvent(QMouseEvent *ev);

private:
    bool m_checked;
    bool m_enter;

    QList<QPixmap> m_checklist;
    QPixmap m_pixcheck;
    QPixmap m_pixuncheck;
    int m_checkindex;
    int m_uncheckindex;
};

#endif // BUTTONBASE3_H
