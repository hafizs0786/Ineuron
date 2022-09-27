#include<math.h>
#define PI 3.14159
#define R 6371 //Radius of earth in kms

double toRadian(double angle)
{ return angle*(PI/180); }

double find_angle(double a1, double b1, double a2, double b2)
{
    //m = -a/b, m is slope of line
    double m1=-a1/b1; //Slope of first line
    double m2=-a2/b2; //Slope of second line
    
    //Formula to find angle of intersection between two lines
    double angle = atan((m2-m1)/(1+m2*m1));
    // To Convert from Radian to Degree, because atan() returns value in radians
    angle = angle*(180/PI);

    if(angle<0) // to convert in positive in case of negative angle
        angle = -angle;

    return angle;
}

double find_distance(double lat1, double lon1, double lat2, double lon2)
{
    double a,c,d;
    // Converting to Radians because trigonometric func.(Ex: sin()) accept values in radians
    lat1 = toRadian(lat1), lat2 = toRadian(lat2);
    lon1 = toRadian(lon1), lon2 = toRadian(lon2);
    double lat = lat2-lat1; //Latitude difference of two coordinates
    double lon = lon2-lon1; //Longitude difference of two coordinates

    // Haversine formula to calculate distance
    a = pow(sin(lat/2),2) + cos(lat1) * cos(lat2) * pow(sin(lon/2),2);
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    d = R * c;    
            
    return d;
}

double find_area(double x1,double y1,double x2,double y2,double x3,double y3)
{
    x2 = x2-x1;
    y2 = y2-y1;
    x3 = x3-x1;
    y3 = y3-y1;

    double area = ((x2*y3) - (x3*y2))/2; //to get area

    if(area<0) // to convert in positive in case of negative value
        area = -area;

    return area;
}