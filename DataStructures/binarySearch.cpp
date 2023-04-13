#include <iostream>

int binarySearch(int sortedArray[], int arraySize, int target) {
    int leftIndex = 0;
    int rightIndex = arraySize - 1;

    while (leftIndex <= rightIndex) {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
        int middleValue = sortedArray[middleIndex];

        if (middleValue == target) {
            return middleIndex;
        } else if (middleValue < target) {
            leftIndex = middleIndex + 1;
        } else {
            rightIndex = middleIndex - 1;
        }
    }

    return -1;
}

int main() {
    int numbers[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int arraySize = sizeof(numbers) / sizeof(numbers[0]);
    int target = 12;

    int resultIndex = binarySearch(numbers, arraySize, target);

    if (resultIndex != -1) {
        std::cout << "Target " << target << " found at index " << resultIndex << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the array." << std::endl;
    }

    return 0;
}
