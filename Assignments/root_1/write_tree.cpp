#include<TFile.h>
#include <TTree.h>
#include <TRandom.h>

int main (){
    TFile f("SimpleTree.root","RECREATE"); // Create file first. The TTree will be associated to it
    TTree data("tree","Example TTree"); // No need to specify column names
    double x, y, z, t;
    data.Branch("x",&x,"x/D"); // Associate variable pointer to column and specify its type, double
    data.Branch("y",&y,"y/D");
    data.Branch("z",&z,"z/D");
    data.Branch("t",&t,"t/D");
    for (int i = 0; i<1024; ++i) {
    x = gRandom->Uniform(-10,10);
    y = gRandom->Gaus(0,5);
    z = gRandom->Exp(10);
    t = gRandom->Landau(0,2);
    data.Fill(); // Make sure the values of the variables are recorded
    }
    data.Write(); // Dump on the file
    f.Close();
}

//g++ write_tree.cpp -o wt `root-config --cflags --libs`
// root SimpleTree.root
//_file0->ls()
// t=(TTree *)_file0->Get("tree")
//t->Print()
//t->Scan()
//t->Draw("x")