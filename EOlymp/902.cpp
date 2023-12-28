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

    int n;
    cin >> n;

    if (n <= 3)
        cout << "Initial";
    else if (n <= 6)
        cout << "Average";
    else if (n <= 9)
        cout << "Sufficient";
    else
        cout << "High";
}