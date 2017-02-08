#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int MaxIloscWezlow   = 100;
const int MaxIloscKrawedzi = 1000;


struct KrawedzGrafu{
        int odwezla;
        int dowezla;
        int koszt;
};



void SortujKrawedzie( KrawedzGrafu **G1, int gk)
{
        KrawedzGrafu tmp;

        for (int i=1; i<= gk-1; i++)
        for (int j=1; j<= gk-i; j++)
        if ( (*G1)[j].koszt > (*G1)[j+1].koszt )
        {
                tmp    = (*G1)[j];
                (*G1)[j]   = (*G1)[j+1];
                (*G1)[j+1] = tmp;
        }
}


int AlgKruskala( int n, KrawedzGrafu **G1, KrawedzGrafu **T1 )
{
        int *Z = (int*)malloc( sizeof( int) * (n+3) );
        int  j, k, u, v, w;
        int tk =0;

        for (int i=1; i<=n; i++) Z[i] = 0;

        k  =1;
        j  =1;
        while (k<n)
        {
                u = (*G1)[j].odwezla;
                v = (*G1)[j].dowezla;
                j =j+1;
                if ( Z[u]==0 || Z[v]==0 || Z[u]!=Z[v] )
                {
                        tk =tk +1;
                        (*T1)[ tk ] = (*G1)[j-1];
                        if ( Z[u]==0 && Z[v]!=0 )
                        {
                                w =u;
                                u =v;
                                v =w;
                        }
                        if ( Z[u]==0 ) Z[u] =u;

                        if ( Z[v]==0 ) Z[v] =Z[u];
                        else
                        {
                                w =Z[v];
                                for (int i=1; i<=n; i++)
                                if ( Z[i]==w ) Z[i] =Z[u];
                        }
                        k =k+1;
                }
        }

        delete Z;
        return tk;
}


int main(int argc, char* argv[])
{
        int n, gk, tk;


        printf("%s %d %s", "Ilosc wezlow <= ", MaxIloscWezlow, " = ");
        scanf( "%d", &n);
        printf("%s %d %s", "Ilosc krawedzi <= ", MaxIloscKrawedzi, " = ");
        scanf( "%d", &gk);
        printf( "OdWezla DoWezla Koszt\n" );


        KrawedzGrafu *G = (KrawedzGrafu *)malloc( (gk+3)* sizeof( KrawedzGrafu )  );
        KrawedzGrafu *T = (KrawedzGrafu *)malloc( (gk+3)* sizeof( KrawedzGrafu )  );

        for (int i=1; i<=gk; i++)
        scanf( "%d %d %d", &(G[i].odwezla), &(G[i].dowezla), &(G[i].koszt) );

        SortujKrawedzie( &G, gk);

        tk = AlgKruskala(n, &G, &T );

        for ( int i=1; i<= tk; i++)
        printf( "%d %s %d %s %d\n", T[i].odwezla, " -> ", T[i].dowezla , " : ", T[i].koszt  );

        delete G;
        delete T;
system("pause");
        return 0;
}
