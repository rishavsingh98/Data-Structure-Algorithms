/*
Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 
Example 1:
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).

Example 2:
Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already 
sorted so there is no inversion count.
*/
class Solution{
  public:
    
    long long Merge(long long arr[], long long temp[], long long start, long long mid, long long end)
    {
        long long left = start, right = mid, inv = 0, index = start;
        while((left <= mid - 1 ) and (right <= end))
        {
            if(arr[left] <= arr[right])
                temp[index++] = arr[left++];
            else
            {
                temp[index++] = arr[right++];
                inv += (mid - left);
            }
        }
        
        while(right <= end)
            temp[index++] = arr[right++];
        
        while(left <= mid - 1)
            temp[index++] = arr[left++];
            
        for(int i = start; i <= end; i++)
            arr[i] = temp[i];
        
        return inv;
    }
    long long int invCountMrgsort(long long arr[], long long temp[],long long start, long long end)
    {
        long long inv = 0;
        if(start < end)
        {
            long long mid = (start + end) / 2;
            inv += invCountMrgsort(arr, temp, start, mid);
            inv += invCountMrgsort(arr, temp, mid + 1, end);
            inv += Merge(arr, temp, start, mid + 1, end);
        }
        return inv;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        return invCountMrgsort(arr, temp, 0, N-1);
    }

};
