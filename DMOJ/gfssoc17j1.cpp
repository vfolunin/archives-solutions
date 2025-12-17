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

    int size, sum;
    cin >> size >> sum;

    vector<string> names = { "TOK", "English", "Chemistry", "Math" };
    vector<int> a(size);
    for (int &value : a) {
        string name;
        cin >> name;

        value = find(names.begin(), names.end(), name) - names.begin() + 1;
    }

    sort(a.begin(), a.end());

    int res = 0;
    while (res < a.size() && sum >= a[res])
        sum -= a[res++];
    
    if (res == a.size())
        cout << "YEA BOI";
    else
        cout << "Go to Metro\n" << res;
}