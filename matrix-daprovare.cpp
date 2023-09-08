#include <iostream>
#include <cmath>
#include <vector>

class Matrix
{
private:
    std::vector<int> matrix_{};
    int row_{};
    int col_{};

public:
    Matrix(std::vector<int> mat, int row, int col) : matrix_{mat}, row_{row}, col_{col} {}
    int getRow() const { return row_; }
    int getCol() const { return col_; }
    auto getMatrix() const { return matrix_; }

    int Get_ij(int i, int j) const 
    {
        return matrix_[col_ * (i - 1) + j - 1];
    }

    int Trace_ (Matrix) const
    {
        if (col_ != row_)
            throw std::runtime_error{"Can't calculate trace on non-square matrix"};
        int trace = 0;
        for (int i = 0; i < row_; i++)
        {
            trace += Get_ij(i, i);
        }
        return trace;
    }

    bool Simmetry() const //NON FUNZIONA
    {
        if (col_ != row_)
            return false;

        for (int i = 0; i < row_; i++)
        {
            for (int j = 0; j < col_; j++)
            {
                if (Get_ij(i, j) == Get_ij(j, i))
                    return true;
            }
        }
        return false;
    }

    /*bool operator==(Matrix const& mat1, Matrix const& mat2){
        if(mat1.col != mat2.col || mat1.row != mat2.row) return false;
       for (int i = 0; i != a.row; i++) {
    for (int j = 0; j != a.col; j++) {
      if (mat1.Get_ij(i,j) != mat2.Get_ij(i,j)) return false;
    }
  }
  return true; 
    }*/
    
};

int main()
{
    Matrix matrix(std::vector<int>{
                      1, 2, 2,
                      2, 3, 4,
                      4, 5, 12},
                  3, 3);
    Matrix matrix1(std::vector<int>{
                       1, 1,
                       2,2},
                   2, 2);
    std::cout << matrix.Get_ij(2, 2) << '\n';
    std::cout << matrix.Trace_(matrix) << '\n';
    std::cout << matrix1.Simmetry() << '\n'; // perché non va?
}