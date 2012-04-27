/* 
 * File:   TNT.h
 * Author: morellearian
 *
 * Created on April 20, 2012, 5:33 PM
 */

#ifndef TNT_H
#define	TNT_H


#include "Thing.h"
#include <QImage>
#include <QRect>
#include <cstdlib>
#include <iostream>


class TNT : public Thing { 
    public: 
        TNT() : Thing() {
            image.load("tnt.png"); // load image
            rect = image.rect();
            Reset();
            timerID = startTimer(5000);
        }
            

        void Reset() {
            Move();
        }

        void Move() {
            rect.moveTo(rand() % 800, rand() % 600);
        } // move randomly every five seconds.

            
private:
            
};

#endif	/* TNT_H */

