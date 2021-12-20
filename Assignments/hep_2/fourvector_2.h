#ifndef FOURVECTOR2_H
#define FOURVECTOR2_H
#include <math.h>

template <class T>
class FourVectorE {
    public:
    //salvo il tipo della variabile che metto in fourvector (eg:doule, int,...)
    typedef T numberType;
      FourVectorE() {}
      FourVectorE(T  px, T  py, T  pz, T  energy) :
	      m_px(px),m_py(py), m_pz(pz), m_e(energy) {
          //nothing special to do
        }
      //getters
      T px() const { return m_px;}
      T py() const { return m_py;}
      T pz() const { return m_pz;}
      T e() const { return m_e;}
      T pt() const { return sqrt(px()*px()+py()*py());}
      T m() const { return sqrt(m_e*m_e-(m_px*m_px+m_py*m_py+m_pz*m_pz));}
      /*
      template <class T2>
      FourVectorE<T> operator+(const T2 & other) const {
	      FourVectorE ret(m_px+other.px(), m_py+other.py(),m_pz+other.pz(),m_e+other.e());
	      return ret;
      }*/
      //setters
      void setPx(T px) {m_px=px;}
      void setPy(T py) {m_py=py;}
      void setPz(T pz) {m_pz=pz;}
      void setE(T e) {m_e=e;}

    private:
      T m_px;
      T m_py;
      T m_pz;
      T m_e;

};



template <class T>
class FourVectorM {
    public:
      typedef T numberType;
      FourVectorM() {}
      FourVectorM(T  px, T  py, T  pz, T  mass) :
	      m_px(px),m_py(py), m_pz(pz), m_m(mass) {
          //nothing special to do
        }
      //getters
      T px() const { return m_px;}
      T py() const { return m_py;}
      T pz() const { return m_pz;}
      T m() const { return m_m;}
      T pt() const { return sqrt(m_px*m_px+m_py*m_py);}
      // così funziona lo stesso anche se cambio raprresentazione interna
      // ad eg se tolgo m_px m_py e ci metto al loro posto gli impulsi in
      //coordinate polari, poi ricalcolo px() py()
      // e in questo modo la funzione pt() funziona uguale
      //T pt() const { return sqrt(px()*px()+py()*py());}
      T e() const { return sqrt(m_m*m_m+(m_px*m_px+m_py*m_py+m_pz*m_pz));}
      //setters
      void setPx(T px) {m_px=px;}
      void setPy(T py) {m_py=py;}
      void setPz(T pz) {m_pz=pz;}
      void setE(T m) {m_m=m;}

    private:
      T m_px;
      T m_py;
      T m_pz;
      T m_m;

};


//funziona per ogni classe con metodi px ,...
template <class T, class T1>
FourVectorE<typename T::numberType> operator+(const T & a, const T1 & b )  {
	      return FourVectorE<typename T::numberType> (a.px()+b.px(), a.py()+b.py(),a.pz()+b.pz(),a.e()+b.e());
}




#endif