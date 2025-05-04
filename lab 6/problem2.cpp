#include <iostream>
#include <string>

using namespace std;

unsigned int modullus(int x) {
    return (x>0) ? x : -1*x;
}

class ChessPiece {
    string VALID_PIECES[6] = {"Pawn", "Bishop", "Knight", "Rook", "King", "Queen"};
    protected:
        unsigned int m_positionX;
        unsigned int m_positionY;
        string m_name;
    private:
        char m_color;
    public:
        ChessPiece(unsigned int positionX, unsigned int positionY, string name, char color):
        m_positionX{positionX}, m_positionY{positionY}, m_name{name}, m_color{color}{}

        bool movePiece(unsigned int newX, unsigned int newY) {
            return false;
        }

        unsigned int getPositionX() const {
            return this->m_positionX;
        }

        unsigned int getPositionY() const {
            return this->m_positionY;
        }

        string getName() const {
            return this->m_name;
        }

        char getColor() const {
            return this->m_color;
        }

        bool setX(unsigned int newX) {
            if (1 <= newX and newX <= 8) {
                this->m_positionX = newX;
                return true;
            }
            return false;
        }

        bool setY(unsigned int newY) {
            if (1 <= newY and newY <= 8) {
                this->m_positionY = newY;
                return true;
            }
            return false;
        }

        bool setName(string newName) {
            for (int i = 0; i < 6; i ++) {
                if (newName == VALID_PIECES[i]) {
                    this->m_name = newName;
                    return true;
                }
            }
            return false;
        }

        bool setColor(char newColor) {
            if (newColor != 'b' and newColor != 'w') {
                return false;
            }
            this->m_color = newColor;
            return true;
        }


};

class Bishop : public ChessPiece {
    public:
        Bishop(unsigned int positionX, unsigned int positionY, char color) :
        ChessPiece{positionX, positionY, "Bishop", color}{}
        bool movePiece(unsigned int newX, unsigned int newY) {
            if (newX < 1 or newX > 8 or newY < 1 or newY > 8)
                return false;
            if((modullus(newX - this->m_positionX) == modullus(newY - this->m_positionY))) {
                this->m_positionX = newX;
                this->m_positionY = newY;
                return true;
            }
            return false;
        }
};

class Rook : public ChessPiece {
    public:
    Rook(unsigned int positionX, unsigned int positionY, char color) :
    ChessPiece{positionX, positionY, "Rook", color}{}
    bool movePiece(unsigned int newX, unsigned int newY) {
        if (newX < 1 or newX > 8 or newY < 1 or newY > 8)
            return false;
        if( (newX - this->m_positionX) * (newY - this->m_positionY) == 0) {
            this->m_positionX = newX;
            this->m_positionY = newY;
            return true;
        }
        return false;
    }
};

class Pawn : public ChessPiece {
    public:
    Pawn(unsigned int positionX, unsigned int positionY, char color) :
    ChessPiece{positionX, positionY, "Pawn", color}{}
    bool movePiece(unsigned int newX, unsigned int newY) {
        if (newX < 1 or newX > 8 or newY < 1 or newY > 8)
            return false;
        if( (this->getColor() == 'w' and newX == this->m_positionX - 1) or (this->getColor() == 'b' and newX == this->m_positionX + 1)) 
        // positionX is the row and positionY the column
        {
            this->m_positionX = newX;
            this->m_positionY = newY;
            return true;
        }
        return false;
    }
};

class Queen : public ChessPiece {
    public:
    Queen(unsigned int positionX, unsigned int positionY, char color) :
    ChessPiece{positionX, positionY, "Queen", color}{}
    bool movePiece(unsigned int newX, unsigned int newY) {
        if (newX < 1 or newX > 8 or newY < 1 or newY > 8)
            return false;
        if((newX - this->m_positionX) * (newY - this->m_positionY) == 0 || (modullus(newX - this->m_positionX) == modullus(newY - this->m_positionY))) 
        {
            this->m_positionX = newX;
            this->m_positionY = newY;
            return true;
        }

        return false;
    }
};

class King : public ChessPiece {
    public:
    King(unsigned int positionX, unsigned int positionY, char color):
    ChessPiece{positionX,positionY,"King",color}{}

    bool movePiece(unsigned int newX, unsigned int newY) {
        if (newX < 1 or newX > 8 or newY < 1 or newY > 8)
            return false;

        if(!(modullus(newX - this->m_positionX) + modullus(newY - this->m_positionY) == 1))
            return false;
        
        this->m_positionX = newX;
        this->m_positionY = newY;
        return true;
    }
};