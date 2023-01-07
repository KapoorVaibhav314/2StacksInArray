#include<iostream>
#include<stack>
using namespace std;
class TwoStack{
   int *arr;
   int top1;
   int top2;
   int size;

   public:
    TwoStack(int s){
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    //push in stack 1
    void push1(int num){
        //so atleast 1 space should we available
        if (top2 - top1 > 1){
            top1++;
            arr[top1] = num;
        }
    }
    //push in stack 2
    void push2(int num){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = num; 
        }
    }

    int pop1(){
      //check if elements are even present or not
      if(top1 >= 0){
        int ans = arr[top1]; //saving element to be popped
        top1--;
        return ans;
      }
      else{
        return -1;
      }
    }

    int pop2(){
        if(top2 < size){
            int ans = arr[top2];
            top2++; //increment top2, visualse it
            return ans;
        }
    }
};


int main(){
   TwoStack s(10);
   s.push1(10);
   s.push1(20);
   s.push1(30);
   s.push1(40);
   s.push2(50);
   s.push2(60);
   s.push2(70);
   s.push2(80);
   s.push2(90);
   s.push2(100);

   cout << s.pop1();
}