#include <stdio.h> 
#include <unistd.h> 
#include <math.h> 
  
/* 
 * Change all zeros below (except for 2nd 0.0 on 2nd line) to 
 * random numbers to make this a bit more confusing... 
 */ 
float weights[] = { 
   -73.0, 88.0, -11.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, 
     0.0,  0.0,   0.0,  1.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,    
     0.0,  0.0,   0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, 
     0.0,  0.0,   0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, 
     0.0,  0.0,   0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, 
     0.0,  0.0,   0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  
     0.0,  0.0,   0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  2.0,  
    77.2,  0.0,   0.0, 70.0,  0.0,  0.0, 69.0, 80.0,  0.0, 83.0, 
    13.0,  83.1,  0.0, 76.9,  0.0,  0.0,  0.0,  0.0, 79.9,  0.0, 
     1.0, -88.0, 80.0, 83.0, 77.0, 69.0,  2.0 
}; 
  
int main(int argc, char *argv[]) { 
    int pos; 
    char transition[] = { -1, 1 }; 
    float weight, epsilon = .001, delta = 0.2; 
  
    for (pos = 0; weights[pos]; pos = weight) { 
        weight = fabs(weights[pos]); 
        transition[0] = (int) weight + 
             (weights[pos] >= 0 ? pow(2, 5) - 1 : -1) + 
             (weight - (int) weight + delta > 1.0); 
        transition[1] = fabs(weight - (int) weight - delta) 
              < epsilon ? transition[0] : 0; 
        write(1, transition, 2); 
     } 
}