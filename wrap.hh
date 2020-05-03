#include <iostream>
#include <fstream>
#include <set>
#include <vector>

#ifndef WRAP
#define WRAP
class GiftWrap{
    // Stores the result (points of convex hull)
    // iPair is integer pairs
    #define iPair std::pair<int, int>
    std::set<iPair> hull;
public:
    int counter = 0;



    int orientation(iPair p, iPair q, iPair r) 
{ 
    int val = (q.second - p.second) * (r.first - q.first) - 
              (q.first - p.first) * (r.second - q.second); 
  
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
// Prints convex hull of a set of n iPairs. 
void convexHull(iPair points[], int n) 
{ 
    // There must be at least 3 points 
    if (n < 3) return; 
  
    // Initialize Result 
    std::vector<iPair> hull; 
  
    // Find the leftmost point 
    int l = 0; 
    for (int i = 1; i < n; i++) 
        if (points[i].first < points[l].first) 
            l = i; 
  
    // Start from leftmost point, keep moving counterclockwise 
    // until reach the start point again.  This loop runs O(h) 
    // times where h is number of points in result or output. 
    int p = l, q; 
    do
    { 
        // Add current point to result 
        hull.push_back(points[p]); 
  
        // Search for a point 'q' such that orientation(p, x, 
        // q) is counterclockwise for all points 'x'. The idea 
        // is to keep track of last visited most counterclock- 
        // wise point in q. If any point 'i' is more counterclock- 
        // wise than q, then update q. 
        q = (p+1)%n; 
        for (int i = 0; i < n; i++) 
        { 
           // If i is more counterclockwise than current q, then 
           // update q 
           if (orientation(points[p], points[i], points[q]) == 2){  
               q = i; 
               counter++; }
        } 
  
        // Now q is the most counterclockwise with respect to p 
        // Set p as q for next iteration, so that q is added to 
        // result 'hull' 
        p = q; 
  
    } while (p != l);  // While we don't come to first point 
        std::cout << "Giftwrapping Points in output2.txt:\n";
        std::cout << "There are " << counter << " points in Giftwrapping" << std::endl;
        std::ofstream myfile;
        myfile.open("output2.txt");
    for (int i = 0; i < hull.size(); i++) 
            myfile << "(" << hull[i].first << ", "
              << hull[i].second << ")\n"; 
    } 
 };
#endif