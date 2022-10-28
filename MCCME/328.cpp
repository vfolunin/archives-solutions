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

    vector<double> sum(3);
    for (int i = 0; i < studentCount; i++) {
        string name;
        cin >> name >> name;

        for (int j = 0; j < sum.size(); j++) {
            int mark;
            cin >> mark;
            sum[j] += mark;
        }
    }

    for (double &s : sum)
        cout << fixed << s / studentCount << " ";
}