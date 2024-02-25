#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, s, c, cnt;
    vector<int> diff;
    int prev_cow;
    int curr_cow;
    int first_cow;
    int last_cow;
    cin >> m >> s >> c;
    for (int i = 0; i < c; i++) {
        if (i == 0) {
            cin >> first_cow;
            prev_cow = first_cow;
            last_cow = first_cow;
        } else {
            cin >> curr_cow;
            if (curr_cow - prev_cow - 1 > 0) {
                diff.push_back(curr_cow - prev_cow - 1);
            } 
            prev_cow = curr_cow;
            if (i == c - 1) {
                last_cow = curr_cow;
            }
        }
    }
    if (m >= c) {
        cout << c << endl;
        return 0;
    }
    cnt = last_cow - first_cow + 1;
    if (diff.size() == 0) {
        cout << cnt << endl;
        return 0;
    }
    sort(diff.begin(), diff.end(), greater<int>());
    if (diff[0] > 0) {
        for (int i = 0; i < m - 1 && i < diff.size(); i++) {
            cnt -= diff[i];
        }
    }    
    cout << cnt << endl;
    return 0;
}