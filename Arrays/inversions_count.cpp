#include <bits/stdc++.h>

using namespace std;

int merge(long long *nums, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;      
    int right = mid + 1;   

    int cnt = 0;

    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            cnt += (mid - left + 1); 
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }

    return cnt;
}

int mergesort(long long *nums, int low, int high) {
    int count = 0;
    if (low >= high) return count;
    int mid = low + (high - low) / 2;
    count += mergesort(nums, low, mid);
    count += mergesort(nums, mid + 1, high);
    count += merge(nums, low, mid, high);
    return count;
}

long long getInversions(long long *nums, int n) {
    int low = 0;
    int high = n - 1;
    return mergesort(nums, low, high);
}