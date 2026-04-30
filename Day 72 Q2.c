#include <limits.h>
#include <stdio.h>
#include <string.h>


#define MAXN 15
#define MAXMASK (1 << 15)

int dp[MAXMASK][MAXN];

int min(int a, int b) { return a < b ? a : b; }

int tsp(int n, int cost[MAXN][MAXN]) {
  int maxMask = 1 << n;

  // Initialize DP
  for (int i = 0; i < maxMask; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = INT_MAX;
    }
  }

  // Start from city 0
  dp[1][0] = 0;

  // Iterate over all masks
  for (int mask = 1; mask < maxMask; mask++) {
    for (int u = 0; u < n; u++) {
      if (!(mask & (1 << u)))
        continue;

      for (int v = 0; v < n; v++) {
        if (mask & (1 << v))
          continue;

        int newMask = mask | (1 << v);

        if (dp[mask][u] != INT_MAX) {
          dp[newMask][v] = min(dp[newMask][v], dp[mask][u] + cost[u][v]);
        }
      }
    }
  }

  int ans = INT_MAX;
  int fullMask = (1 << n) - 1;

  // Return to city 0
  for (int i = 1; i < n; i++) {
    if (dp[fullMask][i] != INT_MAX) {
      ans = min(ans, dp[fullMask][i] + cost[i][0]);
    }
  }

  return ans;
}