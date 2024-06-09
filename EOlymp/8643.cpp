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

    string start, finish;
    cin >> start >> finish;

    int d1 = abs(start[0] - finish[0]);
    int d2 = abs(start[1] - finish[1]);
    if (d1 > d2)
        swap(d1, d2);

    cout << d1 << " " << d2;
}