function majorityElement(nums: number[]): number {
    const n = nums.length;
    let element : number;
    let count = 0;
    for(let i = 0; i<n; i++){
        if(count == 0){
            element = nums[i];
            count++;
        }else if(element == nums[i])    count++;
        else    count--;
    }
    return element;
};