#include <iostream>
#include <vector>

using namespace std;

vector<int> findval(vector<int>& a){
    
   long long xorAll = 0;
        for (int num : a) {
            xorAll ^= num;
        }

        long long diffBit = xorAll & (-xorAll);

        int num1 = 0, num2 = 0;
        for (int num : a) {
            if (num & diffBit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }

        return {num1, num2};
}

int main()
{

    vector<int> nums = {1, 2, 1, 3, 2, 5};
    cout << endl;
    for(auto& x :findval(nums))
        cout << x;

    return 0;
}
