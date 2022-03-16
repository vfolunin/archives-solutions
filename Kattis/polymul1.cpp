#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int aDegree;
    cin >> aDegree;

    vector<int> a(aDegree + 1);
    for (int &coeff : a)
        cin >> coeff;

    int bDegree;
    cin >> bDegree;

    vector<int> b(bDegree + 1);
    for (int &coeff : b)
        cin >> coeff;


    vector<int> res(aDegree + bDegree + 1);
    for (int ai = 0; ai <= aDegree; ai++)
        for (int bi = 0; bi <= bDegree; bi++)
            res[ai + bi] += a[ai] * b[bi];
    
    cout << res.size() - 1 << "\n";
    for (int coeff : res)
        cout << coeff << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}