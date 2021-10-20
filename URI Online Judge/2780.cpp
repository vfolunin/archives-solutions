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

    if (n <= 800)
        cout << "1\n";
    else if (n <= 1400)
        cout << "2\n";
    else
        cout << "3\n";
}