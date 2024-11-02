function groupAnagrams(strs: string[]): string[][] {
    const map : Map<string , string[]> = new Map();
    for(const str of strs){
        const key = str.split('').sort().join('');
        if(map.has(key)){
            map.get(key).push(str);
        }else{
            map.set(key , [str]);
        }
    }
    return Array.from(map.values());
};