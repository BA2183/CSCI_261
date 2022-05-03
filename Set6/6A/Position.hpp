#ifndef POSITION_HPP
#define POSITION_HPP
struct Position {
    int rowNum;
    int colNum;
    Position() {rowNum = 0; colNum = 0;}
    Position(int ROW, int COL) { rowNum = ROW; colNum = COL;}
    Position& operator=(const Position& OTHER) {rowNum = OTHER.rowNum; colNum = OTHER.colNum;}
};
#endif