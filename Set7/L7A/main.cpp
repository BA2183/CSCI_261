/*  CSCI 261: Lab 7A - SFML Drawing
 *
 * Author: Duan Nguyen
 * Reference: SFML documents, the photo of Walter White on Google
 * 
 * I tried to draw Walter White with the breaking bad theme playing in the background
 */
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

int main() {
    // create a window
    RenderWindow window( VideoMode(640, 640), "Lab 7A" );

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING

    Music song;
    if (!song.openFromFile("Breaking Bad Main Title Theme (Extended).ogg")) {
        return -1;
    }
    song.setVolume(100);
    song.setLoop(true);
    song.play();

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
        // top
        CircleShape triangle(400, 3);
        triangle.setPosition(-80, 280);
        triangle.setFillColor(Color(85,61,24));
        window.draw(triangle);

        // neck
        RectangleShape neck;
        neck.setSize(Vector2f(200, 400));
        neck.setPosition(215, 240);
        neck.setFillColor(Color(230,212,34));
        window.draw(neck);
        RectangleShape inSuit;
        inSuit.setSize(Vector2f(200, 400));
        inSuit.setPosition(215, 520);
        inSuit.setFillColor(Color(241,231,132));
        window.draw(inSuit);

        // head
        CircleShape baseShape;
        baseShape.setPosition( 110, 50 );
        baseShape.setRadius(200 );
        baseShape.setFillColor( Color(232,216,56) );
        window.draw( baseShape);

        // classes 
        RectangleShape leftGlass;
        leftGlass.setSize(Vector2f(125, 75));
        leftGlass.setPosition(150, 175);
        leftGlass.setFillColor(Color(232,216,56));
        leftGlass.setOutlineThickness(10);
        leftGlass.setOutlineColor(Color(0,0,0));
        window.draw(leftGlass);
        RectangleShape rightGlass;
        rightGlass.setSize(Vector2f(125, 75));
        rightGlass.setPosition(350, 175);
        rightGlass.setFillColor(Color(232,216,56));
        rightGlass.setOutlineThickness(10);
        rightGlass.setOutlineColor(Color(0,0,0));
        window.draw(rightGlass);
        RectangleShape midGlass;
        midGlass.setSize(Vector2f(75,10));
        midGlass.setPosition(275,200);
        midGlass.setFillColor(Color(0,0,0));
        window.draw(midGlass);
        // mustache
        RectangleShape upstache;
        upstache.setSize( Vector2f( 150, 25 ) );
        upstache.setPosition( 240, 325 );
        upstache.setFillColor( Color(36,33,4));
        window.draw( upstache );
        RectangleShape downstache;
        downstache.setSize(Vector2f(150, 45));
        downstache.setPosition(240, 405);
        downstache.setFillColor(Color(36,33,4));
        window.draw(downstache);
        RectangleShape sidestacheOne;
        sidestacheOne.setSize(Vector2f(25, 85));
        sidestacheOne.setPosition(240, 325);
        sidestacheOne.setFillColor(Color(36,33,4));
        window.draw(sidestacheOne);
        RectangleShape sidestacheTwo;
        sidestacheTwo.setSize(Vector2f(25, 85));
        sidestacheTwo.setPosition(365, 325);
        sidestacheTwo.setFillColor(Color(36,33,4));
        window.draw(sidestacheTwo);
        CircleShape midstache;
        midstache.setPosition(285, 375);
        midstache.setRadius(30);
        midstache.setFillColor(Color(36,33,4));
        window.draw(midstache);
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

    return 0;
}