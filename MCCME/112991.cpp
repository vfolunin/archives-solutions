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

    double whole = 0, num = 0, den = 1;
    cin >> num;
    if (cin.peek() == ' ') {
        whole = num;
        cin >> num;
    }
    if (cin.peek() == '/') {
        cin.ignore();
        cin >> den;
    }

    cout << fixed << (whole * den + num) / den;
}