import ROOT
v=ROOT.vector("float")(100)
print(v.size())
v.push_back(1)
v[0]=2
print(v[0])
print(v[100])
w=ROOT.vector("float")([1,2,3])
print(w[0])
