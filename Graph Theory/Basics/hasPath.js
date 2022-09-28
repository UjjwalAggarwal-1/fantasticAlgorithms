/*
    "graph" aka "adjency-list"
*/
graph = { //directed path
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


function hasPath(graph,src,dst) {
    if (src===dst) return true;

    for (neighbour of graph[src]){
        if (hasPath(graph,neighbour,dst)===true){
            return true;
        }
        // else{
        //     continue;
        // }
    }

    return false;
};

// console.log(hasPath(graph,'c','g'));



edges = [
    ['i','j'],
    ['i','k'],
    ['k','m'],
    ['k','l'],
    ['o','n'],
]

function E2G (edges){
    Wörterbuch = {}
    for(a of edges){
        for(halfa of a){
            if (!(halfa in Wörterbuch)) Wörterbuch[halfa] = [];
        };
    };
    for(a of edges){
        Wörterbuch[a[0]].push(a[1]);
        Wörterbuch[a[1]].push(a[0]);
    };
    return Wörterbuch;
};
//need this thingy below
undGraph = {
    'i':['j','k'],
    'j':['i'],
    'k':['i','m','l'],
    'm':['k'],
    'l':['k'],
    'o':['n'],
    'n':['o'],
};

function undPath(edges,nodeA,nodeB){
    const graph = E2G(edges);
    return hasPathMOD(graph, nodeA,nodeB,new Set());
};
function hasPathMOD(graph,src,dst,vis) {
    if (src===dst) return true;
    if (!(src in vis)) vis.add(src);
    for (neighbour of graph[src]){
        // half an hour of BT for using neighbour in vis rather than vis.has(neighbour)
        if (!(vis.has(neighbour))){
            vis.add(neighbour);
            console.log(vis)
            if (hasPathMOD(graph,neighbour,dst,vis)===true){
                return true;
            };
        };
    };

    return false;
};

// console.log(undPath(edges,'i','o'));
