int[] nums = Array.ConvertAll<char, int>(Console.ReadLine().ToCharArray(), new Converter<char, int>((c) => Convert.ToInt32(c.ToString())));

int temp = 0;
for (int i = 0; i < nums.Length - 1; i++)
{
    for (int j = 0; j < nums.Length - 1; j++)
    {
        if (nums[j] < nums[j + 1])
        {
            temp = nums[j + 1];
            nums[j + 1] = nums[j];
            nums[j] = temp;
        }
    }
}

for(int i = 0; i < nums.Length; i++) 
{
    Console.Write(nums[i]);
}