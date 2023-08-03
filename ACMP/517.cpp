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
 
    vector<int> a(size);
    for (int &value : a)
        cin >> value;
 
    int res = 0;
    for (int i = 0, round = 1, ball = 1; i < a.size(); i++) {
        res += a[i];
 
        if (a[i] == 10 && round < 10 && ball == 1) {
            res += a[i + 1] + a[i + 2];
            round++;
        } else if (ball == 2) {
            if (a[i - 1] + a[i] == 10 && round < 10)
                res += a[i + 1];
            round++;
            ball = 1;
        } else {
            ball++;
        }
    }
 
    cout << res;
}