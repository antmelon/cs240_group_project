# CS240 Group Project

### Group Members
- Anthony Longo: Joint Implementation, Testing, Analyzation
- Tyler Katz: Quickhull Implementation
- Stephen Black: Gift Wrapping Inplementation

## Requirements
Two convex hull algorithms will be implemented to determine the ideal implementation of an animal habitat tracking program. Points will randomly be generated in order to simulate geolocations of an animal tracker.
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
## Algorithms

### Gift Wrapping
This algorithm works by essentially forming a fixed perimeter around the set of points by marking one point at a time as the “most clockwise” point. That is the point which is clockwise relative to all the other points and as such a suitable candidate for the next part of the perimeter. The weakness of this algorithm comes from how that point is selected, once the system approximates a point it runs a calculation for all other points surrounding it to ensure it is in fact the most clockwise point. This dramatically increases the time complexity compared to the quickhull because it requires a loop initialized for each instance of a point which will on average cover the same area as any other point. This means the total number of points to form this perimeter will also be far higher than quick hull.

### Convex Hull
This algorithm works on the principle of recursive shape tracing, or approximating the total area required to cover all points until that approximation covers all points in the set presented. It begins by dividing the points into two subsets (represented by a line) and then using the farthest point as a basis for its first shape. After which it repeats this process recursively until all points are covered within the scope of the new shape. This process is markedly more efficient than gift wrapping because of its use of approximation, by dividing the points into two subsections, its first process will cover a massive swath of all points in the set. After which point each recursive call will cover less and less total points until the shape has been completed. As an analogy think of a program which computes 100 through smaller numbers. Gift wrapping does this by adding 1 100 times, Quick hull adds 50, then 25, then 15 and then 10. The decreasing efficiency makes the system more efficient in the aggregate because of how many points were skipped by the first step. 


## Documentation and Analysis
