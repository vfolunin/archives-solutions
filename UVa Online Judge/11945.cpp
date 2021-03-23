#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    double average = 0;
    for (int i = 0; i < 12; i++) {
        double x;
        cin >> x;
        average += x;
    }
    average /= 12;

    stringstream ss;
    ss.precision(2);
    ss << fixed << average;
    string res = ss.str();

    cout << test << " $";
    for (int i = 0; i < res.size(); i++) {
        if (i && res.size() - i > 3 && (res.size() - i) % 3 == 0)
            cout << ",";
        cout << res[i];        
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}