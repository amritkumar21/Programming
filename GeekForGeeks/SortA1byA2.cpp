vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        vector<int> res;
        map <int, int> m;
        
        for(int i=0;i<N;i++)
           m[A1[i]]++;
           
        for(int i=0;i<M;i++)
        {
            if(m.find(A2[i])!=m.end())
            {
                while(m[A2[i]]!=0)
                {
                   res.push_back(A2[i]);
                   m[A2[i]]--;
                }
                m.erase(A2[i]);
                
                
            }
        }
        
        for(auto i = m.begin();i!=m.end();i++)
        {
            while(i->second)
            {
                res.push_back(i->first);
                i->second--;
            }
        }
        
        return res;
    } 