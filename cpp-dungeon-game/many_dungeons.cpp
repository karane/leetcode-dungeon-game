#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <chrono>   // For timing

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        int dp[m + 1][n + 1];
        memset(dp, 0x3f, sizeof dp);

        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Error opening file: " << argv[1] << endl;
        return 1;
    }

    int testCases;
    inputFile >> testCases;

    Solution sol;
    for (int t = 1; t <= testCases; ++t) {
        int rows, cols;
        inputFile >> rows >> cols;

        vector<vector<int>> dungeon(rows, vector<int>(cols));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                inputFile >> dungeon[i][j];
            }
        }

        // Start timing
        auto start = high_resolution_clock::now();

        int result = sol.calculateMinimumHP(dungeon);

        // End timing
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);

         cout << "Test Case #" << t
             << ": (" << rows << "x" << cols << ")"
             << " | Minimum initial health required = " << result
             << " | Time elapsed: " << duration.count() << " ms" << endl;
    }

    inputFile.close();
    return 0;
}
