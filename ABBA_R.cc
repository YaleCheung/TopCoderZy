#include <iostream>
#include <string>
#include <algorithm>


using std::cin;
using std::cout;
using std::string;

class ABBA {
public:
    auto canObtain(const string base, const string expand) -> string {
        if (base == expand)
            return "Possible";
        if (base.size() > expand.size())
            return "Impossible";

        string addedA = addAToEnd_(base);
        string reverse = reverseAndAddB_(base);
        return (canObtain(addedA, expand) == "Possible") || 
                (canObtain(reverse, expand) == "Possible") ? "Possible" : "Impossible"; 
    }
private:
    auto addAToEnd_(const string& base) -> string {
        return {base + 'A'};
    }
    auto reverseAndAddB_(const string& base) -> string {
        string ret = base;
        std::reverse(ret.begin(), ret.end());
        return {ret + 'B'};
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
