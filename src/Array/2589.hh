#include "../../include/common.hh"

using namespace std;

struct Task
{
    int id;
    int start;
    int end;
    int slew;
    bool operator < (const Task& i) const {
        // if(slew != i.slew) {
        //     return slew > i.slew; 
        // } else {
        //     return start < i.start;
        // }
        if(end != i.end) {
            return end > i.end;
        } else {
            return start < i.start;
        }        
    }
};

struct TimeBlock
{
    int id;
    double buzy;
    bool operator < (const TimeBlock& i) const {
        if(buzy != i.buzy) {
            return buzy < i.buzy;
        } else {
            return id > i.id;
        }
    }
};

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int task_num = tasks.size();
        int max_len = 2020;
        vector<double> time_buzy_sum(max_len, 0.0);
        vector<double> time_buzy_diff(max_len, 0.0);
        vector<bool> time_use(max_len, false);
        vector<int> time_use_sum(max_len, 0);
        vector<int> time_use_diff(max_len, 0);
        vector<bool> task_done(task_num, false);
        
        for (int task_id=0; task_id<task_num; task_id++) {
            // sort task by slew 
            int start = tasks[task_id][0], end = tasks[task_id][1];
            int slew = end - start - tasks[task_id][2] + 1;
            taskQueue.push({task_id, start, end, slew});
            // sum time buzy
            double adv = (double)tasks[task_id][2] / (double)(end-start+1);
            time_buzy_diff[start] += adv;
            time_buzy_diff[end+1] -= adv;                     
        }
        // update time_buzy_sum
        double diff_buzy = 0.0;
        for (int i=1; i<max_len; i++) {
            diff_buzy += time_buzy_diff[i];
            time_buzy_diff[i] = 0;
            time_buzy_sum[i] += diff_buzy;
            // cout << time_buzy_sum[i] << ' ';
        }

        while (!taskQueue.empty()) {
            auto task = taskQueue.top();
            taskQueue.pop();
            if (task_done[task.id]) continue;
            int start = task.start, end = task.end;
            int slew = task.slew;
            int duration = end - start - slew + 1;
            // cout << start << ' ' << end << endl;

            // update time_use_sum
            int diff_use = 0;
            diff_buzy = 0.0;
            for (int i=1; i<max_len; i++) {
                diff_use += time_use_diff[i];
                time_use_diff[i] = 0;
                time_use_sum[i] += diff_use;
                diff_buzy += time_buzy_diff[i];
                time_buzy_diff[i] = 0;
                time_buzy_sum[i] += diff_buzy;               
            }

            // if not done
            int cost = time_use_sum[end]-time_use_sum[start-1];
            if (cost < duration) {
                priority_queue<TimeBlock> timeblock;
                for (int i=start; i<=end; i++) {
                    if (!time_use[i]) {
                        timeblock.push({i, time_buzy_sum[i]}); 
                    }
                }
                double front_buzy = 10000;
                while (cost < duration) {
                    auto timex = timeblock.top();
                    timeblock.pop();
                    if (timex.buzy == front_buzy) {
                        // update time_use_sum
                        diff_use = 0;
                        for (int i=1; i<max_len; i++) {
                            diff_use += time_use_diff[i];
                            time_use_diff[i] = 0;
                            time_use_sum[i] += diff_use;             
                        }
                        // check hasdone task
                        for (int i=0; i<tasks.size(); i++) {
                            if (task_done[i]) continue;
                            int cost_x = time_use_sum[tasks[i][1]]-time_use_sum[tasks[i][0]-1];
                            if (cost_x >= tasks[i][2]) {
                                task_done[i] = true;
                                double adv_x = (double)tasks[i][2] / (double)(tasks[i][1]-tasks[i][0]+1);
                                time_buzy_diff[tasks[i][0]] -= adv_x;
                                time_buzy_diff[tasks[i][1]+1] += adv_x;                                 
                            }
                        }
                        // update time_buzy_sum
                        diff_buzy = 0.0;
                        for (int i=1; i<max_len; i++) {
                            diff_buzy += time_buzy_diff[i];
                            time_buzy_diff[i] = 0;
                            time_buzy_sum[i] += diff_buzy;
                        }                       
                        // update timeblock
                        priority_queue<TimeBlock>().swap(timeblock);
                        for (int i=start; i<=end; i++) {
                            if (!time_use[i]) {
                                timeblock.push({i, time_buzy_sum[i]}); 
                            }
                        }
                        timex = timeblock.top();
                        timeblock.pop();
                    }
                    time_use[timex.id] = true;
                    time_use_diff[timex.id]++;
                    front_buzy = timex.buzy;
                    cost++;
                }
            }
            task_done[task.id] = true;
            double adv = (double)duration / (double)(end-start+1);
            time_buzy_diff[start] -= adv;
            time_buzy_diff[end+1] += adv;                              
        }
        int diff_use = 0;
        for (int i=1; i<max_len; i++) {
            diff_use += time_use_diff[i];
            time_use_sum[i] += diff_use;             
        }
        return time_use_sum[max_len-1];
    }
private:
    priority_queue<Task> taskQueue; 
};
