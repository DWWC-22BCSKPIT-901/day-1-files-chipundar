#include <iostream>
using namespace std;

int main() {
    int n, count = 0;
    

    cout << "Enter a positive integer: ";
    cin >> n;
    
    if (n == 0) {
        count = 1;
    } else {
        while (n > 0) {
            n = n / 10; 
            count++;     
        }
    }

    cout << "The number of digits is: " << count << endl;

    return 0;
}
