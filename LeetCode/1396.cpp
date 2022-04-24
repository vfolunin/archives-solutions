class UndergroundSystem {
    map<pair<string, string>, int> sum, count;
    unordered_map<int, pair<string, int>> in;
    
public:    
    void checkIn(int id, string startStation, int startTime) {
        in[id] = { startStation, startTime };
    }
    
    void checkOut(int id, string endStation, int endTime) {
        auto [startStation, startTime] = in[id];
        pair<string, string> route = { startStation, endStation };
        sum[route] += endTime - startTime;
        count[route]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<string, string> route = { startStation, endStation };
        return (double)sum[route] / count[route];
    }
};