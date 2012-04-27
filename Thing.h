#ifndef THING_H_
#define THING_H_

#include <cstdlib>
#include <QApplication>
#include <iostream>
#include <QImage>
#include <QRect>
#include <QTimerEvent>
#include <QWidget>
#include <vector>
#include <QPoint>



class Thing : public QWidget {
    Q_OBJECT
    
public:
        Thing() : xdir(0), ydir(0), bounces_off_Borders(false), 
                LifeThing(false), ScoreThing(false) {}
        virtual void Move() {} // have a move function for every subclass
        virtual void timerEvent(QTimerEvent *event) { Move(); }  
        
        virtual bool is_Collision(QRect Player) {		
            if(Player.intersects(rect)) {
                Reset();
                return true;
            }
            else {
                return false;
            }
        }
        
        virtual bool Multiple_Items_to_Print() { return false; }
        virtual std::vector<Thing*> getVector() {}

        
        virtual void Reset() { rect.moveTo(400, 600); }
        virtual void EndTimer() { killTimer(timerID); }
        virtual void setTimerID(int i) { timerID = startTimer(10); }
        
        
        virtual void checkBorderCollisions(std::vector<QRectF> Borders) {
                        
            if(!bounces_off_Borders) return;
            
            int ObjectLeft = rect.left();
            int ObjectHeight = rect.height();        
            int ObjectWidth = rect.width();        
            int ObjectTop = rect.top();
            
            QPoint pointRight(ObjectLeft + ObjectWidth, ObjectTop + 3);
            QPoint pointLeft(ObjectLeft, ObjectTop + 3);
            QPoint pointTop(ObjectLeft + 3, ObjectTop);
            QPoint pointBottom(ObjectLeft + 3, ObjectTop + ObjectHeight);
            
            for(int i = 0 ; i < Borders.size() ; i ++) {
                if(Borders[i].contains(pointRight))  setXDir(-1);
                 else if(Borders[i].contains(pointLeft))  setXDir(1);
                if(Borders[i].contains(pointTop))  setYDir(1);
                 else if(Borders[i].contains(pointBottom))  setYDir(-1);
            }
            
        }

        void setXDir(int x) {xdir = x;} // getters and setters
        void setYDir(int y) {ydir = y;}
        virtual bool bounceBorders() { return bounces_off_Borders; }
	QRect getRect() {return rect;}
	QImage & getImage() {return image;}
        
        bool isScoreThing() { return ScoreThing; }
        bool isLifeThing() { return LifeThing; }
        

protected:
        QImage image; 
	QRect rect;
	int xdir;
	int ydir;
        int timerID;
        
        bool bounces_off_Borders;
        bool LifeThing;
        bool ScoreThing;
};


#endif  /* THING_H_ */
