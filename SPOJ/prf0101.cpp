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

    cout << "Please enter any integer: ";
    int n;
    cin >> n;

    if (n > 0)
        cout << n << " is a positive number";
    else if (n < 0)
        cout << n << " is a negative number";
    else
        cout << "The number entered is zero";
}