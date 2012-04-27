/* 
 * File:   Maze.h
 * Author: morellearian
 *
 * Created on April 16, 2012, 9:04 AM
 */

#ifndef MAZE_H
#define	MAZE_H


#include "MyPlayer.h"
#include "Treasure.h"
#include "Ghost.h"
#include "Ball_Shooter.h"
#include "Ball.h"
#include "TNT.h"
#include "AngryBird.h"
#include "newLife.h"
#include "AddScore.h"

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QTimerEvent>
#include <vector>
#include <QString>
#include <QTextStream>
#include <iostream>


extern int HEIGHT, WIDTH;



class Maze : public QWidget {
    Q_OBJECT
public:
    Maze (QWidget *parent = 0);
   
protected:
    void timerEvent(QTimerEvent *event);	
    void paintEvent(QPaintEvent *event);	
    void keyPressEvent(QKeyEvent *event);

    void startGame();	
    void pauseGame();	
    void endGame();    
    void Next_Level();	
    bool checkCollision();
    void checkBorderCollsion();
    
    //void Borders();
        
    
    private:
	MyPlayer *Player;
	std::vector<Thing*> Objects;
        std::vector<QRectF> Borders;
	int Lives;
	int Score;
	bool EndGame;
	bool gamePaused;
	bool gamePlaying;
        bool gameWon;
        int timerID;
        
        int Level;
        
        
};

#endif	/* MAZE_H */

