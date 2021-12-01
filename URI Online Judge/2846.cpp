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
    for (int i = 2; fib.back() < 1.1e5; i++)
        fib.push_back(fib[i - 2] + fib[i - 1]);

    vector<int> notFib;
    for (int i = 4; i < 1.1e5; i++)
        if (!binary_search(fib.begin(), fib.end(), i))
            notFib.push_back(i);

    int n;
    cin >> n;

    cout << notFib[n - 1] << "\n";
}