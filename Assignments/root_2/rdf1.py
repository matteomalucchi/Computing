import ROOT 

rdf = ROOT.RDataFrame("Events",
                      "Run2012B_DoubleMuParked.root")

print(rdf.GetColumnNames())
#rdf.Display().Print()
ROOT.gInterpreter.ProcessLine('''
#include "../hep_2/fourvector.h"
float invMass(float pt0,float eta0, float phi0, float pt1, float eta1, float phi1){
    VectorPtEtaPhiMass<float> mu0(pt0,eta0,phi0,0.106);
    VectorPtEtaPhiMass<float> mu1(pt1,eta1,phi1,0.106);
    return (mu0+mu1).m();
}
''')

sel=rdf.Filter("nMuon>1")\
    .Filter("Muon_pt[0]>40")\
    .Define("invMass","invMass(Muon_pt[0],Muon_eta[0],Muon_phi[0],Muon_pt[1],Muon_eta[1],Muon_phi[1])")
oppCharge=sel.Filter("Muon_charge[0]*Muon_charge[1]<0")
sameCharge=sel.Filter("Muon_charge[0]*Muon_charge[1]>0")

sel.Display(["nMuon","Muon_eta","Muon_pt","invMass"]).Print()

histOS=oppCharge.Histo1D(("invMassOS", "Invariant Mass OS",100,0,300),"invMass")
histSS=sameCharge.Histo1D(("invMassSS", "Invariant Mass SS",100,0,300),"invMass")

histOS.Draw()
#histSS.Draw()
'''outCols= ROOT.vector("std::string")() 
outCols.push_back("invMass")
outCols.push_back("invMass")
outCols.push_back("Muon_pt")
'''


oppCharge.Snapshot("Events","outNtuple.root",("invMass","nMuon","Muon_pt"))