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

    if (n <= 0)
        cout << "E\n";
    else if (n <= 35)
        cout << "D\n";
    else if (n <= 60)
        cout << "C\n";
    else if (n <= 85)
        cout << "B\n";
    else
        cout << "A\n";
}