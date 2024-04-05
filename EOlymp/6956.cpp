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

    vector<int> count(12);
    for (int i = 0; i < size; i++) {
        int id, day, month, year;
        char slash;
        cin >> id >> day >> slash >> month >> slash >> year;
        count[month - 1]++;
    }

    for (int i = 0; i < count.size(); i++)
        cout << i + 1 << " " << count[i] << "\n";
}