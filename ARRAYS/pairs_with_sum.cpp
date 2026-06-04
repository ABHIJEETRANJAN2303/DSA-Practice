class FindSumPairs
{
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> frequency;

public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int i = 0; i < nums2.size(); i++)
        {
            frequency[nums2[i]]++;
        }
    }

    void add(int index, int val)
    {
        int oldValue = nums2[index];
        frequency[oldValue]--;
        nums2[index] += val;
        int newValue = nums2[index];
        frequency[newValue]++;
    }

    int count(int tot)
    {
        int pairs = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            int needed = tot - nums1[i];
            pairs += frequency[needed];
        }
        return pairs;
    }
};
