#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

class AB {
public:
    auto createString(const size_t input_size, const size_t pair_num) -> string {
        if (pair_num > input_size * input_size / 4)
            return "";
        string str(input_size, 'A');
        if(0 == pair_num )
            return str;
      
        auto pairs = 0; 

        int i = input_size - 1;
        auto num_B = 0;
        while(i > 0) {
            for(auto j = 1; j <= i; ++ j) {
                str.at(j - 1) = 'A';
                str.at(j) = 'B';
                ++ pairs;
                if (pairs == pair_num)
                    return str;
            }
            -- i;
            ++ num_B;
            pairs -= num_B;
        }
        // ret 
        return "";
    }
};

int main(int argc, char* argv[]) {
    unsigned int input_size = 0;
    unsigned int pair_num = 0;
    cin >> input_size >> pair_num;
    AB ab;
    cout << ab.createString(input_size, pair_num) << '\n';
    return 0; 
}
