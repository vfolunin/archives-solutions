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
    cin >> size >> size;

    vector<int> count(1000);
    for (int i = 0; i < size; i++) {
        int day, hour, duration;
        cin >> day >> day >> hour >> duration;

        for (int j = 0; j < duration; j++)
            count[day * 24 + hour + j]++;
    }

    int i = max_element(count.begin(), count.end()) - count.begin();

    cout << count[i] << " " << i / 24;
}