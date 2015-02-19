#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

struct Trie {
  Trie *next[26];

  Trie() {
    for (int i = 0; i < 26; i++) next[i] = nullptr;
  }

  void insert(const char *s) {
    if (*s == '\0') return;
    if (next[*s - 'a'] == nullptr) next[*s - 'a'] = new Trie();
    next[*s - 'a']->insert(s + 1);
  }

  bool find(const char* s) {
    if (*s == '\0') return true;
    if (next[*s - 'a'] == nullptr) return false;
    next[*s - 'a']->find(s + 1);
  }
};

int main() {

  string s;
  REP(i,26) s += 'a' + i;

  Trie trie;
  trie.insert("aaaaiueo");
  if (trie.find("aaaiueo")) cout << "found" << endl;
  if (trie.find("aaaaiueo")) cout << "found" << endl;

  return 0;
}

