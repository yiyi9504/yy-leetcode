#include "../../include/common.hh"

using namespace std;

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        sort(milestones.begin(), milestones.end());
        int task_num = milestones.size();
        if (task_num == 1) return 1;
        long long diff = milestones[task_num-1] - milestones[task_num-2] - 1;
        for (int i=0; i<task_num-2; i++) {
            diff -= milestones[i];
            if (diff<=0) break;
        }
        long long sum = 0;
        for (int i=0; i<task_num; i++) sum += milestones[i];
        return diff<=0 ? sum : sum - diff;
    }
};


// struct Task
// {
//     int id;
//     int cost;
//     bool operator < (const Task& i) const {
//         if (cost != i.cost) {
//             return cost < i.cost;  
//         } 
//         return id < i.id;
//     }
// };

// class Solution {
// public:
//     long long numberOfWeeks(vector<int>& milestones) {
        
//         auto comp = [](const Task& lhs, const Task& rhs) { 
//             if (lhs.cost != rhs.cost) {
//                 return lhs.cost > rhs.cost;  
//             } 
//             return lhs.id > rhs.id;
//         };
//         priority_queue<Task> max_priority; 
//         // priority_queue<Task, vector<Task>, decltype(comp)> min_priority(comp);

//         int task_num = milestones.size();
//         for (int i=0; i<task_num; i++) {
//             max_priority.push({i,milestones[i]});
//             // min_priority.push({i,milestones[i]});
//         }
//         vector<bool> isdone(task_num,false);

//         // priority_queue<Task, vector<Task>, decltype(comp)> min_test = min_priority;
//         // while(!min_test.empty()) {
//         //     auto lhs = min_test.top();
//         //     min_test.pop();
//         //     cout << lhs.id << ':' << lhs.cost << ' ';            
//         // }
//         // cout << endl;
//         priority_queue<Task> max_test = max_priority; 
//         while(!max_test.empty()) {
//             auto lhs = max_test.top();
//             max_test.pop();
//             cout << lhs.id << ':' << lhs.cost << ' ';             
//         }               
//         cout << endl;

//         int last_id = -1;
//         int weeks = 0;
//         while(!max_priority.empty() || !min_priority.empty()) {
//             Task lhs({-1,0}), rhs({-1,0});
//             while(!min_priority.empty()) {
//                 lhs = min_priority.top();
//                 min_priority.pop();
//                 if (!isdone[lhs.id]) break;               
//             }
//             while (!max_priority.empty()) {
//                 rhs = max_priority.top();
//                 max_priority.pop();
//                 if (!isdone[rhs.id]) break; 
//             }

//             cout << lhs.id << ':' << lhs.cost << ' ' << rhs.id << ':' << rhs.cost << endl; 
//             if (lhs.id>=0 && rhs.id>=0) {
//                 if (lhs.id == rhs.id) {
//                     max_priority.push({rhs});
//                     continue;
//                 } else if (lhs.cost > rhs.cost) {
//                     break;
//                 } else {
//                     weeks += (lhs.cost * 2);
//                     isdone[lhs.id] = true;
//                     last_id = lhs.id;
//                     if (lhs.cost < rhs.cost) {
//                         max_priority.push({rhs.id, rhs.cost-lhs.cost});
//                         min_priority.push({rhs.id, rhs.cost-lhs.cost});                      
//                     }
//                 }
//             } else if (lhs.id>=0 || rhs.id>=0) {
//                 int id = lhs.id>=0 ? lhs.id : rhs.id;
//                 if (id != last_id) weeks++;
//                 break;
//             } else {
//                 break;
//             }
//         }
//         return weeks;
//     }
// };