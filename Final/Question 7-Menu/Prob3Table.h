#ifndef PROB3TABLE_H
#define PROB3TABLE_H

#include <fstream>

using namespace std;

template<class T>
class Prob3Table{
protected:
    int rows;       //Number of rows in the table
    int cols;       //Number of cols in the table
    T *rowSum;      //RowSum array
    T *colSum;      //ColSum array
    T *table;       //Table array
    T grandTotal;   //Grand total
    void calcTable(void); //Calculate all the sums
public:
    Prob3Table(char *,int,int); //Constructor
    ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
    const T *getTable(void){return table;};
    const T *getRowSum(void){return rowSum;};
    const T *getColSum(void){return colSum;};
    T getGrandTotal(void){return grandTotal;};
};

template<class T>
Prob3Table<T>::Prob3Table(char *file, int r, int c)
{
    rows = r;
    cols = c;

    table = new T[rows * cols];
    rowSum = new T[rows];
    colSum = new T[cols];

    // init to 0
    for(int i=0;i<rows*cols;i++) table[i]=0;
    for(int i=0;i<rows;i++) rowSum[i]=0;
    for(int j=0;j<cols;j++) colSum[j]=0;
    grandTotal = 0;

    ifstream fin(file);
    if(fin)
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                fin >> table[i*cols + j];
            }
        }
        fin.close();
    }

    calcTable();
}

template<class T>
void Prob3Table<T>::calcTable(void)
{
    // reset sums
    for(int i=0;i<rows;i++) rowSum[i]=0;
    for(int j=0;j<cols;j++) colSum[j]=0;
    grandTotal = 0;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            T val = table[i*cols + j];
            rowSum[i] += val;
            colSum[j] += val;
            grandTotal += val;
        }
    }
}

template<class T>
class Prob3TableInherited:public Prob3Table<T>{
protected:
    T *augTable; //Augmented Table with sums
public:
    Prob3TableInherited(char *,int,int); //Constructor
    ~Prob3TableInherited(){delete [] augTable;}; //Destructor
    const T *getAugTable(void){return augTable;};

    T *operator+(const Prob3TableInherited<T> &); //Extra Credit #3!!!

};

template<class T>
Prob3TableInherited<T>::Prob3TableInherited(char *file, int r, int c)
    : Prob3Table<T>(file, r, c)
{
    int r2 = this->rows + 1;
    int c2 = this->cols + 1;

    augTable = new T[r2 * c2];

    // fill with 0
    for(int i=0;i<r2*c2;i++) augTable[i]=0;

    // copy table
    for(int i=0;i<this->rows;i++)
    {
        for(int j=0;j<this->cols;j++)
        {
            augTable[i*c2 + j] = this->table[i*this->cols + j];
        }
    }

    // row sums (last col)
    for(int i=0;i<this->rows;i++)
    {
        augTable[i*c2 + (c2-1)] = this->rowSum[i];
    }

    // col sums (last row)
    for(int j=0;j<this->cols;j++)
    {
        augTable[(r2-1)*c2 + j] = this->colSum[j];
    }

    // grand total (bottom-right)
    augTable[(r2-1)*c2 + (c2-1)] = this->grandTotal;
}

template<class T> //#Extra Credit #3!!!
T * Prob3TableInherited<T>::operator+(const Prob3TableInherited<T> &rhs)
{
    int size = this->rows * this->cols;
    T *sum = new T[size];

    for(int i=0;i<size;i++)
        sum[i] = this->table[i] + rhs.table[i];

    return sum;
}

#endif
