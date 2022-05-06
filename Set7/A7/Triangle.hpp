#include <SFML\Graphics.hpp>
using namespace sf;

#include <vector>
using namespace std;

class Triangle {
    public:
        Triangle() {shapeColor = Color::White; vertexNum = 3;}
        ~Triangle() {delete xyCoord;}
        void setColor(const Color color) {shapeColor = color;}
        void draw(RenderTarget& window) {
            ConvexShape conShape;
            conShape.setPointCount(vertexNum);
            for(int i = 0; i < vertexNum; i++) {
                conShape.setPoint(i, (*xyCoord)[i]);
            }
            window.draw(conShape);
        }
        virtual bool setCoordinates(Vector2f ver1, Vector2f ver2, Vector2f ver3);
    protected:
        int vertexNum;
        vector<Vector2f>* xyCoord;
    private:
        Color shapeColor;
};