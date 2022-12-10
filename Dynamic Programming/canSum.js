// can target be a sum of elements of numbers array, repition allowed

const canSum=(target,numbers,memo={}) => {

    if (target===0) return true;
    if (target>0){
        if (target in memo) return memo[target];
        for (let a of numbers){
            result = (canSum(target-a,numbers,memo));
            memo[target] = result;
            if (result) return true;
        }
    }
    return false;
}

// console.log(canSum(7000,[8,5,3,1]))

// if your array has 1, at the 0th index, it will call that stack target number of times, and cause stack overflow
// so if smaller numbers are going to cause so much stack usage, intuitivelly i'd arrange the array in a descending order

// ---------------------------------------------------------------------------------------------
// tabulation


// const canSumTab=(target, numbers)=>{
//     if (target===0) return true;
//     possys = new Set();
//     for (let a of numbers) possys.add(a);
//     for (let a of possys) {
//         for (let b of possys){
//             if (a+b == target) return true;
//             if(a+b<=target){
//                 possys.add(a+b);
//             }
//         }
//     }
//     console.log(possys);
//     return false
// }


//best sum
const canSumTab=(target, numbers)=>{
    possys = [];
    possys.push([]);
    for(var i=0; i< numbers.length;i++) 
        possys.push(null);
    for (var i =0;i<=target;i++){
        for(let a of numbers){
            if (i+a<=target && possys[i] ){
                if (!possys[i+a])
                possys[i+a] = [...possys[i],a];
                else if (possys[i+a].length-1>possys[i].length)
                possys[i+a] = [...possys[i],a];
            }
        }
    }
    return possys[target];
    
}


console.log(canSumTab(450,[2,4,44,8]));
console.log(canSumTab(8,[5,4,1]));
console.log(canSumTab(8,[5,2,3]));