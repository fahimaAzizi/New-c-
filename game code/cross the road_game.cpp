#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class cPlayer
{ public: 
int x,y;
cPlayer(int width){ x = width /2; y = 0;}
};
class cLane{
 private:
   deque<bool> cars;
 public :
   cLane(int width){
   for(int i = 0;i < width ; i++)
   cars.push_front(false);
   }
   void Move()
   {
    if (rand()% 10 == 1)
      cars.push_front(true);
      else 
      cars.push_front(false);
   }
   bool CheckPos(int pos){return cars [pos];}
};
class cGame
{
 private:
   bool quit;
   int numberOfLanes;
   int width;
   int score;
   cPlayer * player;
   vector<cLane*> map;
 public:
 cGame(int w = 20 ,int h = 10 )
  {
  numberOfLanes =h;
  width = w;
  quit =false;
  for (int  i = 0; i< numberOfLanes;i++)
  map.push_back(new cLane(width));
  player =new cPlayer(width);
  }
  void Draw(){
  system("cls");
  for (int  i = 0; i< numberOfLanes;i++)
    {
       for (int  j = 0; j< width; j++)
    {
        if(map[i]->CheckPos(j))
          cout <<"#";
        else if (player-> x == j && player-> y ==i )
        cout<<"V";
        else 
        cout << " ";
    }
    cout << endl;
    }
  }
  void Input(){

  }
  void Logic(){

  }
  void Run(){
     while(!quit){
    Input();
    Draw();
    Logic();
  }
  }
 
};
int main()
{
  cLane lane1(10);
  for (int i =0 ; i <20 ; i++){

     if (lane1.CheckPos(i))
     cout << "1";
     else
     cout <<"0" ;
  }
  lane1.Move();
  lane1.Move();
  lane1.Move();
  lane1.Move();
  cout << endl;

   for (int i =0 ; i <20 ; i++){

     if (lane1.CheckPos(i))
     cout << "1";
     else
     cout <<"0" ;
cGame game(30,5);
 getchar();
 game.Run();
 return 0;
  }
