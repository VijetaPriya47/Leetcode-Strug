class Solution {
public:
    bool parseBoolExpr(string exp) {

        int N=exp.size();
        stack<char>st;
        for(int i=0;i<N;i++){
            if(exp[i]==',' || exp[i]=='('){
                continue;
            }
            if(exp[i]==')'){
                    bool hastrue=false;
                    bool hasfalse=false;
                while(st.top()=='f' || st.top()=='t'){
                    char s=st.top();
                    st.pop();
                    if(s=='f')hasfalse=true;
                    else if(s=='t')hastrue=true;
                }

                char op = st.top();
                st.pop();
                if (op == '!') {
                    st.push(hastrue ? 'f' : 't');
                } else if (op == '&') {
                    st.push(hasfalse ? 'f' : 't');
                } else {
                    st.push(hastrue ? 't' : 'f');
                }
            }
            else{
                st.push(exp[i]);
            }

        }

        return st.top()=='t';
    }
};