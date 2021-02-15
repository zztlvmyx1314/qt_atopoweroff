#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <stdlib.h>
#include <QTimer>
#include <QTime>
#include <Windows.h>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void LCD_Init();

    void counter();




private slots:
    void on_start_clicked();


    void on_stop_clicked();

private:

    QTimer* timer=NULL;
    QTime  *time=NULL;









    Ui::Widget *ui;
};
#endif // WIDGET_H
