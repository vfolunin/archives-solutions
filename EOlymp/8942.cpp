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

    int w;
    cin >> w;

    cout << string(w, '*') << "\n";
    cout << "*" << string(w - 2, ' ') << "*\n";
    cout << string(w, '*') << "\n";
}