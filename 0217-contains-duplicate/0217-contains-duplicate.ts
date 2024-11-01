function containsDuplicate(nums: number[]): boolean {
    const arrayLength = nums.length;
    const hashSet = new Set();
    for(const num of nums){
        hashSet.add(num);
    }
    return !(hashSet.size == arrayLength);
};