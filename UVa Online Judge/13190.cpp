#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int drugCount, iterCount;
    cin >> drugCount >> iterCount;

    vector<string> name(drugCount);
    vector<int> frequency(drugCount);
    set<pair<int, int>> queue;
    
    for (int i = 0; i < drugCount; i++) {
        cin >> name[i] >> frequency[i];
        queue.insert({ frequency[i], i });
    }

    for (int i = 0; i < iterCount; i++) {
        auto [time, index] = *queue.begin();
        queue.erase(queue.begin());
        cout << time << " " << name[index] << "\n";
        queue.insert({ time + frequency[index], index });
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}