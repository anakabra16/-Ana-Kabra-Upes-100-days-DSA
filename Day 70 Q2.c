#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int u, v, weight;
};

int findCheapestPrice(int n, struct Edge* flights, int flightsSize, int src, int dst, int k) {
    int* dist = (int*)malloc(n * sizeof(int));
    
    // Initialize distances to infinity
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Run Bellman-Ford algorithm for exactly k + 1 iterations
    // (At most k stops means at most k + 1 edges)
    for (int i = 0; i <= k; i++) {
        // Need a temporary array to avoid using updated distances in the same iteration
        int* temp = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            temp[j] = dist[j];
        }

        // Relax all edges
        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j].u;
            int v = flights[j].v;
            int w = flights[j].weight;

            // We use dist[u] from previous iteration to ensure we only take paths of length <= i+1
            if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }
        
        // Move to next iteration
        free(dist);
        dist = temp;
    }

    int result = (dist[dst] == INT_MAX) ? -1 : dist[dst];
    free(dist);
    return result;
}

int main() {
    int n, m, src, dst, k;
    // Read number of cities, number of flights, source, destination, and max stops
    if (scanf("%d %d %d %d %d", &n, &m, &src, &dst, &k) != 5) return 0;

    struct Edge* flights = (struct Edge*)malloc(m * sizeof(struct Edge));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &flights[i].u, &flights[i].v, &flights[i].weight);
    }

    int ans = findCheapestPrice(n, flights, m, src, dst, k);
    printf("%d\n", ans);

    free(flights);
    return 0;
}
