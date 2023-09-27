#include <iostream>
using namespace std;

class Matrix
{
private:
    int row, col, **arr;

public:
    Matrix()
    {
        this->row = 1;
        this->col = 1;
        arr = NULL;
    }

    Matrix(int row, int col)
    {
        this->row = row;
        this->col = col;
        arr = new int *[row];

        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[col];
        }

        // this->row = row;
        // this->col = col;
    }

    void acceptMatrix()
    {
        cout << "Enter Value for matrix:" << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << "Enter Values:";
                cin >> arr[i][j];
            }
        }
    }

    friend void printMatrix(Matrix &m);

    void addMatrix(Matrix &m1, Matrix &m2, Matrix &m3)
    {
        cout << "Addition of Matrix:" << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                m3.arr[i][j] = m1.arr[i][j] + m2.arr[i][j];
                // cout<<m1.arr[i][j]+m2.arr[i][j]<<" ";
            }
        }

        printMatrix(m3);
    }

    void subMatrix(Matrix &m1, Matrix &m2, Matrix &m3)
    {
        cout << "Subtraction of Matrix:" << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                m3.arr[i][j] = m1.arr[i][j] - m2.arr[i][j];
                // cout<<m1.arr[i][j]-m2.arr[i][j]<<" ";
            }
        }

        printMatrix(m3);
    }

    void multiplyMatrix(Matrix &m1, Matrix &m2, Matrix &m3)
    {
        cout << "Matrix Multiply:" << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                m3.arr[i][j] = 0;
                for (int k = 0; k < col; k++)
                {
                    m3.arr[i][j] += m1.arr[i][k] * m2.arr[k][j];
                }
            }
            // cout<<endl;
        }

        // for(int i = 0;i<row;i++)
        // {
        //     for(int j=0;j<col;j++)
        //     {
        //         cout<<m3.arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        printMatrix(m3);
    }

    void transposeMatrix(Matrix &m1, Matrix &m3)
    {
        cout << "Transpose Matrix" << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                m3.arr[i][j] = m1.arr[j][i];
            }
        }
        printMatrix(m3);
    }
};

void printMatrix(Matrix &m)
{
    cout << "Matrix is:" << endl;
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
            cout << m.arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int r, c;
    cout << "Enter row,col";
    cin >> r >> c;
    Matrix m(r, c);
    Matrix m2(r, c);
    Matrix m3(r, c);
    m.acceptMatrix();
    printMatrix(m);
    m2.acceptMatrix();
    printMatrix(m2);
    m.addMatrix(m, m2, m3);
    m3.multiplyMatrix(m, m2, m3);
    m.subMatrix(m, m2, m3);
    m.transposeMatrix(m, m3);

    return 0;
}