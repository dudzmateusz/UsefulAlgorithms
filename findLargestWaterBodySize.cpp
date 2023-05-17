#include <iostream>
#include <vector>

int findLargestWaterBodySize(std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int largestWaterBodySize = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                int currentWaterBodySize = 0;
                std::vector<std::pair<int, int>> stackData;
                stackData.push_back(std::make_pair(i, j));

                while (!stackData.empty()) {
                    int row = stackData.back().first;
                    int column = stackData.back().second;
                    stackData.pop_back();

                    if (row >= 0 && row < rows && column >= 0 && column < cols && grid[row][column] == 1) {
                        grid[row][column] = 0;
                        currentWaterBodySize++;
                        stackData.push_back(std::make_pair(row, column + 1));
                        stackData.push_back(std::make_pair(row, column - 1));
                        stackData.push_back(std::make_pair(row + 1, column));
                        stackData.push_back(std::make_pair(row - 1, column));
                    }
                }
                largestWaterBodySize = std::max(largestWaterBodySize, currentWaterBodySize);
            }
        }
    }
    return largestWaterBodySize;
}

int main() {
    std::vector<std::vector<int>> grid = {
            {0, 0, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 1, 1, 1, 0, 1},
            {1, 0, 0, 1, 1, 0, 0, 0},
            {1, 1, 0, 1, 0, 0, 0, 0},
            {1, 0, 0, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 1}
    };
    std::cout << findLargestWaterBodySize(grid);

    return 0;
}
