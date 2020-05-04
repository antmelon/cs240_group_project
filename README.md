# CS240 Group Project

### Group Members
- Anthony Longo: Joint Implementation, Testing, Analyzation
- Tyler Katz: Quickhull Implementation
- Stephen Black: Gift Wrapping Inplementation

## Requirements
Two convex hull algorithms will be implemented to determine the ideal implementation of an animal habitat tracking program. Points will randomly be generated in order to simulate geolocations of an animal tracker. We initially wanted to test floating points to more accurately simulate latitude and longitude coordinates, but due to time restraints, we settled to test points with integers.
```cpp
srand (time(NULL));
for(long int i = 0; i < numCords; i++){
    Coords newCoord;
    newCoord.first = rand() % 1000;
    newCoord.second = rand() % 1000;
    coordinates[i] = newCoord;
}
```
Mock points will be sent to both algorithms to test the time efficiency using various data sizes.

We tested the efficiency of the algorithms using the std::chrono library to see how long each algorithm took with various dataset sizes (1000, 10000, 100000). After the final implementation, the Gift Wrapping algorithm did have an error in which it continues to add (0,0) several times to the hull. However, upon removing the extra points from the output, the hulls contained the correct points and did result in the expected time complexities.

With more time, we would have liked to implement floating point coordinates, use different variable types to simulate more frequent gathering of coordinates, and fix the gift wrapping algorithm in order to fix the issues.

## Algorithms

Both algorithms were adapted from the convex hull algorithms from geeksforgeeks.org

### Gift Wrapping
This algorithm works by essentially forming a fixed perimeter around the set of points by marking one point at a time as the “most clockwise” point. That is the point which is clockwise relative to all the other points and as such a suitable candidate for the next part of the perimeter. The weakness of this algorithm comes from how that point is selected, once the system approximates a point it runs a calculation for all other points surrounding it to ensure it is in fact the most clockwise point. This dramatically increases the time complexity compared to the quickhull because it requires a loop initialized for each instance of a point which will on average cover the same area as any other point. This means the total number of points to form this perimeter will also be far higher than quick hull.

### QuickHull
This algorithm works on the principle of recursive shape tracing, or approximating the total area required to cover all points until that approximation covers all points in the set presented. It begins by dividing the points into two subsets (represented by a line) and then using the farthest point as a basis for its first shape. After which it repeats this process recursively until all points are covered within the scope of the new shape. This process is markedly more efficient than gift wrapping because of its use of approximation, by dividing the points into two subsections, its first process will cover a massive swath of all points in the set. After which point each recursive call will cover less and less total points until the shape has been completed. As an analogy think of a program which computes 100 through smaller numbers. Gift wrapping does this by adding 1 100 times, Quick hull adds 50, then 25, then 15 and then 10. The decreasing efficiency makes the system more efficient in the aggregate because of how many points were skipped by the first step.

The division formation of triangles and distance checking to create the hull is performed by the following

```cpp
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
```


## Documentation and Analysis

### Gift wrapping
| 1000 points | Best case (μs) | Worst case (μs) | Average case  (μs) | Lowest number of points | Highest number of points | Average number of points |
|-------------|----------------|-----------------|--------------------|-------------------------|--------------------------|--------------------------|
| Anthony |  |  |  |  |  |  |
| Tyler |  |  |  |  |  |  |
| Stephen |  |  |  |  |  |  |
| Average |  |  |  |  |  |  |


| 10000 points | Best case (μs) | Worst case (μs) | Average case  (μs) | Lowest number of points | Highest number of points | Average number of points |
|-------------|----------------|-----------------|--------------------|-------------------------|--------------------------|--------------------------|
| Anthony |  |  |  |  |  |  |
| Tyler |  |  |  |  |  |  |
| Stephen |  |  |  |  |  |  |
| Average |  |  |  |  |  |  |

| 10000000 points | Best case (μs) | Worst case (μs) | Average case  (μs) | Lowest number of points | Highest number of points | Average number of points |
|-------------|----------------|-----------------|--------------------|-------------------------|--------------------------|--------------------------|
| Anthony |  |  |  |  |  |  |
| Tyler |  |  |  |  |  |  |
| Stephen |  |  |  |  |  |  |
| Average |  |  |  |  |  |  |

Gift Wrapping has a time complexity of O(nh), where n is the number of points in the data set and h is the number of points in the final hull. This is because of the lookup of each point having the worst case time of O(n).

---
### QuickHull

| 1000 points | Best case (μs) | Worst case (μs) | Average case  (μs) | Lowest number of points | Highest number of points | Average number of points |
|-------------|----------------|-----------------|--------------------|-------------------------|--------------------------|--------------------------|
| Anthony | 999 | 4762 | 1875 | 12 | 24 | 18 |
| Tyler |  |  |  |  |  |  |
| Stephen |  |  |  |  |  |  |
| Average |  |  |  |  |  |  |


| 10000 points | Best case (μs) | Worst case (μs) | Average case  (μs) | Lowest number of points | Highest number of points | Average number of points |
|-------------|----------------|-----------------|--------------------|-------------------------|--------------------------|--------------------------|
| Anthony | 3801 | 11543 | 7818 | 12 | 24 | 17 |
| Tyler |  |  |  |  |  |  |
| Stephen |  |  |  |  |  |  |
| Average |  |  |  |  |  |  |

| 10000000 points | Best case (μs) | Worst case (μs) | Average case  (μs) | Lowest number of points | Highest number of points | Average number of points |
|-------------|----------------|-----------------|--------------------|-------------------------|--------------------------|--------------------------|
| Anthony | 198149 | 271049 | 231321 | 7 | 9 | 8 |
| Tyler |  |  |  |  |  |  |
| Stephen |  |  |  |  |  |  |
| Average |  |  |  |  |  |  |

The worst case time complexity for QuickHull is O(nlog(r)) where n is the number of coordinates and r is the number of processed points. There is no way to easily calculate the average case for this algorithm though. This is remarkably more efficient when there are a larger number of points in the final hull when compared to Gift Wrapping.

### Conclusions

We concluded that for the application that the algorithm would be implemented in, QuickHull would be a more efficient method of calculating animal habitats. If the points were collected frequently and in large volumes, the chances of having a larger number of points in the hull would also increase, resulting in Gift Wrapping being too inefficient for quick analysis of the coordinates.

Due to some errors in the implementation in the driver as well as the Gift Wrapping algorithm, we were unable to test with the same random coordinates for both algorithms which may have resulted in some errors in the numbers for Gift Wrapping. However, in standalone testing of the algorithm, the numbers did line up with the O(nh) time complexity of the algorithm. Because of this we still believe that for this type of application, QuickHull is the most efficient algorithm for determining the habitat of animals based off of location coordinates.
