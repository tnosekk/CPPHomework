#include<iostream>
#include<stdlib.h>  
#include<time.h> 

int my_random(int min,int max){
    return min + (rand()%(max-min));
}
int main(){
  srand(time(NULL));
  
  int random = my_random(0,100);
  int n = 0;
  int min = 0, max = 100;
  
  do{
    n = my_random(min,max);

    std::cout<<std::endl;
    std::cout<<"Guess = "<<n<<std::endl;

    if(n == random){
        std::cout<<"The number you are looking for is "<<n<<std::endl;
    }
    else if (n > random){
        std::cout<<"Too big"<<std::endl;
        max = n;
        std::cout<<"Finding number between "<<min<< " and "<<max<<std::endl;
    }
    else if (n < random){
        std::cout<<"Too small"<<std::endl;
        min = n;
        std::cout<<"Finding number between "<<min<<" and "<<max<<std::endl;
    }    
  }
while(n!=random);
    
return 0;
}






