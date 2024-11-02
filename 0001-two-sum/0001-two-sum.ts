function twoSum(nums: number[], target: number): number[] {
    const mp: Map<number , number> = new Map();
    for(let i = 0; i<nums.length; i++){
        const complement = target - nums[i];
        if(mp.has(complement)){
            return [i , mp.get(complement)];
        }
        mp.set(nums[i] , i);
    }
    return [];
};