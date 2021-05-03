#include <iostream>
#include <fstream>
using namespace std;

int Cmax(int N, int M, int*P, int*X)
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

int QCmax(int N, int M, int*P, int*X, int*C, int*RC)
{



    int T[100]; for(int i=0;i<=M;i++)T[i]=0;
    for(int n=0;n<N;n++)
        for(int m=1;m<=M;m++)
            T[m]=max(T[m-1],T[m])+P[(m-1)+X[n]*M];
    return T[M];
}

int QNeh(int N, int M, int*P, int*X)
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
    int*C,*RC; // C- najdluzsza sciezka prowadzaca od poczatku do danego punktu, RC - od konca
    for(int i=0;i<N*M;i++){C[i]=-1;RC[i]=-1;}






    return QCmax(N,M,P,X,C,RC);
}


int main()
{
    int N,M,P[10000],X[1000];
    string data4_3[] = {"data.w:", "data.000:"};
    string data20_5[] = {"data.001:", "data.002:", "data.003:", "data.004:", "data.005:", "data.006:", "data.007:", "data.008:", "data.009:", "data.010:"};
    string data20_10[] = {"data.011:", "data.012:", "data.013:", "data.014:", "data.015:", "data.016:", "data.017:", "data.018:", "data.019:", "data.020:"};
    string data20_20[] = {"data.021:", "data.022:", "data.023:", "data.024:", "data.025:", "data.026:", "data.027:", "data.028:", "data.029:", "data.030:"};
    string data50_5[] = {"data.031:", "data.032:", "data.033:", "data.034:", "data.035:", "data.036:", "data.037:", "data.038:", "data.039:", "data.040:"};
    string data50_10[] = {"data.041:", "data.042:", "data.043:", "data.044:", "data.045:", "data.046:", "data.047:", "data.048:", "data.049:", "data.050:"};
    string data50_20[] = {"data.051:", "data.052:", "data.053:", "data.054:", "data.055:", "data.056:", "data.057:", "data.058:", "data.059:", "data.060:"};
    string data100_5[] = {"data.061:", "data.062:", "data.063:", "data.064:", "data.065:", "data.066:", "data.067:", "data.068:", "data.069:", "data.070:"};
    string data100_10[] = {"data.071:", "data.072:", "data.073:", "data.074:", "data.075:", "data.076:", "data.077:", "data.078:", "data.079:", "data.080:"};
    string data100_20[] = {"data.081:", "data.082:", "data.083:", "data.084:", "data.085:", "data.086:", "data.087:", "data.088:", "data.089:", "data.090:"};
    string data200_10[] = {"data.091:", "data.092:", "data.093:", "data.094:", "data.095:", "data.096:", "data.097:", "data.098:", "data.099:", "data.100:"};
    string data200_20[] = {"data.101:", "data.102:", "data.103:", "data.104:", "data.105:", "data.106:", "data.107:", "data.108:", "data.109:", "data.110:"};
    string data500_20[] = {"data.111:", "data.112:", "data.113:", "data.114:", "data.115:", "data.116:", "data.117:", "data.118:", "data.119:", "data.120:"};

    string data_all[] = {"data.000:", "data.001:", "data.002:", "data.003:", "data.004:", "data.005:", "data.006:", "data.007:", "data.008:", "data.009:", "data.010:",
                        "data.011:", "data.012:", "data.013:", "data.014:", "data.015:", "data.016:", "data.017:", "data.018:", "data.019:", "data.020:",
                        "data.021:", "data.022:", "data.023:", "data.024:", "data.025:", "data.026:", "data.027:", "data.028:", "data.029:", "data.030:",
                        "data.031:", "data.032:", "data.033:", "data.034:", "data.035:", "data.036:", "data.037:", "data.038:", "data.039:", "data.040:",
                        "data.041:", "data.042:", "data.043:", "data.044:", "data.045:", "data.046:", "data.047:", "data.048:", "data.049:", "data.050:",
                        "data.051:", "data.052:", "data.053:", "data.054:", "data.055:", "data.056:", "data.057:", "data.058:", "data.059:", "data.060:",
                        "data.061:", "data.062:", "data.063:", "data.064:", "data.065:", "data.066:", "data.067:", "data.068:", "data.069:", "data.070:",
                        "data.071:", "data.072:", "data.073:", "data.074:", "data.075:", "data.076:", "data.077:", "data.078:", "data.079:", "data.080:",
                        "data.081:", "data.082:", "data.083:", "data.084:", "data.085:", "data.086:", "data.087:", "data.088:", "data.089:", "data.090:",
                        "data.091:", "data.092:", "data.093:", "data.094:", "data.095:", "data.096:", "data.097:", "data.098:", "data.099:", "data.100:",
                        "data.101:", "data.102:", "data.103:", "data.104:", "data.105:", "data.106:", "data.107:", "data.108:", "data.109:", "data.110:",
                        "data.111:", "data.112:", "data.113:", "data.114:", "data.115:", "data.116:", "data.117:", "data.118:", "data.119:", "data.120:"};

    for(int d=0;d<2;d++)
    {
    	string data = data20_10[d];
        ifstream f("data.txt");
        string s; while(s!=data)f>>s;
        f>>N>>M; for(int i=0;i<N*M;i++) f>>P[i]; f.close();

        cout<<data<<endl;
        cout<<N<<" "<<M<<endl; // wypisanie wczytanej liczby zadan i maszyn
      /*  for(int n=0;n<N;n++){ // wypisanie wczytanych danych
            for(int m=0;m<M;m++)
                cout<<P[m+n*M]<<" "; //P[n][m]
            cout<<endl;
        }*/


        cout<< Neh(N,M,P,X)<<endl<<endl; // wypisanie wartosci cmax
      /*  for(int i=0;i<N;i++){ // wypisanie permutacji
            cout<<X[i]+1<<" ";
        }cout<<endl;*/
    }

    //cin.get();
    return 0;
}
