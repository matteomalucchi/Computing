import ROOT


'''
cppstring="int myFunc(const std::string & s){return s.size();}"
ROOT.gInterpreter.ProcessLine(cppstring)
print(ROOT.myFunc("PIPPO"))
'''
'''
ROOT.gInterpreter.ProcessLine('#include "myFunc.h"' )
print(ROOT.myFunc("PIPP0"))
'''

'''
ROOT.gInterpreter.ProcessLine('#include "myFunc_lib.h"' )
ROOT.gInterpreter.ProcessLine('.L myFunc_lib.cpp+' )
ROOT.gSystem.Load("myFunc_lib_cpp.so")
print(ROOT.myFunc("PIPP"))
'''

#gcc -fPIC -shared -o myFunc_lib.so myFunc_lib.cpp
ROOT.gSystem.Load("myFunc_lib.so")
ROOT.gInterpreter.ProcessLine('#include "myFunc_lib.h"' )
print(ROOT.myFunc("PIPP"))

