#include <iostream>
#include <fstream>
using namespace std;

int Cmax(int N, int M, int*P, int* X)
{
    int T[100]; for(int i=0;i<=M;i++)T[i]=0;
    for(int n=0;n<N;n++)
        for(int m=1;m<=M;m++)
            T[m]=max(T[m-1],T[m])+P[(m-1)+X[n]*M];
    return T[M];
}

int Neh(int N, int M, int*P, int*X)
{
    //etap 1: w X bedzie kolejnosc ukladania (wg wag rosnaco)
    int *w = new int[N];
    for(int n=0;n<N;n++){
        X[n]=n; //tymczasowa kolejnosc 123...
        w[n]=Cmax(1,M,P,&n); //policzenie wag kazdego zadania
    }
    for(int b=0;b<N-1;b++) for(int a=0;a<N-1;a++) // sortowanie babelkowe
        if(w[a]<w[a+1]){swap(w[a],w[a+1]);swap(X[a],X[a+1]);}
    delete[]w;
    //etap 2
    for(int n=0; n<N; n++){
        int best=-1, cmax=999999999;
        for(int p=n;p>=0;p--){
            int tmp = Cmax(n+1,M,P,X);
            if(tmp<=cmax){best=p;cmax=tmp;}
            if(p)swap(X[p],X[p-1]);
        }
        for(int i=0;i<best;i++)swap(X[i],X[i+1]);
    }
    return Cmax(N,M,P,X);
}

int main()
{
    int N,M,P[10000],X[1000];
    ifstream f("data.txt");
    string s; while(s!="data.w:")f>>s;
    f>>N>>M; for(int i=0;i<N*M;i++) f>>P[i]; f.close();

    for(int n=0;n<N;n++){
        for(int m=0;m<M;m++)
            cout<<P[m+n*M]<<" "; //P[n][m]
        cout<<endl;
    }


    cout<< Neh(N,M,P,X)<<endl;
    for(int i=0;i<N;i++){
        cout<<X[i]+1<<" ";
    }cout<<endl;


    cin.get();return 0;
}
