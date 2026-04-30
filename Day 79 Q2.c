#include <bits/stdc++.h>
using namespace std;

class Solution{public :

                   void dfs1(int u, vector<int> adj[], vector<bool> &visited,
                             stack<int> &st){visited[u] = true;

for (int v : adj[u]) {
  if (!visited[v]) {
    dfs1(v, adj, visited, st);
  }
}

st.push(u); // finish time
}

void dfs2(int u, vector<int> adjRev[], vector<bool> &visited) {
  visited[u] = true;

  for (int v : adjRev[u]) {
    if (!visited[v]) {
      dfs2(v, adjRev, visited);
    }
  }
}

int kosaraju(int V, vector<vector<int>> &edges) {
  vector<int> adj[V];

  // Build graph
  for (auto &e : edges) {
    adj[e[0]].push_back(e[1]);
  }

  stack<int> st;
  vector<bool> visited(V, false);

  // Step 1: Fill stack
  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      dfs1(i, adj, visited, st);
    }
  }

  // Step 2: Reverse graph
  vector<int> adjRev[V];
  for (auto &e : edges) {
    adjRev[e[1]].push_back(e[0]);
  }

  // Step 3: DFS on reversed graph
  fill(visited.begin(), visited.end(), false);

  int sccCount = 0;

  while (!st.empty()) {
    int node = st.top();
    st.pop();

    if (!visited[node]) {
      dfs2(node, adjRev, visited);
      sccCount++;
    }
  }

  return sccCount;
}
}
;