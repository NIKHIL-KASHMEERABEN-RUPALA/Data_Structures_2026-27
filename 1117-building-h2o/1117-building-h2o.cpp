class H2O {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int h_count;
public:
    H2O() : h_count(0){}

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(mtx);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        cv.wait(lock,[this](){
            return h_count < 2;
        });
        releaseHydrogen();
        h_count++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[this](){
            return h_count==2;
        });

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        h_count = 0;
        cv.notify_all();
    }
};