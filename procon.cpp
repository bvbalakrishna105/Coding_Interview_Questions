#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

const int MaxItems = 10; // Maximum number of items the buffer can hold

queue<int> buffer; // Shared buffer
mutex mtx; // Mutex for critical section
condition_variable cvProducer, cvConsumer; // Condition variables for signaling

// Producer function
void producer() {
    for (int i = 1; i <= MaxItems; ++i) {
        unique_lock<mutex> lock(mtx);
        cvProducer.wait(lock, [] { return buffer.size() < MaxItems; }); // Wait if buffer is full

        buffer.push(i);
        cout << "Produced item: " << i << endl;
        lock.unlock();
        cvConsumer.notify_one(); // Notify consumer that an item is available
    }
}

// Consumer function
void consumer() {
    for (int i = 1; i <= MaxItems; ++i) {
        unique_lock<mutex> lock(mtx);
        cvConsumer.wait(lock, [] { return !buffer.empty(); }); // Wait if buffer is empty

        int item = buffer.front();
        buffer.pop();
        cout << "Consumed item: " << item << endl;
        lock.unlock();
        cvProducer.notify_one(); // Notify producer that space is available in buffer
    }
}

int main() {
    thread producerThread(producer);
    thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}
