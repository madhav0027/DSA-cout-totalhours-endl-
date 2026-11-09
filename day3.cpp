#include <iostream>
#include <queue>
#include <vector>

class MedianFinder {
private:
    std::priority_queue<int> small; 
    std::priority_queue<int, std::vector<int>, std::greater<int>> large; 

public:
    MedianFinder() {}
    
    void addNum(int num) {
        small.push(num);
        
        large.push(small.top());
        small.pop();
        
        if (small.size() < large.size()) {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if (small.size() > large.size()) {
            return small.top();
        }
        return (double)(small.top() + large.top()) / 2.0;
    }
};

int main() {
    std::cout << "=== Test Case 1: [1, 2, 3] ===" << std::endl;
    MedianFinder mf1;
    
    mf1.addNum(1);
    std::cout << "Added 1 -> Median: " << mf1.findMedian() << std::endl; // Expected: 1.0

    mf1.addNum(2);
    std::cout << "Added 2 -> Median: " << mf1.findMedian() << std::endl; // Expected: 1.5

    mf1.addNum(3);
    std::cout << "Added 3 -> Median: " << mf1.findMedian() << std::endl; // Expected: 2.0

    std::cout << "\n=== Test Case 2: Unordered Stream [5, 15, 1, 3] ===" << std::endl;
    MedianFinder mf2;
    std::vector<int> stream = {5, 15, 1, 3};
    
    for (int num : stream) {
        mf2.addNum(num);
        std::cout << "Added " << num << " -> Current Median: " << mf2.findMedian() << std::endl;
    }

    return 0;
}
