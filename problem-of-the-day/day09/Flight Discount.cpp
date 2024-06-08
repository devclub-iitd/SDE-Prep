#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::vector;

/**
 * given a start point, and an adjacency list with costs,
 * this function gives an array with the minimum distances
 * from all the other nodes to the start node
 * (the value is INT64_MAX if unreachable)
 */
vector<long long> min_costs(int from,
                            const vector<vector<pair<int, int>>> &neighbors) {
	vector<long long> min_costs(neighbors.size(), INT64_MAX);
	min_costs[from] = 0;
	std::priority_queue<pair<long long, int>> frontier;
	frontier.push({0, from});
	while (!frontier.empty()) {
		pair<long long, int> curr_state = frontier.top();
		frontier.pop();
		int curr = curr_state.second;
		if (-curr_state.first != min_costs[curr]) { continue; }

		for (auto [n, nc] : neighbors[curr]) {
			long long new_cost = min_costs[curr] + nc;
			if (new_cost < min_costs[n]) {
				min_costs[n] = new_cost;
				frontier.push({-new_cost, n});
			}
		}
	}
	return min_costs;
}

int main() {
	int city_num;
	int flight_num;
	std::cin >> city_num >> flight_num;
	vector<vector<pair<int, int>>> neighbors(city_num);
	vector<vector<pair<int, int>>> reverse_neighbors(city_num);
	for (int f = 0; f < flight_num; f++) {
		int from;
		int to;
		int cost;
		std::cin >> from >> to >> cost;
		neighbors[--from].push_back({--to, cost});
		reverse_neighbors[to].push_back({from, cost});
	}

	vector<long long> start_costs = min_costs(0, neighbors);
	vector<long long> end_costs = min_costs(city_num - 1, reverse_neighbors);
	long long total_min = INT64_MAX;
	for (int c = 0; c < city_num; c++) {
		for (auto [n, nc] : neighbors[c]) {
			if (start_costs[c] == INT64_MAX || end_costs[n] == INT64_MAX) {
				continue;
			}
			total_min =
			    std::min(total_min, start_costs[c] + (nc / 2) + end_costs[n]);
		}
	}
	cout << total_min << endl;
}