/* 
 * File:   AddScore.h
 * Author: morellearian
 *
 * Created on April 22, 2012, 2:02 AM
 */

#ifndef ADDSCORE_H
#define	ADDSCORE_H


#include "Thing.h"
#include <QImage>
#include <QRect>
#include <cstdlib>


class AddScore : public Ghost {
     public: 
	AddScore() : Ghost() {
            ScoreThing = true;

            killTimer(timerID);
            image.load("smiley1.jpeg"); // load image
            rect = image.rect();
            timerID = startTimer(3);
            Reset();
	}
};

#endif	/* ADDSCORE_H */

