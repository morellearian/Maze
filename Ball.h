/* 
 * File:   Ball.h
 * Author: morellearian
 *
 * Created on April 19, 2012, 6:01 PM
 */

#ifndef BALL_H
#define	BALL_H


#include "Thing.h"
#include <QImage>
#include <QRect>
#include <cstdlib>
#include <iostream>


class Ball : public Thing { 
    public: 
    Ball(int i, int k) : Thing(), x_position(i), y_position(k) {
        
        image.load("blueball.jpg"); // load image
        rect = image.rect();
        Ball::Reset();
        timerID = startTimer(20);
    }

    void timerEvent(QTimerEvent *event) { Move(); }

    
    virtual void Reset() {

        rect.moveTo(x_position, y_position); // start at a random point on the screen

                       
        int value = rand() % 8;  // choose random direction in which to move

                switch(value) {    //   0  7  6
                                   //   1     5
                                   //   2  3  4
                case 0:
                        ydir = -3;
                        xdir = -3;
                     break;
                case 1:
                        ydir = -3;
                        xdir = 0;
                break;
                case 2:
                        ydir = -3;
                        xdir = 3;
                break;
                case 3:
                        xdir = 3;
                        ydir = 0;
                break;
                case 4:
                        ydir = 3;
                        xdir = 3;
                     break;
                case 5:
                        ydir = 3;
                        xdir = 0;
                     break;
                case 6:
                        ydir = 3;
                        xdir = -3;
                     break;
                case 7:
                        xdir = -3;
                        ydir = 0;
                     break;
                }
    }
    
    virtual void Move() {

        rect.translate(xdir, ydir); // move in the specified direction
             
        if(rect.left() < 0) // check if you're out of bounds
            Reset();//rect.moveRight(1000);
        if(rect.right() > 1000)
            Reset(); //rect.moveLeft(0);
        if(rect.top() < 0)
            Reset(); //rect.moveBottom(1000);
        if(rect.bottom() > 1000)
            Reset(); //rect.moveTop(0);

    }
   
    
protected:
    int x_position;
    int y_position;
};

#endif	/* BALL_H */

