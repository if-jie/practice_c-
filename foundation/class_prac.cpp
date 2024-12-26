/*
 * @Author: 1454164915@qq.com 1454164915@qq.com
 * @Date: 2024-11-28 12:40:17
 * @LastEditors: 1454164915@qq.com 1454164915@qq.com
 * @LastEditTime: 2024-12-26 15:33:29
 * @FilePath: /C++/foundation/class_prac.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <ostream>
#include <vector>
#include <climits>
using namespace std;


class an_base{
    public:
        an_base(int a, int b):privatenum(a),protectednum(b){
            // std::cout<<"base_constructor"<<std::endl;
        }
        void baseFunc(){
            std::cout<<"Base_func"<<std::endl;
            std::cout<<"privatenum： "<<privatenum<<std::endl;
            std::cout<<"protectednum： "<<privatenum<<std::endl;
            std::cout<<"protectednum： "<<protectednum<<std::endl;

        }
        ~an_base(){
            // std::cout<<"base_dede： "<<privatenum<<std::endl;
        }
        virtual void speak_base(){
            std::cout<<"protectednum： "<<privatenum<<std::endl;
            std::cout<<"protectednum： "<<protectednum<<std::endl;

        }
        virtual void speak(){}
    private:
        int privatenum;
    protected:
        int protectednum;
};

class dog : public an_base {
public:
    dog(int a, int b):an_base(a,b){
        // std::cout<<"dog construct"<<std::endl;
    }
    void speak(){
        cout<< "wow wow!"<<endl;
    }
    int get(){
        return protectednum;
    }

    ~dog(){
        // std::cout<<"dog_dede"<<protectednum<<std::endl;
    }
};

class cat : public an_base {
public:
    void speak() override {
        cout<< "miao miao!"<<endl;
    }
};


int main(){
    // an_base* animal;
    // dog1 = animal<dog>();
    // dog d;
    // cat c;
    // d.speak();
    // c.speak();
    // animal = &d;
    // animal->speak();
    // animal = &c;
    // animal->speak();
    //訪問構造順序
    dog d(1,2);
    d.baseFunc();
    d.speak();
    std::cout<<"-----------"<<std::endl;
    d.speak_base();
    std::cout<<"-----------"<<std::endl;
    an_base* snoopy = new dog(1,3);
    snoopy->speak();



    return 0;
}