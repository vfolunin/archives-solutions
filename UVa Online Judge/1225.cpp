#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> k(10001, vector<int>(10));
    for (int i = 1; i < k.size(); i++) {
        k[i] = k[i - 1];
        for (int val = i; val; val /= 10)
            k[i][val % 10]++;
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        for (int digit = 0; digit < 10; digit++)
            cout << k[val][digit] << (digit < 9 ? ' ' : '\n');
    }
}