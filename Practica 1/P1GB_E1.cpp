#include <iostream>
#include <vector>

//Practica realizada por Juan Manuel Muñoz del Cerro

using namespace std;

int solicitarNumero(){
    int num;
    cout<<"\n";
    cout<<"Introduce un numero:";
    cin>>num;
    return num;
}

int multiplicarCifrasImpares(int num){
    if(num/10 > 1){
     if((num%10)%2 == 1){
        return num%10*multiplicarCifrasImpares(num/10);
       }else{
         return multiplicarCifrasImpares(num/10);
     }
    }else{
        if((num%10)%2 == 1) return num%10;
        else return 1;
    }
}


int  totalNumNegativosREC(vector<int> nums){
    int cont= 0;
    for(auto elem:nums){
        if(elem < 0) ++cont;
    }

    return cont;
}

vector<int> solicitarDatosVector(vector<int> nums){

    cout << "Introduce cuantas numeros quires introducir en el vector:";
    int tam;
    cin >> tam;

    cout << endl <<"Introudce los datos: ";
    for(int i{0}; i < tam; ++i){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    return nums;
}




int fibonacciValorIterativo(int cont){
    int n_aa = 1;
    int n_a = 1;
    int n = 0;

    if(cont==1 || cont==2){
        return 1;
    }
    else{
        for(int i = 3; i <= cont;i++){
        n = n_a + n_aa;
        n_aa =n_a;
        n_a = n;
}
    }

    return n;
}
vector<int>fibonacciSerieIterativo(int cont){
    vector<int>fibo;
    int n_aa = 1;
    int n_a = 1;
    int n = 0;

    if(cont==1){
        fibo.push_back(1);
        return fibo;
    }else if(cont==2){
        fibo.push_back(1);
        fibo.push_back(1);

        return fibo;
    }
    else{
        fibo.push_back(1);
        fibo.push_back(1);
        for(int i = 3; i <= cont;i++){
        n = n_a + n_aa;
        n_aa =n_a;
        n_a = n;
        fibo.push_back(n);
}
    }

    return fibo;

}

int fibonacciValorRecursivo(int num){

    if(num == 1 || num == 2) return 1;
       else return fibonacciValorRecursivo(num-1) + fibonacciValorRecursivo(num-2);
}

vector<int> fibonacciSerieRecursivo(int num,vector<int> v){

    /*if(num == 1){

    v.push_back(1);
    return v;

    } else if(num==2){

      v.push_back(1);
      return v;
    }

       else { v.push_back( fibonacciSerieRecursivo(num-1) + fibonacciSerieRecursivo(num-2));

    }
*/

    return v;

}

int factorial(int num){

    if(num!=1){
        return factorial(num-1)*num;
    }else{
        return 1;
    }
}


void menu(){

    int num;
    vector<int> nums;

  do{

    cout<<"                                  Menu"<<"\n"<<"\n"<<"1. Calcular el factorial de un numero de forma recursiva"<<
          "\n"<<"2.Determinar el numero de elementos negativos en un vector de forma iterativa"<<
          "\n"<<"3.Calcular el producto de las cifras impares de un numero entero de forma recursiva."<<
          "\n"<<"4.Secuencia de Fibonacci"<<
          "\n"<<"5.Salir programa.";
    cout<<"\n"<<"Introduce una opcion:";
          cin>>num;

    if(num==1){
       cout<< factorial(solicitarNumero());
       cout<<"\n";

    }else if(num==2){
        vector<int>nums;
        cout<<totalNumNegativosREC(solicitarDatosVector(nums));
        cout<<"\n";
    }else if(num==3){
        cout<< multiplicarCifrasImpares(solicitarNumero());
        cout<<"\n";

    }else if(num==4){

        cout<<"Fibonacci Valor Iterativo :";
        cout<<fibonacciValorIterativo(solicitarNumero());
        cout<<"\n";

        cout<<"Fibonacci Serie Iterativo :";
        for(auto elem:fibonacciSerieIterativo(solicitarNumero())){
            cout<< elem<<" ";
        }
        cout<<"\n";

        cout<<"Fibonacci Valor Recursivo :";
        cout<<fibonacciValorRecursivo(solicitarNumero());
        cout<<"\n";
       /*
        cout<<"Fibonacci Serie Recursivo :";
        for(auto elem:fibonacciSerieRecursivo(solicitarNumero())){
            cout<< elem<<" ";
        }
        cout<<"\n";*/

    }else{
        break;
    }


    }while (num!=5);

}

int main()
{
    menu();

    return 0;
}
