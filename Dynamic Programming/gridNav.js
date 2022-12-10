/**
 * how many ways
 * to traverse a m X n grid
 * from top-left to bottom-right
 * we take 1X1 to have 1 way
 * 
 * keep in mind
 * not the number of steps
 * PNC nai karna yaha baith ke ((n-1 + m-1)!)/(n-1)!(m-1)!
 */


//      memoization?! wo kya?

// const gridNav = (n,m) => {
//     if(n==1 && m==1) return 1;
//     if(n==0 || m==0) return 0;
//     return gridNav(n-1,m)+gridNav(n,m-1);
// }



//      oh! memo-i-zation
//       matlab map 
//        viz python ka dictionary 

const gridNav = (n,m, memo={}) => {
    if(m==1 || n==1) return 1;
    if(n==0 || m==0) return 0;
    if(n+","+m in memo) return memo[n+","+m];
    child= gridNav(n-1,m, memo)+gridNav(n,m-1,memo);
    memo[n+","+m] = child;
    return child;
}

console.log(gridNav(3,3));
console.log(gridNav(3,2));
console.log(gridNav(2,3));
console.log(gridNav(12,12));