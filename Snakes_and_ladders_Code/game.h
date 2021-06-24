#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <map>

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    Game (int);
    ~Game();
    void set_Player1();
    void set_Player2();
    void set_Player3();
    void set_Player4();
    void set_Board();
    void change_Position(int,int);
private slots:


    void on_Dice_Button_clicked();

private:
    Ui::Game *ui;
    QGraphicsScene *scene, *player1_piece, *player2_piece, *player3_piece, *player4_piece, *clear;
    QGraphicsPixmapItem *BoardGame;
    std::vector<std::vector<QGraphicsView*>> Fields;
    std::vector<int> Player_positions {0,0,0,0};
    int number_of_players, max_players;
    int player_Number = 0;
    std::map <int, int> snakes_Ladders {{1,38}, {4,14}, {9,31}, {17,7}, {21,42}, {28,84}, {51,67}, {54,34}, {62,19}, {64,60}, {72,91}, {80,99}, {87,36}, {93,73}, {95,75}, {98,79}};
};

#endif // GAME_H
