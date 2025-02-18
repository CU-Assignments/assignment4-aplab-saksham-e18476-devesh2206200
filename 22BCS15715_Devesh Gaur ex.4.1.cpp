#include <iostream>
#include <vector>
using namespace std;

vector<int> beautifulArray(int n) {
    vector<int> res = {1};
    while (res.size() < n) {
        vector<int> temp;
        for (int num : res) {
            if (2 * num - 1 <= n)
                temp.push_back(2 * num - 1);
        }
        for (int num : res) {
            if (2 * num <= n)
                temp.push_back(2 * num);
        }
        res = temp;
    }
    return res;
}

int main() {
    int n = 4;
    vector<int> result = beautifulArray(n);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
