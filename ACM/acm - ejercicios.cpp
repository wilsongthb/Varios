#include <iostream>

using namespace std;

void eja(){
    size_t a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<( (a+d) - (b+c) );
}
void ejf(){
    int n,c,s;
    cin>>n>>c>>s;
    int N[c],cont=0,i=0;
    for(;i<c;i++){
        cin>>N[i];
    }
    i=1;

    if( i == s ){
        cont++;
    }

    for(int j=0;j<c;j++){
        if(N[j] == 1){
            i++;
            if( i > n)
                i=1;
        }else{
            i--;
            if( i == 0)
                i=n;
        }
        if( i == s ){
            cont++;
        }
    }
    cout<<cont;
}
void ejk(){
    int n,con = 0;
    cin>>n;
    int N[n][2];
    for(int i=0; i < n; i++){
        cin>>N[i][0]>>N[i][1];
    }
    // cada individuo sera el lobo
    for(int i=0; i < n; i++){
        int lobo = i;
        int V[n];
        for(int j=0;j<n;j++){V[j]=0;}

        //para cada caso , excepto el lobo

        for(int aldeano=0; aldeano<n; aldeano++){
            if(aldeano != lobo){
                if(N[aldeano][0] == (lobo+1) || N[aldeano][1] == (lobo+1)){
                    V[lobo]++;
                }else{
                    V[N[aldeano][0]-1]++;
                    V[N[aldeano][1]-1]++;
                }
            }
        }
        //el lobo va a votar :3
        int mayor = -1, indi_ma = 0;
        for(int j=0;j<n;j++){
            if(V[j] > mayor){
                mayor = V[j];
                indi_ma = j;
            }
        }
        //lobo a votado
        if(N[lobo][0] == (indi_ma+1) || N[lobo][1] == (indi_ma+1) ){
            V[indi_ma]++;
        }else{
            V[N[lobo][0]-1]++;
            V[N[lobo][1]-1]++;
        }


        // mostramos las eleciones de los aldeanos
        for(int u=0; u<n; u++){
            cout<<V[u]<<",";
        }
        cout<<endl;


        // resltados
        mayor = -1;indi_ma =0;
        int ind_seg = 0, seg = -1;
        for(int j=0;j<n;j++){
            if(V[j] >= mayor){
                seg = mayor;
                ind_seg = indi_ma;

                mayor = V[j];
                indi_ma = j;
            }else if(V[j]>=seg){
                seg = V[j];
                ind_seg = j;
            }
        }
        cout<<"mayor="<<indi_ma<<" seg: "<<ind_seg<<endl;

        if(V[indi_ma]==V[lobo]){
            if( V[indi_ma] == V[ind_seg]){
                con++;
            }

        }else{
            con++;
        }


    }
    cout<<con;
}

int main(){

}
