/* 
 * File:   Ghost.h
 * Author: morellearian
 *
 * Created on April 18, 2012, 8:13 PM
 */

#ifndef GHOST_H
#define	GHOST_H

#include "Thing.h"
#include <QImage>
#include <QRect>
#include <cstdlib>


class Ghost : public Thing {

    
    public: 
	Ghost() : Thing() {
            
            image.load("ghost.jpg"); // load image
            rect = image.rect();
            timerID = startTimer(5);
            Reset();
	}
        
	void Reset() {
		rect.moveTo(rand() % 800, rand() % 600); // start at a random point on the screen
	}
        
        bool is_Collision(QRect Player) {
            
            if(Player.intersects(rect)) {
                Reset();
                return true;
            }
            else {
                return false;
            }
        }
        
	void Move() {
                int value = rand() % 8;  // move randomly

                switch(value) {    //   0  7  6
                                   //   1     5
                                   //   2  3  4
                case 0:
                        ydir = -5;
                        xdir = -5;
                     break;
                case 1:
                        ydir = -5;
                        xdir = 0;
                break;
                case 2:
                        ydir = -5;
                        xdir = 5;
                break;
                case 3:
                        xdir = 5;
                        ydir = 0;
                break;
                 case 4:
                        ydir = 5;
                        xdir = 5;
                     break;
                 case 5:
                        ydir = 5;
                        xdir = 0;
                     break;
                 case 6:
                        ydir = 5;
                        xdir = -5;
                     break;
                 case 7:
                        xdir = -5;
                        ydir = 0;
                     break;
                default:
                     break;
		}

		rect.translate(xdir, ydir); // move in the specified direction

		if(rect.left() < 0) // check if you're out of bounds
			rect.moveRight(1000);
		if(rect.right() > 1000)
			rect.moveLeft(0);
		if(rect.top() < 0)
			rect.moveBottom(1000);
		if(rect.bottom() > 1000)
			rect.moveTop(0);
	}        


};



#endif	/* GHOST_H */

