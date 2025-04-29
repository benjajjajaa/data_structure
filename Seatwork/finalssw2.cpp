#include <iostream> 
using namespace std;

class CRectangle {
    int width, height;
public:
    void set_values(int, int);
    int area(void) { return (width * height); }
};

void CRectangle::set_values(int a, int b) {
    width = a;
    height = b;
}

int main() {
    CRectangle a, *b, *c;
    CRectangle* d = new CRectangle[2];

    b = new CRectangle; // Fixed typo: Crectangle -> CRectangle
    c = &a;

    a.set_values(1, 2);
    b->set_values(3, 4);
    d[0].set_values(5, 6); // Fixed: Correctly accessing the first element of the array
    d[1].set_values(7, 8);

    cout << "a area: " << a.area() << endl;
    cout << "*b area: " << b->area() << endl;
    cout << "*c area: " << c->area() << endl;
    cout << "d[0] area: " << d[0].area() << endl;
    cout << "d[1] area: " << d[1].area() << endl;

    delete[] d; // Free the dynamically allocated array
    delete b;   // Free the dynamically allocated object

    return 0;
}