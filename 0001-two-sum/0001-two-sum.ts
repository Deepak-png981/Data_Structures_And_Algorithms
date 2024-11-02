function twoSum(nums: number[], target: number): number[] {
    const mp : Map<number , number> = new Map();
    for(let i = 0; i<nums.length; i++){
        mp.set(nums[i] , i);
    }
    for(let i = 0; i<nums.length; i++){
        const complement = target - nums[i];
        if(mp.has(complement) && mp.get(complement) != i ){
            return [i , mp.get(target -nums[i])];
        }
    }
    return [];
};