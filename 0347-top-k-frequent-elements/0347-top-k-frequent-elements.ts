function topKFrequent(nums: number[], k: number): number[] {
    const map: Map<number , number> = new Map();
    for(const num of nums){
        map.set(num , ((map.get(num) || 0) + 1));
    }
    const sortedMap = new Map([...map].sort((a,b)=>b[1] - a[1]));
    return Array.from(sortedMap.keys()).splice(0,k);
};