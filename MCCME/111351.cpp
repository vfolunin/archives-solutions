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

    map<int, int> count;

    string name;
    int form, score;
    while (cin >> name >> name >> form >> score)
        count[form]++;

    vector<int> forms;
    for (auto &[form, count] : count)
        forms.push_back(form);
    stable_sort(forms.begin(), forms.end(), [&](int a, int b) {
        return count[a] > count[b];
    });

    for (int form : forms)
        cout << form << " ";
}