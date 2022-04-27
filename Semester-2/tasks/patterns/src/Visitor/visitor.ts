// ____________________________Компоненты____________________________
class Table {
    length: number  // Длина стола
    width: number   // Ширина стола

    constructor(length: number, width: number) {
        this.length = length
        this.width = width
    }

    accept(visitor: IVisitor): void {
        visitor.visitTable(this)
    }
}

class Chair {
    height: number     // Высота стула
    maxWeight: number  // Сколько стул выдержит веса
    
    constructor(height: number, maxWeight: number) {
        this.height = height
        this.maxWeight = maxWeight
    }

    accept(visitor: IVisitor): void {
        visitor.visitChair(this)
    }
}

class Fork {
    material: string  // Из чего сделана вилка
    size: number      // Размер вилки
    
    constructor(material: string, size: number) {
        this.material = material
        this.size = size
    }

    accept(visitor: IVisitor): void {
        visitor.visitFork(this)
    }
}


// ____________________________Посетители__________________________________
interface IVisitor {
    visitTable(t: Table): any
    visitChair(ch: Chair): any
    visitFork(f: Fork): any
}

// Функция посетителя - выводить в консоль информацию об объекте
class HelpVisitor implements IVisitor {
    visitTable(t: Table) {
        let res = "Стол. Предназначен для размещения на нём предметов. Данный стол имеет следующие характеристики: длина=" + t.length + " ширина=" + t.width
        console.log(res)
    }

    visitChair(ch: Chair) {
        let res = "Стул. На нём можно сидеть. Данный стул имеет следующие характеристики: высота=" + ch.height + " максимальный вес=" + ch.maxWeight
        console.log(res)
    }

    visitFork(f: Fork) {
        let res = "Вилка. Ткни ей в кусок мяса и посмотри, что получится. Данная вилка имеет следующие характеристики: материал=" + f.material + " размер=" + f.size
        console.log(res)
    }
}

class UselessHelpVisitor implements IVisitor {
    visitTable(t: Table) {
        let res = "Стол. Без понятия зачем он нужен"
        console.log(res)
    }

    visitChair(ch: Chair) {
        let res = "Стул. Наверное где-то пригодится"
        console.log(res)
    }

    visitFork(f: Fork) {
        let res = "Вилка. Блестит"
        console.log(res)
    }
}

class Helper {
    visitor: HelpVisitor

    constructor() {
        this.visitor = new HelpVisitor()
    }

    help(target: Table | Chair | Fork) {
        target.accept(this.visitor)
    }
}

class UselessHelper {
    visitor: UselessHelpVisitor

    constructor() {
        this.visitor = new UselessHelpVisitor()
    }

    help(target: Table | Chair | Fork) {
        target.accept(this.visitor)
    }
}


function main() {
    let table = new Table(5, 10)
    let chair = new Chair(13, 300)
    let fork = new Fork("wood", 3)

    let helper = new Helper()
    let uselessHelper = new UselessHelper()

    helper.help(table)
    helper.help(chair)
    helper.help(fork)

    uselessHelper.help(table)
    uselessHelper.help(chair)
    uselessHelper.help(fork)
}

main()