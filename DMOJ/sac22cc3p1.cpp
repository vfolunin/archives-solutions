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

    int a, b, size;
    cin >> a >> b >> size;

    for (int i = 0; i < size; i++) {
        a -= b;
        cout << a << "\n";
    }
}