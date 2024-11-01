/*
 * @Author: 1454164915@qq.com 1454164915@qq.com
 * @Date: 2024-11-01 09:42:18
 * @LastEditors: 1454164915@qq.com 1454164915@qq.com
 * @LastEditTime: 2024-11-01 09:51:34
 * @FilePath: /learn/C++/lineIntersection.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
template<class P>
int lineIntersection(const P& s1,const P& e1, const P& s2, const P& e2, P& r){
    if((e1-s1).cross(e2-s2)){
        // 判断是否平行
        r = s2-(e2-s2)*(e1-s1).cross(s2-s1)/(e1-s1).cross(e2-s2);
        return 1;
    }else{
        return -((e1-s1).cross(s2-s1) == 0 || s2==e2);
    }
}