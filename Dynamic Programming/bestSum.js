//  see howSum first

//here i tried to implement such that the difference comes out zero, as such i take the big terms but it didnt work becuse difference can be zero in many cases
// also i am pretty sure i am supposed to use the variable declaration keywords(let, const, var) here else its BT
/**console.log(target);
    if (target===0) return [];
    if (target<0) return  null;
    for (a of numbers){
        if (target-a===0){
            console.log('exact zero', target,a);
            res = [a];
            return res;
        }
    }
    for(a of numbers){
        console.log('not exact zero', target,a);
        res = bestSum(target-a,numbers);
        console.log('res', res);
        if (res){
            res.push(a);
            return res;
        }
    } */

const bestSum = (target, numbers,memo={}) => {
    if (target==0) return [];
    if (target<0) return null;
    if (target in memo) return memo[target];

    let shortest = null; // so the part of me missing the let keyword here was the only BT.
    for (let a of numbers){
        let res = bestSum(target-a,numbers,memo);
        if (res){
            if (shortest===null || res.length<shortest.length){
                shortest = [...res,a];
            }
        }
    }
    memo[target] = shortest;
    return shortest;
}

console.log(bestSum(8,[5,4,1])) /// using howSum might give [1,1,1,5] or eight 1s but best one is [4,4]
console.log(bestSum(678,[54,45,12]))
console.log(bestSum(100,[1,2,5,25]))