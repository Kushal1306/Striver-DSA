#include <bits/stdc++.h> 

// Function to partition the array and return the pivot index
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    
    // Partitioning the array around the pivot
    while (i < j) {
        // Find an element from the left side greater than the pivot
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        
        // Find an element from the right side smaller than the pivot
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        
        // Swap the elements if they are out of order
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    
    // Place the pivot element in its correct position
    swap(arr[low], arr[j]);
    return j;
}

// Function to perform quicksort
void qs(vector<int>& arr, int low, int high) {
    if (low < high) {
        int part = partition(arr, low, high);
        
        // Recursively sort the left and right partitions
        qs(arr, low, part - 1);
        qs(arr, part + 1, high);
    }
}

// Function to perform quicksort on the given array
vector<int> quickSort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}
