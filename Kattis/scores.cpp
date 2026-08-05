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

    vector<double> a;
    for (double value; cin >> value; )
        a.push_back(value);

    if (a.size() < 3) {
        cout << "At least 3 scores needed!";
        return 0;
    }

    sort(a.begin(), a.end());
    double sum = 0;
    for (int i = 3; i < a.size(); i++)
        sum += a[i];

    cout.precision(1);
    cout << "Sum of scores (3 lowest removed): " << fixed << sum;
}