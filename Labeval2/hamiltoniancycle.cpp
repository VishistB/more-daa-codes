#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if it's safe to add vertex v to the path
bool isSafe(vector<vector<int>>& graph, vector<int>& path, int v, int pos) {
    // Check if the vertex is adjacent to the previous vertex in the path
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }
    // Check if the vertex has already been visited in the path
    if (find(path.begin(), path.end(), v) != path.end()) {
        return false;
    }
    return true;
}

// Recursive function to find a Hamiltonian cycle starting from vertex v
bool backtrack(vector<vector<int>>& graph, vector<int>& path, int v) {
    if (path.size() == graph.size()) {
        // All vertices have been added to the path
        // Check if the last vertex is adjacent to the first vertex
        if (graph[path.back()][path[0]] == 1) {
            return true;
        }
        return false;
    }
    // Try all possible vertices for the next position in the path
    for (int i = 0; i < graph.size(); i++) {
        if (isSafe(graph, path, i, path.size())) {
            path.push_back(i);
            // Recursively add the next vertex to the path
            if (backtrack(graph, path, i)) {
                return true;
            }
            // Backtrack and try a different vertex for the next position in the path
            path.pop_back();
        }
    }
    // Could not find a valid Hamiltonian cycle starting from vertex v
    return false;
}

// Function to solve the Hamiltonian Cycle problem using backtracking
vector<int> hamiltonianCycle(vector<vector<int>>& graph) {
    vector<int> path = {0}; // Start with vertex 0 in the path
    if (backtrack(graph, path, 0)) {
        return path;
    }
    return {};
}

int main() {
    vector<vector<int>> graph = {{0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0}};
    vector<int> cycle = hamiltonianCycle(graph);
    if (cycle.empty()) {
        cout << "Could not find a Hamiltonian cycle" << endl;
    } else {
        cout << "Hamiltonian cycle: ";
        for (int i = 0; i < cycle.size(); i++) {
            cout << cycle[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
