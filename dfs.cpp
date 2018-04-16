/*  Depth-first search
    God is Almighty
    Indrojit Mondal
    Department of Computer Science and Engineering,
    University of Barisal
    */
#include<bits/stdc++.h>
using namespace std;
int Vertex,Edge;
int G[100][100];
//vector<int>G[100];
int Time=0;
int Color[100];
int Par[100];
 /* 0(NULL)==>White
   1==>Gray
   2==>Black
   */

int D[100]; // D->Discovery Time
int F[100]; // F->Finishing Time
void DFS_VISIT(int U);

void DFS(int x)
{
    DFS_VISIT(x);
    for(int I=1; I<=Vertex; I++)
    {
        if(Color[I]==0)
        {
            DFS_VISIT(I);
        }
    }
}

void DFS_VISIT(int U)
{
    Color[U]=1;
    Time=Time+1;
    D[U]=Time;

     for(int xy=1; xy<=Vertex; xy++)
     {
        if(G[U][xy]==1 && Color[xy]==0)
        {
            Par[U]=xy;

            DFS_VISIT(xy);
        }

     }

     Color[U]=2;

    Time = Time +1;
    F[U]=Time;

}
void PathPrint(int px)
{
    if(Par[px]==0) return;
     cout<<Par[px]<<" ";
    PathPrint(Par[px]);
}

int main()
{
    int i,j;
    freopen("dfsinput.txt","r",stdin);
    cin>>Vertex>>Edge;
    int Node1,Node2;
    for(i=1; i<=Edge; i++)
    {
        cin>>Node1>>Node2;
        //G[Node1].push_back(Node2);
        G[Node1][Node2]=1;

    }

    for(int I=1; I<=Vertex; I++)
    {
        Color[I]=0;
        Par[I]=0;
    }
     //Time=0;
    DFS(3);

    for( int V=1; V<=Vertex; V++)
    {
        cout<<V<<" 's Discovery Time = "<<D[V]<<" & Finishing Time = "<<F[V]<<endl;

    }
    ///Check kore dekhlam 3 theke kothai kothai jaoa jai
     cout<<"3 ";
    PathPrint(3);


    return 0;
}


