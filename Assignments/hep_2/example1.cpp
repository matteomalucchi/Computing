#include "fourvector.h"
#include <iostream>
int main()
{
 
 VectorXYZT<float> p4_a(0,50.,7.,100.);
 VectorPtEtaPhiMass<double> p4_b(50,0.5,1.7,10.);

 //VectorXYZT<double> p4_c;
 //p4_c=p4_b;
 //stessa cosa se faccio:
 VectorXYZT<double> p4_c(p4_b);

 std::cout << p4_a.m() << " " << p4_a.pt() << std::endl;
 std::cout << p4_b.m() << " " << p4_b.pt() << std::endl;
 std::cout << p4_c.m() << " " << p4_c.pt() << std::endl;
 std::cout << (p4_a+p4_b).m() << " " << (p4_a+p4_b).pt() << std::endl;
}