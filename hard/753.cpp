class Solution {
public:
    string crackSafe(int n, int k) {
        int kn = pow(k, n), kn_1 = pow(k, n-1), num[kn_1];
        fill(num, num + kn_1, k-1);
        string s(kn + (n-1), '0');
        for(int i = n-1, node = 0; i < s.size(); ++i) {
            s[i] = num[node]-- + '0';
            node = node*k - (s[i-(n-1)]-'0')*kn_1 + num[node] + 1;
        }
        return s;
    }
};
