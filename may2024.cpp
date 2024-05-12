#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>

using namespace std;

const int BUFFER_SIZE = 5;  // Size of the buffer
const int MAX_NUM = 20;

mutex mtx;  // Mutex  for critical sections

condition_variable cv_producer, cv_consumer; // Condition variables for synchronization

queue<int> buffer; // Shared buffer

void producer() {

    for (int i = 0; i < 10; ++i) {
        unique_lock<mutex> lock(mtx);
        // Wait if buffer is full
        cv_producer.wait(lock, []{return buffer.size() < BUFFER_SIZE; });

        int item = rand() % 100; // Producer an item

        buffer.push(item);

        cout << "Produced : " << item << endl;

        cv_consumer.notify_one();  // Notify consumer

    }
} 

void consumer() {
    
    for (int i = 0; i < 10; ++i) {
        unique_lock<mutex> lock(mtx);
        // Wait if buffer is empty
        cv_consumer.wait(lock, []{return !buffer.empty(); });

        int item = buffer.front();

        buffer.pop();

        cout << "Consumed : " << item << endl;

        cv_producer.notify_one();  // Notify producer

    }
}

void exampleProducerConsumer() {

    thread  producer_thread(producer);
    thread  consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

}

condition_variable cv; // Condition variable for synchronization
bool is_even = true; // Flag to indicate whether the next number to print should be even or odd 

void print_even() {

    for (int i = 2; i <= MAX_NUM; i +=2 ) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []{return is_even;}); // Wait until it's the turn to print even number
        cout << "Even : " << i << endl;
        is_even = false; // Set flag for next turn
        cv.notify_one(); // Notify waiting thread
    }
}

void print_odd() {

    for (int i = 1; i <= MAX_NUM; i +=2 ) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []{return !is_even;}); // Wait until it's the turn to print even number
        cout << "Odd : " << i << endl;
        is_even = true; // Set flag for next turn
        cv.notify_one(); // Notify waiting thread
    }
}

void examplePrintEvenOdd() {

    
    thread odd_thread(print_odd);
    thread even_thread(print_even);

    even_thread.join();
    odd_thread.join();

}

int main() {

    exampleProducerConsumer();
    examplePrintEvenOdd();

    return 0;
}