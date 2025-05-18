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

    cout << "Please enter an odd number:";

    int n;
    cin >> n;

    if (!n)
        cout << "0 is zero.";
    else if (n % 2 == 0)
        cout << n << " isn't an odd number.";
    else
        cout << "Thank you.";
}