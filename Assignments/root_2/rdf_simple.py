import ROOT
rdf=ROOT.RDataFrame("ntuple", "/home/matteo/root/tutorials/hsimple.root")
h=rdf.Filter("px>py").Histo1D(("pz", "isto", 10,-2,2),"pz")
h.Draw()

input()



