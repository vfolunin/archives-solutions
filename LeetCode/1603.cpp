class ParkingSystem {
    vector<int> count, limit;
    
public:
    ParkingSystem(int big, int medium, int small) {
        count.assign(3, 0);
        limit = { big, medium, small };
    }
    
    bool addCar(int carType) {
        carType--;
        if (count[carType] == limit[carType])
            return 0;
        count[carType]++;
        return 1;
    }
};