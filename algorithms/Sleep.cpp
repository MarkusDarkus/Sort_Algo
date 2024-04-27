#include "Sleep.h"

#include <vector>
#include <thread>
#include <format>

// This is the function that will be run by individual threads
void SleepAndPrint(int n) {
    // replace seconds with minutes for maximum efficiency
    std::this_thread::sleep_for(std::chrono::seconds(n));
    // C++ now has a format() function similar to Python
    // std::cout << std::format("{}, ", n);             // типа закинул, похуй
}

void sleepSort(std::vector<int> &data) {
    // a vector to store threads
    std::vector<std::thread> threads;

    for (int n: data) {
        // spawn a new thread that will run SleepAndPrint with arguement n
        std::thread t{SleepAndPrint, n};

        // Add thread to the vector
        // threads can only be moved, and not copied
        // we do not join now as it will stall the spawning of new threads
        threads.push_back(std::move(t));
    }

    // now join all the threads
    for (auto &t: threads) {
        // A thread may already be done by the time we get here, so check for that first
        if (t.joinable()) {
            t.join();
        }
    }
}
