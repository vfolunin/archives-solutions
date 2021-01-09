#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Elephant {
    int weight, iq, index;

    bool operator < (const Elephant &that) const {
        return weight < that.weight;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<Elephant> elephants;
    int weight, iq;
    for (int index = 1; cin >> weight >> iq; index++)
        elephants.push_back({ weight, iq, index });
    sort(elephants.begin(), elephants.end());

    vector<int> lisLength(elephants.size(), 1);
    vector<int> prev(elephants.size(), -1);
    for (int i = 0; i < elephants.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (elephants[j].weight < elephants[i].weight &&
                elephants[j].iq > elephants[i].iq &&
                lisLength[j] + 1 > lisLength[i]) {
                lisLength[i] = lisLength[j] + 1;
                prev[i] = j;
            }
        }
    }

    int last = max_element(lisLength.begin(), lisLength.end()) - lisLength.begin();
    cout << lisLength[last] << "\n";

    vector<int> path;
    for (; last != -1; last = prev[last])
        path.push_back(last);
    reverse(path.begin(), path.end());

    for (int i : path)
        cout << elephants[i].index << "\n";
}