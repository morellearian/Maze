/* 
 * File:   Treasure.h
 * Author: morellearian
 *
 * Created on April 17, 2012, 5:11 PM
 */

#ifndef TREASURE_H
#define	TREASURE_H

#include "Thing.h"
//#include <iostream>
#include <QImage>
#include <QRect>
#include <QKeyEvent>

extern int HEIGHT, WIDTH;



class Treasure : public Thing {
public:
    Treasure(int i = 150, int k = 150) : Thing(), x_position(i), y_position(k) {
        
        image.load("triangle2.png");
        rect = image.rect();
        Reset();
        
    }
    
    
    void Reset() {rect.moveTo(x_position,y_position);}
    void Move() {} // doesn't move!!

    
private:
    int x_position;
    int y_position;
    
};


#endif	/* TREASURE_H */

