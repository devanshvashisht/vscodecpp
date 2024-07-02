#include <iostream>
#include <vector>

class Search {
public:
    bool linear_search(std::vector<int> data, int target) {
        for (int item =0;item< data.size();item++) {
            if (item == target) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    std::vector<int> data = {2, 81, 7, 3};
    Search search;
    
    std::cout << search.linear_search(data, 2) << std::endl;  // Output: 1 (true)
    std::cout << search.linear_search(data, 81) << std::endl;  // Output: 1 (true)
    std::cout << search.linear_search(data, 7) << std::endl;  // Output: 1 (true)
    std::cout << search.linear_search(data, 3) << std::endl;  // Output: 1 (true)
    std::cout << search.linear_search(data, 4) << std::endl;  // Output: 0 (false)

    return 0;
}