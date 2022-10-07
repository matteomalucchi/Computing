#include<TFile.h>
#include <TTree.h>
#include <TRandom.h>

void write_array (){
    TFile f("SimpleTree2.root","RECREATE"); // Create file first. The TTree will be associated to it
    TTree data("tree","Example TTree"); // No need to specify column names
    float myFloats[100];
    int nFloats;
    data.Branch("n",&nFloats,"n/I"); // Associate variable pointer to column and specify its type, double
    data.Branch("fl",myFloats,"fl[n]/F");
    for (int i = 0; i<32; ++i) {
        nFloats=gRandom->Uniform(0,30);
        for (int j=0;j<nFloats;j++){
           myFloats[j]=j*j; 
        }
    data.Fill(); // Make sure the values of the variables are recorded
    }
    data.Write(); // Dump on the file
    f.Close();
}
// per ogni evento ho un vettore

int main (){
    write_array();
}