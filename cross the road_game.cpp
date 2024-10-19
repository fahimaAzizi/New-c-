#include <iostream>
#include <deque>

using namespace std;

class cplayer
{ public: 
int x,y;
cplayer(int width){ x = width /2; y = 0;}
};
class cLane{
 private:
   deque<bool> cars;
 public :
   cLane(int width){
   for(int i = 0;i < width ; i++)
   cars.push_front(false);
   }
};
class cGame
{
 private:
   bool quit;
 public:
  void Draw(){

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
        getchar();

    }
