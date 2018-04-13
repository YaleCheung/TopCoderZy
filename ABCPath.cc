#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::vector;

class ABCPath {
    const int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int y[8] = {-1,  0,  1,-1, 1,-1, 0, 1};
    int dfs_(const vector<string>& vec, int row, int col, char letter) {
        int max = 0;
        for(int i = 0; i < 8; ++ i) {
            if (row + x[i] < 0 || row + x[i] >= vec.size() || col + y[i] < 0 || col + y[i] >= vec[0].size())
                continue;
            auto cur_depth = 0;
            if (vec.at(row).at(col) == letter) {
                cur_depth = dfs_(vec, row + x[i], col + y[i], letter + 1) + 1;
                if (cur_depth > max)
                    max = cur_depth;
            } else 
                return 0;
        }
        return max;
    }
public:
    int length(const vector<string>& vec) {
        char letter = 'A';
        int ret = 0;
        for(int i = 0; i < vec.size(); ++ i) {
            for(auto j = 0; j < vec[0].size(); ++ j) {
                if (vec.at(i).at(j) == letter) {
                    int depth = dfs_(vec, i, j, 'A');
                    if (depth > ret)
                        ret = depth;
                }
            }
        }
        cout << ret << '\n';
        return ret;
    }
};

int main(int argc, char* argv[]) {
    vector<string> vec{ "ABE", "CFG", "BDH", "ABC" };
    ABCPath abc;
    abc.length(vec);
    return 0;
}
