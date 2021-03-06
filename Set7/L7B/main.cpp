/*  CSCI 261: Lab 7B
 *
 * Author: Duan Nguyen
 * Reference: class slide
 * 
 * 
 */
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#include "Star.hpp"

int main() {
    // create a window
    RenderWindow window( VideoMode(640, 640), "Lab 7B" );

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING

    ifstream fileIn;
    fileIn.open("stars.txt");

    // check if file open
    if (fileIn.fail()) {
        cerr << "File failed to open, closing . . .";
        return -1;
    }

    int widthMax, heightMax, starShade;
    widthMax = heightMax = 640;
    float xStar, yStar, tempValue, brightValue, xPixel, yPixel;
    vector<float> xVector;
    vector<float> yVector;
    vector<float> brightVector;
    do {
        // get x coords
        fileIn >> xStar;
        if(!fileIn.fail()) {
            xVector.push_back(xStar);
        }
        // get y coords
        fileIn >> yStar;
        if(!fileIn.fail()) {
            yVector.push_back(yStar);
        }
        // get but no store z coord
        fileIn >> tempValue;
        // get brightness value
        fileIn >> brightValue;
        if(!fileIn.fail()) {
            brightVector.push_back(brightValue);
        }
        // get but no store trash values
        fileIn >> tempValue;
        fileIn >> tempValue;
    } while (!fileIn.eof());
    // get max value
    float maxBright = brightVector[0];
    for(int i = 1; i < brightVector.size(); i++) {
        if(brightVector[i] > maxBright) {
            maxBright = brightVector[i];
        }
    }
    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    Event event;

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE
        
        Star baseShape(widthMax, heightMax, maxBright);
        baseShape.setRadius(2);
        for(int j = 0; j < brightVector.size(); j++) {
            xPixel = xVector[j];
            yPixel = yVector[j];
            baseShape.getPosition(xPixel, yPixel);
            baseShape.setPosition(xPixel, yPixel);
            starShade = baseShape.setBrightness(brightVector[j]);
            baseShape.setFillColor(Color(starShade, starShade, starShade));
            window.draw(baseShape);
        }

        //  END  DRAWING HERE
        /////////////////////////////////////


        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    fileIn.close();
    return 0;
}