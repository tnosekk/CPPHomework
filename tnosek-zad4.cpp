#include <iostream>
#include <cmath>


void pmf(int n, double *table_pmf){
    srand(time(nullptr)); //ustawiamy ziarno generatora zalezne od czasu
    int table[11] ={0}; // inicjujemy tablice o wielkosci 11(mozemy wylosowac liczby od 2 do 12), gdzie kazdy index
                        //odpodwiada konkretnej wylosowanej liczbie, tj. table[0] odpowiada wylosowaniu 2 itd.

    for(int i = 0; i<n;i++){
        uint throw1 = rand()%6 + 1;
        uint throw2 =  rand()%6 + 1; 
        uint total = throw1 + throw2;
        table[total-2]++; //przy wylosowaniu danej liczby dodajemy 1 w miejsu odpowiadajacej jej liczbie. -2 wywodzi się z tego,
                            // ze indexujemy od 0 a najmniejsza liczba mozliwa do wylosowania to 2, gdybsmy rzucali 3 koscmi odjelibyśmy
                            // 3
    }

    for(int i=0; i<11; i++){
        table_pmf[i] = (double)table[i]/n; //dla kazdej liczby wyliczamy prawdopowodbienstwo jej wyrzucenia dzielac ilosc wylosowania danej
                                            // liczby przez ilosc wszystkich rzutow
    }
}

void print_histogram(double v[], int n){ //int x_start, double y_scale
    //v[] = wyniki rozkładu, n = ilosc prob,  x_start = zmienne niezalezne, y_scale = przeskalowana(*1000) i zaokraglona wartość funkcji
    for(int i = 0; i<11;i++){
        int x_start = i+2;
        int y_scale = round(v[i]*100); //zaokraglenie oraz przeskalowanie lizczby

        std::cout<<x_start;
        if(x_start<10) std::cout<<"  | ";
        else std::cout<<" | ";
        for(int i = 0; i < y_scale;i++) std::cout<<"* ";
        double rounded = round(v[i]*1000)/1000;
        std::cout<<rounded<<"\n";

    }
}

int main(){
    int n; // ilosc rzutow obiema kosciami
    double table_pmf[11] = {0};
    std::cout<<"How many times do you want to roll the dice?\n";
    std::cin>>n;
   
    pmf(n, table_pmf);
    print_histogram(table_pmf, n);

    return 0;
}


