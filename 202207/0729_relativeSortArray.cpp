// C++ 简洁的计数排序实现

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
{
    // 1. 利用算法找出最小最大值
    auto [minNum, maxNum] = std::minmax_element(arr1.begin(), arr1.end());
    
    // 2. 计数排序
    vector<int> bucket(*maxNum - *minNum + 1);
    for (auto x : arr1) {
        bucket[x - *minNum]++;
    }

    // 3. 根据arr2的顺序排序
    vector<int> res;
    for (auto x : arr2) {
        while (bucket[x - *minNum] -- > 0) {
            res.emplace_back(x);
        }
    }

    // 4. 把剩余的元素排序
    for (int i = 0; i < bucket.size(); i++) {
        while (bucket[i] -- > 0) {
            res.emplace_back(i + *minNum);
        }
    }
    return res;
}