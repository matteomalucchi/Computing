import ROOT
from array import array
g=ROOT.TGraph(3,array('d',[10,2,3]),array('d',[0,3,4]))
g.Draw()