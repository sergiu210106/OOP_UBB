#include <iostream>
#include <string>

using namespace std;

class ChessPiece {
    protected:
        int m_positionX;
        int m_positionY;
        string m_name;
    private:
        char m_color;
    public:
        ChessPiece(int positionX, int positionY, string name, char color):
        m_positionX{positionX}, m_positionY{positionY}, m_name{name}, m_color{color}{}

        
};