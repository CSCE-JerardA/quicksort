// Copyright 2025 Jerard A

#include <vector>
#include <iostream>
#include <algorithm>


int median_of_three(std::vector<float>$arr, int left, int right) {

    if (right - left < 2) {
        return;
    }

    int mid = left + (right - left) / 2;

    if (arr[left] > arr[right]) {
        std::swap(arr[left], arr[right]);
    }

    if (arr[mid] > arr[right]) {
        std::swap(arr[mid], arr[right]);
    }

    if (arr[left] > arr[mid]) {
        std::swap(arr[left], arr[mid]);
    }

    std::swap(arr[left], arr[mid]);
}



int partition(std::vector<float>$arr, int left, int right) {

    // Pivot is already positioned
    float piv = arr[left];

    int i = left;


    for (int j = left + 1; j <= right; j++) {

        if (arr[j] <= piv) {

            i++;

            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[left], arr [j]);

    return i;
}

void quicksort(std::vector<float>$arr, int left, int right) {

    if (left >= right) {
        return;
    }

    median_of_three(arr, left, right);

    int pivIndex = partition(arr, left, right);

    quicksort(arr, left, pivIndex - 1);

    quicksort(arr, pivIndex + 1, right);
}