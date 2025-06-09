#include<bits/stdc++.h>
#define maxnum 1000000000

using namespace std;

typedef tuple<int,int,int> tp;

void dijkstra(vector<tp> graph[], long long int* distance, int* shorest_found,int* ans){
    priority_queue<tp,vector<tp>,greater<tp>> heap;
    int top_of_heap,vertex,weight,fiber;
    distance[0]=0;
    heap.push({0,0,0});
    while(!heap.empty()){
        top_of_heap = get<2>(heap.top());
        fiber = get<1>(heap.top());
        // cout << top_of_heap << fiber << endl;
        heap.pop();
        if(shorest_found[top_of_heap]==1)continue;
        else{
            shorest_found[top_of_heap]=1;
            // cout << fiber << endl;
            if(fiber==1){
                (*ans)++;
                // cout << "hi" << endl;
            }

        }
        for(auto it: graph[top_of_heap]){
            vertex = get<0>(it);
            weight = get<1>(it);
            if(distance[top_of_heap]+weight<=distance[vertex]){
                distance[vertex]=distance[top_of_heap]+weight;
                heap.push({distance[vertex],get<2>(it),vertex});
                // cout << distance[vertex] << get<2>(it) << vertex << endl;
            }
        }
    }
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<tp> graph[n+1];
    tp u,v;
    int vertex1,vertex2,weight;
    int normal[n+1];
    for(int i =0;i<m;i++){
        cin >> vertex1 >> vertex2 >> weight;
        vertex1--;
        vertex2--;
        u = {vertex1 , weight , 0};
        v = {vertex2 , weight , 0};
        graph[get<0>(u)].push_back(v);
        graph[get<0>(v)].push_back(u);
    }
    int l[k],p[k];
    for(int i =0;i<k;i++){
        cin >> l[i] >> p[i];
        l[i]--;
        u = {l[i],p[i],1};
        v = {0,p[i],1};
        graph[get<0>(u)].push_back(v);
        graph[get<0>(v)].push_back(u);
    }
    long long int distance[n+1];
    int shortest_found[n+1];
    for(int i =0;i<n+1;i++){
        shortest_found[i]=0;
        distance[i]= maxnum;
    }
    int ans=0;
    dijkstra(graph,distance,shortest_found,&ans);
    // for(int i =0;i<n;i++){
    //     cout << i+1 << ":" << distance[i] << endl;
    // }
    cout << k-ans << endl;
    return 0;
}