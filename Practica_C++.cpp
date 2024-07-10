#include <bits/stdc++.h>

using namespace std;

int A[101][101];
int n,m,MX,MN;

ifstream in("Select.txt");
ofstream out("Select.txt");

void CitesteFisier(){
    ifstream citeste("Matrice.in");
    citeste>>n>>m;
    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
    citeste>>A[i][j];
    if(A[i][j]>MX)
    MX=A[i][j];
    if(A[i][j]<MN)
    MN=A[i][j];
    }
}
void adauga(int (&a)[][101],int &n,int &m){
    int x,optiune;
    cout<<"Ce vreti sa introduceti?"<<endl;
    cout<<"1. Linie"<<endl;
    cout<<"2. Coloana"<<endl;
    cin>>optiune;
    if(optiune==1){
        ++n;
        cout<<"Introduceti elementele: ";
        for(int i=1;i<=m;i++){
        cin>>a[n][i];
        if(a[n][i]>MX)
        MX=a[n][i];
        else if(a[n][i]<MN)
        MN=a[n][i];
}
        
    }
    if(optiune==2){
        ++m;
        cout<<"Introduceti elementele: ";
        for(int i=1;i<=n;i++){
        cin>>a[i][m];
        if(a[i][m]>MX)
        MX=a[i][m];
        else if(a[i][m]<MN)
        MN=a[i][m];
    }
    }
    
    ofstream fout("Matrice.in");
    fout<<n<<' '<<m<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
        fout<<a[i][j]<<' ';
        fout<<endl;
    }
    
        fout.close();
}

void afisare(int a[][101],int n, int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
        cout<<a[i][j]<<' ';
        cout<<endl;
    }
}


void StergeMaxim(int (&a)[101][101], int &n, int &m) {
    
    cout<<"\t\t\t ---- Matricea originala ----"<<endl;
    
    afisare(a,n,m);
    
    
    
    
    int mx = INT_MIN, indexI = -1, indexJ = -1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] > mx) {
                mx = a[i][j];
                indexI = i;
                indexJ = j;
            }
        }
    }
    
        cout<<endl<<"Elementul maxim pentru care coloana si rindul vor fi eliminate   [ "<<mx<<" ]";


    if (indexI == n) {
        --n;
    } else {
        for (int i = indexI; i < n; ++i) 
            for (int j = 1; j <= m; ++j) 
                a[i][j] = a[i + 1][j];
        
        --n;
    }

    if (indexJ == m) {
        --m;
    } else {
        for (int i = 1; i <= n; ++i) 
            for (int j = indexJ; j < m; ++j) 
                a[i][j] = a[i][j + 1];
            
        
        --m;
    }
    
    
    cout<<endl<<"\t\t\tElementele matricii dupa stergere"<<endl;
    afisare(a,n,m);
}

void Frecventa(int a[][101],int n,int m){
    
MN=abs(MN);
int freq[MX+1]={0};
int freqN[MN+1]={0};

for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        if(a[i][j]<0)
        freqN[abs(a[i][j])]++;
    else freq[a[i][j]]++;

int mx=freq[0];
int indexP=0;
int indexN=0;

for(int i=1;i<=MX;i++)
if(freq[i]>mx){
mx=freq[i];
indexP=i;}


for(int i=1;i<=MN;i++)
if(freqN[i]>mx){
mx=freqN[i];
indexN=i;}

if(indexN>indexP)
indexP=-indexN;

    afisare(a,n,m);

cout <<"\nCel mai frecvent element al matricei este " <<indexP<< endl;


}



void MediaAritmetica(int a[][101],int n,int m){
    double aux;
    int cnt=0;
    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(a[i][j]>=-10 && a[i][j]<=10)
    aux+=a[i][j], cnt++;
    aux/=cnt;
    cout<<"\n\t\t ---------- Media elementelor cuprinse in intervalul [-10;10] = "<<aux<<" ----------\n";
    
    
}

void OrdoneazaRinduri(int a[][101],int n,int m){
    
    cout<<"\t\t\t ---- Matricea originala ----"<<endl;
    
    afisare(a,n,m);
    
    for(int x=1;x<=n;x++)
    for(int i=1;i<m;i++)
        for(int j=i+1;j<=m;j++)
        if(a[x][i]>a[x][j]) swap(a[x][i],a[x][j]);
        
           cout<<"\t\t\t ---- Matricea sortata pe linii ----"<<endl;
    afisare(a,n,m);

}

void ScrieSubsir(int a[][101],int n,int m){
    
    cout<<"\t\t\t ---- Matricea originala ----"<<endl;
    
    afisare(a,n,m);
    
    int lung_mx=0,inceput_mx,sfirsit_mx,lung=1,inceput,sfirsit;
    for(int i=1;i<=n;i++){
        lung_mx=0,inceput=1,sfirsit=1;
        for(int j=1;j<=m;j++)
        if(a[i][j+1]>a[i][j])
            lung++, sfirsit=j+1;
        else{
                if(lung>lung_mx){
                lung_mx=lung;
                inceput_mx=inceput;
                sfirsit_mx=sfirsit;
                }
                
            lung=1;
            inceput=j+1;
            sfirsit=j+1;
        }
        
        cout<<"\t\t\t--- SUBSIRUL CRESCATOAR DE LUNGIME MAXIMA PE RANDUL "<<i<<"---"<<endl;
        
    for(int x=inceput_mx;x<=sfirsit_mx;x++)
    cout<<a[i][x]<<' ';
    cout<<endl; 
    
    
    for(int x=inceput_mx;x<=sfirsit_mx;x++)
    out<<a[i][x]<<' ';
    out<<endl;
}

cout<<"\n \n-------Datele au fost transmise in fisier.-------\n";
}


void ParcurgeSpirala(int a[][101],int n,int m){
    
    
    cout<<"------ Matricea ------\n"<<endl;
    afisare(a,n,m);
    
    
    int sir[100*100]={0};
    int index=0;
    
    bool V[n][m]={false};
    
    int dr[]={0,1,0,-1};
    int dc[]={1,0,-1,0};
    
    int X=1,Y=1, di=0;
    
    for(int i=1;i<=n*m;i++){
        
        sir[++index]=a[X][Y];
        V[X][Y]=true;
        
        int x=X+dr[di];
        int y=Y+dc[di];
        
        if(1<=x && x<=n && 1<=y && y<=m && !V[x][y]){
            X=x;
            Y=y;
        }
        else{
            di=(di+1)%4;
            X+=dr[di];
            Y+=dc[di];
        }
        
    }
    

    
    cout<<"Parcurgerea matricei in spirala: ";
    for(int i=1;i<=index;i++)
    cout<<sir[i]<<' ';
    
    
    cout<<endl;
    bool adevar1=true;
    int intrus1,intrus2;
    bool adevar2=true;
    int progresie=sir[2]-sir[1];
    
    for(int i=3;i<index;i++){
        if(sir[i+1]-progresie==sir[i] && adevar2)
        continue;
        else{
            if(!adevar1){
            adevar2=false,intrus2=sir[i];
            break;}
            else adevar1=false,intrus1=sir[i];
            
        }
    }
    
    if(adevar1==true && adevar2==true)
    cout<<"DA \n"<<sir[index];
    else{
        cout<<"NU\n";
    cout<<intrus1<<' ';
    if(adevar2==false) cout<<intrus2;
    }
    
}

void SubmatriceMaxima(int a[][101],int n,int m){
    
    cout<<"------ Matricea ------\n"<<endl;
    afisare(a,n,m);
    
    cout<<endl;
     cout<<"------ Submatricea de lungime maxima ------\n"<<endl;
     
     cout<<"Coordonatele varfului din stinga sus: "<<"[0]"<<" [0]"<<endl;
     
     
     

    if(n>m)
        n-=(n-m);
        
    else if(m>n)
        m-=(m-n);
        
    
    else{
        --n;
        --m;
    }
    
        afisare(a,n,m);

    
}




int main(){
    CitesteFisier();
    
    cout << "----------------------------------------" << endl;
    cout << "|             BUN VENIT!               |" << endl;
    cout << "----------------------------------------" << endl;

    cout << "----------------------------------------" << endl;
    afisare(A, n, m);
    cout << "----------------------------------------" << endl;

   
    bool continua=true;
    
    do{
    int optiune;
    cout<<"\n1. Insereaza in matricea A o noua linie/coloana"<<endl;
        cout<<"2. Exclude din matricea A linia si coloana la intersectia caror se afla primul element maximal intilnit la parcurgerea pe linii"<<endl;
        cout<<"3. Gaseste numarul care apare cel mai frecvent in matricea A"<<endl;
        cout<<"4. Determina media aritmetica a elementelor matricei A, care apartin intervalului [-10,10]"<<endl;
        cout<<"5. Sorteaza crescator elementele fiecarei linii ale matricei A prin metoda numararii"<<endl;
        cout<<"6. Copie subsirurile crescatoare de lungime maximala din liniile matricei A"<<endl;
        cout<<"7. Gaseste in componenta matricei A submatricea patratica simetrica de dimensiune maximala"<<endl;
        cout<<"8. Parcurge in spirala matricea si determina daca formeaza o progresie arimetica"<<endl;
        
        cout<<"Selecteaza o optiune: ";
        cin>>optiune;
    switch(optiune){
        case 1:
        adauga(A,n,m);
        
        break;
        case 2:
        StergeMaxim(A,n,m);
        
        break;
        
        case 3:
        Frecventa(A,n,m);
        break;
        
        case 4:
        MediaAritmetica(A,n,m);
        
        break;
        
        case 5:
        OrdoneazaRinduri(A,n,m);
        break;
        
        case 6:
        ScrieSubsir(A,n,m);
        break;
        case 7:
        SubmatriceMaxima(A,n,m);
        break;
        
        case 8:
        for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
        cout<<A[i][j]<<' ';
        cout<<endl;
        
        }
        cout<<endl;
        ParcurgeSpirala(A,n,m);
        
        break;
        
        
        case 0: continua=false; break;
        
        
    }
    
    }while(continua);

    
}