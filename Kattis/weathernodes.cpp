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

    int size;
    cin >> size;

    vector<double> a(size);
    double average = 0;
    for (double &value : a) {
        cin >> value;
        average += value;
    }
    average /= size;

    int res = 0;
    for (double &value : a)
        res += abs(value - average) > 10;
    
    cout << res;
}