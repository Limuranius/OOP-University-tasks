"use strict";
// Шахтёр. Копает разные материалы в зависимости от своих характеристик
class Miner {
    constructor(x, y, type) {
        this.x = x;
        this.y = y;
        this.type = type;
    }
    getMiningResults() {
        return this.type.getMiningStats();
    }
}
// Легковес шахтёра. Хранит тип шахтёра и характеристики, соответствующие этому типу
class MinerType {
    constructor(typeName, miningStats) {
        this.typeName = typeName;
        this.miningStats = miningStats;
    }
    getMiningStats() {
        return this.miningStats;
    }
}
// Фабрика шахтёров. Создаёт шахтёров определённых типов и кеширует эти типы
class MinerFactory {
    constructor() {
        this.types = new Map();
    }
    getMinerType(typeName, miningStats) {
        if (!this.types.has(typeName)) {
            this.types.set(typeName, new MinerType(typeName, miningStats));
        }
        return this.types.get(typeName);
    }
    createUniversal1(x, y) {
        let typeName = "Universal miner LVL 1";
        let miningStats = [2, 2, 1, 0, 0];
        return new Miner(x, y, this.getMinerType(typeName, miningStats));
    }
    createUniversal2(x, y) {
        let typeName = "Universal miner LVL 2";
        let miningStats = [6, 5, 5, 1, 1];
        return new Miner(x, y, this.getMinerType(typeName, miningStats));
    }
    createGem1(x, y) {
        let typeName = "Gem miner LVL 1";
        let miningStats = [0, 0, 0, 0, 3];
        return new Miner(x, y, this.getMinerType(typeName, miningStats));
    }
    createGold1(x, y) {
        let typeName = "Gold miner LVL 1";
        let miningStats = [0, 0, 0, 7, 0];
        return new Miner(x, y, this.getMinerType(typeName, miningStats));
    }
}
// Шахта. Может создавать шахтёров и заставлять их работать
class Mine {
    constructor() {
        this.factory = new MinerFactory();
        this.miners = [];
        this.totalResourcesMined = [0, 0, 0, 0, 0];
        this.daysPassed = 0;
    }
    spendDay() {
        this.miners.forEach(miner => {
            let workRes = miner.getMiningResults();
            for (let i = 0; i < 5; i++) {
                this.totalResourcesMined[i] += workRes[i];
            }
        });
        this.daysPassed++;
    }
    printResults() {
        console.log(`День ${this.daysPassed}. Результаты:
Железо: ${this.totalResourcesMined[0]}
Медь: ${this.totalResourcesMined[1]}
Олово: ${this.totalResourcesMined[2]}
Золото: ${this.totalResourcesMined[3]}
Драгоценные камни: ${this.totalResourcesMined[4]}`);
    }
    printWorkers() {
        console.log("Список сотрудников:");
        this.miners.forEach(miner => {
            console.log(miner.type.typeName + " : " + miner.type.getMiningStats());
        });
    }
    addUniversal1(x = 0, y = 0) {
        this.miners.push(this.factory.createUniversal1(x, y));
    }
    addUniversal2(x = 0, y = 0) {
        this.miners.push(this.factory.createUniversal2(x, y));
    }
    addGem1(x = 0, y = 0) {
        this.miners.push(this.factory.createGem1(x, y));
    }
    addGold1(x = 0, y = 0) {
        this.miners.push(this.factory.createGold1(x, y));
    }
}
function main() {
    let mine = new Mine();
    mine.addUniversal1();
    mine.addUniversal1();
    mine.addUniversal1();
    mine.addUniversal1();
    mine.addUniversal1();
    mine.addUniversal2();
    mine.addUniversal2();
    mine.addGold1();
    mine.addGem1();
    mine.printWorkers();
    mine.printResults();
    let daysToSpend = 5;
    for (let i = 0; i < daysToSpend; i++) {
        mine.spendDay();
    }
    mine.printResults();
}
main();
