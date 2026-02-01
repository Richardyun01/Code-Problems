// Union-Find
// two element belong to same group if they share a common factor
// standard Disjoint Set Union Class template
class DSU {
public:
    vector<int> par, sz;
    // initialization
    // each node's parent to be itself
    // fills the range with sequentially increasing values [0, 1, 2, ..., n]
    DSU(int n) : par(n), sz(n, 1) {
        iota(begin(par), end(par), 0);
    }
    // finds the id which represents the component that a node belongs to
    // x: the parent of the component that it belongs to
    // update parent of x before returning for each call-path compression
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    // joins the two components into a single component
    // find representive of x and y component and assigning common representative
    bool Union(int x, int y) {
        int xp = find(x), yp = find(y);
        // x, y belong to same component: cannot union
        if (xp == yp) {
            return false;
        }
        // union by size: join smaller sized to bigger one
        if (sz[xp] > sz[yp]) {
            par[yp] = par[xp];
            sz[xp] += sz[yp];
        } else {
            par[xp] = par[yp];
            sz[yp] += sz[xp];
        }
        return true;
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = size(nums), ans = 1;
        // max(nums): largest element that will be stored in DSU
        DSU ds(*max_element(begin(nums), end(nums)) + 1);
        // matains {parent of component : frequency}
        unordered_map<int, int> mp;
        for (auto c : nums) {
            // factors of each element
            for (int f = 2; f <= sqrt(c); f++) {
                // if f divides c then f and c / f are its factor -> union
                if (c % f == 0) {
                    ds.Union(c, f);
                    ds.Union(c, c/f);
                }
            }
        }
        //iterate and find parent that is seen most -> gives largest group
        for (int i = 0; i < n; i++) {
            ans = max(ans, ++mp[ds.find(nums[i])]);
        }
        return ans;
    }
};