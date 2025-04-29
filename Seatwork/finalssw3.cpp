#include <iostream>
using namespace std;

union Place {
    int SamsonRd;
    int LapuLapuSt;
    int BagongBario;
    int Payatas;
};

int main() {
    Place tao1, tao2, tao3; 

    tao1.SamsonRd = 5;
    cout << "tao1.SamsonRd: " << tao1.SamsonRd << endl;

    tao1.BagongBario = 6; 
    cout << "tao1.SamsonRd (overwritten): " << tao1.SamsonRd << endl;
    cout << "tao1.BagongBario: " << tao1.BagongBario << endl;

    // Assign and display values for tao2
    tao2.LapuLapuSt = 10;
    cout << "tao2.LapuLapuSt: " << tao2.LapuLapuSt << endl;

    tao2.Payatas = 15; 
    cout << "tao2.LapuLapuSt (overwritten): " << tao2.LapuLapuSt << endl;
    cout << "tao2.Payatas: " << tao2.Payatas << endl;

    return 0;
}