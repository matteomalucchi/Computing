#include<TFile.h>
#include <TTree.h>
#include <TRandom.h>
#include <TSystem.h>
#include <vector>
#include <iostream>
#include "fourvector.h"

int main (){
    TFile f("SimpleTree3.root","RECREATE"); // Create file first. The TTree will be associated to it
    TTree data("tree","Example TTree"); // No need to specify column names
    int nParticles;
    std::vector<FourVector> particles;
    gInterpreter->GenerateDictionary( "std::vector<FourVector>","fourvector.h");
    gInterpreter->GenerateDictionary( "FourVector","fourvector.h");
    data.Branch("particles",&particles); // Associate variable pointer to column and specify its type, double
    for (int i = 0; i<32; i++) {
        nParticles=gRandom->Uniform(0,30);
        particles.clear();
        //particles.resize(nParticles);
        for (int j=0;j<nParticles;j++){
           particles.push_back(FourVector(gRandom->Gaus(3,2),i,j,j*j)); 
        }
    data.Fill(); // Make sure the values of the variables are recorded
    }
    data.Write(); // Dump on the file
    f.Close();
}
// per ogni evento ho un vettore