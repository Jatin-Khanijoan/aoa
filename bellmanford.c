#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int source, destination, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

void BellmanFord(struct Graph* graph, int source) {
    int V = graph->V;
    int E = graph->E;
    int StoreDistance[V];

    for (int i = 0; i < V; i++)
        StoreDistance[i] = INT_MAX;
    StoreDistance[source] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            if (StoreDistance[u] != INT_MAX && StoreDistance[u] + weight < StoreDistance[v])
                StoreDistance[v] = StoreDistance[u] + weight;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        if (StoreDistance[u] != INT_MAX && StoreDistance[u] + weight < StoreDistance[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t\t%d\n", i, (StoreDistance[i] == INT_MAX ? INT_MAX : StoreDistance[i]));
}

int main() {
    int V, E;
    printf("Enter number of vertices in graph: ");
    scanf("%d", &V);
    printf("Enter number of edges in graph: ");
    scanf("%d", &E);
    struct Graph* graph = createGraph(V, E);
    printf("Enter source vertex number: ");
    int source;
    scanf("%d", &source);
    printf("Enter edge properties (Source, Destination, Weight) for each edge:\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &graph->edge[i].source, &graph->edge[i].destination, &graph->edge[i].weight);
    }
    BellmanFord(graph, source);
    return 0;
}



// Enter number of vertices in graph: 5
// Enter number of edges in graph: 8
// Enter source vertex number: 0
// Enter edge properties (Source, Destination, Weight) for each edge:
// Edge 1: 0 1 6
// Edge 2: 0 2 7
// Edge 3: 1 2 8
// Edge 4: 1 3 5
// Edge 5: 1 4 -4
// Edge 6: 2 3 -3
// Edge 7: 2 4 9
// Edge 8: 3 1 -2
// Vertex Distance from Source
// 0               0
// 1               2
// 2               7
// 3               4
// 4               -2