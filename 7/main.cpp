#include <thread>
#include <iostream>
#include <chrono>
#include <vector>
#include <atomic>

typedef std::chrono::high_resolution_clock Clock;

int VECTOR_SIZE = 10000000;

void parallelArraySum(const std::vector<int> & arr, std::atomic_llong & result, int index, int step, std::atomic_int & threadsDone) {
    for (int i = index; i < arr.size(); i += step) {
        result += arr[i];
    }
    threadsDone++;
}

int main() {
    std::vector<int> arr(VECTOR_SIZE);
    srand(time(nullptr));
    for (int i = 0; i < VECTOR_SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    {
        std::cout << "Parallel sum:\n";
        auto start = Clock::now();

        std::atomic_llong result(0);
        std::atomic_int threadsDone(0);
        unsigned int count = std::thread::hardware_concurrency();
        for (int i = 0; i < count; i++) {
            std::thread t(parallelArraySum, std::ref(arr), std::ref(result), i, count, std::ref(threadsDone));
            t.detach();
        }
        while (threadsDone != count);

        auto end = Clock::now();
        long long duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << "Result: " << result << "\nDuration: " << duration << " microseconds\n\n";
    }

    {
        std::cout << "Linear sum:\n";
        auto start = Clock::now();

        long long result = 0;
        for (int i = 0; i < VECTOR_SIZE; i++) {
            result += arr[i];
        }

        auto end = Clock::now();
        long long duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << "Result: " << result << "\nDuration: " << duration << " microseconds\n\n";
    }
}