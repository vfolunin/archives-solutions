#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int participantCount, overtakeCount;
    cin >> participantCount >> overtakeCount;

    unordered_set<int> behind;
    int res = 0;
    for (int i = 0; i < overtakeCount; i++) {
        int participant;
        cin >> participant;

        if (participant > 0) {
            if (behind.count(participant)) {
                res++;
                behind.clear();
            }
            behind.insert(participant);
        } else {
            behind.erase(-participant);
        }
    }

    cout << res;
}