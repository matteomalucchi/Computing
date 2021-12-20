#include "fourvector_2.h"
#include <iostream>
int main()
{
 
 FourVectorE<float> p4_a(0,50.,7.,100.);
 FourVectorM<double> p4_b(50,0.5,1.7,10.);
 std::cout << (p4_a+p4_b).m() << std::endl;
}