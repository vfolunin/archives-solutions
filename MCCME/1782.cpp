#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Gnome {
    int index, careTime, sleepTime;

    bool operator < (const Gnome &that) const {
        return careTime + sleepTime > that.careTime + that.sleepTime;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int gnomeCount;
    cin >> gnomeCount;

    vector<Gnome> gnomes(gnomeCount);
    int totalCareTime = 0;

    for (int i = 0; i < gnomes.size(); i++) {
        gnomes[i].index = i;
        cin >> gnomes[i].careTime;
        totalCareTime += gnomes[i].careTime;
    }
    for (auto &[index, careTime, sleepTime] : gnomes)
        cin >> sleepTime;

    sort(gnomes.begin(), gnomes.end());

    for (int i = 0; i < gnomes.size(); i++) {
        totalCareTime -= gnomes[i].careTime;
        if (gnomes[i].sleepTime <= totalCareTime) {
            cout << -1;
            return 0;
        }
    }

    for (auto &[index, careTime, sleepTime] : gnomes)
        cout << index + 1 << " ";
}