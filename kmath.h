#ifndef KMATH_H
#define KMATH_H

#include <errno.h>
#include <math.h>

static const double cordic_angles[] = {
    0.7853981633974483,    
    0.4636476090008061,    
    0.24497866312686414,   
    0.12435499454676144,   
    0.06241880999595735,   
    0.031239833430268277,  
    0.015623728620476831,  
    0.007812341060101111,  
    0.0039062301319669718, 
    0.0019531225164788188, 
    0.0009765621895593195, 
    0.0004882812111948983, 
    0.00024414062014936177, 
    0.00012207031189367021, 
    0.00006103515617420877  
};

#define CORDIC_K 0.6072529350088812561694
#define CORDIC_ITERATIONS 15
#define max(A, B) ((A) > (B) ? (A) : (B))

/* trigonometric function */
/* Calculating angles for object rotation, aiming, and movement along curves */
static void caluclate_cordic(double angle, double *cos, double* sin); 
double ksin(double angle); 
double kcos(double angle); 
double ktan(double angle); 

/* Defining position, velocity, direction, and forces in 2D/3D space */
double ksqrt(double x); 
double kfabs(double x);
double khypot(double x, double y); 


#endif 
