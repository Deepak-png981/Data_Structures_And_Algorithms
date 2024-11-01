function isAnagram(s: string, t: string): boolean {
    return s.split('').sort().join('') === t.split('').sort().join('');
//     if(s.length !== t.length){
//         return false;
//     }
//     const obj : Record<string , number> = {};
//     for(let i = 0; i<s.length; i++){
//         const s_char = s[i];
//         const t_char = t[i];
//         if(obj[s_char] === undefined)   obj[s_char] = 0;
//         if(obj[t_char] === undefined)   obj[t_char] = 0;
        
//         obj[s_char]++;
//         obj[t_char]--;
//     }
//     const keys: string[] = Object.keys(obj);
//     for(const key of keys){
//         const value = obj[key];
//         if(value != 0)
//             return false;
//     }
//     return true;
};