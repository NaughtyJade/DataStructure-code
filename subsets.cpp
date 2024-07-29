#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void powersetHelper(const vector<int>& S, vector<vector<int>>& result, vector<int>& current, int index) {
    if (index == S.size()) {
        result.push_back(current);
        return;
    }
    powersetHelper(S, result, current, index + 1);

    current.push_back(S[index]);
    powersetHelper(S, result, current, index + 1);
    current.pop_back();
}

vector<vector<int>> powerset(const vector<int>& S) {
    vector<vector<int>> result;
    vector<int> current;
    powersetHelper(S, result, current, 0);
    return result;
}

bool compareSets(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

int main() {
    vector<int> S = {1, 2, 3};

    vector<vector<int>> result = powerset(S);

    sort(result.begin(), result.end(), compareSets);

    cout << "集合 {1, 2, 3} 的冪集:" << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int element : subset) {
            cout << element << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}

