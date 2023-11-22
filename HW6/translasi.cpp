#include <iostream>
#include <iomanip>
using namespace std;

void translasi(int &x, int &y, int tx, int ty) 
{
    x += tx;
    y += ty;
}

int main() 
{
    int x = 2, y = 4;
    int tx = 3, ty = 5;
    cout << "Koordinat awal: P(" << x << ", " << y << ")" << endl;
    translasi(x, y, tx, ty);
    cout << "Matriks translasi:" << endl;
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (i == j) 
            {
                cout << setw(4) << 1;
            } else if (j == 2) 
                {
                    cout << setw(4) << ((i == 0) ? tx : ty);
                } else 
                    {
                        cout << setw(4) << 0;
                    }
        }
        cout << endl;
    }
    cout << "Koordinat setelah translasi: P(" << x << ", " << y << ")" << endl;
    return 0;
}