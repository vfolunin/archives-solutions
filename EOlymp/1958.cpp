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

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int divisor;
    cin >> divisor;

    int remainder = 0;
    for (int value : a)
        remainder = (remainder * 10 + value) % divisor;

    cout << (remainder ? "NO" : "YES");
}