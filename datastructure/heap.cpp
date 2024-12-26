/*
 * @Author: 1454164915@qq.com 1454164915@qq.com
 * @Date: 2024-11-05 15:04:11
 * @LastEditors: 1454164915@qq.com 1454164915@qq.com
 * @LastEditTime: 2024-12-20 09:50:30
 * @FilePath: /learn/C++/datastructure/heap.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

// heap conducted in STL
#include <queue>
using namespace std;

class MaxHeap {
    private:
        vector<int> store;
        //1 2 2 3 3 3 3
        //1 2 3 4 5 6 7 8
        //1 1 1 2 2 3 3 4
        //tree structure
        int parent(int i){return (int)(i-1)/2;}
        int left(int i){return 2*i +1;}
        int right(int i){return 2*i + 2;}

        void heapd(){
            int n = store.size();

            
        }

    public:
        void push(){

        }

        void pop(){

        }

        int top(){
            return store[0];
        }



}



int main(){

    priority_queue<int> q;// big heap
    priority_queue<int,vector<int>,greater<int>> p;// small heap

    vector<int> input = {1, 3, 2};
    priority_queue<int> pq(input.begin(), input.end());

    // q.top();
    // q.pop();
    // q.push();//int enter
    // q.empty();//heap if empty()
    // q.size();//elemnt num


    return 0;
}