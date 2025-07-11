//There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
//You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
//For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
//Return true if you can finish all courses. Otherwise, return false.
//Example 1:
//Input: numCourses = 2, prerequisites = [[1,0]]
//Output: true
//Explanation: There are a total of 2 courses to take. 
//To take course 1 you should have finished course 0. So it is possible.

bool canFinish(int numCourses,vector<vector<int>> &prerequisite)
{
    vector<vector<int>> graph(numCourses);
     vector<int> inDegree(numCourses,0);

for(auto& pre:prerequiste){
   int a=pre[0];
  int b=pre[1];
   graph[b].push_back(a);
   inDegree[a]++;
}

queue<int> q;

for(int i=0;i<numCourses;i++)
{
   if(inDegree[i]==0) q.push(i);
}

int visited=0;

while(!q.empty())
{
    visited++;
   int course=q.front(); q.pop();

for(auto neighbour:graph[course])
{
   inDegree[neighbour]--;
if(inDegree[neighbour]==0) q.push(neighbour);
}
}
return visited==numCourses;
}
