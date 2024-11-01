function containsDuplicate(nums: number[]): boolean {
    const hashSet = new Set<number>();
    for(const num of nums){
        if(hashSet.has(num)){
            return true;
        }
        hashSet.add(num);
    }
    return false;
};