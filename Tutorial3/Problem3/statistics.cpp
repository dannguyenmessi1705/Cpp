#include <cmath>
float mean(float a){
    return a;
}
float mean(float a, float b){
    return (a+b)/2;
}
float mean(float a, float b, float c){
    return (a+b+c)/3;
}
float mean(float a, float b, float c, float d){
    return (a+b+c+d)/4;
}
float variance(float a){
    return (pow(a-a,2))/1;
}
float variance(float a, float b){
    return (pow(a-mean(a,b),2) + pow(b-mean(a,b),2))/2;
}
float variance(float a, float b, float c){
    return (pow(a-mean(a,b,c),2) + pow(b-mean(a,b,c),2) + pow(c-mean(a,b,c),2))/3;
}
float variance(float a, float b, float c, float d){
    return (pow(a-mean(a,b,c,d),2) + pow(b-mean(a,b,c,d),2) + pow(c-mean(a,b,c,d),2) + pow(d-mean(a,b,c,d),2))/4;
}