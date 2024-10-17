#include <iostream>
using namespace std;
bool gameOver;
const int width =20 ;
const int height =20 ;
int x,y ,furitX, furitY , score;
enum eDirecton {STOP =0 ,LEFT , RIGHT ,UP, DOWN};
eDirecton dir;

void Setup()
 {
  
  gameOver = false ;
  dir = STOP;
  x = width /2 ;
  y  = height / 2;
  furitX =rand()% width ;
  furitY = rand()% height;
}
void Draw()
{
  system("cls"); 
  for (int i =0 ; i < width+2 ; i++);
     cout <<"#" ;
  cout << endl ;

  for (int i =0 ; i < height ; i++)
  {
      for (int j =0 ; j < width ; j++)
      {
        if (j == 0 )
          cout << "#";
          
        if (i == y && j == x)

          cout <<"0";
        else if (i == furitY && j == furitX)
          cout <<"f";
        else 
          cout <<" ";
        if (j == width -1)
          cout <<"#";
      }
      cout << endl ;
    
  }

  for (int i =0 ; i < width+2 ; i++);
    cout <<"#" ;
  cout << endl ;
}
void input()
{

}
void logic()
{

}
int main()
{
  Setup();
  while ( !gameOver )
  {
    Draw();
    input();
    logic();
  }
return 0 ;
}


