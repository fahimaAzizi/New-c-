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


