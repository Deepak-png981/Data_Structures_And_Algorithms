function containsDuplicate(nums: number[]): boolean {
    const hashSet = new Set<number>(nums);
    return hashSet.size !== nums.length;
};