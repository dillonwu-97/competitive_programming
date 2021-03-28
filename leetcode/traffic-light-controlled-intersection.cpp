class TrafficLight {
private:
    mutex m;
    int p = 1;
public:
    TrafficLight() {
    }
    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can 
            be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green 
            on current road
        function<void()> crossCar    // Use crossCar() to make car cross the 
            intersection
    ) {
        // cout << carId << " " << roadId << " " << direction << " " << endl;
        m.lock();
        if (p != roadId) {
            turnGreen();
        }   
        p = roadId;
        crossCar();
        m.unlock();
        // if ()
    }
};