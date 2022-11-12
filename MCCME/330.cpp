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

    int studentCount;
    cin >> studentCount;

    int maxSum = 0;
    vector<pair<string, string>> res;
    for (int i = 0; i < studentCount; i++) {
        string surname, name;
        cin >> surname >> name;

        int sum = 0;
        for (int j = 0; j < 3; j++) {
            int mark;
            cin >> mark;
            sum += mark;
        }

        if (maxSum < sum) {
            maxSum = sum;
            res = { { surname, name } };
        } else if (maxSum == sum) {
            res.push_back({ surname, name });
        }
    }

    for (auto &[surname, name] : res)
        cout << surname << " " << name << "\n";
}