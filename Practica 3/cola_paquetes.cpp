#include "cola_paquetes.h"
using namespace std;
ColaPaquetes::ColaPaquetes()
{

}

void ColaPaquetes::enqueue(const Paquete &paquete)
{

    data_[++tail_] = paquete;

}

void ColaPaquetes::dequeue()
{
   if(empty() != true) ++head_;

}

Paquete ColaPaquetes::front() const
{
    return data_[head_];
}

int ColaPaquetes::size() const
{
    int cont = 0;
    for(int i = 0; i < tail_;++i){
        ++cont;
    }

    return cont;
}

bool ColaPaquetes::empty() const
{
    return head_ == tail_ + 1;
}
