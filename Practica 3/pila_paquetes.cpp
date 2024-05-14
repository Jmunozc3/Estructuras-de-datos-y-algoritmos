#include "pila_paquetes.h"
using namespace std;
PilaPaquetes::PilaPaquetes()
{

}


void PilaPaquetes::push(const Paquete &paquete){

  data_[++top_] = paquete;
}

void PilaPaquetes::pop()
{
   if(empty() != true) --top_;


}

Paquete PilaPaquetes::top() const
{
    return data_[top_];
}

int PilaPaquetes::size() const
{
    int cont = 0;
    for(int i = 0; i < top_;++i) ++cont;
    return cont;
}

bool PilaPaquetes::empty() const
{
    return top_ == 0;
}
