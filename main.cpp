#include <iostream>
#include<iomanip>
using namespace std;
void SSTF(){
    int peticiones,temp;
    cout<<endl<<"ingrese la cantidad de peticiones"<<endl;
    cin>>peticiones;
    int lista[peticiones];
    int aux[peticiones];
    cout<<"ingrese las peticiones:"<<endl;
    for(int i=0;i<peticiones;i++){
        cin>>lista[i];
    }
    for(int i=1;i<peticiones;i++){
            for(int j=0;j<peticiones-1;j++){
                if(lista[j]>lista[j+1]){
                    temp=lista[j];
                    lista[j]=lista[j+1];
                    lista[j+1]=temp;
                }
            }
    }
    cout<<"ingrese el cabezal:"<<endl;
    cin>>temp;
    cout<<"el cabezal es :"<<temp<<endl;
    for(int i=0;i<lista[peticiones-1];i++){
        cout<<" "<<i<<" ";
    }
    cout<<endl;
}
void SCAN(){
     int peticiones,temp,cabezal;
     float promedio;
    cout<<endl<<"ingrese la cantidad de peticiones"<<endl;
    cin>>peticiones;
    int lista[peticiones];
    int aux[peticiones];
    int aux1[peticiones];
    cout<<"ingrese las peticiones:"<<endl;
    for(int i=0;i<peticiones;i++){
        cout<<"Peticion=";
        cin>>lista[i];
    }
    for(int i=1;i<peticiones;i++){
            for(int j=0;j<peticiones-1;j++){
                if(lista[j]>lista[j+1]){
                    temp=lista[j];
                    lista[j]=lista[j+1];
                    lista[j+1]=temp;
                }
            }
    }
    cout<<"ingrese el cabezal:"<<endl;
    cin>>cabezal;
    int cont=0,ini=0,sum=1;
    for(int i=0;i<peticiones;i++){
        if(cabezal<lista[i]){
            aux1[ini]=lista[i];
            aux[ini]=lista[i]-cabezal;
            cabezal=lista[i];
            cont++;
            ini++;
        }else{
            sum++;
        }
    }
    int a=0;
    cont =cont -sum;
    for(int i=peticiones;i>=0;i--){
        if(i<cont){
            aux1[ini]=lista[i];
            aux[ini]=cabezal-lista[i];
            cabezal=lista[i];
            ini++;
        }
    }
    for(int i=1;i<peticiones;i++){
        aux[i]=aux[i]+aux[i-1];
    }
    cout<<setw(20)<<"ORDEN DE ATENCION"<<setw(20)<<"T.B. SCAN"<<endl;
    sum=0;
    for(int j=0;j<peticiones;j++){
        cout<<setw(2)<<"Peticiones:"<<setw(5)<<aux1[j]<<setw(20)<<aux[j]<<" "<<endl;
        sum=sum+aux[j];
    }
    promedio=sum/peticiones;
    cout<<setw(35)<<"Promedio=="<<promedio<<endl;
}
void C_LOOK(){
    int peticiones,temp,cabezal;
     float promedio;
    cout<<endl<<"ingrese la cantidad de peticiones"<<endl;
    cin>>peticiones;
    int lista[peticiones], aux[peticiones], aux1[peticiones];
    cout<<"ingrese las peticiones:"<<endl;
    for(int i=0;i<peticiones;i++){
        cout<<"Peticion=";
        cin>>lista[i];
    }
    for(int i=1;i<peticiones;i++){
            for(int j=0;j<peticiones-1;j++){
                if(lista[j]>lista[j+1]){
                    temp=lista[j];
                    lista[j]=lista[j+1];
                    lista[j+1]=temp;
                }
            }
    }
    cout<<"ingrese el cabezal:"<<endl;
    cin>>cabezal;
    int cont=0,ini=0,sum=1,temporal=0;
    for(int i=0;i<peticiones;i++){
        if(cabezal<lista[i]){
            aux1[ini]=lista[i];
            aux[ini]=lista[i]-cabezal;
            cabezal=lista[i];
            temporal=aux[ini];
            cont++;
            ini++;
        }else{
            sum++;
        }
    }
     for(int i=0;i<sum;i++){
            aux1[ini]=lista[i];
            ini++;
    }
    for(int i=0;i<sum;i++){
        if(i==0){
            aux[cont]=(i+aux1[cont])+1;
        }else{
            aux[cont+i]=(aux1[cont+1]-aux1[cont]);
        }
    }
    for(int i=1;i<peticiones;i++){
        aux[i]=aux[i]+aux[i-1];
    }
    cout<<setw(20)<<"ORDEN DE ATENCION"<<setw(20)<<"T.B. SCAN"<<endl;
    sum=0;
    for(int j=0;j<peticiones;j++){
        cout<<setw(2)<<"Peticiones:"<<setw(5)<<aux1[j]<<setw(20)<<aux[j]<<" "<<endl;
        sum=sum+aux[j];
    }
    promedio=sum/peticiones;
    cout<<setw(35)<<"Promedio=="<<promedio<<endl;
}
void principal(){
    int opcion;

    do {
        cout<<setw(50)<<"GESTION DE DISCO"<<endl;
        cout<<setw(40)<<"SSTF    =1"<<endl;
        cout<<setw(40)<<"SCAN    =2"<<endl;
        cout<<setw(40)<<"C_LOOK  =3"<<endl;
        cout<<setw(40)<<"SALIR   =4"<<endl;
        cin>>opcion;
        switch(opcion)
        {
        case 1:
            SSTF();
            break;
        case 2:
            SCAN();
            break;
        case 3:
            C_LOOK();
            break;
        }
    }while(opcion!=4);
}
int main()
{

   principal();
    return 0;
}
