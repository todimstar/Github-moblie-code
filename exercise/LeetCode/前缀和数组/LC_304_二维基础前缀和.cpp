#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> summatrix;
    int row_len,col_len;

    NumMatrix(vector<vector<int>>& matrix) {
        row_len=matrix.size();
        col_len=matrix[0].size();
        
        //梦寐以求的快速创建前缀和矩阵空间，之前太人机了,c风格的手动创建，还没想到多加一行一列应对边界问题
        summatrix = vector<vector<int>>(row_len+1,vector<int>(col_len+1,0));//初始化

        //通用性构造前缀和矩阵
        for(int i=1;i<=row_len;i++){
            for(int j=1;j<=col_len;j++){
                summatrix[i][j] += matrix[i-1][j-1] +//注意matrix的索引要-1
                                    summatrix[i][j-1]+summatrix[i-1][j] -
                                    summatrix[i-1][j-1];//大功告成
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // 注意索引需要+1，因为前缀和矩阵有额外的一行一列
        row1++; col1++; row2++; col2++;
        return summatrix[row2][col2]-summatrix[row2][col1-1]-summatrix[row1-1][col2]+summatrix[row1-1][col1-1];
    }
};

int main() {
    // 测试用例1
    vector<vector<int>> matrix1 = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    
    NumMatrix numMatrix1(matrix1);
    
    cout << "测试用例1:" << endl;
    cout << "sumRegion(2, 1, 4, 3) = " << numMatrix1.sumRegion(2, 1, 4, 3) << ", 期望值: 8" << endl;
    cout << "sumRegion(1, 1, 2, 2) = " << numMatrix1.sumRegion(1, 1, 2, 2) << ", 期望值: 11" << endl;
    cout << "sumRegion(1, 2, 2, 4) = " << numMatrix1.sumRegion(1, 2, 2, 4) << ", 期望值: 12" << endl;
    
    // 测试用例2
    vector<vector<int>> matrix2 = {
        {-4, -5}
    };
    
    NumMatrix numMatrix2(matrix2);
    
    cout << "\n测试用例2:" << endl;
    cout << "sumRegion(0, 0, 0, 0) = " << numMatrix2.sumRegion(0, 0, 0, 0) << ", 期望值: -4" << endl;
    cout << "sumRegion(0, 0, 0, 1) = " << numMatrix2.sumRegion(0, 0, 0, 1) << ", 期望值: -9" << endl;
    
    return 0;
}