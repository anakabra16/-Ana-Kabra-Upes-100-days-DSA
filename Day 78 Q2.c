#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int timer;

  void dfs(int u, int parent, vector<int> adj[], vector<int> &disc,
           vector<int> &low, vector<bool> &visited, vector<bool> &isAP) {

    visited[u] = true;
    disc[u] = low[u] = ++timer;

    int children = 0;

    for (int v : adj[u]) {
      if (v == parent)
        continue;

      if (!visited[v]) {
        children++;
        dfs(v, u, adj, disc, low, visited, isAP);

        low[u] = min(low[u], low[v]);

        // 🔥 articulation condition
        if (parent != -1 && low[v] >= disc[u]) {
          isAP[u] = true;
        }
      } else {
        // back edge
        low[u] = min(low[u], disc[v]);
      }
    }

    // 🔥 root condition
    if (parent == -1 && children > 1) {
      isAP[u] = true;
    }
  }

  vector<int> articulationPoints(int V, vector<int> adj[]) {
    vector<int> disc(V, 0), low(V, 0);
    vector<bool> visited(V, false), isAP(V, false);

    timer = 0;

    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        dfs(i, -1, adj, disc, low, visited, isAP);
      }
    }

    vector<int> result;

    for (int i = 0; i < V; i++) {
      if (isAP[i])
        result.push_back(i);
    }

    if (result.empty())
      return {-1};

    sort(result.begin(), result.end());
    return result;
  }
};