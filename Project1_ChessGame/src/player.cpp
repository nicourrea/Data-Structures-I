#include "player.h"

//Queen
Queen::Queen() {
    x = 6;
    y = 0;
}

Queen::Queen(int x, int y) {
    this->x = x;
    this->y = y;
}

void Queen::print() const {
    cout << "(" << x << ", " << y << ")" << endl;
}



void Queen::move(int x, int y) {
 while (true) {
        if (x >= 0 && x < 10 && y >= 0 && y < 10) {
            this->x = x;
            this->y = y;
            cout << "Queen Moved To Position (" << x << "," << y << ")" << endl;
            return; // Exit the loop if the move is valid
        } else {
            cout << "Invalid move. Enter new position: ";
            cin >> x >> y;
        }
    }
}



int Queen::getX() const{
    return x;
}

int Queen::getY() const{
    return y;
}



//Bishop
Bishop::Bishop() {
    x = 5;
    y = 0;
}

Bishop::Bishop(int x, int y) {
    this->x = x;
    this->y = y;
}

void Bishop::print() const {
    cout << "(" << x << ", " << y << ")" << endl;
}

void Bishop::move(int x, int y) {
    while (true) {
        int dx = x - this->x;//diff between new x and current x
        int dy = y - this->y;//diff between new y and current y

        // Check if the move is diagonal (dx must equal dy) and within the chessboard bounds
        if ((dx == dy || dx == -dy) && x >= 0 && x < 10 && y >= 0 && y < 10) {
            this->x = x;
            this->y = y;
            cout << "Bishop Moved To Position (" << x << "," << y << ")" << endl;
            return; // Exit the loop if the move is valid
        } else {
            cout << "Invalid move. Enter new position: ";
            cin >> x >> y;
        }
    }
}

int Bishop::getX() const{
    return x;
}

int Bishop::getY() const{
    return y;
}



//Knight
Knight::Knight(){
        x = 4;
        y = 0;
}

Knight::Knight(int x, int y){
    this->x = x;
    this->y = y;
}
void Knight::print() const {
    cout << "(" << x << ", " << y << ")" << endl;
}
void Knight::move(int x, int y) {
    while (true) {
        int dx = x - this->x;
        int dy = y - this->y;

        // Check if the move is a valid knight move
        if ((dx == -2 && dy == 1) || (dx == -2 && dy == -1) ||
            (dx == 2 && dy == 1) || (dx == 2 && dy == -1)) {
            // Also check if the move is within the chessboard bounds
            if (x >= 0 && x < 10 && y >= 0 && y < 10) {
                this->x = x;
                this->y = y;
                cout << "Knight Moved To Position (" << x << "," << y << ")" << endl;
                return; // Exit the loop if the move is valid
            }
        }

        cout << "Invalid move. Enter new position: ";
        cin >> x >> y;
    }
}

int Knight::getX() const{
    return x;
}

int Knight::getY() const{
    return y;
}



//Rook
Rook::Rook(){
        x = 3;
        y = 0;
}

Rook::Rook(int x, int y){
    this->x = x;
    this->y = y;
}
void Rook::print() const {
    cout << "(" << x << ", " << y << ")" << endl;
}
void Rook::move(int x, int y) {
    while (true) {
        int dx = x - this->x;
        int dy = y - this->y;

        // Check if the move is a valid Rook move (either vertical or horizontal)
        if ((dx == 0 && dy != 0) || (dx != 0 && dy == 0)) {
            // Also check if the move is within the chessboard bounds
            if (x >= 0 && x < 10 && y >= 0 && y < 10) {
                this->x = x;
                this->y = y;
                cout << "Rook Moved To Position (" << x << "," << y << ")" << endl;
                return; // Exit the loop if the move is valid
            }
        }

        cout << "Invalid move. Enter new position: ";
        cin >> x >> y;
    }
}

int Rook::getX() const {
    return x;
}

int Rook::getY() const {
    return y;
}


