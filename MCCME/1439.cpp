#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Student {
    string surname, name;
    long long sum = 0, count = 0;

    friend istream &operator >> (istream &in, Student &student) {
        in >> student.surname >> student.name >> student.count;
        for (int i = 0; i < student.count; i++) {
            int mark;
            in >> mark;
            student.sum += mark;
        }
        return in;
    }

    friend ostream &operator << (ostream &out, Student &student) {
        return out << student.surname << " " << student.name;
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

    int limit;
    cin >> limit;

    for (Student &student : students)
        if (student.sum >= student.count * limit)
            cout << student << "\n";
}