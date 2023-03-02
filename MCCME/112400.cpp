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
    int score, count = 0;
    while (cin >> surname >> name >> score)
        if (score > threshold)
            cout << ++count << ") " << name[0] << ". " << surname << "\n";

    cout << count;
}