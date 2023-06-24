#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(vector<double> &a, vector<int> &used, double target, double &res) {
    for (int i = 0; i < a.size(); i++) {
        if (used[i])
            continue;
        
        if (abs(res - target) > abs(a[i] - target))
            res = a[i];

        for (int j = i + 1; j < a.size(); j++) {
            if (used[j])
                continue;

            used[i] = used[j] = 1;

            a.push_back(a[i] + a[j]);
            used.push_back(0);
            rec(a, used, target, res);

            a.back() = a[i] * a[j] / (a[i] + a[j]);
            rec(a, used, target, res);
            a.pop_back();
            used.pop_back();

            used[i] = used[j] = 0;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    double target;
    cin >> size >> target;

    vector<double> a(size);
    for (double &value : a)
        cin >> value;

    vector<int> used(size);
    double res = 0;
    rec(a, used, target, res);

    cout << fixed << res;
}