// C++ program to implement Quick Hull algorithm
// to find convex hull.
#include <iostream>
#include <fstream>
#include <set>

#ifndef CHULL
#define CHULL

class QuickHull{

    #define iPair std::pair<int, int>
    std::set<iPair> hull;
public:
<<<<<<< HEAD
    int counter = 0;
=======
    long int counter = 0;
    // Returns the side of point p with respect to line
    // joining points p1 and p2.
>>>>>>> bbc962f84fd1290bdd55c4df02f7fe6a2d9f2984
    int findSide(iPair p1, iPair p2, iPair p)
    {
        int val = (p.second - p1.second) * (p2.first - p1.first) -
        (p2.second - p1.second) * (p.first - p1.first);

        if (val > 0){
            return 1;
        }
        if (val < 0){
            return -1;
        }
        return 0;
    }

    int lineDist(iPair p1, iPair p2, iPair p)
    {
        return abs ((p.second - p1.second) * (p2.first - p1.first) -
        (p2.second - p1.second) * (p.first - p1.first));
    }

<<<<<<< HEAD
    void quickHull(iPair a[], int n, iPair p1, iPair p2, int side)
    {
        int ind = -1;
        int max_dist = 0;

        for (int i=0; i<n; i++)
=======
    // End points of line L are p1 and p2.  side can have value
    // 1 or -1 specifying each of the parts made by the line L
    void quickHull(iPair a[], long int n, iPair p1, iPair p2, int side)
    {
        int ind = -1;
        int max_dist = 0;
        // finding the point with maximum distance
        // from L and also on the specified side of L.
        for (long int i=0; i<n; i++)
>>>>>>> bbc962f84fd1290bdd55c4df02f7fe6a2d9f2984
        {
            int temp = lineDist(p1, p2, a[i]);
            if (findSide(p1, p2, a[i]) == side && temp > max_dist)
            {
                ind = i;
                max_dist = temp;
            }
        }

        if (ind == -1)
        {
            hull.insert(p1);
            hull.insert(p2);
            counter += 1;
            return;
        }

        // Recur for the two parts divided by a[ind]
        quickHull(a, n, a[ind], p1, -findSide(a[ind], p1, p2));
        quickHull(a, n, a[ind], p2, -findSide(a[ind], p2, p1));
    }

    void printHull(iPair a[], long int n)
    {
        // a[i].second -> y-coordinate of the ith point
        if (n < 3)
        {
            std::cout << "Convex hull not possible\n";
            return;
        }

<<<<<<< HEAD
        int min_x = 0, max_x = 0;
        for (int i=1; i<n; i++)
=======
        // Finding the point with minimum and
        // maximum x-coordinate
        long int min_x = 0, max_x = 0;
        for (long int i=1; i<n; i++)
>>>>>>> bbc962f84fd1290bdd55c4df02f7fe6a2d9f2984
        {
            if (a[i].first < a[min_x].first)
            min_x = i;
            if (a[i].first > a[max_x].first)
            max_x = i;
        }

        quickHull(a, n, a[min_x], a[max_x], 1);
        quickHull(a, n, a[min_x], a[max_x], -1);

        std::cout << "QuickHull Points in output.txt:\n";
        std::cout << "There are " << counter << " points in QuickHull" << std::endl;
        std::ofstream myfile;
        myfile.open("output.txt");
        while (!hull.empty())
        {

            myfile << "(" <<( *hull.begin()).first << ", "
            << (*hull.begin()).second << ") \n";
            hull.erase(hull.begin());
        }
        myfile.close();
    }
};
#endif
