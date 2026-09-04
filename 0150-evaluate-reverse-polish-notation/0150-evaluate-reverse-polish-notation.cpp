class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;
        int ans=0;
        int n=tokens.size();
        for(int i=0;i<n;i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/" )
            {
                if(tokens[i]=="+"){
                    
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    int ans= a+b;
                    s.push(ans);

                }
                if(tokens[i]=="-"){
                    
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    int ans= b-a;
                    s.push(ans);

                }
                if(tokens[i]=="*"){
                    
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    int ans= a*b;
                    s.push(ans);

                }
                if(tokens[i]=="/"){
                    
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    int ans= b/a;
                    s.push(ans);

                }
            }
            else
            {
                int a=stoi(tokens[i]);
                s.push(a);
            }
        }

        return s.top();


    }
};