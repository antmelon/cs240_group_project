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

### Convex Hull


## Documentation and Analysis
