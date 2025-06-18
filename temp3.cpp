#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
  int i = 0;
  int j = 0;

  vector<int> res;
  while (true) {
    if (i == nums1.size()) {
      while (j < nums2.size()) {
        res.push_back(nums2[j]);
        j++;
      }
      /*cout << "breaking out the this after i ended" << endl;*/
      break;
    }

    if (j == nums2.size()) {
      while (i < nums1.size()) {
        res.push_back(nums1[i]);
        i++;
      }
      break;
    }

    if (nums1[i] >= nums2[j]) {
      res.push_back(nums2[j]);
      j++;
    } else {
      res.push_back(nums1[i]);
      i++;
    }
    /*cout << "inside the loop " << res.size() << endl;*/
  }

  /*cout << "after the loop " << res.size() << endl;*/
  return res;
}

int main() {
  vector<int> nums1 = {1, 12, 3, 4};
  vector<int> nums2 = {5, 6, 78, 81};
  // Given two sorted arrays merge them into one sorted array.

  vector<int> res = merge(nums1, nums2);

  cout << "Size of the final res vector " << res.size() << endl;

  for (auto num : res) {
    cout << num << " ";
  }

  cout << endl;
  return 0;
}
