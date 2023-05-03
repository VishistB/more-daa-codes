#include <iostream>
#include <vector>
using namespace std;

// Check if it's safe to color the vertex v with color c
bool isSafe(vector<vector<int>>& graph, vector<int>& colors, int v, int c) {
    for (int i = 0; i < graph[v].size(); i++) {
        int u = graph[v][i];
        if (colors[u] == c) {
            return false;
        }
    }
    return true;
}

// Recursive function to assign colors to the vertices of the graph
bool backtrack(vector<vector<int>>& graph, int numColors, vector<int>& colors, int v) {
    if (v == graph.size()) {
        return true;
    }
    // Try all possible colors for vertex v
    for (int c = 1; c <= numColors; c++) {
        if (isSafe(graph, colors, v, c)) {
            colors[v] = c;
            // Recursively assign colors to the remaining vertices
            if (backtrack(graph, numColors, colors, v + 1)) {
                return true;
            }
            // Backtrack and try a different color for vertex v
            colors[v] = 0;
        }
    }
    // Could not assign a valid color to vertex v
    return false;
}

// Function to solve the Graph Coloring problem using backtracking
vector<int> graphColoring(vector<vector<int>>& graph, int numColors) {
    vector<int> colors(graph.size(), 0); // Initialize all colors to 0 (not colored)
    if (backtrack(graph, numColors, colors, 0)) {
        return colors;
    }
    return {};
}

int main() {
    vector<vector<int>> graph = {{1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 2}};
    int numColors = 3;
    vector<int> colors = graphColoring(graph, numColors);
    if (colors.empty()) {
        cout << "Could not color the graph" << endl;
    }
    else{
        for(int i = 0; i < colors.size(); i++){
            cout << "Vertex " << i << " is colored with " << colors[i] << endl;
        }
    }
    return 0;
}
