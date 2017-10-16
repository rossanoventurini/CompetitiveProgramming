#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <chrono>

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

private:
    type_traits m_traits;
    std::vector<IntType> m_tree;
};

template<typename T>
inline void do_not_optimize_away(T&& datum) {
    asm volatile("" : "+r" (datum));
}

template<typename IntType>
struct range_min_query_operator {
    IntType operator()(IntType x, IntType y) {
        return std::min<IntType>(x, y);
    }
};

template<typename IntType>
struct range_max_query_operator {
    IntType operator()(IntType x, IntType y) {
        return std::max<IntType>(x, y);
    }
};

int main() {

    std::ios_base::sync_with_stdio(false);

    uint64_t n = 0;
    std::cin >> n;

    typedef std::chrono::high_resolution_clock clock_type;

    auto start = clock_type::now();
    std::vector<int> leaves;
    leaves.reserve(n);
    for (uint64_t i = 0; i < n; ++i) {
        int x = 0;
        std::cin >> x;
        leaves.push_back(x);
    }
    auto end = clock_type::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "parsing the input took: " << elapsed.count() << " [sec]" << std::endl;

    typedef rmq_segment_tree<int, range_min_query_operator<int>> segment_tree_type;
    // typedef rmq_segment_tree<int, range_max_query_operator<int>> segment_tree_type;

    segment_tree_type::type_traits traits;
    traits.invalid = std::numeric_limits<int>::max();
    // traits.invalid = std::numeric_limits<int>::min();

    std::cout << "building tree with " << n << " leaves" << std::endl;
    start = clock_type::now();
    segment_tree_type::builder builder(leaves, traits);
    segment_tree_type min_seg_tree;
    builder.build(min_seg_tree);
    end = clock_type::now();
    elapsed = end - start;
    std::cout << "building took: " << elapsed.count() << " [sec]" << std::endl;

    uint64_t m = 0;
    std::cin >> m;

    std::vector<segment_tree_type::range> queries;
    queries.reserve(m);

    for (uint64_t i = 0; i < m; ++i) {
        int lo, hi;
        std::cin >> lo >> hi;
        queries.emplace_back(lo, hi);
    }

    std::cout << "executing " << m << " range queries" << std::endl;
    auto root = min_seg_tree.root();
    start = clock_type::now();
    for (int run = 0; run < 5; ++run) {
        for (uint64_t i = 0; i < m; ++i) {
            auto x = min_seg_tree.rmq(queries[i], root, 0);
            // std::cout << "rmq in [" << queries[i].lo << ", "
            //                         << queries[i].hi << "]: " << x << "\n";
            do_not_optimize_away(x);
        }
    }
    end = clock_type::now();
    elapsed = end - start;

    std::cout << "average query time: "
              << static_cast<double>(elapsed.count()) / (5 * m) * 1000000
              << " [musec]" << std::endl;

    return 0;
}
