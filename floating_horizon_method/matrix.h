#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{

    int dimm; //строк (массивчиков)
    int dimn; //столбцов

private:
    float **mas;
public:

    int GetDimn() {return dimn;}
    int GetDimm() {return dimm;}

    Matrix (const Matrix& mat, int sm, int sn, int em, int en);  // иницализация куском матрицы от [sn, sm] до [en, em]
    Matrix (int dimm_, int dimn_);
    Matrix (float** b, int dimm_b, int dimn_b);
    Matrix (float b[3][3]);
    Matrix (float b[4][4]);
    Matrix (float b[], int dim);



    Matrix(const Matrix&);  //copying constructor

    ~Matrix();

    float get (int i, int j) { return this->mas[i][j]; };
    void set (float val, int i, int j) { this->mas[i][j] = val; };
    Matrix& operator= (const Matrix&);
    Matrix operator* (Matrix x);
    Matrix operator* (float k);


};


#endif // MATRIX_H
