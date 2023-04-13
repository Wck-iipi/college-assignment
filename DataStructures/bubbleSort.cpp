#include <iostream>

void optimizedBubbleSort(int array[], int arraySize) {
    bool flag;
    for (int pass = 0; pass < arraySize - 1; ++pass) {
        flag = false;
        for (int currentIndex = 0; currentIndex < arraySize - pass - 1; ++currentIndex) {
            int nextIndex = currentIndex + 1;
            int currentValue = array[currentIndex];
            int nextValue = array[nextIndex];

            if (currentValue > nextValue) {
                // Swap elements
                int temp = currentValue;
                array[currentIndex] = nextValue;
                array[nextIndex] = temp;
                flag = true;
            }
        }

        if (!flag) {
            break;
        }
    }
}

int main() {
    int numbers[] = {14, 1, 22, 3, 51, 23, 5221, 2, 8, 4, 1};
    int arraySize = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    optimizedBubbleSort(numbers, arraySize);

    std::cout << "Sorted array: ";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
