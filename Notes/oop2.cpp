#include <iostream>
#include <string>
using namespace std;

class Clothes{
    public:
        string brand;
        string type;
        string color;
        double length;
        double width;
        double height;
        double price;
        double discount;

    public:
        double discountedPrice(){
            double discounted_price = price - (discount * price);
            return discounted_price;
        }

        void setData(string b, string t, string c, double l, double w, double h, double p, double d){
            brand = b;
            type = t;
            color = c;
            length = l;
            width = w;
            height = h;
            price = p;
            discount = d;
        }

        void displayInfo(){
            cout << "Clothes Information" << endl;
            cout << "Brand: " << brand << endl;
            cout << "Type: " << type << endl;
            cout << "Color: " << color << endl;
            cout << "Original Price: " << price << endl;
            cout << "Discounted Price: " << discountedPrice() << endl;
        }

        void displaySize(){
            //
            double volume = length * width * height;
            string size;
            if  (volume < 20){
                size = "Small Size";
            } else if (volume >= 20 && volume < 40){
                size = "Medium Size";
            } else {
                size = "Large Size";
            }
            cout << "Clothes Size: " << size << endl;
            cout << "Volume: " << volume << endl;
        }
};

int main(){
    Clothes shirt1, shirt2, pant1, pant2, pant3, tshirt1, tshirt2, tshirt3;
    shirt1.setData("Levis", "Shirt", "Blue", 9, 4, 1, 1500, 0.1);
    shirt2.setData("Peter England", "Shirt", "White", 5, 3, 1, 2000, 0.2);
    pant1.setData("Wrangler", "Pant", "Black", 6, 4, 2, 2000, 0.2);
    pant2.setData("Levis", "Pant", "Blue", 7, 4, 2, 2500, 0.25);
    pant3.setData("Peter England", "Pant", "Grey", 6, 4, 2, 3000, 0.3);
    tshirt1.setData("Puma", "T-Shirt", "White", 4, 2, 3, 1000, 0.15);
    tshirt2.setData("Nike", "T-Shirt", "Black", 1, 2, 1, 1200, 0.2);
    tshirt3.setData("Adidas", "T-Shirt", "Grey", 4, 5, 3, 1500, 0.25);

    cout << pant2.price + pant3.price << endl;
    //cout << pant2.discountedPrice() + pant3.discountedPrice() << endl;

    pant3.displayInfo();

    return 0;
}