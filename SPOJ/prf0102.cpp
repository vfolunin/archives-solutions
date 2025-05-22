#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout << "Please enter any number: ";

    double n;
    cin >> n;

    if (n > 0)
        cout << "Square root of " << fixed << n << " is " << sqrt(n);
    else
        cout << "Accept positive number only!";
}