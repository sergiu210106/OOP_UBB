#include "problem2.cpp"

using namespace std;

int main() {

    Bishop b{8,3,'w'};
    Rook r{1,8,'b'};
    Pawn p{7,4,'w'};
    Queen q{1,4,'b'};
    King k{8,5,'w'};

    while (true) {
        cout << "Choose what piece to move: \n";
        cout << "\t1. Bishop, current coordinates:\n";
        cout << "X: " << b.getPositionX() << "\tY: " << b.getPositionY() << '\n';
        cout << "\t2. Rook, current coordinates:\n";
        cout << "X: " << r.getPositionX() << "\tY: " << r.getPositionY() << '\n';
        cout << "\t3. Pawn, current coordinates:\n";
        cout << "X: " << p.getPositionX() << "\tY: " << p.getPositionY() << '\n';
        cout << "\t4. Queen, current coordinates:\n";
        cout << "X: " << q.getPositionX() << "\tY: " << q.getPositionY() << '\n';
        cout << "\t5. King, current coordinates:\n";
        cout << "X: " << k.getPositionX() << "\tY: " << k.getPositionY() << '\n';
        cout << "\t6. STOP\n";

        int option;
        cout << "CHOOSE AN OPTION (1-5):"; cin >> option;

        int x, y;
        if (1 <= option and option <= 5) {
            cout << "Enter new X coordinate: "; cin >> x;
            cout << "Enter new Y coordinate: "; cin >> y;
        }

        if (option == 1) {
            if (b.movePiece(x,y))
                cout << "Move succeded!\n";
            else
                cout << "Not valid\n";
        
        } else if (option == 2) {
            if (r.movePiece(x,y))
                cout << "Move succeded!\n";
            else
                cout << "Not valid\n";
        
        } else if (option == 3) {
            if (p.movePiece(x,y))
                cout << "Move succeded!\n";
            else
                cout << "Not valid\n";
        
        } else if (option == 4) {
            if (q.movePiece(x,y))
                cout << "Move succeded!\n";
            else
                cout << "Not valid\n";
        
        } else if (option == 5) {
            if (k.movePiece(x,y))
                cout << "Move succeded!\n";
            else
                cout << "Not valid\n";
        
        } else if (option == 6) {
            cout << "App stopped.";
            break;
        
        } else { cout << "Invalid Option"; }
    }

    return 0;
}