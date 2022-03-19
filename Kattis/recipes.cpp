#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Item {
    string name;
    double weight;
    double percentage;
};

void solve(int test) {
    int itemCount, den, num;
    cin >> itemCount >> den >> num;

    vector<Item> items(itemCount);
    double baseWeight;
    for (auto &[name, weight, percentage] : items) {
        cin >> name >> weight >> percentage;
        if (percentage == 100)
            baseWeight = weight;
    }
    baseWeight = baseWeight * num / den;

    cout << "Recipe # " << test << "\n";
    for (auto &[name, weight, percentage] : items) {
        cout.precision(1);
        cout << name << " " << fixed << baseWeight * percentage / 100 << "\n";
    }
    cout << string(40, '-') << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}