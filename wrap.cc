// Implementation of Gift wrapping through c++
#include <iostream>
#include <set>
using namespace std;

#define iPair pair<int, int>

// Do following while we don’t come back to the first (or leftmost) point.
// The next point q is the point such that the triplet (p, q, r) is counterclockwise for any other point r.
// next[p] = q (Store q as next of p in the output convex hull).
// p = q (Set p as q for next iteration).


//just setting this up for future refernce, will add more to it in the future