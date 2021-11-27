#include "fourvector.h"
#include <iostream>
int main()
{
 double beta=4.5 ;
 FourVector p4_a(0,50.,7.,100.);
 FourVector p4_b(0,50.,7.,100.);
 //p4_a.setPx(10);
 std::cout << p4_a.m() << " " << p4_a.pt() << " " << p4_a.pz() << std::endl;
 std::cout << (p4_a+p4_b).m() << " " << (p4_a+p4_b).pt() << " " << (p4_a+p4_b).pz()<< std::endl;
 std::cout << (p4_a*beta).m() << " " << (p4_a*beta).pt() << " " << (p4_a*beta).pz()<< " " << (p4_a*beta).e()<< std::endl;
 std::cout << sqrt(p4_a.m()*p4_a.m()+p4_a.pz()*beta*p4_a.pz()*beta+p4_a.py()*beta*p4_a.py()*beta+p4_a.px()*beta*p4_a.px()*beta) << std::endl;
}