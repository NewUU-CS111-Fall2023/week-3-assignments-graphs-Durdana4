#include <iostream>
#include <vector>

using namespace std;

class Transformation {
public:
    void transformation(int a, int b, vector<int>& res, int& step) {
        res.push_back(b);
        step += 1;
        if (a < b && (b % 2 != 0 || b % 10 != 1)) {
            if (b % 2 == 0) {
                b /= 2;
            } else if (b % 10 == 1) {
                b = (b - 1) / 10;
            }
            transformation(a, b, res, step);
        } else if (a > b) {
            cout << "No" << endl;
        } else if (a < b && b % 2 != 0 && b % 10 != 1) {
            cout << "No" << endl;
        } else if (a == b) {
            cout << "Yes" << endl;
            cout << step << endl;
            for (auto it = res.rbegin(); it != res.rend(); ++it) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Transformation number;
    int x, y;
    cout << "Please enter the two numbers! For example: 2 162" << endl;
    cin >> x >> y;

    vector<int> res1;
    int step1 = 0;
    number.transformation(x, y, res1, step1);

    return 0;
}