#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string remove(string s,int n,int k){
  string s1="";
  for (int i=0;i<s.size();i++)
    if ((i<n) or (i>k))
      s1=s1+s[i];
  return s1;
}

int main(int argc, char *argv[]) {
  string s;
  int n,k;
  if (argc<=2){
    cout<<"Не заданы имена файлов"<<endl;
    return 0;
  }
  ifstream f(argv[1]);
  ofstream f1(argv[2]);
  if (!f.is_open()&f1.is_open()){
    cout<<"Ошибка открытия файла, попробуйте еще"<<endl;
    return 0;
  }
  cin>>n>>k;
  f>>s;
  if ((n<0) or (k<0) or (n>k) or (k>=s.size())){
    cout<<"Удаление невозможно"<<endl;
    cout<<"Длина строки: "<<s.size()<<endl;
    return 0;
  }
  f1<<remove(s,n,k);
  f.close();
  f1.close();
}