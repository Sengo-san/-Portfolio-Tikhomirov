
#include "matrix.h"

Matrix::Matrix (int dimm_, int dimn_)
{
    dimm = dimm_;
    dimn = dimn_;

    mas = new float* [dimm];
    for (int i = 0; i < dimm; i++){
        mas[i]=new float [dimn];
        for (int j = 0; j < dimn; j++)
        this->mas[i][j] = 0;
    }
}


Matrix::Matrix (float** b, int dimm_b, int dimn_b)
{
    dimm = dimm_b;
    dimn = dimn_b;
    mas = new float* [dimm];

    for (int i = 0; i < dimm; i++){
        mas[i]=new float [dimn];
        for (int j = 0; j < dimn; j++)
            mas[i][j] = b[i][j];
    }
}

Matrix::    Matrix (float b[3][3])
{
    dimm = 3;
    dimn = 3;
    mas = new float* [dimm];

    for (int i = 0; i < dimm; i++){
        mas[i]=new float [dimn];
        for (int j = 0; j < dimn; j++)
            mas[i][j] = b[i][j];
    }
}

Matrix::    Matrix (float b[4][4])
{
    dimm = 4;
    dimn = 4;
    mas = new float* [dimm];

    for (int i = 0; i < dimm; i++){
        mas[i]=new float [dimn];
        for (int j = 0; j < dimn; j++)
            mas[i][j] = b[i][j];
    }
}

Matrix::Matrix (float b[], int dim)
{
    dimm = 1;
    dimn = dim;
    mas = new float* [dimm];
    mas[0]=new float [dimn];

        for (int j = 0; j < dimn; j++)
            mas[0][j] = b[j];

}

Matrix::Matrix (const Matrix& x)//copying constructor
{
    this->dimm = x.dimm;
    this->dimn = x.dimn;

    mas = new float* [dimm];

    for (int i = 0; i < dimm; i++){
         mas[i]=new float[dimn];
         for (int j = 0; j < dimn; j++)
             mas[i][j] = x.mas[i][j];
    }

}

Matrix::Matrix (const Matrix& mat, int sm, int sn, int em, int en)
{
    this->dimm = em-sm+1;
    this->dimn = en-sn+1;

    this->mas = new float* [dimm];

    for (int i = 0; i < dimm ; i++){
        this->mas [i] = new float [dimn];
         for (int j = 0; j < dimm ; j++){
         this->mas[i][j] = mat.mas[i+sm][j+sn];
         }
    }

}


Matrix& Matrix::operator=(const Matrix& x)
{

    this->dimm = x.dimm;
    this->dimn = x.dimn;

    for (int i = 0; i < dimm; i++)
        for (int j = 0; j < dimn; j++)
            mas[i][j]=x.mas[i][j];

    return *this;
}



Matrix::~Matrix()
{
    delete[]mas;
}

Matrix Matrix::operator* (Matrix x)
{
    Matrix res (this->dimm,  x.dimn);

    for (int i = 0; i < dimm; i++)
        for (int j = 0; j < dimn; j++)
            for (int k = 0; k < res.dimn; k++)
                res.mas[i][j]+=mas[i][k] * x.mas[k][j];
    return res;
}

Matrix Matrix::operator* (float val)
{
    Matrix res (this->dimm,  this->dimn);

    for (int i = 0; i < dimm; i++)
        for (int j = 0; j < dimn; j++)
            res.mas[i][j]=mas[i][j] * val;
    return res;
}
