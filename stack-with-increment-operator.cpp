#include <iostream>
#include <vector>
using namespace std;

class CustomStack {
private:
    vector<int> stack;    
    vector<int> inc;       
    int maxSize;

public:
    
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        stack.reserve(maxSize);
        inc.assign(maxSize, 0);
    }

    
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }

    
    int pop() {
        int n = stack.size();
        if (n == 0) return -1;

        int i = n - 1;
        int res = stack[i] + inc[i];

        if (i > 0)
            inc[i - 1] += inc[i];  

        inc[i] = 0;
        stack.pop_back();
        return res;
    }

    
    void inc(int k, int val) {
        int n = stack.size();
        if (n == 0) return;

        int limit = min(k, n);
        inc[limit - 1] += val;  
    }
};

int main() {
    CustomStack st(5);
    st.push(5);
    st.push(2);
    cout << st.pop() << endl;   
    st.push(3);
    st.push(7);
    st.inc(2, 1);               
    cout << st.pop() << endl;   
    cout << st.pop() << endl;   
    cout << st.pop() << endl;   
    return 0;
}