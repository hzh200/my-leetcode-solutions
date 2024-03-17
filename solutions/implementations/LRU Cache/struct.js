/**
 * @param {number} key
 * @param {number} val
 */
const LinkedList = function(key, value) {
    this.key = key;
    this.value = value;
    this.pre = null;
    this.aft = null;
};

/**
 * @param {number} capacity
 */
const LRUCache = function(capacity) {
    this.capacity = capacity;
    this.count = 0;
    this.map = new Map();
    this.head = new LinkedList(0, 0);
    this.tail = new LinkedList(0, 0);
    this.head.aft = this.tail;
    this.tail.pre = this.head;
};

/**
 * @param {number} key
 * @param {number} val
 * @return {void}
 */
LRUCache.prototype.insert = function(key, value) {
    const newNode = new LinkedList(key, value);
    newNode.aft = this.head.aft;
    this.head.aft.pre = newNode;
    this.head.aft = newNode;
    newNode.pre = this.head;
    this.count++;
    this.map.set(key, newNode);
};

/**
 * @param {number} key
 * @return {void}
 */
LRUCache.prototype.delete = function(key) {
    const node = this.map.get(key);
    node.pre.aft = node.aft;
    node.aft.pre = node.pre;
    this.count--;
    this.map.delete(key);
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    if (this.map.has(key)) {
        const value = this.map.get(key).value;
        this.delete(key);
        this.insert(key, value);
        return this.map.get(key).value;
    } else {
        return -1;
    }
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    if (this.map.has(key)) {
        this.delete(key);
    } else {
        if (this.count == this.capacity) {
            this.delete(this.tail.pre.key);   
        }
    }
    this.insert(key, value);
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */