#pragma once

#include <memory>

template <class TGraph>
class DFS
{
  typedef std::shared_ptr<TGraph> TGraphPtr;
  typedef std::vector<int> TTime;

public:
  DFS(TGraphPtr ip_graph)
    : mp_graph(ip_graph)
    , m_discovery_time(ip_graph->VerticesNumber())
    , m_finish_time(ip_graph->VerticesNumber())
    , m_edge_to(ip_graph->VerticesNumber(), -1)
  {}

  void Execute(typename TGraph::vertex_type& io_start_vertex)
  {
    time = 0;
    m_discovery_time.at(i_start_vertex.id) = ++time;

  }

  bool PathExists(const typename TGraph::vertex_type& i_from
    , const typename TGraph::vertex_type& i_to) const
  {
  }

  std::vector<typename TGraph::vertex_type> GetPath(const typename TGraph::vertex_type& i_from
    , const typename TGraph::vertex_type& i_to) const
  {
    std::vector<typename TGraph::vertex_type> path;

    if(!PathExists())
      return 
  }

private:
  void dfs_algo(typename TGraph::vertex_type& io_source_vertex)
  {
    io_source_vertex.visited = true;
    auto& adjacent_to_v = mp_graph->GetAdjacentTo(io_source_vertex);
    for(auto& vertex : adjacent_to_v)
    {
      if(!vertex.visited)
      {
        dfs_algo(vertex);
        m_edge_to.at(vertex.id) = io_source_vertex.id;
      }
    }
  }

private:
  TGraphPtr mp_graph;

  TTime m_discovery_time;
  TTime m_finish_time;

  std::vector<int> m_edge_to;
  
  int time;
};