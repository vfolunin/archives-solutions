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

    cout << "Please enter an even number:";

    int n;
    cin >> n;

    if (n % 2)
        cout << n << " isn't an even number.";
    else if (n)
        cout << "Thank you.";
    else
        cout << "0 is zero.";
}