// _______________________________________________________Продукты_____________________________________________________

// Рука робота
class Arm {
    info: string
    constructor(info: string = "None") {
        this.info = info
    }
}

// Нога робота
class Leg {
    info: string
    constructor(info: string = "None") {
        this.info = info
    }
}

// Робот
class Robot {
    leftArm: Arm = new Arm()
    rightArm: Arm = new Arm()
    leftLeg: Leg = new Leg()
    rightLeg: Leg = new Leg()
    hasNightVision: boolean = false

    setLeftArm(arm: Arm): void {
        this.leftArm = arm
    }

    setRightArm(arm: Arm): void {
        this.rightArm = arm
    }

    setLeftLeg(leg: Leg): void {
        this.leftLeg = leg
    }

    setRightLeg(leg: Leg): void {
        this.rightLeg = leg
    }

    setNightVision(value: boolean) {
        this.hasNightVision = value
    }
}

// Информация о роботе
class RobotInfo {
    leftArmInfo: string = "None"
    rightArmInfo: string = "None"
    leftLegInfo: string = "None"
    rightLegInfo: string = "None"
    hasNightVisionInfo: boolean = false

    setLeftArmInfo(arm: string): void {
        this.leftArmInfo = arm
    }

    setRightArmInfo(arm: string): void {
        this.rightArmInfo = arm
    }

    setLeftLegInfo(leg: string): void {
        this.leftLegInfo = leg
    }

    setRightLegInfo(leg: string): void {
        this.rightLegInfo = leg
    }

    setNightVisionInfo(value: boolean) {
        this.hasNightVisionInfo = value
    }

    printInfo(): void {
        console.log(`Left arm: ${this.leftArmInfo}
Right arm: ${this.rightArmInfo}
Left leg: ${this.leftLegInfo}
Right leg: ${this.rightLegInfo}
Night vision: ${this.hasNightVisionInfo}`)
    }
}


// _______________________________________________________Строители_____________________________________________________

// Интерфейс строителя
interface IBuilder {
    reset(): void
    setLeftArm(arm: Arm): void
    setRightArm(arm: Arm): void
    setLeftLeg(leg: Leg): void
    setRightLeg(leg: Leg): void
    setNightVision(value: boolean): void
}

// Строитель робота
class RobotBuilder implements IBuilder {
    private result: Robot = new Robot()

    reset(): void {
        this.result = new Robot()
    }
    
    setLeftArm(arm: Arm): void {
        this.result.setLeftArm(arm)
    }

    setRightArm(arm: Arm): void {
        this.result.setRightArm(arm)
    }

    setLeftLeg(leg: Leg): void {
        this.result.setLeftLeg(leg)
    }

    setRightLeg(leg: Leg): void {
        this.result.setRightLeg(leg)
    }

    setNightVision(value: boolean): void {
        this.result.setNightVision(value)
    }

    getResult(): Robot {
        return this.result
    }
}

// Строитель информации о роботе
class RobotInfoBuilder implements IBuilder {
    private result: RobotInfo = new RobotInfo()

    reset(): void {
        this.result = new RobotInfo()
    }
    
    setLeftArm(arm: Arm): void {
        this.result.setLeftArmInfo(arm.info)
    }

    setRightArm(arm: Arm): void {
        this.result.setRightArmInfo(arm.info)
    }

    setLeftLeg(leg: Leg): void {
        this.result.setLeftLegInfo(leg.info)
    }

    setRightLeg(leg: Leg): void {
        this.result.setRightLegInfo(leg.info)
    }

    setNightVision(value: boolean): void {
        this.result.setNightVisionInfo(value)
    }

    getResult(): RobotInfo {
        return this.result
    }
}


// _______________________________________________________Директор_____________________________________________________

class RobotDirector {
    buildBasicRobot(builder: IBuilder) {
        builder.reset()
        builder.setLeftArm(new Arm("Левая рука. Версия 1.6. Умеет чесать спину"))
        builder.setRightArm(new Arm("Правая рука. Версия 2.0 Способна удлиняться"))
        builder.setLeftLeg(new Leg("Левая нога. Версия 1.2. Осторожно, возможно самовоспламенение"))
        builder.setRightLeg(new Leg("Правая нога. Версия 1.3. Позолоченная"))
        builder.setNightVision(false)
        return builder
    }

    buildKillerMachine(builder: IBuilder) {
        builder.reset()
        builder.setLeftArm(new Arm("Левая рука. Версия 5.0. Оснащена ракетницей и лазерным мечом"))
        builder.setRightArm(new Arm("Правая рука. Версия 5.0. Встроенная бензопила"))
        builder.setLeftLeg(new Leg("Левая нога. Версия 5.0. Оснащена ракетными ускорителями"))
        builder.setRightLeg(new Leg("Правая нога. Версия 5.0. Оснащена ракетными ускорителями"))
        builder.setNightVision(true)
        return builder
    }
}

function main() {
    let director = new RobotDirector()
    let builderR = new RobotBuilder()
    let builderI = new RobotInfoBuilder()

    director.buildBasicRobot(builderR)
    director.buildBasicRobot(builderI)

    let bot1 = builderR.getResult()
    let bot1Info = builderI.getResult()

    director.buildKillerMachine(builderR)
    director.buildKillerMachine(builderI)

    let bot2 = builderR.getResult()
    let bot2Info = builderI.getResult()

    console.log("Bot 1:")
    bot1Info.printInfo()
    
    console.log("Bot 2:")
    bot2Info.printInfo()
}

main()