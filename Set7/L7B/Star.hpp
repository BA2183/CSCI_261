#include <SFML/Graphics.hpp>
using namespace sf;

class Star: public CircleShape {
    private:
        int winWidth;
        int winHeight;
        float maxBright;
    public:
        Star(int width, int height, float brightest) {
            winWidth = width;
            winHeight = height;
            maxBright = brightest;
        }

        void getPosition(float& xCoord, float& yCoord) {
            xCoord = (xCoord + 1.0) * winWidth / 2.0;
            yCoord = (-yCoord + 1.0) * winHeight / 2.0;
        }

        int setBrightness(float bright) {
            float invertShade = maxBright - bright;
            int normalShade = (int) ((255.0 * invertShade) / maxBright);
            return normalShade;
        }
};