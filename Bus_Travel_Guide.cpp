#include<bits/stdc++.h>
using namespace std;
map<string,int>mpp;
map<int,string>Stop_num;
int size;
vector<pair<int,int>> adj_d[100];
vector<pair<int,int>> adj_t[100];
vector<string> stops;

void Add_dist_edge(string a, string b, int  dist) {
    int x=mpp[a];
    int y=mpp[b];
    adj_d[x].push_back({y,dist});
    adj_d[y].push_back({x,dist});
}

void Add_time_edge(string a, string b, int  time) {
    int x=mpp[a];
    int y=mpp[b];
    adj_t[x].push_back({y,time});
    adj_t[y].push_back({x,time});
}

void Print_stops() {
    cout<<"Below are the Area's where Bus services are available"<<endl;
    for (int i=0; i<size; i++) {
        cout<<i+1<<")"<<stops[i]<<endl;
    }
}

int shrotest_dist(int src, int dest) {
    vector<int> dist(size,INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[src]=0;
    pq.push({src,0});
    while (!pq.empty()) {
        auto it=pq.top();
        int node=it.first;
        int dis=it.second;
        pq.pop();
        for (auto x: adj_d[node]) {
            int adjN=x.first;
            int edjw=x.second;
            if (edjw+dis<dist[adjN]) {
                dist[adjN]=edjw+dis;
                pq.push({adjN,edjw+dis});
            }
        }
    }
    return dist[dest];
}

int shrotest_time(int src, int dest) {
    vector<int> dist(size,INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[src]=0;
    pq.push({src,0});
    while (!pq.empty()) {
        auto it=pq.top();
        int node=it.first;
        int dis=it.second;
        pq.pop();
        for (auto x: adj_t[node]) {
            int adjN=x.first;
            int edjw=x.second;
            if (edjw+dis<dist[adjN]) {
                dist[adjN]=edjw+dis;
                pq.push({adjN,edjw+dis});
            }
        }
    }
    return dist[dest];
}

void shortest_path_dist(int src,int dest) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    vector<int> dist(size,1e9);
    vector<int> parent(size,-1);
    pq.push({src,0});
    dist[src]=0;
    while (!pq.empty()) {
        auto it=pq.top();
        int node=it.first;
        int dis=it.second;
        pq.pop();
        for (auto x:adj_d[node]) {
            int adjN=x.first;
            int edjw=x.second;
            if (dis+edjw < dist[adjN]) {
                dist[adjN]=edjw+dis;
                pq.push({adjN,edjw+dis});
                parent[adjN]=node;
            }
        }
    }
    int node=dest;
    vector<int> path;
    while (parent[node]!=-1) {
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(src);
    reverse(path.begin(),path.end());
    for (int i=0; i<path.size()-1; i++) {
        cout<<Stop_num[path[i]]<<" => ";
    }
    cout<<Stop_num[path.size()]<<endl;
}

void shortest_path_time(int src,int dest) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    vector<int> dist(size,1e9);
    vector<int> parent(size,-1);
    pq.push({src,0});
    dist[src]=0;
    while (!pq.empty()) {
        auto it=pq.top();
        int node=it.first;
        int dis=it.second;
        pq.pop();
        for (auto x:adj_t[node]) {
            int adjN=x.first;
            int edjw=x.second;
            if (dis+edjw < dist[adjN]) {
                dist[adjN]=edjw+dis;
                pq.push({adjN,edjw+dis});
                parent[adjN]=node;
            }
        }
    }
    int node=dest;
    vector<int> path;
    while (parent[node]!=-1) {
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(src);
    reverse(path.begin(),path.end());
    for (int i=0; i<path.size()-1; i++) {
        cout<<Stop_num[path[i]]<<" => ";
    }
    cout<<Stop_num[path.size()]<<endl;
}

void Add_dist() {
    Add_dist_edge("Mejestic","Vijayanagara",5);
    Add_dist_edge("Mejestic","KR Market",2);
    Add_dist_edge("Mejestic","Rajaji Nagar",5);
    Add_dist_edge("Mejestic","Vidhan Soudha",2);
    Add_dist_edge("Vijayanagara","RR Nagar",6);
    Add_dist_edge("RR Nagar","Kengeri",6);
    Add_dist_edge("Kengeri","Jaya Nagar",10);
    Add_dist_edge("KR Market","LalBagh",1);
    Add_dist_edge("LalBagh","Jaya Nagar",2);
    Add_dist_edge("Jaya Nagar","Banashankari",3);
    Add_dist_edge("Banashankari","Jayadeva Hosp.",5);
    Add_dist_edge("Jayadeva Hosp.","JP Nagar",2);
    Add_dist_edge("Jayadeva Hosp.","MG Road",15);
    Add_dist_edge("Jayadeva Hosp.","BTM",3);
    Add_dist_edge("Vidhan Soudha","MG Road",2);
    Add_dist_edge("Vidhan Soudha","Shivaji Nagar",1);
    Add_dist_edge("MG Road","Shivaji Nagar",1);
    Add_dist_edge("Shivaji Nagar","Hebbal",15);
    Add_dist_edge("MG Road","Indra Nagar",7);
    Add_dist_edge("BTM","Electronic City",8);
    Add_dist_edge("Indra Nagar","KR Pura",8);
    Add_dist_edge("BTM","Marathahalli",10);
    Add_dist_edge("Marathahalli","Mahadevpura",4);
    Add_dist_edge("Mahadevpura","KR Pura",5);
    Add_dist_edge("KR Pura","White Field",1);
    Add_dist_edge("Rajaji Nagar","Yeshwanthpur",6);
    return;
}

void Add_time() {
    Add_time_edge("Mejestic","Vijayanagara",24);
    Add_time_edge("Mejestic","KR Market",13);
    Add_time_edge("Mejestic","Rajaji Nagar",15);
    Add_time_edge("Mejestic","Vidhan Soudha",11);
    Add_time_edge("Vijayanagara","RR Nagar",14);
    Add_time_edge("RR Nagar","Kengeri",18);
    Add_time_edge("Kengeri","Jaya Nagar",30);
    Add_time_edge("KR Market","LalBagh",16);
    Add_time_edge("LalBagh","Jaya Nagar",21);
    Add_time_edge("Jaya Nagar","Banashankari",17);
    Add_time_edge("Banashankari","Jayadeva Hosp.",23);
    Add_time_edge("Jayadeva Hosp.","JP Nagar",25);
    Add_time_edge("Jayadeva Hosp.","MG Road",35);
    Add_time_edge("Jayadeva Hosp.","BTM",13);
    Add_time_edge("Vidhan Soudha","MG Road",8);
    Add_time_edge("Vidhan Soudha","Shivaji Nagar",19);
    Add_time_edge("MG Road","Shivaji Nagar",15);
    Add_time_edge("Shivaji Nagar","Hebbal",40);
    Add_time_edge("MG Road","Indra Nagar",26);
    Add_time_edge("BTM","Electronic City",45);
    Add_time_edge("Indra Nagar","KR Pura",30);
    Add_time_edge("BTM","Marathahalli",28);
    Add_time_edge("Marathahalli","Mahadevpura",19);
    Add_time_edge("Mahadevpura","KR Pura",22);
    Add_time_edge("KR Pura","White Field",24);
    Add_time_edge("Rajaji Nagar","Yeshwanthpur",36);
    return;
}

void Add_stops() {
    stops.push_back("Mejestic");
    stops.push_back("KR Market");
    stops.push_back("LalBagh");
    stops.push_back("Jaya Nagar");
    stops.push_back("Banashankari");
    stops.push_back("JP Nagar");
    stops.push_back("Vijayanagara");
    stops.push_back("RR Nagar");
    stops.push_back("Kengeri");
    stops.push_back("Rajaji Nagar");
    stops.push_back("Yeshwanthpur");
    stops.push_back("Vidhan Soudha");
    stops.push_back("Jayadeva Hosp.");
    stops.push_back("BTM");
    stops.push_back("Marathahalli");
    stops.push_back("MG Road");
    stops.push_back("Shivaji Nagar");
    stops.push_back("Hebbal");
    stops.push_back("Electronic City");
    stops.push_back("Indra Nagar");
    stops.push_back("KR Pura");
    stops.push_back("White Field");
    stops.push_back("Mahadevpura");

    for (int i=0; i<stops.size(); i++) {
        mpp[stops[i]]=i;
        Stop_num[i]=stops[i];
    }
    size=stops.size();
    Add_dist();
    Add_time();
}

vector<int>metro_map;
void dfs(int src,int par,vector<bool>&vis){
    vis[src]=1;
    metro_map.push_back(src);
    for(auto x:adj_d[src]){
        if(!vis[x.first]){
            cout<<"hi"<<endl;
            dfs(x.first,src,vis);
        }
    }
}

void displaymap(){
    vector<bool>vis(size);
    dfs(0,-1,vis);
    for(int i=0;i<metro_map.size()-1;i++){
        cout<<Stop_num[metro_map[i]]<<"=> ";
    }
    cout<<Stop_num[metro_map[metro_map.size()-1]];
    cout<<endl;
}

void take_inputs(int &x, int &y) {
    cout<<"Enter the serial no. of Source and Destination Area"<<endl;
    Print_stops();
    cout << "\n ---------------------------------------------------------------\n" ;
    cout<<"Source Stop Number ";
    cin>>x;
    cout << "\n ---------------------------------------------------------------\n" ;
    cout<<"Destination Stop Number ";
    cin>>y;
    cout << "\n ---------------------------------------------------------------\n" ;
    x--;
    y--;
}

int main() {
    cout<<"\n###########\tWELCOME TO BENGALURU BUS SERVICE\t###########\n\n"<<endl;
    Add_stops();
    while(true){
        cout << "\n ---------------------------------------------------------------\n" ;
        cout<<"\t\t\t\t~~LIST OF ACTIONS~~\n\n";
        cout<<("1. LIST ALL THE AREA'S IN THE CITY\n");
        cout<<("2. PRINT THE SHORTEST DISTANCE FROM A 'SOURCE' AREA TO 'DESTINATION' AREA\n");
        cout<<("3. PRINT THE SHORTEST PATH TO REACH FROM A 'SOURCE' AREA TO 'DESTINATION' AREA\n");
        cout<<("4. PRINT THE SHORTEST TIME TO REACH FROM A 'SOURCE' AREA TO 'DESTINATION' AREA\n");
        cout<<("5. PRINT SHORTEST PATH W.R.T TIME TO REACH FROM A 'SOURCE' AREA TO 'DESTINATION' AREA\n");
        cout<<("6. EXIT THE MENU\n\n");
        cout<<("\nENTER YOUR CHOICE FROM THE ABOVE LIST (1 to 6) : \n");
        cout << "\n ---------------------------------------------------------------\n" ;
        int choice;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        cout << "\n ---------------------------------------------------------------\n" ;
        if(choice==1){
            Print_stops();
        }
        else if(choice==2){
            int x,y;
            take_inputs(x,y);
            int p=shrotest_dist(x,y);
            cout<<"The shortest distance between "<<Stop_num[x]<<" to "<<Stop_num[y]<<" is "<<p<<" KM\n";
        }
        else if(choice==3){
            int x,y;
            take_inputs(x,y);
            cout<<"The shortest path from "<<Stop_num[x]<<" to "<<Stop_num[y]<<" is "<<endl;
            shortest_path_dist(x,y);
        }
        else if(choice==4){
            int x,y;
            take_inputs(x,y);
            int p=shrotest_time(x,y);
            cout<<"It takes "<<p<<" minutes to reach from "<<Stop_num[x]<<" to "<<Stop_num[y]<<endl;
        }

        else if(choice==5){
            int x,y;
            take_inputs(x,y);
            cout<<"The Path which takes less time from "<<Stop_num[x]<<" to "<<Stop_num[y]<<" is "<<endl;
            shortest_path_time(x,y);
        }
        else if(choice==7) {
            displaymap();
        }
        else{
            break;
        }
    }
    return 0;
}
