#include "player.h"

// code template from class
//#include "players.h"
int main () {


    Knight knight1;
    Rook rook1;
    Bishop bishop1;
    Queen queen1;
    
    int counter = 0;
    int quit = 0;
    while(quit == 0) {
        cout << "Initial Positions:" << endl;
        cout << "Knight" << endl;
        knight1.print();
        cout << "Rook" << endl;
        rook1.print();
        cout << "Bishop" << endl;
        bishop1.print();
        cout << "Queen" << endl;
        queen1.print();
        

        /*cout << "Player 2" << endl;
        p2.Print();*/
        // if(counter == 0) {
            //this is player 1s turn 
            
            cout << "where would you like to move your your knight?" << endl;
            int knew_x, knew_y; //new knight positions
            cin >> knew_x >> knew_y;
            while((knew_x == bishop1.getX() && knew_y == bishop1.getY()) || (knew_x == rook1.getX() && knew_y == rook1.getY()) || (knew_x == queen1.getX() && knew_y == queen1.getY())){
                cout << "Invalid move: position already occupied " << endl;
                cout << "Enter new position: " << endl;
                cin >> knew_x >> knew_y;
            }
            knight1.move(knew_x, knew_y);
            

            cout << "where would you like to move your rook?" << endl;
            int rnew_x, rnew_y; //new rook positions
            cin >> rnew_x >> rnew_y;
            while((rnew_x == bishop1.getX() && rnew_y == bishop1.getY()) || (rnew_x == knight1.getX() && rnew_y == knight1.getY()) || (knew_x == queen1.getX() && knew_y == queen1.getY())){
                cout << "Invalid move: position already occupied " << endl;
                cout << "Enter new position: " << endl;
                cin >> rnew_x >> rnew_y;
            }
            rook1.move(rnew_x, rnew_y);


            cout << "where would you like to move your bishop?" << endl;
            int bnew_x, bnew_y; //new bishop positions
            cin >> bnew_x >> bnew_y;
            while((bnew_x == knight1.getX() && bnew_y == knight1.getY()) || (bnew_x == rook1.getX() && bnew_y == rook1.getY()) || (bnew_x == queen1.getX() && bnew_y == queen1.getY())){
                cout << "Invalid move: position already occupied " << endl;
                cout << "Enter new position: " << endl;
                cin >> bnew_x >> bnew_y;
            }
            bishop1.move(bnew_x, bnew_y);

            cout << "where would you like to move your queen?" << endl;
            int qnew_x, qnew_y;
            cin >> qnew_x >> qnew_y;
            while((qnew_x == knight1.getX() && qnew_y == knight1.getY()) || (qnew_x == rook1.getX() && qnew_y == rook1.getY()) || (qnew_x == queen1.getX() && qnew_y == queen1.getY())){
                cout << "Invalid move: position already occupied " << endl;
                cout << "Enter new position: " << endl;
                cin >> qnew_x >> qnew_y;
            }
            queen1.move(qnew_x, qnew_y);
            
            cout << "Enter 1 to quit" << endl;
            cout << "Enter 0 to keep playing" <<endl;
            cin >> quit;
       /* } else if(counter == 1) {
            //this is player 2s turn
        } else {
            //horrible somthing happened ??
        }
        */
        //counter = (counter + 1) % 2; 

    }
    return 0;
}