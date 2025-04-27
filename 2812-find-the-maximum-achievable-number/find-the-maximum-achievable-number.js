/**
 * @param {number} num
 * @param {number} t
 * @return {number}
 */
var theMaximumAchievableX = function(num, t) {
    //x - t(1) = num + t(1)
    //x = num + 2t(1)
    return num + 2 * t;
};