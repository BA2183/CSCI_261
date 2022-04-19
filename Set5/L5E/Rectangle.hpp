#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
class Rectangle {
    private:
    float rBase;
    float rHeight;

    public:
    Rectangle();
    Rectangle(const Rectangle& OTHER);
    ~Rectangle();

    Rectangle& operator=(const Rectangle& OTHER);
    bool operator<(const Rectangle& OTHER);
    bool operator<=(const Rectangle& OTHER);
    bool operator>(const Rectangle& OTHER);
    bool operator>=(const Rectangle& OTHER);

    float getBase() const;
    float getHeight() const;
    void setBase(const float B);
    void setHeight(const float H);
};

Rectangle::Rectangle() {
    rBase = 1.0;
    rHeight = 1.0;
}

Rectangle::Rectangle(const Rectangle& OTHER) {
    rBase = OTHER.getBase();
    rHeight = OTHER.getHeight();
}

Rectangle::~Rectangle() {
    rBase = 0;
    rHeight = 0;
}

Rectangle& Rectangle::operator=(const Rectangle& OTHER) {
    if (this == &OTHER) {
        return *this;
    } else {
        rBase = OTHER.getBase();
        rHeight = OTHER.getHeight();
    }
}

bool Rectangle::operator<(const Rectangle& OTHER) {
    return (rBase < OTHER.getBase()) || (rBase == OTHER.getBase() && rHeight < OTHER.getHeight());
}

bool Rectangle::operator<=(const Rectangle& OTHER) {
    return (rBase <= OTHER.getBase()) || (rBase == OTHER.getBase() && rHeight <= OTHER.getHeight());
}

bool Rectangle::operator>(const Rectangle& OTHER) {
    return (rBase > OTHER.getBase()) || (rBase == OTHER.getBase() && rHeight > OTHER.getHeight());
}

bool Rectangle::operator>=(const Rectangle& OTHER) {
    return (rBase >= OTHER.getBase()) || (rBase == OTHER.getBase() && rHeight >= OTHER.getHeight());
}

float Rectangle::getBase() const {
    return rBase;
}

float Rectangle::getHeight() const {
    return rHeight;
}

void Rectangle::setBase(const float B) {
    if(B > 0) {
        rBase = B;
    }
}

void Rectangle::setHeight(const float H) {
    if(H > 0) {
        rHeight = H;
    }
}
#endif