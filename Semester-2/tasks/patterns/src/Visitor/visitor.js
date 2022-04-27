"use strict";
// ____________________________Компоненты____________________________
class Table {
    constructor(length, width) {
        this.length = length;
        this.width = width;
    }
    accept(visitor) {
        visitor.visitTable(this);
    }
}
class Chair {
    constructor(height, maxWeight) {
        this.height = height;
        this.maxWeight = maxWeight;
    }
    accept(visitor) {
        visitor.visitChair(this);
    }
}
class Fork {
    constructor(material, size) {
        this.material = material;
        this.size = size;
    }
    accept(visitor) {
        visitor.visitFork(this);
    }
}
// Функция посетителя - выводить в консоль информацию об объекте
class HelpVisitor {
    visitTable(t) {
        let res = "Стол. Предназначен для размещения на нём предметов. Данный стол имеет следующие характеристики: длина=" + t.length + " ширина=" + t.width;
        console.log(res);
    }
    visitChair(ch) {
        let res = "Стул. На нём можно сидеть. Данный стул имеет следующие характеристики: высота=" + ch.height + " максимальный вес=" + ch.maxWeight;
        console.log(res);
    }
    visitFork(f) {
        let res = "Вилка. Ткни ей в кусок мяса и посмотри, что получится. Данная вилка имеет следующие характеристики: материал=" + f.material + " размер=" + f.size;
        console.log(res);
    }
}
class UselessHelpVisitor {
    visitTable(t) {
        let res = "Стол. Без понятия зачем он нужен";
        console.log(res);
    }
    visitChair(ch) {
        let res = "Стул. Наверное где-то пригодится";
        console.log(res);
    }
    visitFork(f) {
        let res = "Вилка. Блестит";
        console.log(res);
    }
}
class Helper {
    constructor() {
        this.visitor = new HelpVisitor();
    }
    help(target) {
        target.accept(this.visitor);
    }
}
class UselessHelper {
    constructor() {
        this.visitor = new UselessHelpVisitor();
    }
    help(target) {
        target.accept(this.visitor);
    }
}
function main() {
    let table = new Table(5, 10);
    let chair = new Chair(13, 300);
    let fork = new Fork("wood", 3);
    let helper = new Helper();
    let uselessHelper = new UselessHelper();
    helper.help(table);
    helper.help(chair);
    helper.help(fork);
    uselessHelper.help(table);
    uselessHelper.help(chair);
    uselessHelper.help(fork);
}
main();
