#include <SFML/Graphics.hpp>
using namespace sf;

class Star: public CircleShape {
    private:
        int winWidth;
        int winHeight;
        float maxBright;
    public:
        Star(int width, int height, float bright, float brightest) {
            winWidth = width;
            winHeight = height;
            maxBright = brightest;
            setRadius(2.0);
            setPosition(0.0f, 0.0f);
            setBrightness(bright);
        }

        void setPosition(float xCoord, float yCoord) {
            float xPixel = (xCoord + 1.0) * winWidth / 2.0;
            float yPixel = (-yCoord + 1.0) * winHeight / 2.0;
            setPosition(xPixel, yPixel);
        }

        void setBrightness(float bright) {
            float invertShade = maxBright - bright;
            int normalShade = (int) ((255.0 * invertShade) / maxBright);
            setFillColor(Color(normalShade, normalShade, normalShade));
        }

};