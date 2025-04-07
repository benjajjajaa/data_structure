#include <iostream>
#include <string>
using namespace std;

class Cars{
    private:
        string company_name;
        string model_name;
        string fuel_type;
        float mileage;
        double price;
        double discount;

    public:
        void setData(string cname, string mname, string ftype, float m, double p, double d){
            company_name = cname;
            model_name = mname;
            fuel_type = ftype;
            mileage = m;
            price = p;
            discount = d;
        }

        void displayData(){
            cout << "Car Properties" << endl;
            cout << "Company Name: " << company_name << endl;
            cout << "Model Name: " << model_name << endl;
            cout << "Fuel Type: " << fuel_type << endl;
            cout << "Mileage (km per litre): " << mileage << endl;
            cout << "Price: " << price << endl;
        }

        void calculateDiscount(){
            double discounted_price = price - (discount * price);
            cout << "Discounted Price: " << discounted_price << endl;
        }

        double discountedPrice(){
            double discounted_price = price - (discount * price);
            return discounted_price;
        }

};

int main(){
    Cars car1, car2, car3;
    car1.setData("Toyota", "Fortuner", "Petrol", 10.5, 3500000, 0.1);
    car2.setData("Maruti", "Swift", "Diesel", 20.5, 800000, 0.2);
    car3.setData("Hyundai", "Creta", "Petrol", 15.5, 1200000, 0.15);
    
    //cout << (car1.price - (car1.discount * car1.price)) + (car2.price - (car2.discount * car2.price)) << endl;

    cout << car1.discountedPrice() + car2.discountedPrice() << endl;
    return 0;
}