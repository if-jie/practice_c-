#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

// heap conducted in STL
#include <queue>
using namespace std;

struct control_block{
    int count;
    control_block(): count(1);
};


template<typename T>
class simple_shared_ptr {
    private:
        T *ptr;
        control_block *count;
    public:
        void release(){
            if(count){
                auto temp = count->count--;
                if(temp){
                
                }else{
                    delete count;
                    count=nullptr;
                    delete ptr;
                    ptr=nullptr;
                }
                
            }
        }

        simple_shared_ptr():ptr(nullptr),count(nullptr){}
        simple_shared_ptr(T *p):ptr(p){
            if(p){
                count = new control_block();
            }else{
                count = nullptr;
            }
        }
        simple_shared_ptr(const simple_shared_ptr &s):ptr(s.ptr),count(s.count){
            if(count){
                ++count->count;
            }
        }
        ~simple_shared_ptr(){
            if(ptr){
                release();
            }
        }
}


int main(){




    return 0;

}