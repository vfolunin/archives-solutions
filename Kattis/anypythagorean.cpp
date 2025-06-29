#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int perimeter;
    cin >> perimeter;

    for (int a = 1; a < perimeter; a++) {
        for (int b = a; b < perimeter; b++) {
            int c = perimeter - a - b;

            if (a * a + b * b == c * c) {
                cout << a << " " << b << " " << c;
                return 0;
            }
        }
    }

    cout << "0 0 0";
}