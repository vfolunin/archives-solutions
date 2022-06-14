class SeatManager {
    priority_queue<int, vector<int>, greater<int>> seats;
    
public:
    SeatManager(int n) {
        for (int seatNumber = 1; seatNumber <= n; seatNumber++)
            seats.push(seatNumber);
    }
    
    int reserve() {
        int seatNumber = seats.top();
        seats.pop();
        return seatNumber;
    }
    
    void unreserve(int seatNumber) {
        seats.push(seatNumber);
    }
};