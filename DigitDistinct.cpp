#include <iostream>

int countDigit(long long n) 
{ 
    int count = 0; 
    while (n != 0) { 
        n = n / 10; 
        ++count; 
    } 
    return count; 
} 

bool BasamakSayisiDogrumu(int number){
  if(countDigit(number)<6){
    return true;
  }
  else{
    return false;
  }
}

bool RakamlarFarklimi(int number) {
    bool arr[10];
    for (int i=0; i<10; i++)
        arr[i] = false;
    while (number > 0) {
    int digit = number % 10;
      if (arr[digit])
           return false;
        arr[digit] = true;
        number = number/10;
    }
    return true;
}
int SayiGirEkrani(int number){
    

  std::cout << "Bir Sayi giriniz: \n";
  std::cin >> number;
  return number;
}

int main() {
  long enterredNumber;
  
  enterredNumber = SayiGirEkrani(enterredNumber);

  while( enterredNumber >2147483647 ){
    std::cout <<" Çok büyük sayi girme! \n";
    enterredNumber = SayiGirEkrani(enterredNumber);
  }
 
  while(!(enterredNumber >=0 && BasamakSayisiDogrumu(enterredNumber) && RakamlarFarklimi(enterredNumber))){

    enterredNumber = SayiGirEkrani(enterredNumber);
    
  }

  std::cout << "\nGiriginiz "  << enterredNumber << " 5 rakamdan az olup her rakami farklidir.";


}
    


