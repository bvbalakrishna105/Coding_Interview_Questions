#include <iostream>

using namespace std;

#define MAX_ROWS 4
#define MAX_COLS 4

class ArrayMatrix {
private:

    int inputMatrx[MAX_ROWS][MAX_COLS]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};


public:
    ArrayMatrix();
    ~ArrayMatrix();
    void displayMatrix();

};

ArrayMatrix::ArrayMatrix() {
    cout << "constructor" << endl;
}

ArrayMatrix::~ArrayMatrix() {
    cout << "desctructor" << endl;
}

void ArrayMatrix::displayMatrix() {

    for (int row = 0; row < MAX_ROWS; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            cout << inputMatrx[row][col] << " " ;
        }
        cout << endl;
    }
}


int main() {

    ArrayMatrix am;

    am.displayMatrix();


    return 0;
}