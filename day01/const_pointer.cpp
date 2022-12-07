#include <iostream>
using namespace std;

void xstrcpy_modify (char *, char *);
void xstrcpy_const (char *, const char *);

int main()
{
  cout << endl << endl << " START " <<  " Const Pointer " << endl;
  cout << "------------------------------------------------------- " << endl;  
  char str1[] = "Nagpur";
  char str2[10];
  xstrcpy_modify (str2, str1);
  cout << endl <<" non const declaration can modify original : Nagpur  =>  " << str1 << endl;
  cout << endl <<" modified copy : " << str2 << endl;

  char str3[] = "Nagpur";
  char str4[10];
  xstrcpy_const (str4, str3);
  cout << endl << " const declaration can not modify original : Nagpur  => " << str3 << endl;
  cout << endl <<" modified copy : " << str4 << endl;
  cout << "------------------------------------------------------- " << endl << endl ; 
  cout << "------------------------------------------------------- " << endl << endl ;
  return 0;
}

void xstrcpy_modify (char *t, char *s)
{
  char *original = s;
  *original = 'K';
  while (*s != '\0') {
    *t = *s;
    t++;
    s++;
  }
  *t = '\0';
}

void xstrcpy_const (char *t, const char *s)
{
  // cannot assign const char* s to char*
  //    char *original = s;
  // cannot modify const char* s
  //    *s = 'K' 

  char str[] = "Nagpur";
  *str = 'K';

  // const pointer can be modified to point another location
  s = str;

  while (*s != '\0') {
    *t = *s;
    t++;
    s++;
  }
  *t = '\0';
}
