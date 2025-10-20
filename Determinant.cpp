#include <vector>
#include <iostream>

std::vector<std::vector<int>> minor(int m, int r, int c, const std::vector<std::vector<int>>& matrix){

    std::vector<std::vector<int>> ret(m-1, std::vector<int>(m-1));

    int k = 0;
    int l = 0;

    for(int i = 0; i < m; i++){

        if(i == r) continue;

        l = 0;

        for(int j = 0; j < m; j++){
            
            if(j == c) continue;

            ret[k][l] = matrix[i][j];
            l++;

        }

        k++;
    }

    return ret;
    
}

std::vector<int> moreZeros(int m, const std::vector<std::vector<int>>& matrix){

    std::vector<int> more = {0, 0, 0};
    int rowCounter = 0;
    int colCounter = 0;

    for(int i = 0; i < m; i++){

        for(int j = 0; j < m; j++){

            if(matrix[i][j] == 0){

                rowCounter++;

                if(more[2] < rowCounter) {more = {0, i, rowCounter};} 

            }

            if(matrix[j][i] == 0){

                colCounter++;

                if(more[2] < colCounter) {more = {1, j, colCounter};}
            }
        }

        rowCounter = 0;
        colCounter = 0;
    }

    return more;
}

long long det(int m, const std::vector<std::vector<int>>& matrix){

    if(m==1){

        return matrix[0][0];
    }

    else{

        long long laplace = 0;
        std::vector<int> L = moreZeros(m, matrix);

        if(L[0]==0){

            for(int i = 0; i < m; i++){

                long long sign = ((L[1] + i) % 2 == 0) ? 1 : -1;

                if(matrix[L[1]][i] != 0) { laplace += sign * matrix[L[1]][i] * det(m-1, minor(m, L[1], i, matrix));}
            }
        }

        else{

            for(int i = 0; i < m; i++){

                long long sign = ((i + L[1]) % 2 == 0) ? 1 : -1;

                if(matrix[i][L[1]] != 0) { laplace += sign * matrix[i][L[1]] * det(m-1, minor(m, i, L[1], matrix));}
            }

        }

        return laplace;
    }
}

int main(){

    std::vector<std::vector<int>> A = {{1, 0, 0, 0},{0, 1, 0, 0},{0, 0, 1, 0},{0, 0, 0, 1}};
    std::vector<std::vector<int>> B = {{1, 0, 5, 8}, {0, 0, 9, 4}, {4, 8, 1, 1},{0, 5, 5, 0}};
    std::vector<std::vector<int>> C = {{4, 9 ,0}, {0, 7, 0}, {1, 1, 0}};

    std::cout << det(4, A);

    std::cout << std::endl << det(4, B);

    std::cout << std::endl << det(3, C);

    return 0;
}
