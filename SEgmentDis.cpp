/*
 * @Author: 1454164915@qq.com 1454164915@qq.com
 * @Date: 2024-10-31 21:23:04
 * @LastEditors: 1454164915@qq.com 1454164915@qq.com
 * @LastEditTime: 2024-10-31 22:01:17
 * @FilePath: /learn/C++/SEgmentDis.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <tuple>
// #include <>
#include "Point.h"
using namespace std;

typedef Point<double> P;

double segDist(P& s, P& e, P& p){
    if(s == e)return (p-s).dist();
    auto d = (e-s).dist2();
    auto t = min(d, max(0.0 , (p-s).dot(e-s)));
    return ((p-s)*d-(e-s)*t).dist()/d;
}





int main(){
    Point<double> a(0,2), b(2,2), p(1,1);
    cout<<segDist(a,b,p);
    cout<<endl;



    return 0;
}