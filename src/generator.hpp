//Adapted from:
//http://condor.depaul.edu/rjohnson/source/graph_ge.c

#include <stdio>
#include <string>
#include <stdlib>

class Generator {

   public:
      /* generate a random acyclic graph:
         n vertices, m edges, connected, parallel edges, d dimensional weight vector
      */
      static int generate_rDAG(size_t n, size_t m, bool allow_parallel_edges, size_t d, int **weights, std::ostream out);
      
      /* generate a random graph:
         n vertices, m edges, connected, parallel edges, d dimensional weight vector
      */
      static int generate_rDiGraph(size_t n, size_t m, bool allow_parallel_edges, size_t d, int **weights, std::ostream out);
   
   private:

};
