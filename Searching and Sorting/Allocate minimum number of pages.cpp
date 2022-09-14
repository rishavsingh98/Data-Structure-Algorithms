/*
You are given N number of books. Every ith book has Ai number of pages. The books are arranged in ascending order.
You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other permutations and print this minimum value.
Each book will be allocated to exactly one student. Each student has to be allocated at least one book.
Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Example 1:
Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in 
following ways:{12} and {34, 67, 90} 
Maximum Pages = 191{12, 34} and {67, 90} 
Maximum Pages = 157{12, 34, 67} and {90} 
Maximum Pages =113. Therefore, the minimum 
of these cases is 113, which is selected 
as the output.
*/
class Solution 
{
    public:
    bool checkAllocation(int A[], int N, int page_range, int max_students)
    {
        int allocated = 1, pages = 0;
        for(int i = 0; i < N; i++)
        {
            if(A[i] > page_range)
                return false;
            if(pages + A[i] > page_range)
            {
                allocated++;
                pages = A[i];
            }
            else
                pages += A[i];
        
            if(allocated > max_students)
                return false;
        }
        return true;
        
    }
    int findPages(int A[], int N, int M) 
    {
        int mid, res = -1, low = INT_MAX, high = 0, mx = INT_MIN;
        for(int i = 0; i<N; i++)
        {
            high += A[i];
            low = min(low, A[i]);
            mx = max(mx, A[i]);
        }
        if(N==M)
            return mx;
        else if(M > N)
            return -1;
            
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(checkAllocation(A, N, mid, M))
            {
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
    
    return res;
    }
};
