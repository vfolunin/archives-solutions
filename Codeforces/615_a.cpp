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

    int buttonCount, lampCount;
    cin >> buttonCount >> lampCount;

    vector<int> isOn(lampCount);
    for (int i = 0; i < buttonCount; i++) {
        int enabledLampCount;
        cin >> enabledLampCount;

        for (int j = 0; j < enabledLampCount; j++) {
            int lamp;
            cin >> lamp;

            isOn[lamp - 1] = 1;
        }
    }

    cout << (find(isOn.begin(), isOn.end(), 0) == isOn.end() ? "YES" : "NO");
}