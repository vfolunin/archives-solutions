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
    while (cin >> a) {
        if (cin >> b)
            cout << b << " ";
        cout << a << " ";
    }
}