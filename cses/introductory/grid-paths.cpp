#include <vector>
#include <iostream>
#include <queue>
 
using namespace std;
 
#define sl signed long long
 
sl xdir[4] = {-1, 1, 0, 0};
sl ydir[4] = {0, 0, 1, -1};
char lett[4] = {'U', 'D', 'R', 'L'};
 
vector<vector<sl>> visited(7, vector<sl>(7, 0));
template<typename T> void printV(vector<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}
 
// 48 - len = number of steps / degrees of freedom i have left
// (6-x) + (y-0) = number of steps i still need
bool calculate(sl x, sl y, sl len) {
    if ( (6 - x) + (y - 0) > (48 - len)) {
        return false;
    }
    return true;
}
 
bool checkbounds(sl x, sl y) {
    if (x >= 0 && x <= 6 && y >= 0 && y<= 6) {
        return true;
    } else {
        return false;
    }
}
 
sl counter = 0;
 
bool check_col(){
    for (sl i = 0; i < 7; i++) {
        if (visited[i][6] == 0) {
            return false;
        }
    }
    return true;
}
 
bool check_row() {
    for (sl i = 0; i < 7; i++) {
        if (visited[0][i] == 0) {
            return false;
        }
    }
    return true;
}
 
// Optimizations:
// If position[i] is different from to_find[i], immediately stop this path
// this is also dfs, so once a path is pruned, I can immediately 
 
void generate_paths(sl x, sl y, vector<char> &to_find, vector<char> &cur_path, sl len) {
    if (x == 6 && y == 0 && len == 48) {
        counter ++;
    } else {
        sl newx, newy;

        // optimization 2: if we are too early
        if (len != 47 && x == 6 && y == 0) {
            return;
        }
        
        // optimization 3:
        if (x == 6 && check_col() == false) {
            return;
        }
        
        if (y == 6 && check_row() == false) {
            return;
        }

        if (x == 6 && y < 6 && visited[x][y-1] == 0 && visited[x][y+1] == 0) {
            return;
        }

        if (y == 6 && x < 6 && x > 0 && visited[x-1][y] == 0 && visited[x+1][y] == 0) {
            return;
        }


        for (sl i = 0; i < 4; i++) {
            newx = x + xdir[i];
            newy = y + ydir[i];
 
            // optimization 1: if it is a letter, check that it is the correct letter
            if (to_find[len] != '?' && to_find[len] != lett[i]) {
                continue;
            }
            if (checkbounds(newx, newy) && visited[newx][newy] == 0) {
                // count number of steps lookahead
                // if there are not enough steps left to reach the end in the shortest route, terminate
                
                
                
                if (len > 40 && calculate(x, y, len) == false) {
                    return;
                }
                
                
                
                // if all the optimization checks pass, check this route and backtrack if it fails
                visited[newx][newy] = 1;
                cur_path.push_back(lett[i]);
                len += 1;
                generate_paths(newx, newy, to_find, cur_path, len);
                visited[newx][newy] = 0;
                cur_path.pop_back();
                len -= 1;
            }
        }
    }
}
 
// Idea: generate all paths first
int main() {
    string s;
    cin >> s;
    vector<char>to_find(s.begin(), s.end());
    visited[0][0] = 1;
    vector<char> cur_path;
    generate_paths(0, 0, to_find, cur_path, 0);
    cout << counter << endl;
 
    return 0;
}

