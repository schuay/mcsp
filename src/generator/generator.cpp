#include "generator.h"

#include <algorithm>
#include <assert.h>
#include <cmath>
#include <ctime>
#include <cstdlib>

Graph *
Generator::
generate_rDAG(const std::string& name,
              const size_t &n,
              const size_t &m,
              const bool &allow_parallel_edges,
              const std::vector<std::pair<int, int>> &weight_limits)
{
   assert(n > 0);
   assert(m > n-1);
   if(!allow_parallel_edges)
        assert(m < n*(n-1));
   
   Graph *g = new Graph(name);
   
   std::vector<Node*> tree;
   
   /*  Generate a random permutation in the array tree. */
   for (size_t i = 0; i < n; i++) {
      tree.push_back(g->add_node());
   }
   std::random_shuffle (tree.begin(), tree.end());

   /*  Next generate a random spanning tree.
       The algorithm is:

         Assume that vertices tree[ 0 ],...,tree[ i - 1 ] are in
         the tree.  Add an edge incident on tree[ i ]
         and a random vertex in the set {tree[ 0 ],...,tree[ i - 1 ]}.
    */
   srand((unsigned short) time(NULL));
   
   size_t tail, head;
    
   for (head = 1; head < n; head++) {
      tail = rand() % head;
      g->add_edge(tree[tail], tree[head], generate_weight_vector(weight_limits));
   }

   /* Add additional random edges until achieving desired number */
   for (size_t i=n-1; i<m; i++) {
      tail = rand() % n;
      do {
         head = rand() % n;
      } while(head == tail || (!allow_parallel_edges && g->contains_edge(tree[tail], tree[head])));
               
      g->add_edge(tree[tail], tree[head], generate_weight_vector(weight_limits));
   }
   return g;
}

std::vector<int>
Generator::
generate_weight_vector(const Wl &weight_limits)
{
   std::vector<int> weights;
   for (auto it : weight_limits) {
      int w = it.first + rand() % (it.second - it.first + 1);
      weights.push_back(w);
   }
   return weights;
}


