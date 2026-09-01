/*  Graph nu Adjacency List representation + DFS ane BFS
    ------------------------------------------------------
    Aa program ek undirected graph banave che, tene
    adjacency list ma store kare che, ane pachhi
    DFS (Depth First Search) ane BFS (Breadth First Search)
    traversal print kare che.                              */
<br

#include <stdio.h>      // printf, scanf jeva input-output mate
#include <stdlib.h>     // malloc (memory allocate karva) mate

#define MAX 100         // graph ma vadhare ma vadhare ketla vertex hoi shake

/* ===== Adjacency list no ek node ===== */
struct Node {
    int vertex;             // aa node kaya vertex ne point kare che
    struct Node* next;      // next padoshi (neighbor) ni link
};


/* ===== Graph ni structure ===== */
struct Graph {
    int numVertices;            // total ketla vertex che
    struct Node* adjList[MAX];  // dareak vertex mate ek alag linked list
};

int visited[MAX];   // kayo vertex visit thayo te yaad rakhva mate (global)

/* ---- Navo node banavva no function (O(1)) ---- */
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // memory lo
    newNode->vertex = v;    // vertex ni value set karo
    newNode->next = NULL;   // navo node etle hamna next kai nathi
    return newNode;         // banavelo node pachho aapo
}

/* ---- Graph banavva no function ---- */
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)); // graph mate memory
    graph->numVertices = vertices;      // ketla vertex che te store karo

    // shariat ma dareak vertex ni list khali (NULL) rakho
    for (int i = 0; i < vertices; i++)
        graph->adjList[i] = NULL;

    
    return graph;
}

/* ---- Edge add karva no function (undirected graph) ----
   Head par insert kariye chhie etle aa O(1) ma thay -> optimized */
void addEdge(struct Graph* graph, int src, int dest) {
    // src -> dest ni link: dest ne src ni list ni aagal muko
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // undirected che etle dest -> src ni link pan add karo
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}


/* ---- Adjacency list print karva no function ---- */
void printGraph(struct Graph* graph) {
    printf("Adjacency List (graph nu representation):\n");
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjList[i];  // aa vertex ni list
        printf("Vertex %d: ", i);
        while (temp != NULL) {          // list na badha node print karo
            printf("-> %d ", temp->vertex);
            temp = temp->next;          // next node par jao
        }
        printf("\n");
    }
}

/* ===== DFS (recursion thi) ===== */
void DFS(struct Graph* graph, int vertex) {
    visited[vertex] = 1;            // aa vertex ne visited mark karo
    printf("%d ", vertex);          // vertex print karo

    struct Node* temp = graph->adjList[vertex]; // aa vertex na padoshi
    while (temp != NULL) {                       // dareak padoshi mate
        int neighbor = temp->vertex;
        if (!visited[neighbor])                 // jo hju visit na thayo hoy to
            DFS(graph, neighbor);               // tena par pachhu DFS karo (recursion)
        temp = temp->next;                      // next padoshi par jao
    }
}

/* ===== BFS mate simple queue ===== */
int queue[MAX];                 // queue no array
int front = -1, rear = -1;      // queue na front ane rear pointer

void enqueue(int value) {       // queue ma value nakho
    if (front == -1) front = 0; // pehli var hoy to front 0 karo
    queue[++rear] = value;      // rear vadharo ane value muko
}

int dequeue() {                 // queue mathi value kadho
    return queue[front++];      // front ni value aapo ane front aagal khasedo
}

int isEmpty() {                 // queue khali che ke nai te check karo
    return (front == -1 || front > rear);
}

/* ===== BFS (queue thi) ===== */
void BFS(struct Graph* graph, int startVertex) {
    front = rear = -1;                  // queue ne fari thi khali karo

    visited[startVertex] = 1;           // start vertex ne visited karo
    enqueue(startVertex);               // ane queue ma nakho

    while (!isEmpty()) {                // jya sudhi queue khali na thay tya sudhi
        int current = dequeue();        // queue mathi ek vertex kadho
        printf("%d ", current);         // te vertex print karo

        struct Node* temp = graph->adjList[current];    // tena padoshi
        while (temp != NULL) {
            int neighbor = temp->vertex;
            if (!visited[neighbor]) {   // jo padoshi visit na thayo hoy to
                visited[neighbor] = 1;  // tene visited mark karo
                enqueue(neighbor);      // ane queue ma nakho
            }
            temp = temp->next;          // next padoshi par jao
        }
    }
}

/* ===== main function ===== */
int main() {
    // 5 vertex no graph banavo (vertex 0 thi 4)
    struct Graph* graph = createGraph(5);

    // graph ma edges (connection) add karo
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    // adjacency list print karo
    printGraph(graph);

    // ---- DFS traversal ----
    for (int i = 0; i < graph->numVertices; i++) // pehla badha ne unvisited karo
        visited[i] = 0;
    printf("\nDFS traversal (0 thi shuru): ");
    DFS(graph, 0);

    // ---- BFS traversal ----
    for (int i = 0; i < graph->numVertices; i++) // fari badha ne unvisited karo
        visited[i] = 0;
    printf("\nBFS traversal (0 thi shuru): ");
    BFS(graph, 0);

    printf("\n");
    return 0;   // program puru
}
