class ZeroEvenOdd {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    int state;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i = 1 ; i<=n ; ++i){
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock,[this](){
                return state == 0;
            });
            printNumber(0);
            state = (i%2==1)?1:2;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2 ; i<=n ; i+=2){
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock,[this](){
                return state==2;
            });
            printNumber(i);
            state = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1; i<=n ; i+=2){
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock,[this](){
                return state==1;
            });
            printNumber(i);
            state = 0;
            cv.notify_all();
        }
    }
};