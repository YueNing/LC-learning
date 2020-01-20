#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <list> 
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int> > edges(numCourses, list<int>());
        vector<int> indegrees(numCourses, 0);
        for(const auto &v:prerequisites){
            edges[v[1]].push_back(v[0]);
            ++indegrees[v[0]];
        }
        queue<int> courses;
        for(int i=0; i<numCourses; ++i)
            if(indegrees[i]==0) courses.push(i);
        for(; !courses.empty(); --numCourses, courses.pop())
            for(const auto &node:edges[courses.front()])
                if(--indegrees[node]==0) courses.push(node);
        return numCourses==0;
    }
};

int main(){
    int numCourses = 2;
    vector<vector<int>> prerequisites={{1,0},{0,1}};
    Solution t;
    auto result = t.canFinish(numCourses, prerequisites);
    cout<< result <<endl;
}