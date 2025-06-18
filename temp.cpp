#include <bits/stdc++.h>
using namespace std;

bool checkHashmap(unordered_map<char, int> hashmap, int k) {
  for (auto entry : hashmap)
    if (entry.second < k)
      return false;
  return true;
}

int main() {
  string s = "aaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccc";
  int res = 0;
  string resString = "";
  int k = 2;
  unordered_map<char, int> hashmap;
  for (int x = 1; x <= 26; x++) {
    int i = 0; // Start of our window
    int j = 0; // End
    hashmap.clear();
    while (j < s.size()) {
      hashmap[s[j]]++;
      if (hashmap.size() == x) {
        // My current window contains at k characters of each type
        if (checkHashmap(hashmap, k)) {
          if (res < j - i + 1) {
            res = j - i + 1;
            resString = s.substr(i, j - i + 1);
          }
        }
      } else if (hashmap.size() > x) { // We have found in our current win some
                                       // repeating characters
        while (i < s.size() && hashmap.size() > x) {
          hashmap[s[i]]--;
          if (hashmap[s[i]] == 0)
            hashmap.erase(s[i]);
          i++;
        }

        if (checkHashmap(hashmap, k)) {
          if (res < j - i + 1) {
            res = j - i + 1;
            resString = s.substr(i, j - i + 1);
          }
        }
      }
      j++;
    }
  }

  cout << "len of the max substr matching our criteria of atleast k characters "
       << res << endl;
  cout << "the actual string that you want is " << resString << endl;
  return 0;
}
