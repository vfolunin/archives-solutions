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

    int size, maxJump;
    cin >> size >> maxJump;

    vector<int> a(size);
    for (int i = 1; i + 1 < size; i++)
        cin >> a[i];

    vector<int> bonus(size, -1e9), from(size, -1);
    bonus[0] = 0;

    for (int i = 1; i < a.size(); i++) {
        for (int jump = 1; jump <= i && jump <= maxJump; jump++) {
            if (bonus[i] < bonus[i - jump] + a[i]) {
                bonus[i] = bonus[i - jump] + a[i];
                from[i] = i - jump;
            }
        }
    }

    vector<int> path;
    for (int i = a.size() - 1; i >= 0; i = from[i])
        path.push_back(i);
    reverse(path.begin(), path.end());

    cout << bonus.back() << "\n" << path.size() - 1 << "\n";
    for (int value : path)
        cout << value + 1 << " ";
}