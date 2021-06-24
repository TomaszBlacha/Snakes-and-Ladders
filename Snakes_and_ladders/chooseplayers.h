#ifndef CHOOSEPLAYERS_H
#define CHOOSEPLAYERS_H

#include <QDialog>
#include <game.h>
//#include <mainwindow.h>

namespace Ui {
class ChoosePlayers;
}

class ChoosePlayers : public QDialog
{
    Q_OBJECT

public:
    explicit ChoosePlayers(QWidget *parent = nullptr);
    ~ChoosePlayers();
    void showMainWindow(int);

private slots:
    void on_Check2Players_clicked();

    void on_Check3Players_clicked();

    void on_Check4Players_clicked();

    void on_StartGameButton_clicked();

private:
    Ui::ChoosePlayers *ui;
    Game *GameMap;
};

#endif // CHOOSEPLAYERS_H
