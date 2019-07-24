#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lcdNumber->display(0);
    falseSaleButton();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::falseSaleButton(){
    ui->pb_coke->setEnabled(false);
    ui->pb_tea->setEnabled(false);
    ui->pb_coffee->setEnabled(false);
}
void Widget::changeMoney(int n){
    int money = ui->lcdNumber->intValue();
    money += n;
    ui->lcdNumber->display(money);
    if(money < 200){
        ui->pb_coke->setEnabled(false);
        if(money < 150) {
            ui->pb_tea->setEnabled(false);
            if(money < 100) {
                ui->pb_coffee->setEnabled(false);
            }
        }
    }
    if(money >= 100){
        ui->pb_coffee->setEnabled(true);
        if (money >= 150){
            ui->pb_tea->setEnabled(true);
        } if (money >= 200) {
            ui->pb_coke->setEnabled(true);
        }
    }
}
int Widget::withdarwMoney(int balance, int money){
    QMessageBox msg;
    QString s1;

    if(balance > 0){
        s1 = QString().number(money) + "won is " + QString().number(balance/money) + " pieces";
        msg.information(nullptr, "Withdraw", s1);
        s1.clear();
    }

    return (balance%money);
}
void Widget::on_on_pb500_clicked_clicked()
{
    changeMoney(500);
}

void Widget::on_on_pb10_clicked_clicked()
{
    changeMoney(10);
}

void Widget::on_on_pb50_clicked_clicked()
{
    changeMoney(50);
}

void Widget::on_on_pb100_clicked_clicked()
{
    changeMoney(100);
}

void Widget::on_pb_coffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pb_tea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pb_coke_clicked()
{
    changeMoney(-200);
}

void Widget::on_pb_reset_clicked()
{
    int balance= ui->lcdNumber->intValue();
    if(balance >= 500){
        balance=withdarwMoney(balance, 500);
    }
    if(balance >= 100){
        balance=withdarwMoney(balance, 100);
    }
    if(balance >= 50){
        balance=withdarwMoney(balance, 50);
    }
    if(balance >= 10){
        balance=withdarwMoney(balance, 10);
    }
    falseSaleButton();
    ui->lcdNumber->display(balance);
}
