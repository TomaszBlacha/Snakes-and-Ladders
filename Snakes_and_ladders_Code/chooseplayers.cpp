#include "chooseplayers.h"
#include "ui_chooseplayers.h"

ChoosePlayers::ChoosePlayers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChoosePlayers)
{
    ui->setupUi(this);
}

void ChoosePlayers::showMainWindow(int players) {
    GameMap = new Game(players);
    GameMap->show();
   // GameMap->showMaximized();
    GameMap->setWindowTitle("Gra");
    close();
}

ChoosePlayers::~ChoosePlayers()
{
    delete ui;
}

void ChoosePlayers::on_Check2Players_clicked()
{
    ui->Check2Players->setChecked(1);
    ui->Check3Players->setChecked(0);
    ui->Check4Players->setChecked(0);
}

void ChoosePlayers::on_Check3Players_clicked()
{
    ui->Check2Players->setChecked(0);
    ui->Check3Players->setChecked(1);
    ui->Check4Players->setChecked(0);
}

void ChoosePlayers::on_Check4Players_clicked()
{
    ui->Check2Players->setChecked(0);
    ui->Check3Players->setChecked(0);
    ui->Check4Players->setChecked(1);
}

void ChoosePlayers::on_StartGameButton_clicked()
{
    int players = 2;
    if (ui->Check3Players->isChecked() == 1) players = 3;
    else if(ui->Check4Players->isChecked() == 1) players = 4;
    showMainWindow(players);
}
