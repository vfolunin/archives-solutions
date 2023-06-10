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
    iota(a.begin(), a.end(), 1);

    int pos = 0;
    while (a.size() > 1) {
        pos = (pos + step - 1) % a.size();
        a.erase(a.begin() + pos);
    }

    cout << a[0];
}