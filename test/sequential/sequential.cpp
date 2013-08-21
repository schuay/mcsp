#include <stack>
#include <unordered_set>

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

#define TESTCASE SequentialTest

namespace
{

class TESTCASE : public ::testing::Test
{
protected:
    virtual void SetUp() {
        g = Generator::directed("g", NODES, EDGES, true,
                                Generator::default_weights(), SEED);
        ASSERT_NE(g, nullptr);

        start = g->nodes().front();
        ASSERT_NE(start, nullptr);
    }

    virtual void TearDown() {
        delete sp;
        delete g;
    }

protected:
    Graph *g;
    Node *start;
    ShortestPaths *sp;
};

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

std::unordered_set<const Node *>
reachable_nodes(const Node *start)
{
    std::unordered_set<const Node *> set = { start };

    std::stack<const Node *> stack;
    for (const Edge * e : start->out_edges()) {
        stack.push(e->head());
    }

    while (!stack.empty()) {
        const Node *n = stack.top();
        stack.pop();

        if (set.find(n) != set.end()) {
            continue;
        }

        set.insert(n);
        for (const Edge * e : n->out_edges()) {
            stack.push(e->head());
        }
    }

    return set;
}

TEST_F(TESTCASE, SanityCheck)
{
    Sequential seq(g, start);
    sp = seq.shortest_paths();
}

TEST_F(TESTCASE, ContainsOptimalPathsOnly)
{
    Sequential seq(g, start);
    sp = seq.shortest_paths();

    for (const auto & node_paths_pair : sp->paths) {
        EXPECT_TRUE(is_optimal_path_set(node_paths_pair.second));
    }
}

TEST_F(TESTCASE, AllReachableNodesPresent)
{
    Sequential seq(g, start);
    sp = seq.shortest_paths();

    std::unordered_set<const Node *> reachables = reachable_nodes(start);

    for (const auto & node_paths_pair : sp->paths) {
        reachables.erase(node_paths_pair.first);
    }

    EXPECT_TRUE(reachables.empty());
}

/* TODO:
 * Repeat these tests for different NODES, EDGES, SEED values.
 * Add other correctness criteria.
 */

} /* namespace */

int
main(int argc,
     char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
