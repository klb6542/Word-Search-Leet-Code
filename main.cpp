#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> bboard;
    vector<vector<bool>> vis;

    bool findWord(int c, int i, string word) {
        bool success = false;
        word = word.substr(1, word.length());
        vis[c][i] = true;

        if (word.empty()) {
            return true;
        }

        // left
        if (i - 1 >= 0 && bboard[c][i - 1] == word[0] && vis[c][i - 1] == false && success == false) {
            success = findWord(c, i - 1, word);
            vis[c][i - 1] = false; // wont break because if success is true it will return
        }

        // right
        if (i + 1 < bboard[0].size() && bboard[c][i + 1] == word[0] && vis[c][i + 1] == false && success == false) {
            success = findWord(c, i + 1, word);
            vis[c][i + 1] = false;
        }

        // up
        if (c - 1 >= 0 && bboard[c - 1][i] == word[0] && vis[c - 1][i] == false && success == false) {
            success = findWord(c - 1, i, word);
            vis[c - 1][i] = false;
        }

        // down
        if (c + 1 < bboard.size() && bboard[c + 1][i] == word[0] && vis[c + 1][i] == false && success == false) {
            success = findWord(c + 1, i, word);
            vis[c + 1][i] = false;
        }

        return success;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> nvis(board.size(), vector<bool>(board[0].size()));
        int i = 0;
        int c = 0;

        vis = nvis;
        bboard = board;

        while (c <= board.size()) {
            if (i == board[0].size()) {
                i = 0;
                c++;
            }

            if (c == board.size()) {
                return false;
            }

            if (board[c][i] == word[0]) {
                bool success = findWord(c, i, word);

                if (success) {
                    return true;
                }
            }

            vis = nvis; // reset it
            i++;
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> m = { {'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'}};

    cout << s.exist(m, "ABCB") << endl; // 0 (false)

	return 0;
}
