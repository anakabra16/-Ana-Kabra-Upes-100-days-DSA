#include <bits/stdc++.h>
using namespace std;

class Solution{public : string findOrder(vector<string> &
                                         words){vector<vector<int>> graph(26);
vector<int> indegree(26, 0);
vector<bool> present(26, false);

// Mark characters present
for (auto &word : words) {
  for (char c : word) {
    present[c - 'a'] = true;
  }
}

// Build graph
for (int i = 0; i < words.size() - 1; i++) {
  string w1 = words[i];
  string w2 = words[i + 1];

  int len = min(w1.size(), w2.size());
  int j = 0;

  while (j < len && w1[j] == w2[j])
    j++;

  // Invalid case
  if (j < w1.size() && j == w2.size())
    return "";

  if (j < len) {
    int u = w1[j] - 'a';
    int v = w2[j] - 'a';

    graph[u].push_back(v);
    indegree[v]++;
  }
}

// Kahn's Algorithm
queue<int> q;

for (int i = 0; i < 26; i++) {
  if (present[i] && indegree[i] == 0) {
    q.push(i);
  }
}

string result = "";

while (!q.empty()) {
  int u = q.front();
  q.pop();
  result += (u + 'a');

  for (int v : graph[u]) {
    indegree[v]--;
    if (indegree[v] == 0) {
      q.push(v);
    }
  }
}

// Check cycle
int count = 0;
for (int i = 0; i < 26; i++) {
  if (present[i])
    count++;
}

if (result.size() != count)
  return "";

return result;
}
}
;