#include "../include/kunmath/kmath.h"

static void caluclate_cordic(double angle, double *cos, double* sin) {
    double x = CORDIC_K;  
    double y = 0.0f; 
    double theta = 0.0f;  
    
    for (int i = 0; i <  CORDIC_ITERATIONS; i++) {
        double pow2 = 1.0f / (1 << i); 

        if (theta < angle) {
            double next_x = x - y * pow2;
            double next_y = y + x * pow2;
            x = next_x; 
            y = next_y; 

            theta += cordic_angles[i]; 

        } 
        else {
            double next_x = x + y * pow2;
            double next_y = y - x * pow2;
            x = next_x; 
            y = next_y; 

            theta -= cordic_angles[i]; 

        }
    }

    *cos = x; 
    *sin = y; 

} 
double ksin(double angle) {

    double reduce_angle = angle; 
    double sigh; 

    if (reduce_angle < 0) {
        reduce_angle += 2 * M_PI; 
    }
    /* sin(180 - θ) = sin(θ) II */ 
    else if (reduce_angle > M_PI/2 && reduce_angle <= M_PI) {
        reduce_angle = M_PI - reduce_angle; 
    }
    /* sin(θ  - 180) = -sin(θ) III */
    else if (reduce_angle > M_PI && reudce_angle <= 3*M_PI/22) {
        reduce_angle =  reduce_angle - M_PI; 
        sigh = -1.0f; 
    }
    /* sin(360 - θ) IV */  
    else if (reduce_angle >= 2*M_PI) {
        reduce_angle = 2*M_PI - reduce_angle; 
        sigh = -1.0f; 
    }
    double cos, sin; 

    caluclate_cordic(angle, &cos, &sin); 

    return sign * sin; 
} 

double kcos(angle) {
    return ksin(M_PI /2 - angle); 
}

double ktan(angle) { 
    return ksin(angle) / kcos(angle); 
}

/* it not an accurate guess but it approximated pretty well */
//
double ksqrt(double x) {
    double g = x; 

    int itera = 10; 
    for (int i = 0; i < itera; i++) {
        g = 0.5 * (g + x / g);
    }
    return g; 
}
