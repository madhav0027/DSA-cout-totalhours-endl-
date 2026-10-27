/*
Problem Statement

Koko loves to eat bananas. There are n piles of bananas, 
the i-th pile has piles[i] bananas. 
The guards have gone and will come back in h hours.


Koko can decide her bananas-per-hour eating speed of k. 
Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.   
Return the minimum integer k such that she can eat all the bananas within h hours.
Example:
    Input: 
        piles = [3, 6, 7, 11], 
        h = 8O
    Output: 4
*/

#include <iostream>
#include <vector>
#include <algorithm>

/*
speed = k
hours = 8
[3,6,7,11]
12 /2 = 6 
k = 6

*/

using namespace std;

int findmink (vector<int>& a,int h){
    
        int low = 1;
        int high = *max_element(a.begin(),a.end());

        cout << high << endl;

        while(low < high){
            long long totalhours = 0;
            int mid = (high+low)/2;

            for(int pile:a){
                totalhours += (pile+mid -1) / mid;
            }
            
            cout << totalhours << endl;
            

            if(totalhours <= h)
                high = mid;
            else
                low = mid + 1;
            
        }
        return low;
}

int main()
{

    vector<int> piles = {3,6,7,11};
    int hour = 8;
    cout << "Result " << findmink(piles,hour);


    return 0;
}