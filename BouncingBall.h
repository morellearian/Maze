/* 
 * File:   BouncingBall.h
 * Author: morellearian
 *
 * Created on April 21, 2012, 9:44 PM
 */

#ifndef BOUNCINGBALL_H
#define	BOUNCINGBALL_H


//#include "Thing.h"
#include <QImage>
#include <QRect>
#include <cstdlib>
#include <iostream>
#include "Ball.h"


class BouncingBall : public Ball { 
    public: 
        BouncingBall(int i, int k) : Ball(i, k) {

            killTimer(timerID);
            bounces_off_Borders = true;            
            image.load("red_ball.gif"); // load image
            rect = image.rect();
            Ball::Reset();
            timerID = startTimer(20);  
        }
        

        bool bounceBorders() { return true; }

        
         
        void Move() {
            rect.translate(xdir, ydir); // move in the specified direction
        }
};



#endif	/* BOUNCINGBALL_H */


