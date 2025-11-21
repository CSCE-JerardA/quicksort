// Copyright 2025 Jerard A

#include <vector>
#include <iostream>
#include <algorithm>

// Function prototypes
void median_of_three(std::vector<float>$arr, int left, int right)
int partition(std::vector<float>$arr, int left, int right)
void quicksort(std::vector<float>$arr, int left, int right)


// Creates median of three implementation
void median_of_three(std::vector<float>$arr, int left, int right) {

    if (right - left < 2) {
        return;
    }
    // The formula for the median of three method while establishing mid 
    int mid = left + (right - left) / 2;

    // If the left is greater than the right, swap positions of left and right
    if (arr[left] > arr[right]) {
        std::swap(arr[left], arr[right]);
    }
    // If the mid greater than the right, swap the position of mid and right
    if (arr[mid] > arr[right]) {
        std::swap(arr[mid], arr[right]);
    }
    // If the left is greater than mid, swap the position of left and mid
    if (arr[left] > arr[mid]) {
        std::swap(arr[left], arr[mid]);
    }

    std::swap(arr[left], arr[mid]);
}


// Chooses the left most element as the pivot and swaps the j
int partition(std::vector<float>$arr, int left, int right) {

    // Pivot is already positioned
    float piv = arr[left];

    int i = left;

    
    for (int j = left + 1; j <= right; j++) {

        // If j is less than or equal to the pivot then swap the positions of the pivot and j
        if (arr[j] <= piv) {

            i++;

            std::swap(arr[i], arr[j]);
        }
    }
    // Swaps the pivot(i) and j 
    std::swap(arr[left], arr [j]);

    return i;
}

// Runs the median_of_three and partition, while also using recursion
void quicksort(std::vector<float>$arr, int left, int right) {

    if (left >= right) {
        return;
    }

    median_of_three(arr, left, right);

    // Establishes the pivot index
    int pivIndex = partition(arr, left, right);

    quicksort(arr, left, pivIndex - 1);

    quicksort(arr, pivIndex + 1, right);
}