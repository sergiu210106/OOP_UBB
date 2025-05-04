/*
Implement a simplified version of the chess game that checks the correctness of moves on
the chessboard of different pieces, and makes the move only the move is valid. The base
class shoule be ChessPiece with the following protected members: positionX, positionY, name.
The class should also have a private attribute color. The class should have method bool
movePiece(unsinged int newX, unsigned int newY); which does nothing in the function body and
returns false. Create getters and setters for all the attributed.

Then create a class for each chess piece (Bishop, Rook, Pawn, Queen, King ) that inherits the
ChessPieces class and implements the movePiece method according to the move rules of each
piece. If the move is not valid, than the function will return false and the position of the piece
will not be changed. If the move is valid, the function will return true and the position of the
piece will be updated.
In the main function, create objects from all the derived classes. Then create a menu-based
console application that prompts the user for which piece to move and then for the
coordinates of where to move the piece. The program will display if the attempt to move the
piece was correct or not and the current position of the piece.
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class ChessPiece {
    private:
        char m_color; // 'b' or 'w'

    protected:
        unsigned int m_positionX;
        unsigned int m_positionY;
        string m_name;
    
    public:
        ChessPiece(unsigned int x, unsigned int y, string n, char c) {
            m_positionX = x;
            m_positionY = y; 
            m_name = n;
            m_color = c;
        }

        bool inside(unsigned int x, unsigned int y) {
            return (0 <= x and x <= 7) and (0 <= y and y <= 7);
        }

        bool movePiece(unsigned int newX, unsigned int newY) {
            return false;
        }

        // getters and setter for color
        char getColor() const {
            return m_color;
        }

        void setColor(char newColor) {
            m_color = newColor;
        }

        // getters and setter for X
        unsigned int getX() const {
            return m_positionX;
        }

        void setX(unsigned int newX) {
            m_positionX = newX;
        }

        // getters and setter for Y
        unsigned int getY() const {
            return m_positionY;
        }

        void setY(unsigned int newY) {
            m_positionY = newY;
        }

        void displayInfo() {
            cout << "Position: (" << m_positionX << ", " << m_positionY << "), name: " << m_name << ", color: " << m_color << endl;
        }
};

class Bishop : public ChessPiece {
    public:
        Bishop(unsigned int x, unsigned int y, string n, char c) : ChessPiece{x,y,n,c} {}

        bool movePiece(unsigned int newX, unsigned int newY) {
            if (!inside(newX, newY)) {
                return false;
            }

            unsigned int dx = abs(static_cast<int>(newX) - static_cast<int>(m_positionX));
            unsigned int dy = abs(static_cast<int>(newY) - static_cast<int>(m_positionY));

            if (dx == dy and dx != 0) {
                m_positionX = newX;
                m_positionY = newY;

                return true;
            }
            return false;
        }

};

class Rook : public ChessPiece {
    public:
        Rook(unsigned int x, unsigned int y, string n, char c) : ChessPiece{x,y,n,c} {}

        bool movePiece(unsigned int newX, unsigned int newY) {
            if (!inside(newX, newY)) {
                return false;
            }

            unsigned int dx = abs(static_cast<int>(newX) - static_cast<int>(m_positionX));
            unsigned int dy = abs(static_cast<int>(newY) - static_cast<int>(m_positionY));

            if (dx * dy == 0 and (dx != 0 or dy != 0)) {
                m_positionX = newX;
                m_positionY = newY;

                return true;
            }
            return false;
        }
};

class Pawn : public ChessPiece {
    public:
        Pawn(unsigned int x, unsigned int y, string n, char c) : ChessPiece{x,y,n,c} {}


        bool movePiece(unsigned int newX, unsigned int newY) {
            if (!inside(newX, newY)) {
                return false;
            }

            unsigned int dx = abs(static_cast<int>(newX) - static_cast<int>(m_positionX));
            unsigned int dy = abs(static_cast<int>(newY) - static_cast<int>(m_positionY));

            if ((dx == 0) and ((dy == 1 and getColor() == 'b') or (dy == -1 and getColor() == 'w'))) {
                m_positionX = newX;
                m_positionY = newY;

                return true;
            }
            return false;
        }
};

class Queen : public ChessPiece {
    public:
        Queen(unsigned int x, unsigned int y, string n, char c) : ChessPiece{x,y,n,c} {}

        bool movePiece(unsigned int newX, unsigned int newY) {
            if (!inside(newX, newY)) {
                return false;
            }

            unsigned int dx = abs(static_cast<int>(newX) - static_cast<int>(m_positionX));
            unsigned int dy = abs(static_cast<int>(newY) - static_cast<int>(m_positionY));

            if (dx * dy == 0 and (dx != 0 or dy != 0)) {
                m_positionX = newX;
                m_positionY = newY;

                return true;
            }
            if (dx == dy and dx != 0) {
                m_positionX = newX;
                m_positionY = newY;

                return true;
            }
            return false;
        }
};

class King : public ChessPiece {
    public:
        King(unsigned int x, unsigned int y, string n, char c) : ChessPiece{x,y,n,c} {}

        bool movePiece(unsigned int newX, unsigned int newY) {
            if (!inside(newX, newY)) {
                return false;
            }

            unsigned int dx = abs(static_cast<int>(newX) - static_cast<int>(m_positionX));
            unsigned int dy = abs(static_cast<int>(newY) - static_cast<int>(m_positionY));

            if (dx <= 1 and dy <= 1) {
                m_positionX = newX;
                m_positionY = newY;

                return true;
            }
            return false;
        }
};

int main() {
    Bishop b{2,0,"bishop", 'b'};
    Rook r{7,7,"rook", 'w'};
    Pawn p{0, 1, "pawn", 'b'};
    Queen q{3, 7, "queen", 'w'};
    King k{4, 7, "king", 'w'};

    while (1) {
        b.displayInfo();
        r.displayInfo();
        p.displayInfo();
        q.displayInfo();
        k.displayInfo();

        cout << "Choose a piece (bishop, rook, pawn, queen, king) or type 0 to stop:\n";

        string input; cin >> input;

        unsigned int x, y;
        bool m;

        if (input == "0")
            break;
        else if (input == "bishop") {
            cout << "Enter newX: "; cin >> x;
            cout << "Enter newY: "; cin >> y;

            m = b.movePiece(x,y);

            if (m) {
                cout << "Piece Moved!\n";
            } else {
                cout << "Invalid Move!\n";
            }
        } else if (input == "rook") {
            cout << "Enter newX: "; cin >> x;
            cout << "Enter newY: "; cin >> y;

            m = r.movePiece(x,y);

            if (m) {
                cout << "Piece Moved!\n";
            } else {
                cout << "Invalid Move!\n";
            }
        } else if (input == "pawn") {
            cout << "Enter newX: "; cin >> x;
            cout << "Enter newY: "; cin >> y;

            m = p.movePiece(x,y);

            if (m) {
                cout << "Piece Moved!\n";
            } else {
                cout << "Invalid Move!\n";
            }
        } else if (input == "queen") {
            cout << "Enter newX: "; cin >> x;
            cout << "Enter newY: "; cin >> y;

            m = q.movePiece(x,y);

            if (m) {
                cout << "Piece Moved!\n";
            } else {
                cout << "Invalid Move!\n";
            }
        } else if (input == "king") {
            cout << "Enter newX: "; cin >> x;
            cout << "Enter newY: "; cin >> y;

            m = k.movePiece(x,y);

            if (m) {
                cout << "Piece Moved!\n";
            } else {
                cout << "Invalid Move!\n";
            }
        } else {
            cout << "Invalid option!\n";
        }
    }

    return 0;
}
