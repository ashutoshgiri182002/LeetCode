class Solution {
public:
    
          
        int removeElement(vector<int> &nums, int val)
{

    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }

    else if (n == 1)
    {
        if (nums[0] == val)
        {
            return 0;
            nums[0] = -1;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        int cnt = 0;

        int j = n - 1;
        int i = 0;
        while (i <= j)
        {

            if (nums[i] == val)
            {   
                cnt++;
                if (nums[j] != val)
                {   
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    j--;
                }
                else
                {
                    nums[j] = nums[j];
                    j--;
                    i--;
                }
            }
            i++;
        }

        // printvec(nums);

        return (n-cnt);
    }

    }
};
