#include <iostream>
#include <fstream>
#include <climits>
#include <vector>

using namespace std;

int n, v[100], x[100], maxim=INT_MIN, counter;
ifstream f("vector.in");

int main()
{
    f>>n;
    for(int i=0; i<n; i++) {
        f>>v[i];
    }

    // aflarea maximului [functioneste]
    for(int i=0; i<n; i++) {
        if(v[i]>maxim) {
            maxim=v[i];
            counter=1;
        } else if(maxim==v[i]) {
            counter++;
        }
    }
    cout<<"Numarul maxim din vector este "<<maxim<<" si apare de "<<counter<<" ori."<<endl;

    // determinarea minimului si indexul acestuia [functioneste]
    maxim=INT_MAX;
    int k;
    for(int i=0; i<n; i++) {
        if(v[i]<maxim) {
            maxim=v[i];
            for(int j=0; j<k; j++) {
                x[i]=0;
            }
            k=1;
            x[0]=i;
        } else if(v[i]==maxim) {
            x[k]=i;
            k++;
        }
    }
    cout<<"Numarul minim din vector este "<<maxim<<" si apare pe pozitiile ";
    for(int i=0; i<k; i++) {
        cout<<x[i];
        if(i==k-1) cout<<"."<<endl;
            else cout<<", ";
    }

    // sortarea vectorului dintre AL DOILEA numar prim si ANTEPENULTIMUL numar cu cifre distincte
    //determinarea celui de-al doilea numar prim [functioneste]
    counter=0;
    int primindex=0;
    for(int i=0; i<n; i++) {
        k=1;
        for(int j=2; j<v[i]&&k==1; j++) {
            if(v[i]%j==0) {
                k=0;
            }
        }
        if(k==1&&counter!=2) {
            counter++;
            if(counter==2) {
                primindex=i;
            }
        }
    }
    cout<<primindex<<endl;
    //determinarea antepenultimului numar cu cifre distincte [functioneste]
    counter=0;
    int distincteindex=0;
    int aux, uc;
    for(int i=n-1; i>=0; i--) {
        k=1;
        aux=v[i];
        uc=aux%10;
        aux/=10;
        while(aux!=0) {
            if(uc!=aux%10) {
                k=0;
            }
            aux/=10;
        }
        if(k==0&&counter!=3) {
            counter++;
            if(counter==3) {
                distincteindex=i;
            }
        }
    }
    cout<<distincteindex<<endl;
    //sortare [functioneste]
    if(primindex!=0&&distincteindex!=0) { //conditie pentru existenta numerelor mentionate
        for(int i=primindex; i<=distincteindex; i++) {
            for(int j=primindex+1; j<=distincteindex-1; j++) {
                if(v[i]<v[j]) {
                    aux=v[i];
                    v[i]=v[j];
                    v[j]=aux;
                }
            }
        }
    }

    // inserarea dupa fiecare numar palindrom tuturor divizorii sai
    //gasirea numerelor palindrom
    for(int i=0; i<n; i++) {
        int inv=0, p=1;
        aux=v[i];
        while(aux) {
            inv=inv*10+v[i]%10;
            aux/=10;
        }
        cout<<aux<<" ";
    }

    return 0;
}
