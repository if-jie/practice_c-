/*
 * @Author: 1454164915@qq.com 1454164915@qq.com
 * @Date: 2024-11-01 19:09:17
 * @LastEditors: 1454164915@qq.com 1454164915@qq.com
 * @LastEditTime: 2024-11-01 21:35:41
 * @FilePath: /learn/C++/linearTransformation.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AEaaa
 */
#include "Point.h"
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

typedef Point<double> P;

// kdtree
typedef long long T;
typedef Point<T> P1;

const T INF = numeric_limits<T>::max();

bool on_x(const P& a, const P& b){return a.x < b.x;}
bool on_y(const P& a, const P& b){return a.y < b.y;}

struct  Node
{
    /* data */
    P pt;
    T x0 = INF, x1 = -INF, y0 = INF, y1 = -INF;//边界
    Node *first = 0, *second = 0;

    T dis(const P& p){
        T x = (p.x < x0 ? x0 : p.x > x1 ? x1 : p.x);
        T y = (p.y < y0 ? y0 : p.y > y1 ? y1 : p.y);
        return (P(x,y)-p).dist2();
    }

    Node(vector<P>&& vp): pt(vp[0]){
        for(P p : vp){
            x0 = min(x0, p.x); x1 = max(x1, p.x);
            y0 = min(y0, p.y); y1 = max(y1, p.y);
        }
        if(vp.size() > 1){
            sort(all(vp), x1 - x0 >= y1 - y0 ? on_x : on_y);

            int half = sz(vp)/2;
            first = new Node({vp.begin(),vp.end()+half});
            second = new Node({vp.begin()+half,vp.end()});
        }
    }

};

struct kdtree
{
    /* data */
    Node* root;
    kdtree(const vector<P>& vp):root(new Node({all(vp)})){}

    pair<T,P> search(Node* node, const P& p){
        if(!node->first){
            return make_pair((p-node->pt).dist2(),node->pt);
        }
    Node *f = node->first, *s = node->second;
    T bfirst = f->dis(p),bsec = s->dis(p);
    if(bfirst > bsec)swap(bsec,bfirst),swap(f,s);
    // search nearest side first,other side if needed\
    
    auto best = search(f, p);
    if(bsec<best.first)
    best = min(best, search(s,p));
    return best;
    }

    // find nearest point to a point and its squared distance

    pair<T,P> nearest(const P& p){
        return search(root,p);
    }

};

