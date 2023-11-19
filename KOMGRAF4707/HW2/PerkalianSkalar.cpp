#include<iostream>
using namespace std;

int main(){
    int A[2][2];
    int scalar;

    cout << "Masukkan nilai skalar: ";
    cin >> scalar;

    cout << "Masukkan nilai matriks 2x2:" << endl;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout << "Elemen baris " << i+1 << ", kolom " << j+1 << ": ";
            cin >> A[i][j];
        }
    }

    cout << "Hasil perkalian skalar dengan matriks: " << endl;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout << scalar * A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
