#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct Vertex {
   int label;
};
//stack variables
int stack[MAX];
int top = -1;
//queue variables
int queue[MAX];
int front= 0;
int rear = -1;
int qItemCount = 0;
//graph variables

//array of vertices
struct Vertex* lstVertices[MAX];
//adjacency matrix
int adjMatrix[MAX][MAX];
//visit matrix
int visit[MAX];
//vertex count
int vertexCount = 0;
//stack functions
void push(int item) {
   stack[++top] = item;
}

int pop() {
   return stack[top--];
}

int peek() {
   return stack[top];
}

bool isStackEmpty() {
   return top == -1;
}
//queue functions
void enqueue(int item){
    queue[++rear] = item;
    qItemCount++;
}

int dequeue(){
    qItemCount--;
    return queue[front++];
}

bool isQueueEmpty(){
    return qItemCount == 0;
}
//graph functions

//add vertex to the vertex list
void addVertex(){
    int v,n;
    printf("Enter the no of vertex: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the value of the vertex: ");
        scanf("%d",&v);
        struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
        vertex->label = v;
        lstVertices[vertexCount++] = vertex;
    }
}

//add edge to edge array
void addEdge(){
    int start,end;
    int c = 1;
    while(c){
        printf("Enter the starting vertex and end vertex of the edge ");
        scanf("%d %d",&start,&end);
        adjMatrix[start][end] = 1;
        adjMatrix[end][start] = 1;
        printf("Do you want to add more edges: 1 - yes,0-no ");
        scanf("%d",&c);
    }
}

//display the vertex
void displayVertex(int vertexIndex) {
   printf("%d ",lstVertices[vertexIndex]->label);
}

//get the adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex) {
   int i;

   for(i = 0; i < vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && visit[i] == 0) {
         return i;
      }
   }

   return -1;
}

void depthFirstSearch(int v) {
   int i;
   //mark first node as visited
   visit[v] = 1;
   //display the vertex
   displayVertex(v);
   //push vertex index in stack
   push(v);
   while(!isStackEmpty()) {
      //get the unvisited vertex of vertex which is at top of the stack
      int unvisitedVertex = getAdjUnvisitedVertex(peek());
      //no adjacent vertex found
      if(unvisitedVertex == -1) {
         pop();
      } else {
         visit[unvisitedVertex] = 1;
         displayVertex(unvisitedVertex);
         push(unvisitedVertex);
      }
   }
   //stack is empty, search is complete, reset the visited flag
   for(i = 0;i < vertexCount;i++) {
      visit[i] = 0;
   }
}
void breadthFirstSearch(int v){
    int i;
    visit[v] = 1;
    displayVertex(v);
    enqueue(v);
    int unvisitedVertex;

    while(!isQueueEmpty()){
        int tempVertex = dequeue();

        while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex))!=-1){
            visit[unvisitedVertex] = 1;
            displayVertex(unvisitedVertex);
            enqueue(unvisitedVertex);
        }
    }
     for(i = 0;i < vertexCount;i++) {
      visit[i] = 0;
   }
}

void initialise(){
    int i,j;
    for(i = 0; i < MAX; i++){    // set adjacency
        for(j = 0; j < MAX; j++){ // matrix to 0
            adjMatrix[i][j] = 0;
        }
        visit[i]= 0;
    }
}

void display(){
    int v;
    printf("Enter the vertex where traversal starts: ");
    scanf("%d",&v);
    printf("depth First Search: ");
    depthFirstSearch(v);
    printf("\nBreadth First Search: ");
    breadthFirstSearch(v);
}

int main() {
    initialise();
    addVertex();
    addEdge();
    display();
    return 0;
}
