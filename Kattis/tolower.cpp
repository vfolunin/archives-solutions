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

    int problemCount, testCount;
    cin >> problemCount >> testCount;

    int res = 0;
    for (int i = 0; i < problemCount; i++) {
        bool ok = 1;
        for (int j = 0; j < testCount; j++) {
            string test;
            cin >> test;
            for (int k = 1; k < test.size(); k++)
                ok &= (bool)islower(test[k]);
        }
        res += ok;
    }
    
    cout << res;
}