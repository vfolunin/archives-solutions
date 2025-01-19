#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Date {
    int day, month, year;

    bool operator != (const Date &that) const {
        return day != that.day || month != that.month || year != that.year;
    }

    bool operator < (const Date &that) const {
        if (year != that.year)
            return year < that.year;
        if (month != that.month)
            return month < that.month;
        return day < that.day;
    }

    Date operator + (int years) {
        return { day, month, year + years };
    }
};

istream &operator >> (istream &in, Date &date) {
    return in >> date.day >> date.month >> date.year;
}

struct Event {
    Date date;
    enum { END, BEGIN } type;
    int index;

    bool operator < (const Event &that) const {
        if (date != that.date)
            return date < that.date;
        return type < that.type;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int segmentCount;
    cin >> segmentCount;

    vector<Event> events;
    for (int i = 0; i < segmentCount; i++) {
        Date l, r;
        cin >> l >> r;
        if (l + 18 < r) {
            events.push_back({ l + 18, Event::BEGIN, i });
            events.push_back({ min(l + 80, r), Event::END, i });
        }
    }

    sort(events.begin(), events.end());

    set<int> segments;
    bool found = 0;
    for (auto it = events.begin(); it != events.end(); it++) {
        auto &[date, type, index] = *it;

        if (type == Event::BEGIN) {
            segments.insert(index);

            if (next(it) != events.end() && next(it)->type == Event::END) {
                for (int index : segments)
                    cout << index + 1 << " ";
                cout << "\n";
                found = 1;
            }
        } else {
            segments.erase(index);
        }
    }

    if (!found)
        cout << 0;
}