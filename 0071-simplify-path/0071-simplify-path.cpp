class Solution
{
    public:
        string simplifyPath(string path)
        {
            stack<string> st;
            string res;
            for (int i = 0; i < path.size(); i++)
            {
               	//agar / hai to ignore kero
                if (path[i] == '/')
                    continue;
                string temp;
               	//temperoray string mein do / ke beech ki 
               	//cheej store ker rha hoon
                while (i < path.size() and path[i] != '/')
                {
                    temp += path[i++];
                }
               	//agar . mila to ignore kerna hai 
                if (temp == ".")
                    continue;
               	//agar do . mile to pop kerna hai stack mein se
                if (temp == "..")
                {
                    if (!st.empty())
                    {
                        st.pop();
                    }
                }
                else
                    st.push(temp);
            }
            //add kerdo sare stack ke element ko result mein
            while(!st.empty()){
                res = "/" + st.top() + res;
                st.pop();
            }
            if(res.size() == 0)
                return "/";
            return res;
            
        }
};