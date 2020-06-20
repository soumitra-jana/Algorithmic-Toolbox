#include <iostream>
#include <vector>
#include <algorithm>

bool sort_by_value_per_weight(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return (a.first / (double)a.second) > (b.first / (double)b.second);
}

double get_optimal_value(int capacity, std::vector<int> weights, std::vector<int> values)
{
    double value = 0.0;
    int n = weights.size();

    std::vector<std::pair<int, int>> value_weight_pairs;

    for (int i = 0; i < n; i++)
    {
        value_weight_pairs.push_back(std::make_pair(values[i], weights[i]));
    }

    std::sort(value_weight_pairs.begin(), value_weight_pairs.end(), sort_by_value_per_weight);

    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
            return value;

        int current_capacity = std::min(value_weight_pairs[i].second, capacity);
        capacity -= current_capacity;
        value += current_capacity * (value_weight_pairs[i].first / (double)value_weight_pairs[i].second);
    }

    return value;
}

int main()
{
    int n;
    int capacity;

    std::cin >> n >> capacity;
    std::vector<int> values(n);
    std::vector<int> weights(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;

    return 0;
}
