class RideSharingSystem {
    unordered_set<int> availableRiders;
    queue<int> riderQ, driverQ;

    void removeUnavailableRiders() {
        while (!riderQ.empty() && !availableRiders.count(riderQ.front()))
            riderQ.pop();
    }

public:
    void addDriver(int driverId) {
        driverQ.push(driverId);
    }

    void addRider(int riderId) {
        availableRiders.insert(riderId);
        riderQ.push(riderId);
    }
    
    vector<int> matchDriverWithRider() {
        removeUnavailableRiders();
        
        if (driverQ.empty() || riderQ.empty())
            return { -1, -1 };

        vector<int> res = { driverQ.front(), riderQ.front() };
        availableRiders.erase(riderQ.front());
        riderQ.pop();
        driverQ.pop();
        return res;
    }
    
    void cancelRider(int riderId) {
        availableRiders.erase(riderId);
    }
};