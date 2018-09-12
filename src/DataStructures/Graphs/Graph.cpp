class Graph
{
 
private:
  struct Edge
  {
    int source;
    int destination;
    int cost;
    Edge *next;
 
    Edge(int src, int dst, int cst);
  };
 
  struct AdjList
  {
    Edge *head;
  };
 
  int count;
  std::vector<AdjList*> ListVector;
 
  class EdgeComparator
  {
  public:
    bool operator()(Edge *x, Edge *y);
  };
 
public:
  Graph(int cnt);
 
  virtual void AddEdge(int source, int destination, int cost);
  virtual void AddEdge(int source, int destination);
  virtual void AddBiEdge(int source, int destination, int cost); // bi
  virtual void AddBiEdge(int source, int destination); // bi directional edge
  virtual void Print();
 
  // Other Methods of graph.
};
 
Graph::Edge::Edge(int src, int dst, int cst = 1)
{
  source = src;
  destination = dst;
  cost = cst;
  next = nullptr;
}
 
Graph::Graph(int cnt)
{
  count = cnt;
  ListVector = std::vector<AdjList*>(cnt);
  for (int i = 0; i < cnt; i++)
    {
      ListVector[i] = new AdjList();
      ListVector[i]->head = nullptr;
    }
}
 
void Graph::AddEdge(int source, int destination, int cost)
{
  Edge *edge = new Edge(source, destination, cost);
  edge->next = ListVector[source]->head;
  ListVector[source]->head = edge;
}
 
void Graph::AddEdge(int source, int destination)
{
  AddEdge(source, destination, 1);
}
 
void Graph::AddBiEdge(int source, int destination, int cost)
{
  AddEdge(source, destination, cost);
  AddEdge(destination, source, cost);
}
 
void Graph::AddBiEdge(int source, int destination)
{
  AddBiEdge(source, destination, 1);
}
 
void Graph::Print()
{
  Edge *ad;
  for (int i = 0; i < count; i++)
    {
      ad = ListVector[i]->head;
      if (ad != nullptr)
        {
          std::cout << "Vertex " << i << " is connected to : ";
          while (ad != nullptr)
            {
              std::cout << ad->destination << " ";
              ad = ad->next;
            }
          std::cout << std::endl;
        }
    }
}
 
bool Graph::EdgeComparator::operator()(Edge *x, Edge *y)
{
  if (x->cost <= y->cost)
    {
      return false;
    }
  return true;
}
