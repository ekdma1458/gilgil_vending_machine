#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void changeMoney(int n);
    int withdarwMoney(int balance, int money);
    void falseSaleButton();


private slots:
    void on_on_pb100_clicked_clicked();

    void on_on_pb500_clicked_clicked();

    void on_on_pb10_clicked_clicked();

    void on_on_pb50_clicked_clicked();

    void on_pb_coffee_clicked();

    void on_pb_tea_clicked();

    void on_pb_coke_clicked();

    void on_pb_reset_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
