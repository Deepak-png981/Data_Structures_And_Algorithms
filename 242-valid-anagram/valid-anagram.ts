const isAnagram = (s: string, t: string): boolean => {
    if (s.length !== t.length)  return false;
    //for the s
    const map_s = new Map<string, number>();
    for (const ch of s) {
        map_s.set(ch, (map_s.get(ch) || 0) + 1);
    }

    const map_t = new Map<string, number>();
    for (const ch of t) {
        map_t.set(ch, (map_t.get(ch) || 0) + 1);
    }
    //as we have confirmed that the length is same 
    for(const [key , value] of map_s){
        if(map_t.get(key) !== value)
            return false;
    }
    return true;

};