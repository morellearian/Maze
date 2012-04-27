/* 
 * File:   newLife.h
 * Author: morellearian
 *
 * Created on April 22, 2012, 1:58 AM
 */

#ifndef NEWLIFE_H
#define	NEWLIFE_H



#include "Thing.h"
#include "Treasure.h"
//#include <iostream>
#include <QImage>
#include <QRect>
#include <QKeyEvent>

extern int HEIGHT, WIDTH;



class newLife : public Ghost {
public:
    newLife() : Ghost() {
        LifeThing = true;
        

        killTimer(timerID);
        image.load("star.gif");
        rect = image.rect();
        timerID = startTimer(3);
        Reset();
    }
    
    
};


#endif	/* NEWLIFE_H */

