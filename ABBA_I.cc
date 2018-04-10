#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;

class ABBA {
public: 
    auto canObtain(const string& base, string& expand) {
        size_t base_size = base.size();
        while(base_size < expand.size()) {
            if (expand.back() == 'A')
                expand.pop_back();
            else {
                expand.pop_back();
                std::reverse(expand.begin(), expand.end());
            }
        }

        if (expand == base)
            return "Possible";
        return "Impossible";
    }
};

int main(int argc, char* argv[]) {
    string base;
    string expand;
    cin >> base >> expand;
    ABBA solution;
    cout << solution.canObtain(base, expand) << '\n';
    return 0;
}
