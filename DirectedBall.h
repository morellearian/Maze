/* 
 * File:   DirectedBall.h
 * Author: morellearian
 *
 * Created on April 22, 2012, 12:12 AM
 */

#ifndef DIRECTEDBALL_H
#define	DIRECTEDBALL_H

#include <QImage>
#include <QRect>
#include <cstdlib>
#include <iostream>
#include "Ball.h"


class DirectedBall : public Ball { 
    public:
        DirectedBall(Thing* F, int x_pos = 300, int y_pos = 300) : Ball(x_pos, y_pos), Followee(F) {
           
         //   std::cout << "directed ball constructor called" << std::endl;
            
            killTimer(timerID);
            image.load("green_ball.jpg"); // load image
            rect = image.rect();
            Reset();
            timerID = startTimer(250);
        }
        
        void Reset() { 
            rect.moveTo(x_position, y_position); 
            xdir = (Followee->getRect().left() - rect.left())/15;         
            ydir = (Followee->getRect().top() - rect.top())/15;
        }
        
        
        void Move() {
            rect.translate(xdir, ydir); // move in the specified direction
               
            if(rect.left() < 0) 
                Reset();
            if(rect.right() > 1000)
                Reset(); 
            if(rect.top() < 0)
                Reset(); 
            if(rect.bottom() > 1000)
                Reset(); 
        }
   
        
    private:
        Thing* Followee;

            
};



#endif	/* DIRECTEDBALL_H */

