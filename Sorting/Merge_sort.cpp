void merge(vector<int>& nums, int low, int mid, int high) {
    // Initialize left and right pointers
    int left = low;
    int right = mid + 1;
    vector<int> temp; // Temporary vector to store sorted elements

    // Merge the two sorted subarrays into the temporary vector
    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    // Copy any remaining elements from the left subarray
    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }

    // Copy any remaining elements from the right subarray
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }

    // Copy the sorted elements from the temporary vector back to the original array
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}

void mergesort(vector<int>& nums, int low, int high) {
    // Base case: If the array has only one element or is empty, return
    if (low >= high) return;

    // Calculate the middle index
    int mid = low + (high - low) / 2;

    // Recursively sort the two halves of the array
    mergesort(nums, low, mid);
    mergesort(nums, mid + 1, high);

    // Merge the sorted halves
    merge(nums, low, mid, high);
}

vector<int> sortArray(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;

    // Perform merge sort on the given array
    mergesort(nums, low, high);

    return nums;
}
