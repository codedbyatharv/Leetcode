/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    // 1. Base cases for invalid inputs
    // If obj is null or undefined, it has no prototype.
    // If classFunction is not a function, it doesn't have a valid prototype to check against.
    if (obj === null || obj === undefined || typeof classFunction !== 'function') {
        return false;
    }

    // 2. Get the initial prototype of the object
    // Object.getPrototypeOf automatically boxes primitives (e.g., 5 becomes new Number(5))
    let currentProto = Object.getPrototypeOf(obj);

    // 3. Traverse up the prototype chain
    while (currentProto !== null) {
        // If we find a match with the class's prototype, it's an instance
        if (currentProto === classFunction.prototype) {
            return true;
        }
        // Move up the chain
        currentProto = Object.getPrototypeOf(currentProto);
    }

    // 4. If we reach the end of the chain without a match
    return false;
};