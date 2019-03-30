#include <bits/stdc++.h>

using namespace std;

int main() {
    long long x = 123456789123456789LL; // LL means type is long long. 64-bit int
    cout << x << "\n";

    int a = 123456789;
    long long b = (long long) a * a; // cast to get correct answer, because answer doesn't fit in int type
    cout << b << "\n";

    // use modular arithmetic when mod of large number is asked
    int n, m;
    cout << "enter n and m for n! mod m : ";
    cin >> n >> m;

    // finding n! mod m.
    x = 1;
    for (int i = 2; i <= n; i++) {
        x = (x * i) % m;
        cout << x << "\n";
    }
    cout << n << "! mod " << m << " = " << x % m << "\n";

    // make remainder positive if taking mod of negative number. it is only needed when subtracting the numbers
//    x = x % m;
//    if (x < 0) x += m;

    // float numbers
    double third = 1.0/3; // 64-bit
    long double t = 1.0/3; // 80-bit extension in g++

    printf("third: %f\n", third);
    printf("value of third with 9 decimal places: %.9f\n", third);

    // some numbers cannot be represented accurately due to rounding error
    double y = 0.3 * 3 + 0.1;
    printf("%.20f\n", y);

    // float values should not be compared with ==
    // assume equal, if difference between two numbers is less than 1e-9
    if (abs(y - third) < 1e-9) {
        // y and third are equal
    }
}
