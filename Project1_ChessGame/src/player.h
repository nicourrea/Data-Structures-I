#include <iostream>
using namespace std;

class Queen {
private:
    int x;
    int y;

public:
    Queen();
    Queen(int startX, int startY);
    void move(int newX, int newY);
    void print() const;
    int getX() const;
    int getY() const;
};


class Bishop {
    //store position
    private: 
        int x; 
        int y;
    public:
        Bishop();
        Bishop(int startX, int startY);
        void move(int newX, int newY);
        void print() const;
        int getX() const;
        int getY() const;
};

class Rook {
    //store position
    private: 
        int x; 
        int y;
    public:
        Rook();
        Rook(int startX, int startY);
        void move(int newX, int newY);
        void print() const;
        int getX() const;
        int getY() const;
};

class Knight {
    //store position
    private: 
        int x; 
        int y;
    public:
        Knight();
        Knight(int startX, int startY);
        void move(int newX, int newY);
        void print() const;
        int getX() const;
        int getY() const;
};
