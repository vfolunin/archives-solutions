#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int studentCount, dispenseLimit;
    cin >> studentCount >> dispenseLimit;

    if (!studentCount)
        return 0;

    queue<int> studentQueue;
    for (int i = 0; i < studentCount; i++)
        studentQueue.push(i);

    vector<int> studentMoney(studentCount), studentOrder;
    int storeMoney = 0, dispenseAmount = 1;

    while (!studentQueue.empty()) {
        int studentIndex = studentQueue.front();
        studentQueue.pop();

        if (!storeMoney) {
            storeMoney = dispenseAmount;
            dispenseAmount++;
            if (dispenseAmount > dispenseLimit)
                dispenseAmount = 1;
        }

        int takenMoney = min(40 - studentMoney[studentIndex], storeMoney);
        studentMoney[studentIndex] += takenMoney;
        storeMoney -= takenMoney;

        if (studentMoney[studentIndex] == 40)
            studentOrder.push_back(studentIndex);
        else
            studentQueue.push(studentIndex);
    }

    for (int studentIndex : studentOrder)
        cout << setw(3) << studentIndex + 1;
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}