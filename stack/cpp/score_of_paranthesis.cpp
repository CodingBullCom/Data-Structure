#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> en;
    int go(int lo, int hi) {
        if(lo+1 == hi) return 1;
        int mid = en[lo];
        if(mid == hi) return 2*go(lo+1, hi-1);
        return go(lo, mid) + go(mid+1, hi);
    }

    //calculates the score of string S
    //This is solution of my YouTube video "The Recursive Stack Problem on Strings"
    int scoreOfParentheses(string &S) {
        int i, n = (int)S.size();
        n = max(n, 1);
        en.resize(n, 0);
        stack<int> s;
        for(i=0; i<n; i++){
          print_vector();
            if(S[i] == ')'){
                int t = s.top();
                en[t] = i;
                s.pop();
            }
            else s.push(i);
        }
        return go(0, n-1);
    }

     void print_vector() {
       cout << endl;
       vector<int> :: iterator itr;
       for(itr = en.begin(); itr != en.end(); ++itr) {
         cout << *itr << " ";
       }
     }
};

int main() {

    Solution solution = Solution();
    string input = "(()(()))";
    int score = solution.scoreOfParentheses(input);
    cout << "\nScore of string " << input << " :: " << score << endl;
    input = "()(())";
    score = solution.scoreOfParentheses(input);
    cout << "\nScore of string " << input << " :: " << score << endl;
    return 0;
}
