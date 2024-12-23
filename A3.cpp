#include <iostream>
using namespace std;

double calculateArea(double radius) {
    return 3.14159 * radius * radius;
}

double calculateArea(double length, double width) {
    return length * width;
}

double calculateArea(double base, double height, bool isTriangle) {
    return 0.5 * base * height;
}

int main() {
    double radius, length, width, base, height;
    
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    cout << "Area of the circle: " << calculateArea(radius) << endl;

    cout << "Enter the length and width of the rectangle: ";
    cin >> length >> width;
    cout << "Area of the rectangle: " << calculateArea(length, width) << endl;

    cout << "Enter the base and height of the triangle: ";
    cin >> base >> height;
    cout << "Area of the triangle: " << calculateArea(base, height, true) << endl;

    return 0;
}
