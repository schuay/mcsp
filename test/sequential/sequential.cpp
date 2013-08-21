#include "generator/generator.h"
#include "gtest/gtest.h"
#include "pareto/less.h"
#include "sequential/sequential.h"

using namespace graph;
using namespace pareto;
using namespace sp;

#define NODES (50)
#define EDGES (150)
#define SEED (42)

#define TESTCASE Sequential

namespace
{

bool
is_optimal_path_set(const Paths &paths)
{
    less dominates;

    for (size_t i = 0; i < paths.size(); i++) {
        for (size_t j = i + 1; j < paths.size(); j++) {
            const Path *l = paths[i].get();
            const Path *r = paths[j].get();

            if (dominates(l, r) || dominates(r, l)) {
                l->print();
                r->print();
                return false;
            }
        }
    }

    return true;
}

TEST(TESTCASE, SanityCheck)
{
    Graph *g = Generator::directed("g", NODES, EDGES, true,
                                   Generator::default_weights(), SEED);
    ASSERT_NE(g, nullptr);

    Node *node = g->nodes().front();
    ASSERT_NE(node, nullptr);

    Sequential seq(g, node);
    ShortestPaths *sp = seq.shortest_paths();

    delete sp;
    delete g;
}

TEST(TESTCASE, ContainsOptimalPathsOnly)
{
    Graph *g = Generator::directed("g", NODES, EDGES, true,
                                   Generator::default_weights(), SEED);
    ASSERT_NE(g, nullptr);

    Node *node = g->nodes().front();
    ASSERT_NE(node, nullptr);

    Sequential seq(g, node);
    ShortestPaths *sp = seq.shortest_paths();

    for (const auto & node_paths_pair : sp->paths) {
        EXPECT_TRUE(is_optimal_path_set(node_paths_pair.second));
    }

    delete sp;
    delete g;
}

} /* namespace */

int
main(int argc,
     char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
