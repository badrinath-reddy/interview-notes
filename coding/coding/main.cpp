#include <iostream>
#include <set>

using namespace std;


vector<bool> solution(vector<vector<int>> operations) {
    set<int> s;
    vector<bool> ans;
    
    for(auto &x: operations) {
        if (x[0] == 1) {
            s.insert(x[1]);
        }
        else {
            auto slb = s.lower_bound(x[1]);
            if(slb == s.end()) {
                ans.push_back(1);
            } else {
                if((*slb) - x[1] < x[2]) {
                    ans.push_back(0);
                }
                else {
                    ans.push_back(1);
                }
            }
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    
    auto x = solution({{1, 2}, {1, 5}, {2, 3, 2}, {2, 3, 3}, {2, 1, 1}, {2, 1, 2}});
    for(auto k : x) {
        cout << k << " ";
    }
    cout << endl;
    return 0;
}
