#ifndef PROB2SORT_H
#define PROB2SORT_H

using namespace std;

//This class sorts arrays either ascending or descending
template<class T>
class Prob2Sort{
private:
    int *index; //Index that is utilized in the sort
public:
    Prob2Sort(){index=NULL;}        //Constructor
    ~Prob2Sort(){delete [] index;}  //Destructor

    T * sortArray(const T*,int,bool);                 //1D sort
    T * sortArray(const T*,int,int,int,bool);         //2D sort (1D rep)
};

template<class T>
T * Prob2Sort<T>::sortArray(const T *arr, int size, bool asc)
{
    if(c < 1) c = 1;
    if(c > col) c = col;

    if(index) delete [] index;
    index = new int[size];

    // init index
    for(int i=0;i<size;i++) index[i]=i;

    // selection sort on index
    for(int i=0;i<size-1;i++)
    {
        int sel=i;
        for(int j=i+1;j<size;j++)
        {
            T a = arr[index[j]];
            T b = arr[index[sel]];

            if(asc)
            {
                if(a < b) sel=j;
            }
            else
            {
                if(a > b) sel=j;
            }
        }
        int tmp=index[i];
        index[i]=index[sel];
        index[sel]=tmp;
    }

    // build sorted output
    T *out = new T[size];
    for(int i=0;i<size;i++)
        out[i]=arr[index[i]];

    return out;
}

template<class T>
T * Prob2Sort<T>::sortArray(const T *arr, int row, int col, int c, bool asc)
{
    if(index) delete [] index;
    index = new int[row];

    // init index by row
    for(int i=0;i<row;i++) index[i]=i;

    // selection sort rows by column c
    for(int i=0;i<row-1;i++)
    {
        int sel=i;
        for(int j=i+1;j<row;j++)
        {
            T a = arr[index[j]*col + (c-1)];
            T b = arr[index[sel]*col + (c-1)];

            if(asc)
            {
                if(a > b) sel=j;
            }
            else
            {
                if(a < b) sel=j;
            }
        }
        int tmp=index[i];
        index[i]=index[sel];
        index[sel]=tmp;
    }

    // build sorted output (copy full rows)
    T *out = new T[row*col];
    for(int i=0;i<row;i++)
    {
        int r = index[i];
        for(int j=0;j<col;j++)
        {
            out[i*col + j] = arr[r*col + j];
        }
    }

    return out;
}

#endif
