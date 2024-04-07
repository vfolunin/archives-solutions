#include <iostream>
#include <sstream>
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

    double sum = 0, count = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value % 2) {
            sum += value;
            count++;
        }
    }

    if (count) {
        stringstream ss;
        ss.precision(3);
        ss << fixed << sum / count;
        string res = ss.str();
        while (res[res.size() - 1] == '0' && res[res.size() - 2] != '.')
            res.pop_back();
        cout << res;
    } else {
        cout << "NO";
    }
}