#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Student {
    string surname, name;
    long long sum, count;

    friend istream &operator >> (istream &in, Student &s) {
        in >> s.surname >> s.name >> s.count;
        s.sum = 0;
        for (int i = 0; i < s.count; i++) {
            int value;
            cin >> value;
            s.sum += value;
        }
        return in;
    }

    friend ostream &operator << (ostream &out, Student &s) {
        return out << s.surname << " " << s.name;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int studentCount;
    cin >> studentCount;

    vector<Student> students(studentCount);
    for (Student &student : students)
        cin >> student;

    int threshold;
    cin >> threshold;

    for (Student &student : students)
        if (student.sum >= student.count * threshold)
            cout << student << "\n";
}