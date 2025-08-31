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

    int size, step;
    cin >> size >> step;

    vector<int> a(size);
    iota(a.begin(), a.end(), 0);

    vector<int> res(size);
    for (int i = 1, pos = 0; !a.empty(); i++) {
        pos = (pos + step - 1) % a.size();
        res[a[pos]] = i;
        a.erase(a.begin() + pos);
        if (!a.empty())
            pos %= a.size();
    }

    for (int value : res)
        cout << value << " ";
}