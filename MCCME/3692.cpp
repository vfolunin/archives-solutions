#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPoint() {
    char c;
    cin >> c;

    int shift = 0;
    if (cin.peek() == '1') {
        cin.get();
        shift = 4;
    }

    static vector<vector<int>> points = {
        { 0, 0, 0 }, { 0, 0, 2 }, { 0, 2, 2 }, { 0, 2, 0 },
        { 2, 0, 0 }, { 2, 0, 2 }, { 2, 2, 2 }, { 2, 2, 0 }
    };

    return points[c - 'A' + shift];
}

vector<vector<int>> getPoints() {
    vector<int> a = getPoint();
    vector<int> b = getPoint();

    vector<int> c(3);
    for (int i = 0; i < c.size(); i++)
        c[i] = (a[i] + b[i]) / 2;

    return { a, b, c };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> a = getPoints();
    vector<vector<int>> b = getPoints();

    for (vector<int> &pa : a) {
        for (vector<int> &pb : b) {
            if (pa == pb) {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
}