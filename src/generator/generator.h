//Adapted from:
//http://condor.depaul.edu/rjohnson/source/graph_ge.c

#ifndef __GENERATOR_H
#define __GENERATOR_H

#include "../graph/edge.h"
#include "../graph/graph.h"
#include "../graph/node.h"
using namespace graph;

namespace graph{

class Generator {

   typedef std::vector<std::pair<int, int>> Wl;

   public:
      /* generate a random connected directed graph
         n vertices, m edges, connected, parallel edges, d dimensional weight vector
      */
      Graph generate_rDiGraph(const std::string& name,         
                           const size_t& n,                    /* Number of nodes (n > 0) */
                           const size_t& m,                    /* Number of edges (n-1 < m < n*(n-1)) */
                           const bool& allow_parallel_edges,   /* If true, graph may contain parallel edges */
                           const Wl& weight_limits);           /* Limits [min, max] for the weight vector of an edge. 
                                                                  length of vector = d = dimension of graph */ 
      
   private:
      /* generate a weight vector w with d = weight_limits.size elements and 
         forall i: weight_limits[i].first <= w[i] <= weight_limits[i].second */ 
      std::vector<int> generate_weight_vector(const Wl& weight_limits); 
};

}
#endif /*__GENERATOR_H */
