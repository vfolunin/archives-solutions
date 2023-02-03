class TrafficLight {
    mutex m;
    bool greenA = 1;

public:
    void carArrived(int id, int from, int to, function<void()> turnGreen, function<void()> crossCar) {
        lock_guard<mutex> guard(m);
        if ((from <= 1) ^ greenA) {
            turnGreen();
            greenA ^= 1;
        }
        crossCar();
    }
};