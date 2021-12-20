#include <TH1F.h>
#include <TF1.h>

void histo(){
auto *myF= new TF1("myF","x",0,16);
auto *h=new TH1F("h", "gaus", 64,0,16);
h->FillRandom("myF");
h->Draw();
//myF->SetParameters(250, 2);
//myF->Draw("Same");

}