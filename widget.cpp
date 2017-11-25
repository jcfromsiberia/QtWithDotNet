#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>

#include "dotnetform.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, &QPushButton::clicked, [ this ](){
       auto name = showDotNetForm();
       QMessageBox::information( this, "Greetings", QString( "Oh, hi there %1" ).arg( name.c_str() ) );
    });
}

Widget::~Widget()
{
    delete ui;
}
