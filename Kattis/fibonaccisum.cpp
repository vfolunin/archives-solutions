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
    
    vector<int> fib = { 1, 2 };
    for (int i = 2; fib.back() < 1e9; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);

    int sum;
    cin >> sum;

    vector<int> res;
    for (int i = fib.size() - 1; i >= 0; i--) {
        while (sum >= fib[i]) {
            res.push_back(fib[i]);
            sum -= fib[i];
        }
    }

    reverse(res.begin(), res.end());

    for (int value : res)
        cout << value << " ";
}