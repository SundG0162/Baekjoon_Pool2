int[] nums = Array.ConvertAll(Console.ReadLine().Split(), e => int.Parse(e));
int bucketCount = nums[0];
int changeCount = nums[1];


int[] bucketInfo = new int[bucketCount];

for (int i = 1; i <= bucketCount; i++)
{
    bucketInfo[i - 1] = i;
}

for (int i = 0; i < changeCount; i++)
{
    int[] nums2 = Array.ConvertAll(Console.ReadLine().Split(), e => int.Parse(e));
    nums2[0] -= 1;
    nums2[1] -= 1;
    int temp = bucketInfo[nums2[0]];
    bucketInfo[nums2[0]] = bucketInfo[nums2[1]];
    bucketInfo[nums2[1]] = temp;
}

for (int i = 0; i < bucketCount; i++)
{
    if (i == bucketCount - 1)
    {
        Console.Write($"{bucketInfo[i]}");
        return;
    }
    Console.Write($"{bucketInfo[i]} ");
}
