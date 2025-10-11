#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    iota(a.begin(), a.end(), 1);

    while (a.size() > 1) {
        vector<int> nextA;
        for (int i = 0; i < a.size(); i += 2) {
            int winner;
            cin >> winner;

            nextA.push_back(a[i + winner - 1]);
        }
        a.swap(nextA);
    }

    cout << a[0];
}