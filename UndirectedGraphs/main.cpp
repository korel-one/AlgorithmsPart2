// UndirectedGraphs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include "Graph.h"
#include "DFS.h"

namespace {
  template <class TGraph>
  void print(const TGraph& i_graph, const char* ip_pattern)
  {
    if(i_graph.empty())
    {
      std::cout<<"graph is empty"<<std::endl;
      return;
    }

    i_graph.print(ip_pattern);
  }
}//namespace

int _tmain(int argc, _TCHAR* argv[])
{
  enum {A, B, C, D, E, F, G, H};
  const char* nodes = "ABCDEFGH";

  //Quiz 1
  typedef UndirectedGraph<Vertex> TUndirGraph;
  
  TUndirGraph graph(8);
  graph.AddEdge(B, F);
  graph.AddEdge(C, B);
  graph.AddEdge(F, G);
  graph.AddEdge(G, C);
  graph.AddEdge(D, C);
  graph.AddEdge(F, A);
  graph.AddEdge(A, E);
  graph.AddEdge(C, F);
  graph.AddEdge(H, C);
  
  print(graph, nodes);

  //graph's move constructor should be called, or copy one? 
  std::shared_ptr<TUndirGraph> p_graph = std::make_shared<TUndirGraph>(graph);

  DFS<TUndirGraph> dfs_algo(p_graph);
  dfs_algo.Execute(Vertex(A));


	return 0;
}