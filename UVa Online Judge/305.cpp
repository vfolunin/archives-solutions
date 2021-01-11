#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool simulate(int n, int k) {
    vector<int> v;
    for (int i = 0; i < 2 * n; i++)
        v.push_back(i);

    int pos = 0;
    while (v.size() > n) {
        pos = (pos + k - 1) % v.size();
        v.erase(v.begin() + pos);
    }

    return *max_element(v.begin(), v.end()) == n - 1;
}

int precalc(int n) {
    int k = 1;
    while (!simulate(n, k))
        k++;
    return k;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //for (int i = 1; i <= 13; i++)
    //    cout << precalc(i) << " ";

    int answer[] = { 0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881 };

    while (1) {
        int n;
        cin >> n;

        if (n)
            cout << answer[n] << "\n";
        else
            break;
    }
}