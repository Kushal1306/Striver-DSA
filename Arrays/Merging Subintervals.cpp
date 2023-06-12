vector<vector<int>> merge(vector<vector<int>> &intervals) {
   sort(intervals.begin(), intervals.end());
    vector<vector<int>>kkj;
    for (auto &i : intervals)
     {
      if (kkj.size() == 0 || kkj.back()[1] < i[0])
       {
        kkj.push_back(i);
       }
       else
        {
        kkj.back()[1] = max(kkj.back()[1], i[1]);
       }
    }
    return kkj;
  }