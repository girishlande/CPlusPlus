
#include <iostream>

class Matrix {
	private:
        int rows_, cols_;
        double **p;

    public:
        Matrix(int, int);  // constructor to initialize matrix to 0
        Matrix(double**, int, int);  // constructor to initialize matrix with input 2D array 
        Matrix();  // default constructor 
        ~Matrix();
        Matrix(const Matrix&);  // copy constructor
        
        Matrix& operator+=(const Matrix&);
        Matrix& operator-=(const Matrix&);
        
        friend std::ostream& operator<<(std::ostream&, const Matrix&);
        
        Matrix transpose();
		Matrix inverse();

        static Matrix createIdentity(int);
              
};

#endif