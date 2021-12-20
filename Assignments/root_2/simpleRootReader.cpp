#include <TFile.h>
#include <TTree.h>
#include <iostream>
#include <TH1F.h>


TH1F* simpleRootReader(){
    float px,py,pz,random,i;
    TH1F* hist=new TH1F("hist", "isto", 10,-2,2);
    TFile f("/home/matteo/root/tutorials/hsimple.root");
    TTree *t=(TTree *) f.Get("ntuple");
    t->SetBranchAddress("px",&px);
    t->SetBranchAddress("py",&py);
    t->SetBranchAddress("pz",&pz);
    t->SetBranchAddress("random",&random);
    t->SetBranchAddress("i",&i);

    for(int j=0; j<t->GetEntries(); j++){
            t->GetEntry(j);
            if (py>px) hist->Fill(pz);
            //std::cout<< px << std::endl;
            // ogni interazione mette il valore della colonna "px"
            // nell'indirizzo puntaot da &px
    }
    hist->Draw();
    return hist;
}
