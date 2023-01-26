#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int INF = 1e9;

// Function to find the shortest path from source vertex to all other vertices 
void Dijkstra(vector<vector<pair<int, int>>>& graph, int source, vector<int>& dist) {
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Insert source itself in priority queue and initialize its distance as 0.
    pq.push({0, source});
    dist[source] = 0;

    // Looping till priority queue becomes empty (or all
    // distances are not finalized)
    while (!pq.empty()) {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        for (auto i : graph[u]) {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = i.first;
            int weight = i.second;

            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight) {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int V, E, source;
    cin >> V >> E;

    // Create a graph in the form of an adjacency list
    // where each element is a pair representing the
    // vertex and the weight of the edge
    vector<vector<pair<int, int>>> graph(V);

    // Adding edges to the graph
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    // Input source vertex
    cin >> source;

    // Vector to store the shortest distance from the source vertex
    vector<int> dist(V, INF);

    // Function call to Dijkstra's shortest path algorithm
    Dijkstra(graph, source, dist);

    // Print the shortest distance to all the vertices from the source vertex
    for (int i = 0; i < V; i++)
    {
    cout << i << ": " << dist[i] << endl;
    }

    return 0;
    
}
