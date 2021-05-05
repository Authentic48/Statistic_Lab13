using namespace std; 
  
int findCeil(int arr[], int r, int l, int h)  
{  
    int mid;  
    while (l < h)  
    {  
        mid = l + ((h - l) >> 1);
        (r > arr[mid]) ? (l = mid + 1) : (h = mid);  
    }  
    return (arr[l] >= r) ? l : -1;  
}  
  
// The main function that returns a random number 
// from arr[] according to distribution array  
int myRand(int arr[], int freq[], int n)  
{  
    // Create and fill prefix array  
    int prefix[n], i;  
    prefix[0] = freq[0];  
    for (i = 1; i < n; ++i)  
        prefix[i] = prefix[i - 1] + freq[i];  
  
   
    // Generate a random number with  
    // value from 1 to this sum  
    int r = (rand() % prefix[n - 1]) + 1;  
  
    // Find index of ceiling of r in prefix arrat  
    int indexc = findCeil(prefix, r, 0, n - 1);  
    return arr[indexc];  
}  
  
// Driver code  
int main()  
{  
    int arr[] = {1, 2, 3, 4};  
    int freq[] = {10, 5, 20, 100};  
    int i, n = sizeof(arr) / sizeof(arr[0]);  
  
    
    srand(time(NULL));  
  
 
    for (i = 0; i < 5; i++)  
    cout << myRand(arr, freq, n) << endl;  
  
    return 0;  
}