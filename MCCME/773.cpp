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

    int delta = b - a;
    for (int i = 0; i < size; i++) {
        cout << a << " ";
        a += delta;
    }
}