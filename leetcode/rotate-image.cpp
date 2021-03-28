class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int layers = matrix.size() / 2 ;
        int size = matrix.size() - 1;
        int temp, start, end;
        start = 0;
        end = matrix.size() - 1;
        if (size == 1) {
            temp = matrix[0][0];
            matrix[0][0] = matrix[1][0];
            matrix[1][0] = matrix[1][1];
            matrix[1][1] = matrix[0][1];
            matrix[0][1] = temp;
        } else {
            // cout << layers << endl;
            for (int i = 0; i < layers; i++) {
                // cout << "i is " + to_string(i) << endl;
                for (int j = start; j < end; j++) {
                    // cout << "j is " + to_string(j) << endl;
                    // cout << "size - j is " + to_string (size - j) << endl;
                    temp = matrix[i][j];
                    matrix [i][j] = matrix[size - j][i];
                    matrix[size - j][i] = matrix[size - i][size - j];
                    matrix[size - i][size - j] = matrix[j][size - i];
                    matrix[j][size - i] = temp;
                    // cout << temp << endl;
                    // break;
                    // temp = matrix[j][j];
                    // matrix[j][j] = matrix[size - j][j];
                    // matrix[size - j][j] = matrix[size-j][size-j];
                    // matrix[size-j][size-j] = matrix[j][size-j];
                    // matrix[j][size-j] = temp;
                    // if (j == 1) {
                    //     break;
                    // }
                }
                start +=1;
                end -=1;
                // size -= 1; // cant subtract because need size for get the 
                    edge of matrix 
            }
        }
    }
    };