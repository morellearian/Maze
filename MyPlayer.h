/* 
 * File:   MyPlayer.h
 * Author: morellearian
 *
 * Created on April 16, 2012, 9:03 AM
 */

#ifndef MYPLAYER_H
#define	MYPLAYER_H



#include "Thing.h"
//#include <iostream>
#include <QImage>
#include <QRect>
#include <QKeyEvent>

extern int HEIGHT, WIDTH;



class MyPlayer : public Thing {
public:
	MyPlayer(int i = 800, int k = 650) : Thing(), x_pos(i), y_pos(k) {
	
            bounces_off_Borders = true;
            
            image.load("circle.gif");
            rect = image.rect();	
            Reset();
            
            timerID = startTimer(5);
	}
        
	void Reset() {rect.moveTo(x_pos, y_pos);}
        
        void Move() { rect.translate(xdir, ydir); }
                
//        void keyPressEvent(QKeyEvent *event) {  // if key is pressed, change directions, or pause or quit or start game
//		switch(event->key()){
//			case Qt::Key_Left:
//				setXDir(-1);
//				setYDir(0);
//				break;
//			case Qt::Key_Right:
//				setXDir(1);
//				setYDir(0);
//				break;
//			case Qt::Key_Down:
//				setYDir(1);
//				setXDir(0);
//				break;
//			case Qt::Key_Up:
//				setYDir(-1);
//				setXDir(0);
//		
//                        //default:
//                          //      ignore();
//                }
//        };
        
        	
        void timerEvent(QTimerEvent *event) { Move(); }
        
private:
    int x_pos;
    int y_pos;
 
};




#endif	/* MYPLAYER_H */

