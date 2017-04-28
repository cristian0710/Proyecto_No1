#include <stdio.h>
#include <stdlib.h>
#define reservar (nodo*)malloc(sizeof(nodo));

struct nodo
{
    int n;
    nodo *sig;
}*pila=NULL,*cabeza=NULL,*cola=NULL, *prim=NULL, *ulti=NULL;

struct nodo2{
    int n;
    nodo2 *siguiente;
    nodo2 *atras;
}*primero=NULL, *ultimo=NULL;

void menu();
void lifo();
void fifo();
void lista_simple();
void lista_doble();

int main()
{
    menu();
    //printf("\n%d",pila->n);
}

void menu()
{
    system("cls");
    int x;
    printf("****************** MENU *******************\n");
    printf("1. Listas LIFO\n");
    printf("2. Listas FIFO\n");
    printf("3. Listas simplemente enlazadas\n");
    printf("4. Listas doblemente anlazada\n");
    printf("5. Listas circulares simplemente enlazadas\n");
    printf("6. Listas circulares doblemente enlazadas\n");
    printf("7. Salir\n");
    printf("Seleccione la opcion: ");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        {
            lifo();
            system("pause");
            menu();
        }break;
    case 2:
        {
            fifo();
            system("pause");
            menu();
        }break;
    case 3:
        {
            lista_simple();
            system("pause");
            menu();
        }break;
    case 4:
        {
            lista_doble();
            system("pause");
            menu();
        }
    }
}
/////////////////////////////////////////////////////FUNCION DE PILA///////////////////////////////////////////
void lifo()
{
    system("cls");
    int x, a, b, c;
    printf("******** PILAS *********\n");
    printf("1. Crear lista LIFO\n");
    printf("2. Insertar elementos\n");
    printf("3. Imprimir lista LIFO\n");
    printf("4. Buscar elementos\n");
    printf("5. Eliminar elementos\n");
    printf("6. Editar elementos\n");
    printf("7. Lista vacia\n");
    printf("8. Eliminar lista LIFO\n");
    printf("9. Volver al menu\n");
    printf("Digite opcion: ");
    scanf("%d",&x);

    switch(x)
    {
    case 1:
        {
            printf("La lista LIFO ha sido creada\n");
            system("pause");
            lifo();
        }break;
    case 2:
        {
            do
            {
                nodo *nuevo_nodo=(nodo*)malloc(sizeof(nodo));
                printf("Ingrese dato de la pila: ");
                scanf("%d",&nuevo_nodo->n);
                nuevo_nodo->sig=pila;
                pila=nuevo_nodo;
                printf("Ingresar mas datos en la pila  1.SI o 2.NO: ");
                scanf("%d",&a);
            }while(a==1);
            lifo();
        }break;
    case 3:
        {
            printf("1. Mostrar el primer elemento\n");
            printf("2. Mostrar el ultimo elemento\n");
            printf("3. Mostrar todos los elementos\n");
            printf("Digite opcion: ");
            scanf("%d",&a);
            if(pila!=NULL)
            {
                switch(a)
                {
                case 1:
                    {
                        nodo *aux=pila;
                        while(aux!=NULL)
                        {
                            if(aux->sig==NULL)
                            {
                                printf("El primer elemento de la pila es: %d\n",aux->n);
                            }
                            aux=aux->sig;
                        }
                        system("pause");
                        lifo();
                    }break;
                case 2:
                    {
                        printf("El ultimo elemento de la pila es: %d\n",pila->n);
                        system("pause");
                        lifo();
                    }break;
                case 3:
                    {
                        nodo *aux=pila;
                        while(aux!=NULL)
                        {
                            b=aux->n;
                            printf("%d ",b);
                            aux=aux->sig;
                        }
                        system("pause");
                        lifo();
                    }break;
                default:
                    printf("opcion incorrecta\n");
                    system("pause");
                }
            }
            else{
                printf("La pila esta vacia\n");
                system("pause");
            }
            lifo();
        }break;
    case 4:
      {
          int c=0;
          printf("Ingrese elemento que desea buscar: ");
          scanf("%d",&a);
          nodo *aux=pila;
          while(aux!=NULL)
          {
              if(aux->n==a)
              {
                  printf("El numero %d esta en la pila\n",a);
                  c++;
              }
              aux=aux->sig;
          }
          if(c==0)
          {
              printf("El numero no se encuentra en la pila\n");
          }
          system("pause");
          lifo();
        }break;
    case 5:
        {
            c=0;
            if(pila!=NULL){
                nodo *actual=reservar;
                actual=pila;
                nodo *anterior=reservar;
                anterior=NULL;
                printf("Ingrese elemento que desea eliminar: ");
                scanf("%d",&a);
                while(actual!=NULL && c!=1){
                        if(actual->n==a){
                            if(actual==pila){
                                pila=pila->sig;
                            }else{
                                anterior->sig=actual->sig;
                            }
                            c=1;
                        }
                        anterior=actual;
                        actual=actual->sig;
                }
                if(c==0){
                    printf("El dato no fue encontrado\n");
                }else{
                    free(anterior);
                }
            }else{
                printf("La pila esta vacia\n");
            }
            system("pause");
            lifo();
        }break;
    case 6:
        {
            if(pila!=NULL){
                c=0;
                nodo *nuevo=(nodo*)malloc(sizeof(nodo));
                nuevo=pila;
                printf("Digite el dato que desea modificar: ");
                scanf("%d",&a);
                while(nuevo!=NULL){
                    if(nuevo->n==a){
                        printf("Ingrese dato: ");
                        scanf("%d",&nuevo->n);
                        c=1;
                    }
                    nuevo=nuevo->sig;
                }
                if(c==0){
                    printf("El dato no fue encontrado\n");
                }
            }else{
                printf("La pila esta vacia\n");
            }
            system("pause");
            lifo();
        }break;
    case 7:
        {
            if(pila==NULL)
            {
                printf("La pila esta vacia\n");
            }
            else
            {
                printf("la pila no esta vacia\n");
            }
        }break;
    case 8:
        {
            if(pila!=NULL){
                printf("La pila no se puede eliminar por que aun tiene elementos\n");
            }else{
                free(pila);
                printf("Pila eliminada\n");
            }
        }break;
    case 9:
        {
            menu();
        }break;
    default:
        {
            printf("opcion incorrecta\n");
            system("pause");
            lifo();
        }
    }
}
///////////////////////////////////////////////////// FUNCION COLA /////////////////////////////////////////////
void fifo()
{
    system("cls");
    int x, a, c;
    printf("******** COLAS *********\n");
    printf("1. Crear lista FIFO\n");
    printf("2. Insertar elementos\n");
    printf("3. Imprimir lista FIFO\n");
    printf("4. Buscar elementos\n");
    printf("5. Eliminar elementos\n");
    printf("6. Editar elementos\n");
    printf("7. Lista vacia\n");
    printf("8. Eliminar lista FIFO\n");
    printf("9. Volver al menu\n");
    printf("Digite opcion: ");
    scanf("%d",&x);

    switch(x){
        case 1:{
            if(cabeza==NULL && cola==NULL){
                nodo *cabeza=NULL, *cola=NULL;
                printf("La lista FIFO ha sido creada\n");
            }else{
                printf("La lista ya esta creada\n");
            }
        }break;
        case 2:{
            do{
                nodo *nuevo=(nodo*)malloc(sizeof(nodo));
                printf("Ingrese dato a la cola: ");
                scanf("%d",&nuevo->n);
                if(cabeza==NULL){
                    cabeza=nuevo;
                    cabeza->sig=NULL;
                    cola=nuevo;
                }
                else{
                    cola->sig=nuevo;
                    nuevo->sig=NULL;
                    cola=nuevo;
                }
                printf("Desea Ingresar mas datos a la cola 1:SI o 2.NO: ");
                scanf("%d",&a);
            }while(a==1);
        }break;
        case 3:{
            printf("1. Mostrar el primer elemento\n");
            printf("2. Mostrar el ultimo elemento\n");
            printf("3. Mostrar todos los elementos\n");
            printf("Digite opcion: ");
            scanf("%d",&a);
            if(cabeza!=NULL){
                switch(a){
                    case 1:{
                        printf("El primer elemento de la cola es: %d\n",cabeza->n);
                    }break;
                    case 2:{
                        printf("El ultimo elemento de la cola es: %d\n",cola->n);
                    }break;
                    case 3:{
                        if(cabeza!=NULL){
                            nodo *aux=reservar;
                            aux=cabeza;
                            while(aux!=NULL){
                                printf("%d ",aux->n);
                                aux=aux->sig;
                            }
                        }
                        else{
                            printf("La cola esta vacia\n");
                        }
                    }break;
                    default:{
                        printf("Opcion incorrecta\n");
                    }break;
                }
            }
            else{
                printf("La pila esta vacia\n");
            }
        }break;
        case 4:{
            if(cabeza!=NULL){
                int c=0;
                printf("Ingrese dato que desea buscar: ");
                scanf("%d",&a);
                nodo *aux=cabeza;
                while(aux!=NULL){
                    if(aux->n==a){
                        printf("El numero %d esta en la cola\n",aux->n);
                        c++;
                    }
                    aux=aux->sig;
                }
                if(c==0){
                    printf("El numero no se encuentra en la cola\n");
                }
            }
            else{
                printf("La cola esta vacia\n");
            }
        }break;
        case 5:{
            c=0;
            nodo *actual=(nodo*)malloc(sizeof(nodo));
            actual=cabeza;
            nodo *anterior=(nodo*)malloc(sizeof(nodo));
            anterior=NULL;
            printf("Ingrese dato que desea eliminar de la cola: ");
            scanf("%d",&a);
            if(cabeza!=NULL){
                while(actual!=NULL && c!=1){
                    if(actual->n==a){
                        if(actual==cabeza)
                        {
                            cabeza=cabeza->sig;
                        }else if(actual==cola){
                            anterior->sig=NULL;
                            cola=anterior;
                        }else{
                            anterior->sig=actual->sig;
                        }
                        printf("Elemento eliminado con exito\n");
                        c=1;
                    }
                    anterior=actual;
                    actual=actual->sig;
                }
                if(c==0){
                    printf("El dato no fue encontrado\n");
                }
                else{
                    free(anterior);
                }
            }
            else{
                printf("La lista se encuentra vacia\n");
            }
        }break;
        case 6:{
            c=0;
            nodo *actual=(nodo*)malloc(sizeof(nodo));
            actual=cabeza;
            printf("Ingrese dato que desea moificar: "),
            scanf("%d",&a);
            if(cabeza!=NULL){
                while(actual!=NULL){
                    if(actual->n==a){
                        printf("Ingrese el nuevo dato: ");
                        scanf("%d",&actual->n);
                        c++;
                    }
                    actual=actual->sig;
                }
                if(c==0){
                    printf("El dato no se encuentra en la cola\n");
                }
            }
            else{
                printf("La cola esta vacia\n");
            }
        }break;
        case 7:{
            if(cabeza!=NULL){
                printf("La cola no esta vacia\n");
            }else{
                printf("La cola esta vacia\n");
            }
        }break;
        case 8:{
            nodo *aux=(nodo*)malloc(sizeof(nodo));
            aux=cabeza;
            if(cabeza!=NULL){
                while(cabeza!=NULL){
                    aux=cabeza;
                    cabeza=aux->sig;
                    free(aux);
                }
            }
            else{
                printf("La cola esta vacia\n");
            }
        }break;
        case 9:{
            menu();
        }break;
        default:{
            printf("Opcion incorrecta\n");
        }
    }
    system("pause");
    fifo();
}
///////////////////////////////////////////////////// LISTAS SIMPLES //////////////////////////////////////////
void lista_simple()
{
    system("cls");
    int x, a, b, c;
    printf("******** LISTAS SIMPLES *********\n");
    printf("1. Crear lista\n");
    printf("2. Insertar elementos en lista\n");
    printf("3. Imprimir lista\n");
    printf("4. Buscar elementos en la lista\n");
    printf("5. Eliminar elementos de la lista\n");
    printf("6. Editar elementos de lista\n");
    printf("7. Lista vacia\n");
    printf("8. Eliminar lista\n");
    printf("9. Volver al menu\n");
    printf("Digite opcion: ");
    scanf("%d",&x);

    switch(x){
        case 1:{
            nodo *prim=NULL, *ulti=NULL;
            printf("La lista simple ha sido creada\n");
        }break;
        case 2:{
            system("cls");
            printf("1. Insertar elementos a la lista\n");
            printf("2. Insertar elementos al inicio de la lista\n");
            printf("3. Insertar despues de un nodo\n");
            printf("4. Insertar antes de un nodo\n");
            printf("5. Insertar en medio de dos nodos\n");
            printf("6. Insertar en forma ascendente\n");
            printf("7. Insertar en forma descendente\n");
            printf("Digite la opcion: ");
            scanf("%d",&a);
            switch(a){
                case 1:{
                    do{
                        nodo *nuevo=(nodo*)malloc(sizeof(nodo));
                        printf("Ingrese dato en la lista: ");
                        scanf("%d",&nuevo->n);
                        if(prim==NULL){
                            prim=nuevo;
                            prim->sig=NULL;
                            ulti=prim;
                        }else{
                            ulti->sig=nuevo;
                            nuevo->sig=NULL;
                            ulti=nuevo;
                        }
                        printf("Desea Ingresar mas datos 1.SI 0 2.NO: ");
                        scanf("%d",&a);
                    }while(a==1);
                }break;
                case 2:{
                    if(prim!=NULL){
                        nodo *nuevo=(nodo*)malloc(sizeof(nodo));
                        printf("Ingrese dato al inicio de la lista: ");
                        scanf("%d",&nuevo->n);
                        nuevo->sig=prim;
                        prim=nuevo;
                    }else{
                        printf("La lista esta vacia\n");
                    }
                }break;
                case 3:{
                    if(prim!=NULL){
                        nodo *actual=(nodo*)malloc(sizeof(nodo));
                        actual=prim;
                        printf("Insertar dato depues del: ");
                        scanf("%d",&a);
                        while(actual!=NULL || c!=1){
                            if(actual->n==a){
                                nodo *nuevo=(nodo*)malloc(sizeof(nodo));
                                printf("Digite dato para ingresar a la lista: ");
                                scanf("%d",&nuevo->n);
                                nuevo->sig=actual->sig;
                                actual->sig=nuevo;
                                actual=nuevo;
                                c=1;
                            }
                            actual=actual->sig;
                        }
                    }else{
                        printf("La lista esta vacia\n");
                    }
                }break;
                case 4:{
                    c=0;
                    if(prim!=NULL){
                        nodo *actual=(nodo*)malloc(sizeof(nodo));
                        actual=prim;
                        nodo *anterior=(nodo*)malloc(sizeof(nodo));
                        anterior=NULL;
                        printf("Insertar dato antes del: ");
                        scanf("%d",&a);
                        while(actual!=NULL && c!=1){
                            if(actual->n==a){
                                nodo *nuevo=reservar;
                                if(actual==prim){
                                    printf("Digite dato para ingresar a la lista: ");
                                    scanf("%d",&nuevo->n);
                                    nuevo->sig=actual;
                                    prim=nuevo;
                                    c=1;
                                }else{
                                    printf("Digite dato para ingresar a la lista: ");
                                    scanf("%d",&nuevo->n);
                                    nuevo->sig=actual;
                                    anterior->sig=nuevo;
                                    anterior=nuevo;
                                    c=1;
                                }
                            }
                            anterior=actual;
                            actual=actual->sig;
                        }
                        if(c==0){
                            printf("El dato no se encuentra en la lsita\n");
                        }
                    }else{
                        printf("La lista esta vacia\n");
                    }
                }break;
                case 5:{
                    c=0;
                    nodo *actual=reservar;
                    actual=prim;
                    nodo *anterior=reservar;
                    anterior=NULL;
                    printf("Ingrese valor del primer dato: ");
                    scanf("%d",&a);
                    printf("Ingrese valor del segundo dato: ");
                    scanf("%d",&b);
                    if(prim!=NULL){
                        while(actual!=NULL && c!=1){
                            if(actual->n==b && anterior->n==a){
                                nodo *nuevo=reservar;
                                printf("Ingrese dato nuevo: ");
                                scanf("%d",&nuevo->n);
                                nuevo->sig=actual;
                                anterior->sig=nuevo;
                                anterior=nuevo;
                                c=1;
                            }
                            anterior=actual;
                            actual=actual->sig;
                        }
                    }else{
                        printf("La lista esta vacia\n");
                    }
                }break;
            }
        }break;
        case 3:{
            if(prim!=NULL){
                printf("1. Imprimir el primer elemento\n");
                printf("2. Mostrar el ultimo elemento\n");
                printf("3. Mostrar todos los elementos\n");
                printf("4. Mostrar el anetrior elemento a un dato dado\n");
                printf("5. Mostrar el siguiente elemento a un nodo dado\n");
                scanf("%d",&a);
                switch(a){
                    case 1:{
                        printf("%d\n",prim->n);
                    }break;
                    case 2:{
                        printf("%d\n",ulti->n);
                    }break;
                    case 3:{
                        nodo *nuevo=reservar;
                        nuevo=prim;
                        while(nuevo!=NULL){
                            printf("%d ",nuevo->n);
                            nuevo=nuevo->sig;
                        }
                    }break;
                    case 4:{
                        c=0;
                        nodo *actual=reservar;
                        actual=prim;
                        nodo *anterior=reservar;
                        anterior=NULL;
                        printf("Imprimir elemento anterior del: ");
                        scanf("%d",&a);
                        while(actual!=NULL){
                            if(actual->n==a){
                                if(actual==prim){
                                    printf("No hay elemento anterior por que %d es el primer elemento\n",actual->n);
                                }else{
                                    printf("El elemento anterior es: %d\n",anterior->n);
                                }
                                c=1;
                            }
                            anterior=actual;
                            actual=actual->sig;
                        }
                        if(c==0){
                            printf("El elemento no se encuentra en la lista\n");
                        }
                    }break;
                    case 5:{
                        c=0;
                        nodo *actual=reservar;
                        actual=prim;
                        nodo *anterior=reservar;
                        anterior=NULL;
                        printf("Imprimir elemento siguiente del: ");
                        scanf("%d",&a);
                        while(actual!=NULL){
                            if(actual->n==a){
                                if(actual==ulti){
                                    printf("No hay elemento siguiente por que el %d es el ultimo dato\n",actual->n);
                                }else{
                                    actual=actual->sig;
                                    printf("El elemento siguiente es: %d\n",actual->n);
                                }
                                c=1;
                            }
                            actual=actual->sig;
                        }
                        if(c==0){
                            printf("El elemento no se encuentra en la lista\n");
                        }
                    }break;
                }
            }else{
                printf("La lista esta vacia\n");
            }
        }break;
        case 4:{
            c=0;
            if(prim!=NULL){
                nodo *aux=reservar;
                aux=prim;
                printf("Ingrese el dato que desea buscar: ");
                scanf("%d",&a);
                while(aux!=NULL){
                    if(aux->n==a){
                        printf("El dato %d se encuentra en la lista\n",aux->n);
                        c=1;
                    }
                    aux=aux->sig;
                }
                if(c==0){
                    printf("El dato no se encuentra en la lista\n");
                }
            }else{
                printf("La lista esta vacia\n");
            }
        }break;
        case 5:{
            if(prim!=NULL){
                nodo *actual=reservar;
                actual=prim;
                nodo *anterior=reservar;
                anterior=NULL;
                printf("Ingrese el dato que desea eliminar: ");
                scanf("%d",&a);
                while(actual!=NULL && c!=1){
                    if(actual->n==a){
                        if(actual==prim){
                            prim=prim->sig;
                        }else if(actual==ulti){
                            anterior->sig=NULL;
                            anterior=actual;
                        }else{
                            anterior->sig=actual->sig;
                        }
                        c=1;
                    }
                    anterior=actual;
                    actual=actual->sig;
                }
                if(c==0){
                    printf("El dato no se encuentra en la lista\n");
                }else{
                    free(anterior);
                    printf("El dato ha sido eliminado\n");
                }
            }
            else{
                printf("La lista esta vacia\n");
            }
        }break;
        case 6:{
            c=0;
            if(prim!=NULL){
                nodo *aux=reservar;
                aux=prim;
                printf("Ingrese dato que desea modificar: ");
                scanf("%d",&a);
                while(aux!=NULL){
                    if(aux->n==a){
                        printf("Ingrese nuevo dato: ");
                        scanf("%d",&aux->n);
                        c=1;
                    }
                    aux=aux->sig;
                }
                if(c==0){
                    printf("El dato no se encuentra en la lista\n");
                }else{
                    printf("El dato ha sido midificado\n");
                }
            }
            else{
                printf("La lista esta vacia\n");
            }
        }break;
        case 7:{
            if(prim==NULL){
                printf("La lista esta vacia\n");
            }else{
                printf("La lista no esta vacia\n");
            }
        }break;
        case 8:{
            if(prim!=NULL){
                nodo *aux=reservar;
                while(prim!=NULL){
                    aux=prim;
                    prim=prim->sig;
                    free(aux);
                }
                printf("Los elementos de la lista se han eliminado\n");
            }else{
                printf("La lista esta vacia\n");
            }
        }break;
        case 9:{
            menu();
        }break;
        default:
            printf("Opcion incorrecta\n");
    }
    system("pause");
    lista_simple();
}
///////////////////////////////////////////////// LISTAS DOBLEMENTE ENLAZADAS ////////////////////////////////
void lista_doble()
{
    system("cls");
    int x, a, b, c;
    printf("******** LISTAS DOBLEMENTE ENLAZADA *********\n");
    printf("1. Crear lista\n");
    printf("2. Insertar elementos en lista\n");
    printf("3. Imprimir lista\n");
    printf("4. Buscar elementos en la lista\n");
    printf("5. Eliminar elementos de la lista\n");
    printf("6. Editar elementos de lista\n");
    printf("7. Lista vacia\n");
    printf("8. Eliminar lista\n");
    printf("9. Volver al menu\n");
    printf("Digite opcion: ");
    scanf("%d",&x);

    switch(x){
        case 1:{
            nodo *primero=NULL, *ultimo=NULL;
            printf("La lista doble enlazada ha sido creada\n");
        }break;
        case 2:{
            system("cls");
            printf("1. Insertar elementos a la lista\n");
            printf("2. Insertar elementos al inicio de la lista\n");
            printf("3. Insertar despues de un nodo\n");
            printf("4. Insertar antes de un nodo\n");
            printf("5. Insertar en medio de dos nodos\n");
            printf("6. Insertar en forma ascendente\n");
            printf("7. Insertar en forma descendente\n");
            printf("Digite la opcion: ");
            scanf("%d",&a);
            switch(a){
                case 1:{
                    do{
                        nodo2 *nuevo=(nodo2*)malloc(sizeof(nodo2));
                        printf("Ingrese dato en la lista: ");
                        scanf("%d",&nuevo->n);
                        if(primero==NULL){
                            primero=nuevo;
                            primero->siguiente=NULL;
                            primero->atras=NULL;
                            ultimo=primero;
                        }else{
                            ultimo->siguiente=nuevo;
                            nuevo->siguiente=NULL;
                            nuevo->atras=ultimo;
                            ultimo=nuevo;
                        }
                        printf("Desea ingresar mas elementos a la lista 1.SI 0 2.NO: ");
                        scanf("%d",&a);
                    }while(a==1);
                }break;
                case 2:{
                    if(primero!=NULL){
                        nodo2 *nuevo=(nodo2*)malloc(sizeof(nodo2));
                        printf("Ingrese data al inicio de la lista: ");
                        scanf("%d",&nuevo->n);
                        primero->atras=nuevo;
                        nuevo->siguiente=primero;
                        nuevo->atras=NULL;
                        primero=nuevo;
                    }else{
                        printf("La lista esta vacia\n");
                    }
                }break;
                case 3:{
                    c=0;
                    if(primero!=NULL){
                        nodo2 *actual=(nodo2*)malloc(sizeof(nodo2));
                        actual=primero;
                        printf("Ingresar dato despues del: ");
                        scanf("%d",&a);
                        while(actual!=NULL && c!=1){
                            if(actual->n==a){
                                nodo2 *nuevo=(nodo2*)malloc(sizeof(nodo2));
                                printf("Ingrese nuevo dato: ");
                                scanf("%d",&nuevo->n);
                                if(actual==ultimo){
                                    ultimo->siguiente=nuevo;
                                    nuevo->siguiente=NULL;
                                    nuevo->atras=ultimo;
                                    ultimo=nuevo;
                                }else{
                                    nuevo->siguiente=actual->siguiente;
                                    nuevo->atras=actual;
                                    actual->siguiente=nuevo;
                                    actual=nuevo;
                                }
                                c=1;
                            }
                            actual=actual->siguiente;
                        }
                        if(c==0){
                            printf("El dato no se encuentra en la lista\n");
                        }
                    }else{
                        printf("La lista esta vacia\n");
                    }
                }break;
            }
        }break;
        case 3:{
            nodo2 *aux=(nodo2*)malloc(sizeof(nodo2));
            aux=primero;
            while(aux!=NULL){
                printf("%d ",aux->n);
                aux=aux->siguiente;
            }
            printf("\n");
            nodo2 *aux2=(nodo2*)malloc(sizeof(nodo2));
            aux2=ultimo;
            while(aux2!=NULL){
                printf("%d ",aux2->n);
                aux2=aux2->atras;
            }
        }break;

    }

}





