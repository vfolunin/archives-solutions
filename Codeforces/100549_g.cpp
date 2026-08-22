#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("pwgen.in", "r", stdin);
    freopen("pwgen.out", "w", stdout);

    int size, a, b;
    cin >> size >> a >> b;

    for (int i = 0; i < a; i++)
        cout << (i % 2 ? "B" : "A");
    for (int i = 0; i < b; i++)
        cout << (i % 2 ? "b" : "a");
    for (int i = a + b; i < size; i++)
        cout << i % 2;
}