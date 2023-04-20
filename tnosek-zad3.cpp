//Proszę napisać program, który wczytuje dwie liczby całkowite 
//(co najwyżej stucyfrowe) a następnie wylicza i drukuje ich iloczyn.
#include<iostream>
#include<stdio.h>
#include<string.h>


using namespace std;
    

string multiply(string num1, string num2){
    //inicjujemy dlugosci naszych stringow z wartosciami jakie chcemy ze soba pomnozyc
    int len1 = num1.size(); 
    int len2 = num2.size();

    //badamy przypadek kiedy dlugosci stringow sa rowne 0
    if(len1 == 0 || len2 == 0) return "0";

    //inicjalizujemy string, w ktorym bedziemy przechowywac wynik mnozenia
    string result(len1 + len2,0);

    //mnozymy przez siebie kolejne elementy podanych numerow od tylu
    for(int i=len1-1; i>=0; i--){
        for(int j=len2-1; j>=0; j--){
            //mnozymy przez siebie nastepne elementy pamietajac o tym, ze string
            //konczy sie \0, czyli musimy usunac '0' z konca mnozonego elementu
            int n = (num1[i]-'0')*(num2[j]-'0') + result[i+j+1];
            // dodajemy wynik podzielony modulo do result
            result[i+j+1] = n%10;
            // do poprzedniego elementu dodajemy liczbe dziesiatek
            result[i+j] += n/10;
        }
    }

    //dodajemy kolejny element do result aby string mial odpowiednia ilosc znakow
    for(int i=0; i< result.size();i++) result[i] += '0';

    //usuwamy nadmiarowe zera z przodu
    int i = 0;
    while(result[i] == '0') i++;
    result = result.substr(i);

 return result;
}



int main(){
    //tworzymy dwa stringi o maksymalnej dlugosci 100 znakow
    string n1{100};
    n1 = "00623781900";
    string n2{100};
    n2 = "0070981200";

    if((n1[0] == '-' || n2[0] == '-')&&
        (n1[0] != '-' || n2[0] != '-')) 
        cout<<"-";
    
    if(n1.at(0) == '-') n1 = n1.substr(1);
    if(n2.at(0) == '-') n2 = n2.substr(1);

    cout<< multiply(n1,n2)<<endl;
    return 0;
}




