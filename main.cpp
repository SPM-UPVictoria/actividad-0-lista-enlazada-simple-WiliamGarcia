#include <iostream>
#include <string>

// Wiliam Hernan Garcia Martinez - 2030247

using namespace std;

/*
*Se define el nodo
*/
struct nodo{
    int cont;
    struct nodo *next;
};



/*
*Encuentra el fin de la lista
*/
nodo* encuentrafin(nodo *&p){
    if(p==NULL)
        return p;
    if(p->next!=NULL)
        return encuentrafin(p->next);
    else
        return p;
}
/*
*Inserta un elemento en la lista
*/
void insertar(nodo *&p, int c){
    nodo *aux = new nodo();
    aux->cont = c;
    aux->next = NULL;
    if(p==NULL){
        p = aux;
    }else{
        nodo *nuevoPtr = encuentrafin(p);
        nuevoPtr->next = aux;
    }
}
/*
*Busca el elemento en la lista
*/
nodo *buscar(nodo *&p, int c){
    if(p->cont==c){
        return p;
    }else{
        return buscar(p->next,c);
    }
}
/*
*Borra un elemento de la lista
*/
void eliminar(nodo *&p, int c){
    if(p==NULL)
        cout << "Lista vacia" << endl;
    else{
        nodo *nuevoPtr = buscar(p,c);
        if(p==nuevoPtr){
            p = nuevoPtr->next;
            delete(nuevoPtr);
            return;
        }
        p->next = nuevoPtr->next;
        delete(nuevoPtr);
    }
}
/*
*Muestra el contenido de la lista
*/
void muestraCont(const nodo *p){
    if(p!=NULL){
        cout << "\n" << p->cont  << endl;
        muestraCont(p->next);
    }
    else
        return;
}

int main()
{
    nodo *raiz = NULL;
    int opcion, val;
    do{
        cout << "[1] Insertar elemento \n";
        cout << "[2] Borrar elemento \n";
        cout << "[3] Mostrar elementos \n";
        cout << "[0] Salir \n";
        cin >> opcion;
        switch(opcion){
            case 1:
                cout << "\nIngrese un valor: ";
                cin >>val;
                insertar(raiz,val);
                break;
            case 2:
                cout << "\nIngrese un valor a borrar: ";
                cin >>val;
                eliminar(raiz, val);
                break;
            case 3:
                cout << "\nContenido de la lista";
                muestraCont(raiz);
                break;
        }
    }while(opcion != 0);



}

