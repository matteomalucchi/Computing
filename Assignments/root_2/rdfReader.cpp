#include <ROOT/RDataFrame.hxx>
#include <TH1D.h>

auto rdfReader(){
    auto rdf=ROOT::RDataFrame("ntuple", "/home/matteo/root/tutorials/hsimple.root");
    //auto h=rdf.Filter("px>py").Histo1D({"pz", "isto", 10,-2,2},"pz");
    auto h=rdf.Filter("px>py").Define("somma","px+py").Histo1D({"pz", "isto", 10,-2,2},"somma");

    h->Draw();
    return h;

}

