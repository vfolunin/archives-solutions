#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void printS(int n) {
    if (n == 0) {
        cout << 0;
        return;
    }
    cout << "S(";
    printS(n - 1);
    cout << ")";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a >> b;

    printS(count(a.begin(), a.end(), 'S') * count(b.begin(), b.end(), 'S'));
}