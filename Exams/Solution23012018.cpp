#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <cmath>

#define LEFT(i)     2 * i + 1
#define RIGHT(i)    2 * i + 2
#define PARENT(i) (i - 1) / 2

struct query {
    query(size_t xx,
          size_t yy,
          size_t kk)
        : x(xx)
        , y(yy)
        , k(kk)
    {}

    size_t x, y, k;
};

template<typename IntType>
struct segment_tree {

    segment_tree(size_t n)
        : m_n(n)
        , m_leaves(n)
    {
        // round up to the next power of 2
        size_t m = size_t(1) << static_cast<size_t>(ceil(log2(n)));
        m_tree.resize(2 * m - 1, IntType(0));
        build(0, n - 1, 0);
    }

    void build(size_t lo, size_t hi, size_t pos) {
        if (lo == hi) {
            m_leaves[lo] = pos; // save leaf position
            return;
        }
        size_t mid = (lo + hi) / 2;
        build(lo, mid, LEFT(pos));
        build(mid + 1, hi, RIGHT(pos));
    }

    // debug purposes
    void print_tree() const {
        for (auto x: m_tree) {
            std::cout << x << " ";
        }   std::cout << std::endl;
    }

    struct range {
        range(size_t l,
              size_t h)
            : lo(l)
            , hi(h)
        {}

        size_t lo, hi;
    };

    range root() const {
        return range(0, size());
    }

    size_t size() const {
        return m_n;
    }

    void copy(query const& q, size_t query_id) {
        range r(q.y, q.y + q.k);
        copy(r, query_id, root(), 0);
    }

    size_t get_query_id(size_t i)
    {
        assert(i < size());
        size_t max = 0;
        size_t pos = m_leaves[i]; // position of the i-th leaf

        while (true) { // return max from leaf to root
            if (m_tree[pos] > max) {
                max = m_tree[pos];
            }
            if (pos == 0) { // root
                break;
            }
            pos = PARENT(pos);
        }

        return max;
    }

private:
    size_t m_n;
    std::vector<size_t> m_leaves;
    std::vector<IntType> m_tree;

    void copy(range const& r, size_t query_id, range node_segment, size_t pos) {

        if (r.lo <= node_segment.lo
        and r.hi >= node_segment.hi) { // total overlap
            m_tree[pos] = query_id;
            if (node_segment.lo == node_segment.hi) { // leaf
                return;
            }
        }

        if (r.lo > node_segment.hi
        or  r.hi < node_segment.lo) { // no overlap
            return;
        }

        // partial overlap
        size_t mid = (node_segment.lo + node_segment.hi) / 2;
        copy(r, query_id, {node_segment.lo, mid}, LEFT(pos));
        copy(r, query_id, {mid + 1, node_segment.hi}, RIGHT(pos));
    }
};

int main() {

    std::ios_base::sync_with_stdio(false);

    uint64_t n = 0; // number of elements in arrays
    std::cin >> n;

    uint64_t m = 0; // number of queries
    std::cin >> m;

    typedef std::chrono::high_resolution_clock clock_type;
    typedef int int_type;

    std::vector<int_type> A;
    std::vector<int_type> B;
    A.reserve(n);
    B.reserve(n);

    for (uint64_t i = 0; i < n; ++i) {
        int_type x = 0;
        std::cin >> x;
        A.push_back(x);
    }

    for (uint64_t i = 0; i < n; ++i) {
        int_type x = 0;
        std::cin >> x;
        B.push_back(x);
    }

    segment_tree<int_type> st(n);

    std::vector<query> queries;
    queries.reserve(m); // upper bound

    // auto start = clock_type::now();
    for (uint64_t i = 0; i < m; ++i)
    {
        size_t type;
        std::cin >> type;

        if (type == 1) {

            size_t x, y, k;
            std::cin >> x >> y >> k;
            queries.emplace_back(x, y, k);
            st.copy(queries.back(),
                    queries.size()); // next query id

        } else if (type == 2) {

            size_t pos;
            std::cin >> pos;
            size_t query_id = st.get_query_id(pos);
            if (query_id == 0) {
                std::cout << B[pos] << "\n";
            } else {
                auto q = queries[query_id - 1];
                std::cout << A[pos - q.y + q.x] << "\n";
            }

        } else {
            std::cerr << "unknown query type" << std::endl;
            return 1;
        }
    }

    std::cout << std::flush;
    // auto end = clock_type::now();
    // std::chrono::duration<double> elapsed = end - start;
    // std::cout << "queries executed in: " << elapsed.count()
    //           << " [sec]" << std::endl;

    return 0;
}
