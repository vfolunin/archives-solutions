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
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());
    do {
        bool ok = 1;
        for (int i = 0; i + 1 < a.size() && ok; i++)
            ok &= gcd(a[i], a[i + 1]) > 1;

        if (ok) {
            for (int value : a)
                cout << value << " ";
            return 0;
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << "Neibb";
}