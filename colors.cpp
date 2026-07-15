#include <iostream>
#include <string>
using namespace std;

enum class PieceType{
    r,b,y,g,p,w
};
 
string showColor(PieceType piece){
    switch (piece) {
        case PieceType::r: return "Red"; break;
        case PieceType::b: return "Blue";break;
        case PieceType::y: return "Yellow";break;
        case PieceType::g: return "Green";break;
        case PieceType::p: return "Purple";break;
        case PieceType::w: return "White";break;
        default:return "Unknown";
    }
}


int main(){
    PieceType piece;
    char choose;
    cout<<"Enter a piece type: ";
    cin >> choose;

    switch (choose) {
        case 'r': piece = PieceType::r;break;
        case 'b': piece = PieceType::b;break;
        case 'y': piece = PieceType::y;break;
        case 'g': piece = PieceType::g;break;
        case 'p': piece = PieceType::p;break;
        case 'w': piece = PieceType::w;break;
        default:
            cout << "Invalid piece" << endl;
            return 0;
    }

    cout << "Your Color is " << showColor(piece) <<endl;
}