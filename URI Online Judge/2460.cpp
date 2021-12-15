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

    int initialQueueSize;
    cin >> initialQueueSize;

    vector<int> initialQueue(initialQueueSize);
    for (int &x : initialQueue)
        cin >> x;

    int leftCount;
    cin >> leftCount;

    set<int> left;
    for (int i = 0; i < leftCount; i++) {
        int x;
        cin >> x;
        left.insert(x);
    }

    vector<int> finalQueue;
    for (int x : initialQueue)
        if (!left.count(x))
            finalQueue.push_back(x);

    for (int i = 0; i < finalQueue.size(); i++)
        cout << finalQueue[i] << (i + 1 < finalQueue.size() ? " " : "\n");
}