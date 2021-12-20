
void graph(){
    double x[]={1,2,3};
    double y[]={11,12,13};
    auto g=new TGraph(3,x,y);
    g->SetPoint(4,10,10);
    g->Draw("*");
}