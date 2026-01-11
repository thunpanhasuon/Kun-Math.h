#include "kmath.h"

static void caluclate_cordic(double angle, double *cos, double* sin) {
    double x = CORDIC_K;  
    double y = 0.0f; 
    double theta = 0.0f;  
    
    for (int i = 0; i <  CORDIC_ITERATIONS; i++) {
        /* try using marden cpu feature of mul */
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
    return ksin(angle + M_PI /2 - angle); 
}

double ktan(angle) { 
    double s = ksin(angle); 
    double c = kcos(angle);
    double t = (c == 0) ? 0 : S / C; 
    return t; 
}
double d2rad(double rad) {
    return 180.0f/M_PI * rad; 
}
double rad2d(double dergee) {
    return M_PI/180.0f * dergee; 
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
double kfabs(double x) {
    return x = (x < 0.0) ? -1.0 * x : x; 
}
double khypot(double x, double y) {
    return ksqrt(x*x + y*y); 
} 
bool kcheck_collision(Game_object* object1, Game_object* object2) {
    bool collision_on_x = object1->pos.x + object1->size.x >= object2->pos.x &&
                          object2->pos.x + object2->size.x >= object1->pos.x; 
    bool collision_on_y = object1->pos.y + object1->size.y >= object2->pos.y &&
                          object2->pos.y + object2->size.y >= object1->pos.y; 
    return collision_on_x && collision_on_y; 
}

