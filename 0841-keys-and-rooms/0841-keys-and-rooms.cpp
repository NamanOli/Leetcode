class Solution 
{
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        stack<int> Q({0});
        unordered_set<int> seen;
        while (!Q.empty())
        {
            int r = Q.top(); Q.pop();
            seen.insert(r);
            for (int k : rooms[r])
                if (!seen.count(k))
                    Q.push(k);
        }
        
        return seen.size() == rooms.size();
    }
};