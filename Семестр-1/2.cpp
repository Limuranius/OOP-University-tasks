#include <iostream>

int findNumberOfDividers(int num) {
    int count = 0;
    for (int i = 1; i <= num / 2; i++) {
        count += num % i == 0;
    }
    return count + 1;  // + 1, т. к. число делится само на себя
}

int main() {
    int i;
    int res = 0;
    int maxDividers = 0;
    int dividersCount;

    while (true) {
        std::cin >> i;
        if (i == 0) break;

        dividersCount = findNumberOfDividers(i);
        if (dividersCount > maxDividers) {
            maxDividers = dividersCount;
            res = i;
        }
    }

    std::cout << "Number with biggest number of dividers: " << res << '\n';
    std::cout << "Number of dividers: " << maxDividers << std::endl;
}