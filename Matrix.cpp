#include <iostream>
#include "Point.hpp"
#include "Matrix1.hpp"

int main(){

  	Point p0;
  	Point p1 = 1.;
  
 	std::cout << "Points: " << p0 << " , " << p1 << std::endl;

  	Matrix<Point> m = {5,5};
  	m.FillMagickNE();
  	std::cout << "Matrix: " << m ;
	
	Matrix<Point> test = {3,4};
        Matrix<Point> two = {4,5};
        
        test.FillMagickNE();
        std::cout<< test;
        
        two.FillMagickNE();
        std::cout<<two << '\n' << "Ahtung!\n";
 //       Matrix<Point> r = test * two;
        
   //     std::cout << r << "All good\n";
        
        Matrix<Point> qw = {5,5};
        Matrix<Point> we = {5,5};
        qw.FillMagickNE();
        we.FillMagickNE();
        std::cout << "qw Matrix:\n"<< qw << "we Matrix:\n" << we<< "operator +\n" << qw+we << "AddMatrix\n";
        std::cout <<we.AddMatrix(qw);
//        qw.WriteMatrix();
//      qw.DelMatrix(we);
        //std::cout << we;
	
}
