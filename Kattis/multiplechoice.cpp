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

    int questionCount;
    cin >> questionCount;

    string answers(questionCount, ' ');
    for (char &answer : answers)
        cin >> answer;

    int studentCount;
    cin >> studentCount;

    vector<pair<int, int>> students(studentCount);
    for (auto &[id, score] : students) {
        cin >> id;

        for (char answer : answers) {
            char studentAnswer;
            cin >> studentAnswer;

            score += studentAnswer == answer;
        }
    }

    string sortType;
    cin >> sortType;

    if (sortType == "STUDENT_ID_ASC") {
        sort(students.begin(), students.end(), [](auto &a, auto &b) {
            return a.first < b.first;
        });
    } else if (sortType == "STUDENT_ID_DESC") {
        sort(students.begin(), students.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });
    } else if (sortType == "GRADE_ASC") {
        sort(students.begin(), students.end(), [](auto &a, auto &b) {
            if (a.second != b.second)
                return a.second < b.second;
            return a.first < b.first;
        });
    } else {
        sort(students.begin(), students.end(), [](auto &a, auto &b) {
            if (a.second != b.second)
                return a.second > b.second;
            return a.first < b.first;
        });
    }

    for (auto &[id, score] : students)
        cout << id << " " << score << "\n";
}