/**************************************************************************
*
*   Ejemplos de algoritmos greedy: PRIM                                   *
*
***************************************************************************/

#include <iostream>
#include <set>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

#define INFINITO 1000
typedef int vertice;
typedef int distancia;

/*--- Grafo matricial basico -----------------------------------------------------------*/
class grafo {

  public:
   grafo (int tama )
       {
         pesos.resize(tama);
         for (int i=0; i< tama; i++)
            pesos[i].resize(tama,0);
        }
   int asignar_peso(int org, int dest, distancia w)
      { pesos[org][dest] = w;}
   distancia  devolver_peso( int org, int dest) const
      { return pesos[org][dest];}
   int size()
      { return pesos.size();}
   vertice begin_ady (vertice i) //primer adyacente
     {return 0;}
   vertice end_ady(vertice i)
     { return pesos.size(); }

  private:
     vector< vector< distancia > > pesos;

};


class heap {
  public:
    heap ( int tama)
    { dentro.resize(tama,false);}

     
    bool en_heap(vertice v)
    { return dentro[v];}


    void insert( distancia d, vertice v)
     { pair<distancia,vertice> aux;
       aux.first = d; aux.second = v;
       heapD.insert(aux);
       dentro[v]=true;
     }


    void actualizar_heap( distancia nueva, vertice v)
    {
      set< pair<distancia,vertice> >::iterator it;
      pair<distancia,vertice> aux;

      for (it =heapD.begin(); it!=heapD.end() && it->second!=v; ++it);
      //Buscamos el vertice
      if (it==heapD.end() ) { 
          cout << "Error, intento de actualizar un elemento que no esta en heap " << endl; 
          exit(0);
      }
      heapD.erase(it);
      aux.first = nueva;
      aux.second = v;
      heapD.insert(aux);

    }


    bool empty( ) const
    {return heapD.empty(); }


    pair<distancia,vertice> erase_min( ) {

      pair<distancia,vertice> aux;
      aux = *(heapD.begin()); // EL menor en el heap (borrar el minimo)
      heapD.erase(heapD.begin());
      return aux;
    }

  private:
   vector<bool> dentro;  // Nodos que estan en el heap
   set< pair<distancia,vertice> >  heapD; //heap de distancias  -- vertice a incluir;

};



/*--- Prim -----------------------------------------------------------*/

void Prim(  grafo & G, vertice v0)
{
// Variables
 vector<bool> seleccionado(G.size(),false);  // Nodos que han sido incluidos en la solucion
 vector<distancia> d(G.size(),INFINITO);  // Matriz de distancias
 heap heapD(G.size());  // Heap de pares (distancia,vertice) ordenados por distancia
 vector<vertice> origen (G.size(), -1 );  // Si v=origen[i] entonces estamos hablando del arco (v,i) en G

 pair<distancia,vertice> aux;
 distancia distancia_candidata ;
 vertice n_act;

 aux.first = 0; aux.second =v0;
 d[v0]=0;
 origen[v0] = v0;
 heapD.insert(0, v0);  // Insertamos el vertice inicio en el heap
 while (!heapD.empty()) {
    aux = heapD.erase_min();  // Borramos el de menor distancia
    cout << "Nodo seleccionado " << aux.second << " Distancia " << aux.first << endl;
    n_act = aux.second;
    seleccionado[n_act] = true;
    for ( vertice ady=G.begin_ady(n_act);  ady !=G.end_ady(n_act);  ady++) {
        // Para cada nodo adyacente al vertice actual
   
        if (!seleccionado[ady]) {  // Si no ha sido incluido en la solucion
          distancia_candidata = G.devolver_peso(n_act,ady);
          if ( d[ady] >  distancia_candidata ){
              origen[ady] = n_act;
              d[ady] =  distancia_candidata;
              if (heapD.en_heap(ady) ) // Ya estaba en el heap, actualizamos la informacion
                  heapD.actualizar_heap( distancia_candidata, ady);  // la subimos hacia arriba en el heap
              else  heapD.insert(distancia_candidata,ady); // Lo metemos en el heap
          }
        }
    } // del for
 } //del while

 // Presentamos los resultados;
 cout << "Presentamos los resultados "<< endl;
 for (int i = 0; i < G.size(); i++)
  cout << " arco  (" << origen[i] << "," << i << ") costo " <<  d[i] <<
 endl;
}



/*--- Programa principal ----------------------------------------------------*/

int main()
{
  grafo G(5);

  G.asignar_peso(0,0,0)  ; G.asignar_peso(0,1,4)  ; G.asignar_peso(0,2,1);  
  G.asignar_peso(0,3,8)  ; G.asignar_peso(0,4,10) ;
  G.asignar_peso(1,0,4)  ; G.asignar_peso(1,1,0)  ; G.asignar_peso(1,2,2);  
  G.asignar_peso(1,3,3)  ; G.asignar_peso(1,4,7)  ;
  G.asignar_peso(2,0,1)  ; G.asignar_peso(2,1,2)  ; G.asignar_peso(2,2,0);  
  G.asignar_peso(2,3,6)  ; G.asignar_peso(2,4,10) ;
  G.asignar_peso(3,0,8)  ; G.asignar_peso(3,1,3)  ; G.asignar_peso(3,2,6);  
  G.asignar_peso(3,3,0)  ; G.asignar_peso(3,4,2)  ;
  G.asignar_peso(4,0,10) ; G.asignar_peso(4,1,7)  ; G.asignar_peso(4,2,10);
  G.asignar_peso(4,3,2)  ; G.asignar_peso(4,4,0);

  vertice org=4;
  cout << "Tamaño del Grafo "  << G.size() << endl;
  cout << "llamo a Prim (origen) " << org <<  endl;
  Prim(G,org);

}
 
                
 
