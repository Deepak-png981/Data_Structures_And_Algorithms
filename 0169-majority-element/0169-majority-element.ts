function majorityElement(nums: number[]): number {
    
    const size = nums.length;
    let count = 0 , element : number;
    for(let i = 0; i<size; i++){
        if(count == 0){
            count++;
            element = nums[i];
        }else if(element == nums[i]) count++;
        else count--;
    }
    return element;
    
};