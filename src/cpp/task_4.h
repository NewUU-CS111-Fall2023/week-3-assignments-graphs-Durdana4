#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

class Genome {
public:
    void GenerateGenome(int n, const std::string& str) {
        std::unordered_set<char> res;
        for (char j : str) {
            res.insert(j);
        }
        for (int i = 1; i < n; i++) {
            std::string fragment;
            std::cout << "Please enter " << i + 1 << " descriptions of a fragment: ";
            std::cin >> fragment;
            for (char j : fragment) {
                res.insert(j);
            }
        }
        std::string result;
        for (const char& c : res) {
            result.push_back(c);
        }
        std::sort(result.begin(), result.end());
        std::cout << result << std::endl;
    }
};

int main() {
    Genome obj;
    int n;
    std::cout << "Please enter the number of genome fragments: ";
    std::cin >> n;
    std::string fragment;
    std::cout << "Please enter 1 description of a fragment: ";
    std::cin >> fragment;
    obj.GenerateGenome(n, fragment);

    return 0;
}