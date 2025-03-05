#include "shortest_paths_sparse.hpp"
#include <priority_queue.hpp>
#include <algorithm>
#include <cmath>

std::vector<hop_t> bellman_ford(const SparseGraph &graph, const int source,
                                bool &has_negative_cycle)
{
    const int V = static_cast<int>(graph.size());
    auto DP = std::vector<hop_t>(V, {inf, -1});
    
    has_negative_cycle = false;

    // Initialise DP from source node
    DP[source] = {0, source};

    // For V-1 times
    for (int j = 0; j < V-1; ++j) {
        // Iterate through all nodes in graph starting from source
        for (int idx = 0; idx < V; ++idx) {
            int i = (idx + source) % V;
            for (const auto& hop : graph[i]) {
                if (DP[i].weight + hop.weight < DP[hop.vertex].weight) {
                    DP[hop.vertex] = {DP[i].weight + hop.weight, i};
                }
            }
        }
    }
    // Check for negative loops
    for (int i = 0; i < V; ++i) {
        for (const auto& hop : graph[i]) {
            if (DP[i].weight + hop.weight < DP[hop.vertex].weight) {
                has_negative_cycle = true;
                return DP;
            }
        }
    }
    return DP;
}

struct triplet_t {
    float d;
    int r;
    int v;
};

std::vector<hop_t> dijkstra(const SparseGraph &graph, const int source)
{
    assert(source >= 0);
    assert(source < (signed)graph.size());

    auto DP = std::vector<hop_t>(graph.size(), {inf, -1});
    auto Q = std::vector<bool>(graph.size(), false);

    // Initialize source node
    DP[source] = {0, source};
    Q[source] = true;

    int curr = source;

    // While there are unvisited nodes
    while (std::find(Q.begin(), Q.end(), false) != Q.end()) {
        hop_t min_hop = {inf, -1};

        // Update DP from current node
        for (const auto& hop : graph[curr]) {
            if (DP[curr].weight + hop.weight < DP[hop.vertex].weight) {
                DP[hop.vertex] = {DP[curr].weight + hop.weight, curr};
                if (hop.weight < min_hop.weight) {
                    min_hop = hop;
                }
            }
        }
        //Update current node
        curr = min_hop.vertex;
        Q[curr] = true;
    }

    return DP;
}


