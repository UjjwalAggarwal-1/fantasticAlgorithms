/*
    "graph" aka "adjency-list"
*/
graph = {
    'a':['c','b'],
    'b':['h'],
    'c':['d'],
    'd':['f','e'],
    'e':[],
    'f':['i','g'],
    'g':[],
    'h':[],
    'i':[],
};

const DFS=(graph,src)=>{
    const stack = [src];

    while (stack.length > 0){
        const current = stack.pop();
        console.log(current);
   
        for(let neighbour of graph[current]){
            stack.push(neighbour);
        }
    }
};

// DFS(graph,'a');

const DFSr=(graph,src)=>{
    /*
        WTF is this?
                    // const stack = [src];
        
                    // current = stack.pop();
                    // console.log(current);
    */                
    console.log(src);
    for(let neighbour of graph[src]){
      DFSr(graph,neighbour)
    };
};

// DFSr(graph,'a');

/*
    order in both methods(recursive and not) is different
*/

const BFS=(graph,src)=>{
    const queue = [src];
    while(queue.length>0){
        current = queue.shift();
        console.log(current);
        for(let neighbour of graph[current]){
            queue.push(neighbour);
        };y
    };  
};

// BFS(graph,'a');

/**
 * is this even possible?
 */
// const BFSr=(graph,src)=>{
//     // console.log(src);
//     for(let neighbour of graph[src]){
//         console.log(neighbour);
//         BFSr(graph,neighbour);
//     };
// };

// BFSr(graph,'a');