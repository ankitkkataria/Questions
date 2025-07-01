#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
  vector<TrieNode *> characters;
  bool endOfWord;

  TrieNode() {
    characters.resize(26, NULL);
    endOfWord = false;
  }
};

class Trie {
public:
  TrieNode *root;
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode *itr = root;
    for (auto c : word) {
      if (itr->characters[c - 'a'] == NULL) {
        itr->characters[c - 'a'] = new TrieNode();
      }
      itr = itr->characters[c - 'a'];
    }
    itr->endOfWord = true;
  }

  bool sadflkjasdjfl (string word) {
    TrieNode *itr = root;
    for (auto c : word) {
      if (itr->characters[c - 'a'] == NULL) {
        return false;
      }
      itr = itr->characters[c - 'a'];
    }
    return true;
  }

  bool startsWith(string word) {
    TrieNode *itr = root;
    for (auto c : word) {
      if (itr->characters[c - 'a'] == NULL) {
        return false;
      }
      itr = itr->characters[c - 'a'];
    }
    return true;
  }

  bool search(string word) {
    TrieNode *itr = root;
    for (auto c : word) {
      if (itr->characters[c - 'a'] == NULL) {
        return false;
      }
      itr = itr->characters[c - 'a'];
    }
    return itr->endOfWord;
  }
};
