#include <iostream>
#include <chrono>

#define Coords std::pair<int, int>

int main(int argc, char * argv[]){
   Coords coordinates[1000] = {};
   //pass random coordinates to array
   //
   //Initiialize Quickhull and Giftwrapping

   //QuickHull qh;
   //GiftWrap gw;
   for(int i = 0; i < 1000; i++){
       Coords newCoord;
       newCoord.first = rand() % 100;
       newCoord.second = rand() % 100;
       coordinates[i] = newCoord;
   }

   for(int i = 0; i < sizeof(coordinates)/sizeof(coordinates[0]); i++){
       std::cout << "(" << coordinates[i].first << "," << coordinates[i].second << "), ";
   }
   Coords test;
   test.first = 1;
   test.second = 2;
   std::cout << test.first << "," << test.second << std::endl;
   //Print out hull coordinates/time for quickhull
   //size = sizeof(coordinates)/sizeof(coordinates[0])
   //printHull(coordinates, size)
   std::cout << "------Beginning QuickHull------" << std::endl;
   auto t1 = std::chrono::high_resolution_clock::now();
   //qh.printHull(coordinates);
   auto t2 = std::chrono::high_resolution_clock::now();

   auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();

   std::cout << "------QuickHull Complete In " << duration << " milliseconds------" << std::endl;
   //Print out hull coordinates/time for giftwrapping

   std::cout << "------Beginning Gift Wrapping------" << std::endl;
   auto t3 = std::chrono::high_resolution_clock::now();
   //gw.printHull(coordinates);
   auto t4 = std::chrono::high_resolution_clock::now();

   auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>( t4 - t3 ).count();

   std::cout << "------Gift Wrapping Complete In " << duration2 << " milliseconds------" << std::endl;

   return 0;
}
