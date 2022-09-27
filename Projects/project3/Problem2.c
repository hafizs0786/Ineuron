#include<stdio.h>
#include"library.h"
#include"library.c"

int main()
{
    double distance;

    double lat1 = 23.259933, lon1 = 77.412613;
    double lat2 = 12.9716, lon2 = 77.5946;

    distance = find_distance(lat1,lon1,lat2,lon2);

    printf("Distance between Saurabh Sir and Prateek Sir: %.2f Kms.",distance);
    
    return 0;
}