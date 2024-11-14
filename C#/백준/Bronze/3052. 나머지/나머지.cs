int[] nums = new int[10];
for (int i = 0; i < 10; i++)
{
    nums[i] = int.Parse(Console.ReadLine());
}
int[] remains = new int[10];


for(int i = 0; i < 10; i++)
{
    remains[i] = -1;
}
int count = 0;
for (int i = 0; i < 10; i++)
{
    if (!remains.Contains(nums[i] % 42))
    {
        count++;
    }
    remains[i] = nums[i] % 42;
}

Console.Write(count);