#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
#define sl signed long long
#define UNV -1
#define VIS -2
#define VISITING -3


// push node into the stack, and keep going until a cycle is detected
// once cycle is detected, pop until the starting value is reached
// after starting value is reached, pop the rest and add to the size of the cycle 
// 
// for each new node, it is either something new, or it goes into an existing node. if it goes into an existing node, just keep track of the values needed to be popped
int main() {
    sl n, t;
    cin >> n;
    vector<sl> visited (n+1, UNV);
    vector<sl> children (n+1, UNV);
    vector<sl> ret( n+1, -1);
    vector<sl> v;
    for (sl i = 0; i < n; i++) {
        cin >> t;
        children[i+1] = t; // i+1 -> t
    }

    sl current = UNV, tracker = UNV, counter = 0;
    for (sl k = 1; k < n+1; k++) {
        if (visited[k] == UNV) {
            v.clear();
            // this keeps going until we have reached a visiting of visited node
            tracker = k;
            while (visited[tracker] == UNV) {
                v.push_back(tracker);
                visited[tracker] = VISITING;
                tracker = children[tracker];
            }

            current = tracker;
            // new cycle was discovered
            if (visited[tracker] == VISITING) {
                counter = 1;
                for (sl i = v.size()-1; i >= 0; i--) {
                    counter ++;
                    if (v[i] == current) {
                        break;
                    }
                }
                
                sl flag = 0;
                for (sl i = v.size()-1; i >= 0; i--) {
                    
                    visited[ v[i] ] = VIS;
                    if (flag == 0) {
                        ret[ v[i] ] = counter;         
                        if (v[i] == current) {
                            flag = 1;
                        }
                    } else {
                        counter ++;
                        ret[ v[i] ] = counter;
                    }
                }
                
                // if there is still stuff in the stack

            } else {
            // old cycle was discovered
                counter = ret[current];
                for (sl i = v.size() -1; i >= 0; i--) {
                    visited[ v[i] ] = VIS;
                    counter ++;
                    ret[ v[i] ] = counter;
                }

            }

        }
    }
    for (sl i = 1; i < ret.size();i++) {
        cout << ret[i]-1 << " ";
    }
    cout << endl;
    
    return 0;
}
