#ifndef __shortest_paths_decode__
#define __shortest_paths_decode__

#include "graph.hpp"
#include <algorithm>
#include <vector>

inline std::vector<int> decode(const std::vector<hop_t> &DP, int v)
{
    // Take DP and destination vertex v index, return path from source to
    // destination as vector of vertex indices.
    int idx = v;
    hop_t node = DP[idx];
    std::vector<int> path;

    // While node is not source
    while (node.weight != 0) {
        if (node.vertex < 0) {
            //std::cout << "-1 vertex detected" << std::endl;
            return std::vector<int>{};
        }
        path.push_back(idx);    // Record index

        idx = node.vertex;      // Update index to previous node index
        node = DP[idx];         // Update node to previous node
    }

    path.push_back(idx);        // include the source node index
    std::reverse(path.begin(), path.end()); // reverse to get the path from source to destination

    return path;
}

#endif // __shortest_paths_decode__
