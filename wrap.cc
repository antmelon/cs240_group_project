// Implementation of Gift wrapping through c++
#include <iostream>
#include <set>
using namespace std;

#define iPair pair<int, int>


int isClockwise(iPair p, iPair q, iPair r){
     int val = (q.second - p.second) * (r.first - q.first) - 
              (q.first - p.first) * (r.second - q.second); 
  
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2;
}
//p = leftmost point (cords can just be whatever point is the most negative x)
//prime = p
//find a point q that seems like it should be the next coordinate point
// create algorithm to determine when p and q are counter clockwise from the rest of the data points
//repeat this process until you return to prime


//just setting this up for future refernce, will add more to it in the future