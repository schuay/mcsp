#include <stack>
#include <unordered_set>

#include "generator/generator.h"
#include "gtest/gtest.h"
#include "pareto/less.h"
#include "sequential/sequential.h"

using namespace graph;
using namespace pareto;
using namespace sp;

#define TESTCASE SequentialTest

namespace
{

class TESTCASE : public ::testing::Test
{
protected:
    virtual void init(const int nodes,
                      const int edges,
                      const int seed) {
        g = Generator::directed("g", nodes, edges, true,
                                Generator::default_weights(), seed);
        ASSERT_NE(g, nullptr);

        start = g->nodes().front();
        ASSERT_NE(start, nullptr);

        Sequential seq(g, start);
        sp = seq.shortest_paths();
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

void
test_optimal_paths_only(const ShortestPaths *sp)
{
    for (const auto & node_paths_pair : sp->paths) {
        EXPECT_TRUE(is_optimal_path_set(node_paths_pair.second));
    }
}

void
test_all_reachable_nodes_present(const Node *start,
                                 const ShortestPaths *sp)
{
    std::unordered_set<const Node *> reachables = reachable_nodes(start);

    for (const auto & node_paths_pair : sp->paths) {
        reachables.erase(node_paths_pair.first);
    }

    EXPECT_TRUE(reachables.empty());
}

void
test_full(const Node *start,
          const ShortestPaths *sp)
{
    test_optimal_paths_only(sp);
    test_all_reachable_nodes_present(start, sp);
}

TEST_F(TESTCASE, SanityCheck)
{
    init(50, 150, 42);

    Sequential seq(g, start);
    sp = seq.shortest_paths();
}

TEST_F(TESTCASE, 50_150_42)
{
    init(50, 150, 42);
    test_full(start, sp);
}

TEST_F(TESTCASE, 50_500_51)
{
    init(50, 500, 51);
    test_full(start, sp);
}

TEST_F(TESTCASE, 50_1000_123)
{
    init(50, 1000, 123);
    test_full(start, sp);
}

TEST_F(TESTCASE, 500_1500_1005)
{
    init(500, 1500, 1005);
    test_full(start, sp);
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
