//   see canSum first

const howSum = (target, numbers,memo={}) => {
    if (target in memo) return memo[target];
    if (target === 0) return [];
    if (target<0) return null;
    for (let a of numbers){
        var next=howSum(target-a,numbers,memo); /// bc var/const kuch likhna tha bas itna sa bt rha gya code mein
        memo[target]=next;
        if (next){
            next.push(a);
            return next;
        }
    }
    return null;
}

// console.log(howSum(343,[23,5,2]))    // descending order mein rakh ke smaller solution milega 
// console.log(howSum(10,[8,3,2]))
// console.log(howSum(7,[4,2]))
// console.log(howSum(8,[8,3,2]))
// console.log(howSum(0,[8,3,2]))

console.time('howSum');
ss=howSum(5003,[31,2]);
console.timeEnd('howSum');
console.log(ss)