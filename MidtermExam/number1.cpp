//1
#include <iostream>
#include <string>
using namespace std;
//id or name when entered must be ask how many will be bought, price and total price must be shown
//use a sorting algorithm (selection sort), sort the prices in ascending order. sort base on shelf life. name should also be displayed
//queue the id then print
class SariSari {
public:
    string name;
    double price;
    double shelflife;
    int pcs;
    int id;

public:
    double totalprice(int quantity) {
        double tprice = quantity * price;
        return tprice;
    }

    void setData(string n, double p, double s, int pcs, int i) {
        name = n;
        price = p;
        shelflife = s;
        this->pcs = pcs;
        id = i;
    }

    void displayInfo(int quantity) {
        cout << "SariSari" << endl;
        cout << "Name: " << name << endl;
        cout << "Price per item: " << price << endl;
        cout << "Shelflife: " << shelflife << endl;
        cout << "id: " << id << endl;
        cout << "Total Price for " << quantity << " items: " << totalprice(quantity) << endl;
    }
};

int main() {
    SariSari food[8];
    food[0].setData("mangoes", 20, 60, 100, 10245);
    food[1].setData("apple", 15, 38, 50, 20255);
    food[2].setData("c2_red", 30, 360, 200, 30356);
    food[3].setData("bukopie", 40, 120, 150, 12347);
    food[4].setData("magic_sarap", 10, 520, 1000, 77878);
    food[5].setData("c2_green", 25, 360, 300, 10255);
    food[6].setData("boy_bawang", 18, 400, 140, 12032);
    food[7].setData("banana", 7, 24, 30, 11234);

    string searchName;
    int quantity;
    cout << "what you want? ";
    cin >> searchName;

    bool found = false;
    for (int i = 0; i < 8; ++i) {
        if (food[i].name == searchName) {
            cout << "how many " << searchName << " you want? ";
            cin >> quantity;
            food[i].displayInfo(quantity);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Food not found." << endl;
    }

    return 0;
}