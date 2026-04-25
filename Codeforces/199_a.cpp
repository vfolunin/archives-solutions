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

    int value;
    cin >> value;

    if (!value) {
        cout << "0 0 0";
        return 0;
    }

    vector<int> fib = { 0, 1, 1 };
    while (fib.back() < value)
        fib.push_back(fib[fib.size() - 2] + fib[fib.size() - 1]);

    cout << "0 " << fib[fib.size() - 3] << " " << fib[fib.size() - 2];
}