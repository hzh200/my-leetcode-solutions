/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
var canCompleteCircuit = function(gas, cost) {
    const n = gas.length;
    for (let i = 0; i < n; i++) {
        const [res, end] = run(gas, cost, i, n);
        if (res) {
            return i;
        }
        if (end < i) {
            break;
        }
        i = end;
    }
    return -1;
};

var run = (gas, cost, start, n) => {
    let index = start;
    let sum = 0;
    do {
        sum += gas[index];
        sum -= cost[index];
        if (sum < 0) {
            return [false, index];
        }
        index++;
        if (index === n) {
            index = 0;
        }
    } while (index !== start)
    return [true, null];
};