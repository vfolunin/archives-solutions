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

    int a, b;
    char c;
    cin >> a >> c >> b;

    if (a < b)
        cout << "<";
    else if (a > b)
        cout << ">";
    else
        cout << "Goggi svangur!";
}