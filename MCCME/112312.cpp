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

    vector<int> fib = { 1, 1 };
    for (int i = 2; fib.back() <= 1e4; i++)
        fib.push_back(fib[i - 2] + fib[i - 1]);

    int size;
    cin >> size;

    bool found = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (binary_search(fib.begin(), fib.end(), value)) {
            cout << value << " ";
            found = 1;
        }
    }

    if (!found)
        cout << 0;
}