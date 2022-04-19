#ifndef PLAYER_HPP
#define PLAYER_HPP
class Player {
private:
    int playNum;
    int chipHas;
public:
    // default functions
    Player();
    Player(const Player& OTHER);
    ~Player();

    // setter and getter
    void setNum(int NUM);
    void setChip(int CHIP);
    int getNum() const;
    int getChip() const;

    // other methods
    void giveChip();
    void takeChip();
    void giveChip(Player& OTHER);
};

// DEFAULTS
    // CONSTRUCTOR
Player::Player() {
    playNum = 0;
    chipHas = 0;
}
    // DECONSTRUCTOR
Player::~Player() {
    playNum = 0; chipHas = 0;
}
    // COPY CONSTUCTOR
Player::Player(const Player& OTHER) {
    playNum = OTHER.getNum();
    chipHas = OTHER.getChip();
}

// SETTERS GETTERS
void Player::setNum(int NUM) {
    if(NUM > 0) {
        playNum = NUM;
    }
}
void Player::setChip(int CHIP) {
    if(CHIP > 0) {
        chipHas = CHIP;
    }
}
int Player::getNum() const {
    return playNum;
}
int Player::getChip() const {
    return chipHas;
}

// OTHERS
void Player::giveChip() {
    chipHas--;
}
void Player::takeChip() {
    chipHas++;
}
void Player::giveChip(Player& OTHER) {
    chipHas--;
    OTHER.takeChip();
}

#endif