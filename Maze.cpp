/* 
 * File:   Maze.cpp
 * Author: morellearian
 * 
 * Created on April 16, 2012, 9:04 AM
 */

//somethin gets a big funky with hitting borders on 2nd and 3rd levels...


#include "Maze.h"


Maze::Maze (QWidget *parent) 
        : QWidget(parent), 
        Lives(3), Score(1),        
        Level(0),
        EndGame(false), gamePaused(false), gamePlaying(false), gameWon(false)
{          
    repaint();
}



void Maze::timerEvent (QTimerEvent *event) {
		
		if(Score % 5 == 0) // every time score is a multiple of five, add more objects
			Score++;
		//	for (int i = 0 ; i < 5 ; i++)
		//		Objects.push_back(new Explosives() );
	//	}
                
                   if(checkCollision()){
                        Lives--;
                        if(Lives == 0) {
                            endGame();
                        }
                    }
                
		repaint();
}

void Maze::paintEvent(QPaintEvent *event) {
		
            QPainter painter(this);
	
            if(!gamePlaying && !EndGame) {  // display menu if you haven't played yet

                painter.drawText(100,100, "Use the arrow keys to move");
                painter.drawText(100,120, "You are the circle, do not run into the objects!");
                painter.drawText(100,140, "You have three lives try to reach the swirly triangle to progress through the three levels.");
                
                painter.drawText(100,180, "The swirly star gives you an extra life, and the smiley face gives you points, but all the other objects will make you lose a life");
                painter.drawText(100,200, "The number of lives left and score is shown in the upper left corner");
                painter.drawText(100,220, "You can quit at any time by pressing 'q' or pause by pressing 'p'");
                painter.drawText(100,240, "Start by pressing enter");            
            }
	
            else {
                checkBorderCollsion();
                
                QString s = QString::number(Lives);
                QString gameinfo = "Lives: "; gameinfo += s;
                s = QString::number(Score);
                gameinfo += ",    Score: "; gameinfo += s;
                
                if(EndGame) {  // game over menu	
                    painter.drawText(100,100, "Game Over");
                    painter.drawText(100, 120, gameinfo);
                    painter.drawText(100, 140, "To start over press enter");
                    
                    killTimer(timerID);	
                    Level = 0;
                    Lives = 3;
                }
                
                if(gameWon) {  // game over menu	
                    painter.drawText(100,100, "VICTORY!");
                    painter.drawText(100, 120, gameinfo);
                    painter.drawText(100, 140, "To start over press enter");
                    
                    killTimer(timerID);	
                    Level = 0;
                    Lives = 3;
                }
		
                else{  // draw all the objects and display the num of lives and the score count on the screen
                    
                    //draw Border
                    for(int i = 0 ; i < Borders.size() ; i++){
                        painter.fillRect(Borders[i], Qt::black);
                        painter.drawRect(Borders[i]);
                    }
                    
                 
                    
                    painter.drawText(25, 20, gameinfo); // draw score + lives etc.
                    
                    painter.drawImage(Player->getRect(), Player->getImage());  // draw player and objects
                    for(int i = 0; i < Objects.size(); i++)
                        painter.drawImage(Objects[i]->getRect(), Objects[i]->getImage());

                    
                    for(int i = 0 ; i < Objects.size() ; i++) { // draw the balls if there's a ball shooter...
                        if(Objects[i]->Multiple_Items_to_Print()){
                            std::vector<Thing*> balls_to_print = Objects[i]->getVector();
                            for(int j = 0 ; j < balls_to_print.size() ; j++)
                                painter.drawImage(balls_to_print[j]->getRect(), balls_to_print[j]->getImage());
                    
                        }
                    }
                }
            }
}


  
void Maze::keyPressEvent(QKeyEvent *event) {  // if key is pressed, change directions, or pause or quit or start game
		switch(event->key()){
                    
			case Qt::Key_P:
				pauseGame();
				break;
			case Qt::Key_Q:
				endGame();
				break;
			case Qt::Key_Return:
				//gamePlaying = true;
				EndGame = false;
				gamePaused = false;
				Lives = 3; Score = 1;
                                startGame();
				break;       
                        case Qt::Key_Left:
				Player->setXDir(-1);
				Player->setYDir(0);
				break;
			case Qt::Key_Right:
				Player->setXDir(1);
				Player->setYDir(0);
				break;
			case Qt::Key_Down:
				Player->setYDir(1);
				Player->setXDir(0);
				break;
			case Qt::Key_Up:
				Player->setYDir(-1);
				Player->setXDir(0);
				break;
                    case Qt::Key_L:
                        Level++;
                        Next_Level();
			default: break;
		}	
}

  
void Maze::startGame() {
            
		if(!gamePlaying) {
                    Player = new MyPlayer(800,650);
                                        
                    gamePlaying = true;
                    Level = 1;
                    Next_Level();    
                }		
}

void Maze::pauseGame() {
		if(gamePaused) {
			timerID = startTimer(10);
			gamePaused = false;
		}
		else {
			gamePaused = true;
			killTimer(timerID);
		}	
}

void Maze::endGame() {
            //    EndGame = true;
                gamePlaying = false;
                killTimer(timerID);
                
                for(int i = 0 ; i < Objects.size() ; i++)
                    Objects[i]->EndTimer();
                
                Objects.erase(Objects.begin(), Objects.begin() + Objects.size());
                Borders.erase(Borders.begin(), Borders.begin() + Borders.size());
            //    delete[] Objects;
                delete Player;
                
                repaint();
}
  

void Maze::Next_Level() { // create all the objects
            
    
    Score+=200;
    
            killTimer(timerID);
    
            Objects.erase(Objects.begin(), Objects.begin() + Objects.size());
            
            if (Level == 1) {
                                   
                Player->Reset();
                Player->setXDir(0);
                Player->setYDir(0);
                
                Objects.push_back(new Treasure() );
                
          //      Objects.push_back(new Ghost());
                
                Objects.push_back(new Ball_Shooter(Player, 500,500));

            //    Objects.push_back(new TNT());          
                                
                Objects.push_back(new AngryBird(Player, 300, 300));
                
                Objects.push_back(new newLife());
                
                Objects.push_back(new AddScore());
                Objects.push_back(new AddScore());
                Objects.push_back(new AddScore());


                
                QRectF rectangle1(0,0,WIDTH,5);
                Borders.push_back(rectangle1); // upper   
                QRectF rectangle2(0,0,5,HEIGHT);
                Borders.push_back(rectangle2); // left     
                QRectF rectangle3(0,750,WIDTH,5);
                Borders.push_back(rectangle3); // lower  
                QRectF rectangle4((WIDTH-5),0,5,HEIGHT);
                Borders.push_back(rectangle4); // right  
            }
            
            else if (Level == 2) {
                Player->Reset();
                Player->setXDir(0);
                Player->setYDir(0);
                
                Objects.push_back(new Treasure(100,100));

                Objects.push_back(new AngryBird(Player, 300, 300));

                Objects.push_back(new AngryBird(Player, 600, 300));

                Objects.push_back(new newLife());
                
                Objects.push_back(new AddScore());
            
                Objects.push_back(new Ghost());

                Objects.push_back(new Ghost());

                Objects.push_back(new Ghost());
                
                Objects.push_back(new Ghost());
                
                
                QRectF rectangle5((WIDTH/3),0,5,600);
                Borders.push_back(rectangle5);
                QRectF rectangle6((2*WIDTH/3),200,5,600); 
                Borders.push_back(rectangle6);
                
            }
            
            else if (Level == 3) {  
                             
                Player->Reset();
                Player->setXDir(0);
                Player->setYDir(0);
                
                Objects.push_back(new Treasure(550,250));

                Objects.push_back(new Ball_Shooter(Player, 500,5));

                Objects.push_back(new newLife());
                
                Objects.push_back(new TNT());          

                
                 
                Borders.erase(Borders.begin() + 4, Borders.begin() + 6);
              
                QRectF rectangle7(200,600,800,5);
                Borders.push_back(rectangle7);
                QRectF rectangle8(200,150,5,450);               
                Borders.push_back(rectangle8);
                QRectF rectangle9(200,150,550,5);
                Borders.push_back(rectangle9);
                QRectF rectangle10(750,150,5,250);            
                Borders.push_back(rectangle10);
                
                QRectF rectangle11(400,400,355,5);      
                Borders.push_back(rectangle11);
                QRectF rectangle12(400,300,6,100);                
                Borders.push_back(rectangle12);
          
            }        
            
            timerID = startTimer(10);
}

void Maze::checkBorderCollsion() {
       
    //check player border collisions
    Player->checkBorderCollisions(Borders);
    
    // check all other objects who bounce of borders for border collision
    for(int j = 0 ; j < Objects.size() ; j++)
        Objects[j]->checkBorderCollisions(Borders);
        
    
}

bool Maze::checkCollision() {  // check if a collision happened
    
 
		for (int i = 0 ; i < Objects.size() ; i++)
			if( Objects[i]->is_Collision(Player->getRect()) ) {
                            if (i == 0){ // they got the treasure
                                Level++;
                                if(Level == 4)
                                    gameWon = true;
                                Next_Level();
                                return false;
                            }
                            else if (Objects[i]->isLifeThing())
                                Lives++;
                            else if(Objects[i]->isScoreThing())
                                Score += 100;
                            else return true;
			}
                
		return false;	
}