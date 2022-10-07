import ROOT
ROOT.gInterpreter.ProcessLine('#include "../hep_2/fourvector.h"')
rdf = ROOT.RDataFrame("Events", "Run2012B_DoubleMuParked.root")

#list available columns
print(rdf.GetColumnNames())
mass=rdf.Range(1000).Define("Muon_p4","ROOT::VecOps::Construct<VectorPtEtaPhiMass<float>>(Muon_pt,Muon_eta,Muon_phi,Muon_mass)")\
    .Define("goodmu","Muon_pt > 20 && abs(Muon_eta) < 2.0  ")\
    .Filter("Sum(goodmu)>=2")\
    .Define("index_mu0","Nonzero(goodmu)[0]")\
    .Define("oppositeCharge","goodmu && Muon_charge[index_mu0]*Muon_charge<0")\
    .Filter("Sum(oppositeCharge)>0")\
    .Define("index_mu1","Nonzero(oppositeCharge)[0]")\
    .Define("Dimuon_mass","(Muon_p4[index_mu0]+Muon_p4[index_mu1]).m()")\
    .Define("Muon_px","return ROOT::VecOps::Map(Muon_p4,[](auto & x){return x.px();});")

 

mass.Display("").Print()

#outCols=ROOT.vector("std::string")() #this creates a c++ std::vector<std::string> and wrap it in python
#outCols.push_back("Dimuon_mass") 

#mass.Snapshot("Events","out_complex.root",["event", "nMuon","goodmu","index_mu0","index_mu1","Dimuon_mass"])

import pandas
#print(pandas.DataFrame(mass.AsNumpy([  "nMuon","index_mu0","index_mu1","Dimuon_mass", "Muon_px"])))

