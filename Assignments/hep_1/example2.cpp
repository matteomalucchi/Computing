#include "particle.h"
#include <iostream>
#include <cfloat>
#include <string>
int main()
{
 Particle photon(FourVector(0,50.,7.,100.), 22, DBL_MAX);
 photon.setPx(10);
 std::cout << photon.pid() <<" " << photon.pz() <<" " << photon.px()<< std::endl;

}