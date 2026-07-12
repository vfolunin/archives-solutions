class Solution {
    int toSeconds(string &time) {
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        int s = stoi(time.substr(6, 2));
        return (h * 60 + m) * 60 + s;
    }
    
public:
    int secondsBetweenTimes(string &time1, string &time2) {
        return toSeconds(time2) - toSeconds(time1);
    }
};