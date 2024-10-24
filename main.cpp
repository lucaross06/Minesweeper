#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>


void mixArray(int array[], int count);
void print(int arr[], int r, int c);
void print(int arr[], int n);
void countMines(int *mat, int r, int c, int mines[], int m);
char getch();

int main(){
    int r,c,m; // rows columns and number of mines
    int difficulty = -1;
    int* mat;
    int* vect;
    int* mines;

    while(difficulty > 2 || difficulty < 0){
        std::cout<<"inserisci difficolta' ";
        std::cin>>difficulty;
    }
    srand(time(NULL));

    switch(difficulty){
        case 0:
            c = 8;
            r = 8;
            m = 10;
            break;
        case 1:
            c = 16;
            r = 16;
            m = 40;
            break;
        case 2:
            c = 24;
            r = 24;
            m = 99;
            break;
    }
    
    mat = (int*)calloc(r * c,sizeof(int));
    vect = (int*)calloc(r * c,sizeof(int));
    mines = (int*)calloc(m,sizeof(int));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            vect[j + i * r] = j + i * r;
        }
    }

    mixArray(vect, r * c);

    for(int i = 0; i < m; i++){
        mines[i] = vect[i];
    }

    //print(vect,r,c);
    //print(mines,m);
    countMines(mat, r, c, mines, m);
    std::cout<<"\n";
    std::cout<<"\n";
    system("clear");
    print(mat,r,c);
    /*while(1){
        char c = getchar();
        std::cout<<c;
    }*/
    
    return 0;
}



void print(int arr[], int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            std::cout<<arr[j + i * r]<<"\t";
        }
        std::cout<<"\n";
    }
}
void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        std::cout<<arr[i]<<"\t";
    }
}

void mixArray(int array[],int count){
    for(int i = 0; i < count; i++){
        int j = rand() % count;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void countMines(int *mat, int r, int c, int mines[], int m){
    for(int l = 0; l < m; l++){
        //fai tutti i check se sei dentro i bordi
        // volendo si puo' fare check che non sia una bomba ma non serve
        // cosa fatta male ma non mi interessa/
        mat[mines[l]] = -999;
        if(mines[l] % r < r - 1){
            mat[mines[l]+1]++; //destra
        }
        if(mines[l] % r > 0){
            mat[mines[l]-1]++; //sinistra
        }
        if(mines[l] < r * c - c){
            mat[mines[l] + c]++;//basso
        }
        if(mines[l] > c - 1){
            mat[mines[l] - c]++;//sopra
        }
        if(mines[l] % r > 0 && mines[l] > c - 1){
            mat[mines[l] - c - 1]++; //sopra sinistra
        }
        if(mines[l] % r < r - 1 && mines[l] > c - 1){
            mat[mines[l] - c + 1]++; //sopra destra
        }
        if(mines[l] % r > 0 && mines[l] < r * c - c){
            mat[mines[l] + c - 1]++; //basso sinistra
        }
        if(mines[l] % r < r - 1 && mines[l] < r * c - c){
            mat[mines[l] + c + 1]++; //basso destra
        }
    } 
}

