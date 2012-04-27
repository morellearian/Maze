/* 
 * File:   Ball_Shooter.h
 * Author: morellearian
 *
 * Created on April 19, 2012, 6:07 PM
 */

#ifndef BALL_SHOOTER_H
#define	BALL_SHOOTER_H


#include "Thing.h"
#include "Ball.h"
#include "BouncingBall.h"
#include "DirectedBall.h"
#include <iostream>
#include <vector>
#include <QImage>
#include <QRect>
#include <cstdlib>

class Ball_Shooter : public Thing {

    
public:
    Ball_Shooter(Thing* F, int i = 500, int k = 500) : Thing(), x_position(i), y_position(k), Followee(F) {

        image.load("shooter.jpg"); // load image
        rect = image.rect();
        Reset();       
        timerID = startTimer(700);

    }
    
    void Reset() { rect.moveTo(x_position,y_position); }
    
    void timerEvent(QTimerEvent *event) { 
       // std::cout << "timerEvent in Ball_Shooter called" << std::endl;
        if(Balls.size() < 10){
            if((Balls.size() % 4) == 0)
                Balls.push_back(new BouncingBall(x_position + 15, y_position));
            else if (Balls.size() == 5)
                Balls.push_back(new DirectedBall(Followee, x_position + 15, y_position));
            else
                Balls.push_back(new Ball(x_position + 15, y_position));
        }
    }
    
    
    void checkBorderCollisions(std::vector<QRectF> Borders) {
            
       // std::cout << "checkbordercollisions called in ball_shooter" << std::endl;
        for(int j = 0 ; j < Balls.size() ; j++)
            if(Balls[j]->bounceBorders()) {
                
            //    std::cout << "checkbordercollisions in ball_shooter bounceborders true " << j << std::endl;
            
            int ObjectLeft = Balls[j]->getRect().left();
            int ObjectHeight = Balls[j]->getRect().height();        
            int ObjectWidth = Balls[j]->getRect().width();        
            int ObjectTop = Balls[j]->getRect().top();
            
            QPoint pointRight(ObjectLeft + ObjectWidth, ObjectTop);
            QPoint pointLeft(ObjectLeft, ObjectTop);
            QPoint pointTop(ObjectLeft, ObjectTop);
            QPoint pointBottom(ObjectLeft, ObjectTop + ObjectHeight);
            
            for(int i = 0 ; i < Borders.size() ; i++) {
              if(Borders[i].contains(pointRight))  Balls[j]->setXDir(-1);       
              else if(Borders[i].contains(pointLeft))  Balls[j]->setXDir(1);      
              if(Borders[i].contains(pointTop))  Balls[j]->setYDir(1);       
              else if(Borders[i].contains(pointBottom))  Balls[j]->setYDir(-1);
            
            }    
            }
    }
    
    
            
    bool Multiple_Items_to_Print() { return true; }
    std::vector<Thing*> getVector() { return Balls; }
    
    
    bool is_Collision(QRect Player) {		
    
        for(int i = 0 ; i < Balls.size() ; i++){
            if(Player.intersects(Balls[i]->getRect())){ 
                Balls[i]->Reset(); 
                return true;
            }
        }
        
        return false;
        
    }
    
    void EndTimer() { 
        killTimer(timerID);
        for(int i = 0 ; i < Balls.size() ; i++)
            Balls[i]->EndTimer();
    }

    
private:
    	
    std::vector<Thing*> Balls;
    int x_position;
    int y_position;       
    Thing* Followee;

};

#endif	/* BALL_SHOOTER_H */

