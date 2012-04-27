/* 
 * File:   AngryBird.h
 * Author: morellearian
 *
 * Created on April 21, 2012, 1:25 PM
 */

#ifndef ANGRYBIRD_H
#define	ANGRYBIRD_H


#include "Thing.h"
#include <QImage>
#include <QRect>
#include <cstdlib>
#include <iostream>

#include <QPoint>


class AngryBird : public Thing {
    public: 
        AngryBird(Thing* F, int x_pos = 300, int y_pos = 300) : Thing(), Followee(F) {

            image.load("angry_bird.jpg"); // load image
            rect = image.rect();
            Reset(x_pos, y_pos);
            timerID = startTimer(1000);
        }
        
        void Reset(int x_pos, int y_pos) { rect.moveTo(x_pos,y_pos); }
        
        void Move() {
                        
            xdir = (Followee->getRect().left() - rect.left())/5; 
            ydir = (Followee->getRect().top() - rect.top())/5;
            
            rect.translate(xdir, ydir);
           
        }
        
        
                
    private:
        Thing* Followee;
};



#endif	/* ANGRYBIRD_H */

