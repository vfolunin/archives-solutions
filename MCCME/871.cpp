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
  
    vector<int> a(3);
    for (int &value : a)
        cin >> value;

    vector<int> b(3);
    for (int &value : b)
        cin >> value;
    sort(b.begin(), b.end());

    int res = 0;
    do {
        int product = 1;
        for (int i = 0; i < a.size(); i++)
            product *= a[i] / b[i];
        res = max(res, product);
    } while (next_permutation(b.begin(), b.end()));

    cout << res;
}