#include "game.h"
#include "ui_game.h"
#include "mainwindow.h"
#include <QLabel>
#include <QMessageBox>

Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);


}

Game::Game(int players) :

    ui(new Ui::Game)
{
    max_players = players -1;
    number_of_players = players;
    ui->setupUi(this);
    clear = new QGraphicsScene ();
    QPixmap empty(25,25);
    empty.fill(Qt::transparent);
    QPainter paint_empty(&empty);
    paint_empty.setRenderHint(QPainter::Antialiasing, true);
    paint_empty.setPen(Qt::NoPen);
    paint_empty.end();
    clear->addPixmap(empty);
    set_Board();
    set_Player1();
    set_Player2();
    if (number_of_players > 2){
        set_Player3();
        if (number_of_players > 3){
            set_Player4();
        }
    }
}

Game::~Game()
{
    delete ui;
}

void Game::set_Board(){
    QPixmap board_image(Path_to_Board);
    scene = new QGraphicsScene();
    scene->addPixmap(board_image);
    ui->Board->setScene(scene);
}

void Game::set_Player1(){
    player1_piece = new QGraphicsScene();
    QPixmap red(25,25);
    red.fill(Qt::transparent);
    QPainter paint_red(&red);
    paint_red.setRenderHint(QPainter::Antialiasing, true);
    paint_red.setPen(Qt::NoPen);
    paint_red.setBrush(QColor(255,153,0));
    paint_red.drawEllipse(5,5,20,20);
    paint_red.end();
    player1_piece->addPixmap(red);
    std::vector<QGraphicsView*>player1 = {		ui->player1_0, ui->player1_1, ui->player1_2, ui->player1_3, ui->player1_4,
                                                ui->player1_5, ui->player1_6, ui->player1_7, ui->player1_8, ui->player1_9,
                                                ui->player1_10, ui->player1_11, ui->player1_12, ui->player1_13, ui->player1_14,
                                                ui->player1_15, ui->player1_16, ui->player1_17, ui->player1_18, ui->player1_19,
                                                ui->player1_20, ui->player1_21, ui->player1_22, ui->player1_23, ui->player1_24,
                                                ui->player1_25, ui->player1_26, ui->player1_27, ui->player1_28, ui->player1_29,
                                                ui->player1_30, ui->player1_31, ui->player1_32, ui->player1_33, ui->player1_34,
                                                ui->player1_35, ui->player1_36, ui->player1_37, ui->player1_38, ui->player1_39,
                                                ui->player1_40, ui->player1_41, ui->player1_42, ui->player1_43, ui->player1_44,
                                                ui->player1_45, ui->player1_46, ui->player1_47, ui->player1_48, ui->player1_49,
                                                ui->player1_50, ui->player1_51, ui->player1_52, ui->player1_53, ui->player1_54,
                                                ui->player1_55, ui->player1_56, ui->player1_57, ui->player1_58, ui->player1_59,
                                                ui->player1_60, ui->player1_61, ui->player1_62, ui->player1_63, ui->player1_64,
                                                ui->player1_65, ui->player1_66, ui->player1_67, ui->player1_68, ui->player1_69,
                                                ui->player1_70, ui->player1_71, ui->player1_72, ui->player1_73, ui->player1_74,
                                                ui->player1_75, ui->player1_76, ui->player1_77, ui->player1_78, ui->player1_79,
                                                ui->player1_80, ui->player1_81, ui->player1_82, ui->player1_83, ui->player1_84,
                                                ui->player1_85, ui->player1_86, ui->player1_87, ui->player1_88, ui->player1_89,
                                                ui->player1_90, ui->player1_91, ui->player1_92, ui->player1_93, ui->player1_94,
                                                ui->player1_95, ui->player1_96, ui->player1_97, ui->player1_98, ui->player1_99,
                                                ui->player1_100};
    Fields.push_back(player1);
    Fields[0][0]->setScene(player1_piece);
}

void Game::set_Player2(){
    player2_piece = new QGraphicsScene();
    QPixmap blue(25,25);
    blue.fill(Qt::transparent);
    QPainter paint_blue(&blue);
    paint_blue.setRenderHint(QPainter::Antialiasing, true);
    paint_blue.setPen(Qt::NoPen);
    paint_blue.setBrush(QColor(30,144,255));
    paint_blue.drawEllipse(5,5,20,20);
    paint_blue.end();
    player2_piece->addPixmap(blue);
    std::vector<QGraphicsView*>player2 = {		ui->player2_0, ui->player2_1, ui->player2_2, ui->player2_3, ui->player2_4,
                                                ui->player2_5, ui->player2_6, ui->player2_7, ui->player2_8, ui->player2_9,
                                                ui->player2_10, ui->player2_11, ui->player2_12, ui->player2_13, ui->player2_14,
                                                ui->player2_15, ui->player2_16, ui->player2_17, ui->player2_18, ui->player2_19,
                                                ui->player2_20, ui->player2_21, ui->player2_22, ui->player2_23, ui->player2_24,
                                                ui->player2_25, ui->player2_26, ui->player2_27, ui->player2_28, ui->player2_29,
                                                ui->player2_30, ui->player2_31, ui->player2_32, ui->player2_33, ui->player2_34,
                                                ui->player2_35, ui->player2_36, ui->player2_37, ui->player2_38, ui->player2_39,
                                                ui->player2_40, ui->player2_41, ui->player2_42, ui->player2_43, ui->player2_44,
                                                ui->player2_45, ui->player2_46, ui->player2_47, ui->player2_48, ui->player2_49,
                                                ui->player2_50, ui->player2_51, ui->player2_52, ui->player2_53, ui->player2_54,
                                                ui->player2_55, ui->player2_56, ui->player2_57, ui->player2_58, ui->player2_59,
                                                ui->player2_60, ui->player2_61, ui->player2_62, ui->player2_63, ui->player2_64,
                                                ui->player2_65, ui->player2_66, ui->player2_67, ui->player2_68, ui->player2_69,
                                                ui->player2_70, ui->player2_71, ui->player2_72, ui->player2_73, ui->player2_74,
                                                ui->player2_75, ui->player2_76, ui->player2_77, ui->player2_78, ui->player2_79,
                                                ui->player2_80, ui->player2_81, ui->player2_82, ui->player2_83, ui->player2_84,
                                                ui->player2_85, ui->player2_86, ui->player2_87, ui->player2_88, ui->player2_89,
                                                ui->player2_90, ui->player2_91, ui->player2_92, ui->player2_93, ui->player2_94,
                                                ui->player2_95, ui->player2_96, ui->player2_97, ui->player2_98, ui->player2_99,
                                                ui->player2_100};
    Fields.push_back(player2);
    Fields[1][0]->setScene(player2_piece);

}

void Game::set_Player3(){
    player3_piece = new QGraphicsScene ();
    QPixmap green(25,25);
    green.fill(Qt::transparent);
    QPainter paint_green(&green);
    paint_green.setRenderHint(QPainter::Antialiasing, true);
    paint_green.setPen(Qt::NoPen);
    paint_green.setBrush(QColor(102,255,102));
    paint_green.drawEllipse(5,5,20,20);
    paint_green.end();
    player3_piece->addPixmap(green);
    std::vector<QGraphicsView*>player3 = {	ui->player3_0, ui->player3_1, ui->player3_2, ui->player3_3, ui->player3_4,
                                            ui->player3_5, ui->player3_6, ui->player3_7, ui->player3_8, ui->player3_9,
                                            ui->player3_10, ui->player3_11, ui->player3_12, ui->player3_13, ui->player3_14,
                                            ui->player3_15, ui->player3_16, ui->player3_17, ui->player3_18, ui->player3_19,
                                            ui->player3_20, ui->player3_21, ui->player3_22, ui->player3_23, ui->player3_24,
                                            ui->player3_25, ui->player3_26, ui->player3_27, ui->player3_28, ui->player3_29,
                                            ui->player3_30, ui->player3_31, ui->player3_32, ui->player3_33, ui->player3_34,
                                            ui->player3_35, ui->player3_36, ui->player3_37, ui->player3_38, ui->player3_39,
                                            ui->player3_40, ui->player3_41, ui->player3_42, ui->player3_43, ui->player3_44,
                                            ui->player3_45, ui->player3_46, ui->player3_47, ui->player3_48, ui->player3_49,
                                            ui->player3_50, ui->player3_51, ui->player3_52, ui->player3_53, ui->player3_54,
                                            ui->player3_55, ui->player3_56, ui->player3_57, ui->player3_58, ui->player3_59,
                                            ui->player3_60, ui->player3_61, ui->player3_62, ui->player3_63, ui->player3_64,
                                            ui->player3_65, ui->player3_66, ui->player3_67, ui->player3_68, ui->player3_69,
                                            ui->player3_70, ui->player3_71, ui->player3_72, ui->player3_73, ui->player3_74,
                                            ui->player3_75, ui->player3_76, ui->player3_77, ui->player3_78, ui->player3_79,
                                            ui->player3_80, ui->player3_81, ui->player3_82, ui->player3_83, ui->player3_84,
                                            ui->player3_85, ui->player3_86, ui->player3_87, ui->player3_88, ui->player3_89,
                                            ui->player3_90, ui->player3_91, ui->player3_92, ui->player3_93, ui->player3_94,
                                            ui->player3_95, ui->player3_96, ui->player3_97, ui->player3_98, ui->player3_99,
                                            ui->player3_100};
    Fields.push_back(player3);
    Fields[2][0]->setScene(player3_piece);
}

void Game::set_Player4(){
    player4_piece = new QGraphicsScene ();
    QPixmap yellow(25,25);
    yellow.fill(Qt::transparent);
    QPainter paint_yellow(&yellow);
    paint_yellow.setRenderHint(QPainter::Antialiasing, true);
    paint_yellow.setPen(Qt::NoPen);
    paint_yellow.setBrush(QColor(255,255,0));
    paint_yellow.drawEllipse(5,5,20,20);
    paint_yellow.end();
    player4_piece->addPixmap(yellow);
    std::vector<QGraphicsView*>player4 = {	ui->player4_0, ui->player4_1, ui->player4_2, ui->player4_3, ui->player4_4,
                                            ui->player4_5, ui->player4_6, ui->player4_7, ui->player4_8, ui->player4_9,
                                            ui->player4_10, ui->player4_11, ui->player4_12, ui->player4_13, ui->player4_14,
                                            ui->player4_15, ui->player4_16, ui->player4_17, ui->player4_18, ui->player4_19,
                                            ui->player4_20, ui->player4_21, ui->player4_22, ui->player4_23, ui->player4_24,
                                            ui->player4_25, ui->player4_26, ui->player4_27, ui->player4_28, ui->player4_29,
                                            ui->player4_30, ui->player4_31, ui->player4_32, ui->player4_33, ui->player4_34,
                                            ui->player4_35, ui->player4_36, ui->player4_37, ui->player4_38, ui->player4_39,
                                            ui->player4_40, ui->player4_41, ui->player4_42, ui->player4_43, ui->player4_44,
                                            ui->player4_45, ui->player4_46, ui->player4_47, ui->player4_48, ui->player4_49,
                                            ui->player4_50, ui->player4_51, ui->player4_52, ui->player4_53, ui->player4_54,
                                            ui->player4_55, ui->player4_56, ui->player4_57, ui->player4_58, ui->player4_59,
                                            ui->player4_60, ui->player4_61, ui->player4_62, ui->player4_63, ui->player4_64,
                                            ui->player4_65, ui->player4_66, ui->player4_67, ui->player4_68, ui->player4_69,
                                            ui->player4_70, ui->player4_71, ui->player4_72, ui->player4_73, ui->player4_74,
                                            ui->player4_75, ui->player4_76, ui->player4_77, ui->player4_78, ui->player4_79,
                                            ui->player4_80, ui->player4_81, ui->player4_82, ui->player4_83, ui->player4_84,
                                            ui->player4_85, ui->player4_86, ui->player4_87, ui->player4_88, ui->player4_89,
                                            ui->player4_90, ui->player4_91, ui->player4_92, ui->player4_93, ui->player4_94,
                                            ui->player4_95, ui->player4_96, ui->player4_97, ui->player4_98, ui->player4_99,
                                            ui->player4_100};
    Fields.push_back(player4);
    Fields[3][0]->setScene(player4_piece);
}

void Game::change_Position(int player, int dice_Roll){
    QGraphicsScene *temp;
    Fields[player][Player_positions[player]] ->setScene(clear);
    Player_positions[player] += dice_Roll;
    if (Player_positions[player] > 100){
        Player_positions[player] = 200 - Player_positions[player];
    }
    auto it = snakes_Ladders.find(Player_positions[player]);
    if (it != snakes_Ladders.end()){
        ui->Informations->append("You landed on snake/ladder on square " + QString::number(Player_positions[player]) + " . You go to square " + QString::number(it->second));
        Player_positions[player] = it->second;

    }
    else ui->Informations->append("You go to square " + QString::number(Player_positions[player]) + ".");
    if(player == 0) temp = player1_piece;
    else if(player == 1) temp = player2_piece;
    else if(player == 2) temp = player3_piece;
    else temp = player4_piece;
    Fields[player][Player_positions[player]] ->setScene(temp);
    if(Player_positions[player] == 100){
        QString winner = "Player " + QString::number(player+1) + " win. Congratulation!";
        QMessageBox win;
        win.setText(winner);
        win.setIcon(QMessageBox::Information);
        win.setWindowTitle("Congratulation!");
        win.exec();
        close();
    }
}

void Game::on_Dice_Button_clicked()
{
    ui->Informations->clear();
    int roll = rand()%6 +1;
    ui->Informations->append("You rolled " + QString::number(roll) + ". ");
    change_Position(player_Number,roll);
    player_Number++;
    if (player_Number > max_players) player_Number = 0;
}
