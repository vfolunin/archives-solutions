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

    int threshold;
    cin >> threshold;

    string surname, name;
    int points, count = 0;
    while (cin >> surname >> name >> points)
        if (points > threshold)
            cout << ++count << ") " << surname << " " << name << "\n";

    cout << count;
}