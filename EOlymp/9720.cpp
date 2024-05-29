#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    set<string> students;
    unordered_map<string, set<string>> studentsOf, subjectsOf;

    for (int i = 0; i < size; i++) {
        string subject, student;
        cin >> subject >> student;

        students.insert(student);
        studentsOf[subject].insert(student);
        subjectsOf[student].insert(subject);
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string arg;
        cin >> arg;

        for (const string &s : students.count(arg) ? subjectsOf[arg] : studentsOf[arg])
            cout << s << " ";
        cout << "\n";
    }
}