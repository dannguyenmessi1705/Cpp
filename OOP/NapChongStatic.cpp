#include <iostream>
using namespace std;
class ArrayCalculator{
public:
    static int sumOfArray(int arr[], int n){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        return sum;
    } 
    static double sumOfArray(double arr[], int n){
        double sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        return sum;
    } 
    static int maxOfArray(int arr[], int n){
        int max=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]>=max) max=arr[i];
        }
        return max;
    } 
    static double maxOfArray(double arr[], int n){
        double max=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]>=max) max=arr[i];
        }
        return max;
    } 
    static int minOfArray(int arr[], int n){
        int min=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]<=min) min=arr[i];
        }
        return min;
    } 
    static double minOfArray(double arr[], int n){
        double min=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]<=min) min=arr[i];
        }
        return min;
    }
};
int main() {
	int arr1[] = { 3, 4, 2 };
	double arr2[] = { 1.3, 4.2, 6.7 };
	cout << ArrayCalculator::sumOfArray(arr1, sizeof(arr1) / sizeof(int)) << endl;
	cout << ArrayCalculator::sumOfArray(arr2, sizeof(arr2) / sizeof(double)) << endl;
    cout << ArrayCalculator::minOfArray(arr1, sizeof(arr1) / sizeof(int)) << endl;
	cout << ArrayCalculator::minOfArray(arr2, sizeof(arr2) / sizeof(double)) << endl;
	cout << ArrayCalculator::maxOfArray(arr1, sizeof(arr1) / sizeof(int)) << endl;
	cout << ArrayCalculator::maxOfArray(arr2, sizeof(arr2) / sizeof(double)) << endl;
    return 0;
}
