#pragma once

#include <algorithm>
#include <iterator>
#include <list>
#include <vector>

template <class TVertex>
class Graph
{
public:
  typedef TVertex vertex_type;

  typedef std::list<TVertex> TAdjacentVertices;
  typedef std::vector<TAdjacentVertices> TAdjacencyList;

  Graph(int i_vertex_number)
    : m_adjacency_list(i_vertex_number)
  {}

  Graph(Graph&& i_graph)
    : m_adjacency_list(std::move(i_graph.m_adjacency_list))
  {}

  Graph(const Graph& i_graph)
    : m_adjacency_list(i_graph.m_adjacency_list)
  {}

public:
  void AddEdge(const TVertex& i_u, const TVertex& i_v)
  {
    _AddEdge(i_u, i_v);
  }

  TAdjacentVertices& GetAdjacentTo(const TVertex& i_v) const
  {
    return m_adjacency_list.at(i_v.id);
  }

  int VerticesNumber() const
  {
    return m_adjacency_list.size();
  }

  bool empty() const
  {
    return m_adjacency_list.empty();
  }

  void print(const char* ip_pattern) const
  {
    int i = 0;
    std::for_each(std::begin(m_adjacency_list), std::end(m_adjacency_list)
      , [=, &i](TAdjacencyList::const_reference adjacent_points)
    {
      std::cout<<ip_pattern[i++]<<": ";

      for(auto& elem: adjacent_points)
        std::cout<<ip_pattern[elem.id]<<", ";

      std::cout<<std::endl;


      //right, but print the numbers - however the letters are required
      /*std::copy(std::begin(adjacent_points), std::end(adjacent_points)
        , std::ostream_iterator<TVertex>(std::cout, ", "));*/
    });
  }

private:
  virtual void _AddEdge(const TVertex& i_u, const TVertex& i_v) = 0;

protected:
  TAdjacencyList m_adjacency_list;
};

template <class TVertex>
class UndirectedGraph
  : public Graph<TVertex>
{
  typedef Graph<TVertex> _super;

public:
  UndirectedGraph(int i_vertex_number)
    : _super(i_vertex_number)
  {}

private:
  virtual void _AddEdge(const TVertex& i_u, const TVertex& i_v) override
  {
    m_adjacency_list.at(i_u.id).push_back(i_v);
    m_adjacency_list.at(i_v.id).push_back(i_u);
  }
};

struct Vertex
{
  Vertex(int i_id)
    : id(i_id)
    , visited(false)
  {}

  int id;
  bool visited;
};

std::ostream& operator << (std::ostream& io_ostrm, const Vertex& i_vertex)
{
  io_ostrm << i_vertex.id;
  return io_ostrm;
}