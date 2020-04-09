#include <iostream>
#include <fstream>
using namespace std;
int main(int ac, char *av[]){
  char *name,*name1;
  if (ac > 1) {
    name = av[1];
    name1 =av[2];
  }
  else {
    cout<<"Не заданы имена файлов\n";
    return 1;
  }
  ifstream f(name);
  int a,k=0,min,max,n1,n2;
  f>>a;
  n1=n2=k;
  min=max=a;
  while (!f.eof()){
    f>>a;
    k++;
    if (a<min){
      min=a;
      n1=k;
    }
    if (a>max){
      max=a;
      n2=k;
    }
  }
  f.seekg(0, ios_base::beg);
  k=-1;
  ofstream f1(name1);
  f1<<min<<" ";
  while (!f.eof()){
    f>>a;
    k++;
    if ((k!=n1)and(k!=n2))
      f1<<a<<" ";
  }
  f1<<max;
  f.close();
  f1.close();
}


