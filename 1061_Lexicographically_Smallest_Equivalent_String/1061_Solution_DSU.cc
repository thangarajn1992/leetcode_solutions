/*
Algorithm :
DSU Approach:
1. We can use Disjoint Set Union (DSU) or Union-Find Data structure to keep track of characters that are equal.
2. Always select a lexicographically smaller character to represent the union.
3. While performing union, join lexicographically bigger root to smaller root.
4. For baseStr, for each character, find the representative of the union to which that character belongs and replace it with that representative. 
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> representative;
    
    // Returns the root representative of the component.
    int find(int x) {
        if (representative[x] == x) {
            return x;
        }
        
        return representative[x] = find(representative[x]);
    }
    
    // Perform union if x and y aren't in the same component.
    void performUnion(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x == y) {
            return;
        }
        
        // Make the smaller character representative.
        if (x < y) {
            representative[y] = x;
        } else {
            representative[x] = y;
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // Make each character representative of itself.
        representative.resize(26);
        for (int i = 0; i < 26; i++) {
            representative[i] = i;
        }
        
        // Perform union merge for all the edges.
        for (int i = 0; i < s1.size(); i++) {
            performUnion(s1[i] - 'a', s2[i] - 'a');
        }
        
        string ans;
        // Create the answer string with final mappings.
        for (char c : baseStr) {
            ans += (char)(find(c - 'a') + 'a');
        }
        
        return ans;
    }
};