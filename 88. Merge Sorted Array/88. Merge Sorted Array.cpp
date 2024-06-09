#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int iterator1 = m-1;
    int iterator2 = n-1;
       
    for (int iteratorTotal = m+n-1; iteratorTotal >= 0; iteratorTotal--) {
        if (iterator2 < 0 || (iterator1 >= 0 && nums1[iterator1] > nums2[iterator2])) {
            nums1[iteratorTotal] = nums1[iterator1];
            iterator1--;
        }
        else if (iterator1 < 0 || (iterator2 >= 0 && nums1[iterator1] <= nums2[iterator2])) {
            nums1[iteratorTotal] = nums2[iterator2];
            iterator2--;
        }
    }
}

int main() {
    vector<int> nums1 = { 0 };
    vector<int> nums2 = { 1 };
    merge(nums1, 0, nums2, 1);
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i];
    }
    return 0;
}