// Solution by Italo Guarrieri
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include "fenwick_tree.h"

int main() {
	std::ios_base::sync_with_stdio(false);

	int64_t n;
	std::cin >> n;

	std::vector<std::tuple<int64_t, int64_t, int64_t>> vet(n);
	std::vector<int64_t> all_elem;
	for (int64_t i = 0; i < n; ++i) {
		int64_t a, b;
		std::cin >> a;
		std::cin >> b;
		all_elem.push_back(a);
		all_elem.push_back(b);
		vet[i]=std::tuple<int64_t, int64_t, int64_t>(a,b,i);
	}

	std::sort(all_elem.begin(), all_elem.end());
	for (int64_t i = 0; i < n; ++i) {
		std::get<0>(vet[i]) = (int64_t) (std::lower_bound(all_elem.begin(), all_elem.end(), std::get<0>(vet[i])) - all_elem.begin());
		std::get<1>(vet[i]) = (int64_t) (std::lower_bound(all_elem.begin(), all_elem.end(), std::get<1>(vet[i])) - all_elem.begin());
	
	}

	std::sort(vet.begin(), vet.end(), [](const std::tuple<uint64_t, uint64_t, uint64_t> & a, const std::tuple<uint64_t, uint64_t, uint64_t> & b) { 
						  					return std::get<0>(a)<std::get<0>(b); 
						  				});

	int64_t size_ft = all_elem.size();

	fenwick_tree<int64_t> s(size_ft);
	for (int64_t i = 0; i < n; ++i) {
		s.add(std::get<1>(vet.at(i)), 1);
	}	

	std::vector<int64_t> res(n);
	for (int64_t i = 0; i < n; ++i) {
		res[std::get<2>(vet.at(i))]=s.sum(std::get<1>(vet.at(i)))-1;
		s.add(std::get<1>(vet.at(i)), -1);
	}

	for (int64_t i = 0; i < n; ++i) {
		std::cout << res[i] << std::endl;
	}

	return 0;
}