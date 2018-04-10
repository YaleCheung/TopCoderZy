#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::sort;

// enumeration
class ASeries {
public:
    int longest(vector<int> seq) {
        sort(seq.begin(), seq.end());
        auto max_count = 1;
        auto max_diff = *seq.rbegin() - *seq.begin();
        for(auto diff = 0; diff <= max_diff; ++ diff) {
            for(auto order_pre = 0; order_pre < seq.size(); ++ order_pre) {
                auto count = 1;
                auto pre = seq.at(order_pre);
                for(auto order_post = order_pre + 1; order_post < seq.size(); ++ order_post) {
                    auto post = seq.at(order_post);
                    if (post - pre == diff) {
                        pre = post;
                        ++ count;
                    } else if (post - pre > diff)
                        break;
                }
                if (count > max_count)
                      max_count = count;
            }
        }
        return max_count;
    }
};

int main(int argc, char* argv[]) {
    vector<int> vec;
    vec.reserve(6000);
    auto ele = 0;
    while(cin >> ele) {
        vec.push_back(ele);
    }
    ASeries solution;
    cout << solution.longest(vec) << '\n';
    return 0;
}
