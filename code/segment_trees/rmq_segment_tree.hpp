#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

#define LEFT(i)     2 * i + 1
#define RIGHT(i)    2 * i + 2
#define PARENT(i) (i - 1) / 2

template<typename IntType, typename BinaryFunct>
struct rmq_segment_tree {

    struct type_traits {
        IntType invalid;
        BinaryFunct funct;
    };

    struct builder {

        builder()
        {}

        builder(std::vector<IntType> const& leaves, type_traits traits)
            : m_traits(traits)
        {
            size_t n = leaves.size();
            // round up to the next power of 2
            size_t m = size_t(1) << static_cast<size_t>(ceil(log2(n)));
            m_tree.resize(2 * m - 1, m_traits.invalid);
            build(leaves, 0, m - 1, 0);

            // for (auto x: m_tree) {
            //     std::cout << x << " ";
            // }   std::cout << std::endl;
        }

        void swap(builder& other) {
            std::swap(other.m_traits, m_traits);
            other.m_tree.swap(m_tree);
        }

        void build(rmq_segment_tree& rst) {
            std::swap(rst.m_traits, m_traits);
            rst.m_tree.swap(m_tree);
            builder().swap(*this);
        }

    private:
        type_traits m_traits;
        std::vector<IntType> m_tree;

        void build(std::vector<IntType> const& leaves, size_t lo, size_t hi, size_t pos) {
            if (lo == hi) {
                m_tree[pos] = leaves[lo];
                return;
            }
            size_t mid = (lo + hi) / 2;
            build(leaves, lo, mid, LEFT(pos));
            build(leaves, mid + 1, hi, RIGHT(pos));
            m_tree[pos] = m_traits.funct(m_tree[LEFT(pos)], m_tree[RIGHT(pos)]);
        }
    };

    rmq_segment_tree()
    {}

    // debug purposes
    void print_tree() const {
        for (auto x: m_tree) {
            std::cout << x << " ";
        }   std::cout << std::endl;
    }

    struct range {
        range(size_t l, size_t h)
            : lo(l), hi(h)
        {}

        size_t lo, hi;
    };

    range root() const {
        return range(0, size() - 1);
    }

    size_t size() const {
        return m_tree.size() / 2 + 1;
    }

    IntType rmq(range const& query, range node_segment, size_t pos) {

        if (query.lo <= node_segment.lo
        and query.hi >= node_segment.hi) { // total overlap
            return m_tree[pos];
        }
        if (query.lo > node_segment.hi
        or  query.hi < node_segment.lo) { // no overlap
            return m_traits.invalid;
        }

        // partial overlap
        size_t mid = (node_segment.lo + node_segment.hi) / 2;
        return m_traits.funct(
            rmq(query, {node_segment.lo, mid}, LEFT(pos)),
            rmq(query, {mid + 1, node_segment.hi}, RIGHT(pos))
        );
    }

    // increment the i-th leaf by delta
    void update(size_t i, IntType delta, range node_segment, size_t pos) {

        if (i > node_segment.hi
        or  i < node_segment.lo) {
            return;
        }

        if (node_segment.lo == node_segment.hi) { // leaf
            m_tree[pos] += delta;
            return;
        }

        size_t mid = (node_segment.lo + node_segment.hi) / 2;
        update(i, delta, {node_segment.lo, mid}, LEFT(pos));
        update(i, delta, {mid + 1, node_segment.hi}, RIGHT(pos));
        m_tree[pos] = m_traits.funct(m_tree[LEFT(pos)], m_tree[RIGHT(pos)]);
    }

    // increment all leaves in the range [query.lo, query.hi] by delta
    void update_range(range const& query, IntType delta, range node_segment, size_t pos) {

        if (query.lo > node_segment.hi
        or  query.hi < node_segment.lo) {
            return;
        }

        if (node_segment.lo == node_segment.hi) { // leaf
            m_tree[pos] += delta;
            return;
        }

        size_t mid = (node_segment.lo + node_segment.hi) / 2;
        update_range(query, delta, {node_segment.lo, mid}, LEFT(pos));
        update_range(query, delta, {mid + 1, node_segment.hi}, RIGHT(pos));
        m_tree[pos] = m_traits.funct(m_tree[LEFT(pos)], m_tree[RIGHT(pos)]);
    }

private:
    type_traits m_traits;
    std::vector<IntType> m_tree;
};
