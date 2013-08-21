#include "generator/generator.h"
#include "gtest/gtest.h"
#include "sequential/sequential.h"

using namespace graph;
using namespace sp;

#define NODES (50)
#define EDGES (150)
#define SEED (42)

#define TESTCASE Sequential

namespace
{

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

} /* namespace */

int
main(int argc,
     char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
