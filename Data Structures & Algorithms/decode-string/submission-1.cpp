class Solution {
public:
    string decodeString(string s) {
        stack<int>countStack;
        stack<string>strStack;

        string curr="";
        int num=0;

        for(char c:s) {
            if(isdigit(c)) {
                num=num * 10 + (c - '0');
            }
            else if (c == '[') {
                countStack.push(num);
                strStack.push(curr);

                num = 0;
                curr = "";
            }
            else if (c == ']') {

                int k = countStack.top();
                countStack.pop();

                string temp = curr;

                while (--k)
                    curr += temp;

                curr = strStack.top() + curr;
                strStack.pop();
            }
            else {
                curr += c;
            }
        }

        return curr;
    }
};