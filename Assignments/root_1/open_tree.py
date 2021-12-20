import ROOT
f=ROOT.TFile.Open("SimpleTree.root")
for row in f.tree:
    print(row.x)