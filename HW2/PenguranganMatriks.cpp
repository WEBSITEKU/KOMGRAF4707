#include<iostream>
using namespace std;

int main(){
    int A[2][2];
    int B[2][2];
        cout << "Masukkan nilai matriks A 2x2:" << endl;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout << "Elemen baris " << i+1 << ", kolom " << j+1 << ": ";
            cin >> A[i][j];
        }
    }

    cout << "Masukkan nilai matriks B 2x2:" << endl;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout << "Elemen baris " << i+1 << ", kolom " << j+1 << ": ";
            cin >> B[i][j];
        }
    }

    cout << "Matriks A + Matriks B: " << endl;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
             cout << A[i][j] - B[i][j]<< " ";
    }
    cout << endl;
  }
 
    return 0;
}