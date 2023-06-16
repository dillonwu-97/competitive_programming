#include <vector>
#include <iostream>
#include <queue>
 
using namespace std;
 
#define sl signed long long
 
sl xdir[4] = {-1, 1, 0, 0};
sl ydir[4] = {0, 0, 1, -1};
char lett[4] = {'U', 'D', 'R', 'L'};
 
vector<vector<sl>> visited(9, vector<sl>(9, 0));
template<typename T> void printV(vector<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}
 
sl counter = 0;
 
bool check_col(){
    for (sl i = 0; i < 7; i++) {
        if (visited[i+1][7] == 0) {
            return false;
        }
    }
    return true;
}
 
bool check_row() {
    for (sl i = 0; i < 7; i++) {
        if (visited[1][i+1] == 0) {
            return false;
        }
    }
    return true;
}
 
void generate_paths(sl x, sl y, vector<char> &to_find, vector<char> &cur_path, sl len) {
    if (len == 48 && x == 7 && y == 1) {
        counter ++;
    } else {
        sl newx, newy;
        // optimization 2: if we are too early
        if (x == 7 && y == 1) {
            return;
        }

        // Special case of hitting real wall
//        if (x == 7 && y < 7 && visited[x][y-1] == 0 && visited[x][y+1] == 0) {
//
//      Special case of hitting artificial wall
 
        if (visited[x+1][y] == 1 && visited[x-1][y] == 1 && visited[x][y-1] == 0 && visited[x][y+1] == 0) {
            return;
        }


        if (visited[x][y+1] == 1 && visited[x][y-1] == 1 && visited[x-1][y] == 0 && visited[x+1][y] == 0) {
            return;
        }
        
        // optimization 3:
        if (x == 7 && !check_col()) {
            return;
        }
        
        if (y == 7 && !check_row()) {
            return;
        }
        
        for (sl i = 0; i < 4; i++) {
            newx = x + xdir[i];
            newy = y + ydir[i];
 
            // optimization 1: if it is a letter, check that it is the correct letter
            if (to_find[len] != '?' && to_find[len] != lett[i]) {
                continue;
            }
            if (visited[newx][newy] == 0) {
                // count number of steps lookahead
                // if there are not enough steps left to reach the end in the shortest route, terminate
                
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
    for (sl i = 0; i < 9; i++) {
        visited[0][i] = 1;
        visited[i][0] = 1;
        visited[i][8] = 1;
        visited[8][i] = 1;
    }
    vector<char>to_find(s.begin(), s.end());
    visited[1][1] = 1;
    vector<char> cur_path;
    generate_paths(1, 1, to_find, cur_path, 0);
    cout << counter << endl;
 
    return 0;
}

