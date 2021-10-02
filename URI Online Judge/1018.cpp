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

    int n;
    cin >> n;

    vector<int> nominals = { 100, 50, 20, 10, 5, 2, 1 };

    cout << n << "\n";
    for (int nominal : nominals) {
        cout << n / nominal << " nota(s) de R$ " << nominal << ",00\n";
        n %= nominal;
    }
}