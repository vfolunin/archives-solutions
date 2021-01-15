#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string toUpper(string s) {
    for (char &c : s)
        c = toupper(c);
    return s;
}

void solve() {
    string bucketName;
    cin.ignore();
    getline(cin, bucketName);
    cout << toUpper(bucketName) << "\n";

    int ingredientCount, recipeCount;
    long long money;
    cin >> ingredientCount >> recipeCount >> money;

    map<string, long long> price;
    for (int i = 0; i < ingredientCount; i++) {
        string ingredientName;
        cin >> ingredientName >> price[ingredientName];
    }

    vector<pair<long long, string>> recipes;
    for (int i = 0; i < recipeCount; i++) {
        string recipeName;
        cin.ignore();
        getline(cin, recipeName);

        int positionCount;
        cin >> positionCount;

        long long recipeCost = 0;
        for (int j = 0; j < positionCount; j++) {
            string ingredientName;
            long long amount;
            cin >> ingredientName >> amount;
            recipeCost += price[ingredientName] * amount;
        }

        if (recipeCost <= money)
            recipes.push_back({ recipeCost, recipeName });
    }

    if (recipes.empty()) {
        cout << "Too expensive!\n";
    } else {
        sort(recipes.begin(), recipes.end());
        for (auto &[_, recipeName] : recipes)
            cout << recipeName << "\n";
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}