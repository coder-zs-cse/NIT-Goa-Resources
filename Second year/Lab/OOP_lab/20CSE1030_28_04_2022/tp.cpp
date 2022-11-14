#include <iostream>
using namespace std;

class MATRIX
{
    int **arr;
    int M;
    int N;

public:
    MATRIX();
    MATRIX(int, int);
    MATRIX(const MATRIX *);
    void takeMatrix();
    MATRIX operator+(const MATRIX &);
    MATRIX operator-(const MATRIX &);
    bool operator==(const MATRIX &);
    ~MATRIX();
    friend ostream &operator<<(ostream &dout, const MATRIX &);
};

MATRIX::MATRIX()
{
    arr = NULL;
    M = N = -1;
}
MATRIX::MATRIX(int M, int N)
{
    this->M = M;
    this->N = N;
    this->arr = new int *[M];
    for (int i = 0; i < M; i++)
        this->arr[i] = new int[N];
}

MATRIX::MATRIX(const MATRIX *M)
{
    this->M = M->M;
    this->N = M->N;
    // delete[] this->arr;
    this->arr = new int *[this->M];
    for (int i = 0; i < this->M; i++)
        this->arr[i] = new int[this->N];
    for (int i = 0; i < this->M; i++)
    {
        for (int j = 0; j < this->N; j++)
            this->arr[i][j] = M->arr[i][j];
    }
}

MATRIX MATRIX ::operator+(const MATRIX &M)
{
    MATRIX M3;
    M3.M = M.M;
    M3.N = M.N;
    M3.arr = new int *[M3.M];
    for (int i = 0; i < M3.M; i++)
        M3.arr[i] = new int[M3.N];

    for (int i = 0; i < this->M; i++)
    {
        for (int j = 0; j < this->N; j++)
            M3.arr[i][j] = this->arr[i][j] + M.arr[i][j];
    }

    return &M3;
}

MATRIX MATRIX::operator-(const MATRIX &M)
{
    MATRIX M3;
    M3.M = M.M;
    M3.N = M.N;
    M3.arr = new int *[M3.M];
    for (int i = 0; i < this->M; i++)
        M3.arr[i] = new int[M3.N];

    for (int i = 0; i < this->M; i++)
    {
        for (int j = 0; j < this->N; j++)
            M3.arr[i][j] = this->arr[i][j] - M.arr[i][j];
    }

    return &M3;
}

void MATRIX::takeMatrix()
{

    if (arr == NULL)
    {
        int M, N;
        do
        {
            cout << "Enter the number of rows of given matrix" << endl;
            cin >> M;
            if (M <= 0)
                cout << "Error!Rows of a matrix cannot be negative or zero" << endl;
        } while (M <= 0);

        this->M = M;
        do
        {
            cout << "Enter the number of columns of given matrix" << endl;
            cin >> N;
            if (N <= 0)
                cout << "Error!columns of a matrix cannot be negative or zero" << endl;
        } while (N <= 0);

        this->N = N;

        arr = new int *[M];
        for (int i = 0; i < M; i++)
        {
            arr[i] = new int[N];
        }
        cout << "Enter the elements of the given matrix" << endl;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> arr[i][j];
            }
        }
    }
}

bool MATRIX ::operator==(const MATRIX &M)
{
    if (this->M == M.M && this->N == M.N)
        return true;
    return false;
}

ostream &operator<<(ostream &dout, const MATRIX &M1)
{

    for (int i = 0; i < M1.M; i++)
    {
        for (int j = 0; j < M1.N; j++)
        {
            cout << M1.arr[i][j] << " ";
        }
        cout << endl;
    }

    return dout;
}

MATRIX::~MATRIX()
{
    cout << "Destructor called" << endl;
    for (int i = 0; i < this->M; i++)
    {
        delete[] this->arr[i];
    }
    delete[] this->arr;
}

int main()
{
    MATRIX M3, M4;
    cout << "For M1:" << endl;
    MATRIX M1;
    M1.takeMatrix();

    cout << "Matrix M1 is:" << endl;
    cout << M1 << endl;

    cout << "For M2:" << endl;
    MATRIX M2;

    M2.takeMatrix();

    cout << "Matrix M2 is:" << endl;
    cout << M2 << endl;
    cout << M3 << M4;
    if (M1 == M2)
    {

        cout << "The sum of the given Matrices is:" << endl;
        M3 = M1 + M2;
        cout << M3;
        cout << "The difference of the given Matrices is:" << endl;
        M4 = M1 - M2;
        cout << M4;
    }

    else
    {
        cout << "Error! The order of the matrices must be same to carry out addition and subtraction" << endl;
    }

    return 0;
}