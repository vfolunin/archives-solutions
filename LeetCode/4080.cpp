class BusBooking {
    vector<vector<int>> time;
    int totalTime = 0, windowCount = 0, middleCount = 0;
    
public:
    BusBooking(int rowCount) : time(rowCount, vector<int>(4)) {}
    
    void toggle(const string &seat) {
        int y = stoi(seat.substr(1)) - 1, x = seat[0] - 'A';
        if (time[y][x]) {
            totalTime -= time[y][x];
            time[y][x] = 0;
            if (x == 0 || x == 3)
                windowCount--;
            else
                middleCount--;
        } else {
            if (x == 0 || x == 3) {
                time[y][x] = (time[y][x ^ 1] ? 3 : 1);
                windowCount++;
            } else {
                time[y][x] = 1;
                middleCount++;
            }
            totalTime += time[y][x];
        }
    }
    
    int getTotalTime() {
        return totalTime;
    }
    
    int getMinTime() {
        return windowCount + middleCount;
    }
};