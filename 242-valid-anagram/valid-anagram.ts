function isAnagram(s: string, t: string): boolean {
    if (s.length !== t.length)  return false;
    const alphabetArray = new Array(26).fill(0);
    for(var i = 0; i<s.length; i++){
        alphabetArray[s.charCodeAt(i) - 'a'.charCodeAt(0)]++;
        alphabetArray[t.charCodeAt(i) - 'a'.charCodeAt(0)]--;
    }
    return alphabetArray.every((c) => c === 0);
};