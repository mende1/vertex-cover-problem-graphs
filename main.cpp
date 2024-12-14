#include <iostream>
#include <list>
using namespace std;

class Graph {
  int V;
  list<int> *adj;

public:
  Graph(int V);
  void addEdge(int v, int w);
  void printVertexCover();
};

Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
  adj[w].push_back(v);
}

void Graph::printVertexCover() {
  // Inicializa todos os vértices como não visitados.
  bool visited[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  list<int>::iterator i;

  // Considera todas as arestas uma por uma
  for (int u = 0; u < V; u++) {

    // Uma aresta é considerada apenas quando ambos visited[u] e visited[v]
    // são falsos
    if (visited[u] == false) {

      // Percorre todos os adjacentes de u e escolhe o primeiro
      // vértice ainda não visitado (basicamente, estamos escolhendo uma
      // aresta (u, v) dentre as arestas restantes).
      for (i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i;
        if (visited[v] == false) {

          // Adiciona os vértices (u, v) ao conjunto resultado.
          // Marcamos os vértices u e v como visitados para que eles sejam ignorados
          visited[v] = true;
          visited[u] = true;
          break;
        }
      }
    }
  }

  // Imprime a cobertura de vértices
  for (int i = 0; i < V; i++)
    if (visited[i])
      cout << i << " ";

  cout << endl;
}

int main() {
  Graph g(7);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(2, 4);
  g.addEdge(3, 4);
  g.addEdge(4, 5);
  g.addEdge(3, 5);
  g.addEdge(3, 6);

  g.printVertexCover();

  return 0;
}
