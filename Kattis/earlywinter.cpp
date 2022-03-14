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

    int yearCount, curTime;
    cin >> yearCount >> curTime;

    for (int i = 0; i < yearCount; i++) {
        int yearTime;
        cin >> yearTime;

        if (yearTime <= curTime) {
            cout << "It hadn't snowed this early in " << i << " years!";
            return 0;
        }
    }

    cout << "It had never snowed this early!";
}